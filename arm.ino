#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>  // Include Servo library
//code for prototype 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define SS_PIN 10       
#define RST_PIN 9       
MFRC522 mfrc522(SS_PIN, RST_PIN);

#define MOTOR_PIN 6   // PWM pin connected to SM-S2309S
Servo touchMotor;    // Create servo object

String rfid_tags[] = {
  "7560562c", "91ee3543", "5dd37cc3", "61113f43" // RFID card UIDs
};

String messages[] = {
  "Touch Detected",
  "Hot Temp. Detected",
  "Cold temp. detected",
  "Wind Detected",
  "Access Denied, Unknown User!"
};

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Prosthetic Arm"));
  display.setCursor(0, 10);
  display.println(F("Deployed"));
  display.display();
  delay(2000);

  SPI.begin();
  mfrc522.PCD_Init();

  if (mfrc522.PCD_PerformSelfTest()) {
    Serial.println(F("RFID Reader is successfully initialized"));
  } else {
    Serial.println(F("RFID Reader initialization failed"));
    while (true);
  }

  // Initialize motor
  touchMotor.attach(MOTOR_PIN);
  touchMotor.write(0); // Initial position
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()) {

      String rfid_uid = "";
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        rfid_uid += String(mfrc522.uid.uidByte[i], HEX);
      }

      Serial.print(F("UID of the card: "));
      Serial.println(rfid_uid);

      String message = messages[4]; // Default message: Unknown user
      for (int i = 0; i < 4; i++) {  // only check known cards
        if (rfid_uid == rfid_tags[i]) {
          message = messages[i];
          break;
        }
      }

      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 20);
      display.println(F("Touch Feeled"));
      display.setCursor(0, 0);
      display.println(message);
      display.display();

      // Rotate motor for 2 seconds
      touchMotor.write(180);  // Rotate to 90 degrees (or desired position)
 
    delay(1000);
      touchMotor.write(0);


      display.clearDisplay();
      display.setCursor(0, 0);
      display.println(F("Prosthetic Arm"));
      display.setCursor(0, 10);
      display.println(F("Deployed"));
      display.display();
      delay(500);
    }
  }
}
