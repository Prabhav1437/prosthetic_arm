#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define SS_PIN 10       
#define RST_PIN 9       
MFRC522 mfrc522(SS_PIN, RST_PIN);

String rfid_tags[] = {
  "7560562c", "55171553", "5dd37cc3",//put your rfid card numbers here 
};
String messages[] = {
    "Touch Feeled, an opject is identified touching the prosthetic arm!",
    "Touch Feeled, a Hot object is identified touching the prosthetic arm!",
    "Touch Feeled, a Cold object is identified touching the prosthetic arm!",
  "Access Denied, Unknown User!"
};

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging


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

  
      String message = "Unknown Card";
      for (int i = 0; i < 7; i++) {   
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

  

      
      delay(1000);

      
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