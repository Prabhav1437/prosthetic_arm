
# 🦾 RFID-Based Prosthetic Arm Sensor

This project simulates a **smart prosthetic arm** equipped with an **RFID reader**, an **OLED display**, and a **servo motor**, allowing it to recognize specific objects or environmental conditions (e.g., hot, cold, touch, wind) via RFID tags. The system provides visual feedback on an OLED screen and simulates **tactile feedback** using a rotating motor when a recognized RFID card is detected.

---

## 🚀 Features

* ✅ Detects and reads RFID cards using the MFRC522 module.
* ✅ Displays custom messages for each recognized card on a 0.96" OLED screen.
* ✅ Mimics tactile feedback by rotating a servo motor (SM-S2309S) for 2 seconds on card scan.
* ❌ Displays "Access Denied" for unknown cards.

---

## 🔧 Hardware Required

* Arduino Uno (or compatible board)
* MFRC522 RFID Reader Module
* RFID Tags/Cards
* SSD1306 OLED Display (I2C, 128x32 or 128x64)
* SM-S2309S Servo Motor (or compatible 180° servo)
* Jumper Wires
* Breadboard (optional)
* (Optional) External power supply for motor

---

## 🔌 Wiring

### RFID (MFRC522) to Arduino:

| MFRC522 Pin | Arduino Uno |
| ----------- | ----------- |
| SDA         | D10         |
| SCK         | D13         |
| MOSI        | D11         |
| MISO        | D12         |
| RST         | D9          |
| VCC         | 3.3V        |
| GND         | GND         |

### OLED (SSD1306) to Arduino:

| OLED Pin | Arduino Uno |
| -------- | ----------- |
| VCC      | 5V          |
| GND      | GND         |
| SDA      | A4          |
| SCL      | A5          |

### Servo Motor (SM-S2309S) to Arduino:

| Servo Wire    | Function    | Arduino Uno       |
| ------------- | ----------- | ----------------- |
| Red           | VCC (Power) | 5V or External 5V |
| Brown/Black   | GND         | GND               |
| Orange/Yellow | Signal      | D6 (PWM)          |
---

## 📦 Libraries Used

Install the following libraries via the Arduino Library Manager:

* **MFRC522** by GithubCommunity
* **Adafruit GFX Library** by Adafruit
* **Adafruit SSD1306** by Adafruit
* **Servo** (built-in Arduino library)

---

## 🧠 How It Works

1. The RFID reader waits for a card to be scanned.
2. On scan, it reads the card's UID and compares it with known UIDs.
3. If matched:

   * Displays a specific message on the OLED.
   * Rotates the servo motor to simulate a "touch" or "feel" feedback for 2 seconds.
4. If the card is unrecognized, it shows "Access Denied" on the display.
5. The system resets the display for the next scan.

---

## 🧾 Sample Output (Serial Monitor)

```
UID of the card: 5dd37cc3
Message: Touch Feeled, a Cold object is identified touching the prosthetic arm!
Servo: Rotated to 90°, holding for 2 seconds...
```

---
