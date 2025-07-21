
# 🦾 RFID-Based Prosthetic Arm Sensor

This project simulates a **smart prosthetic arm** equipped with an **RFID reader** and an **OLED display**, allowing it to recognize specific objects or environmental conditions (e.g., hot, cold, etc.) via RFID tags. The system provides visual feedback on an OLED screen when a recognized RFID card is detected.

## 🚀 Features

* ✅ Detects and reads RFID cards using the MFRC522 module.
* ✅ Displays a custom message for each recognized card.
* ✅ Shows feedback on a 0.96" I2C OLED display (SSD1306).
* ✅ Displays "Touch Feeled" messages mimicking tactile feedback from a prosthetic.
* ❌ Shows an "Access Denied" message for unknown cards.

## 🔧 Hardware Required

* Arduino Uno (or compatible board)
* MFRC522 RFID reader module
* RFID tags/cards
* SSD1306 OLED Display (I2C, 128x32 or 128x64)
* Jumper wires
* Breadboard (optional)

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

## 📦 Libraries Used

Install the following libraries via the Arduino Library Manager:

* **MFRC522** by GithubCommunity
* **Adafruit GFX Library** by Adafruit
* **Adafruit SSD1306** by Adafruit

## 🧠 How It Works

1. The RFID reader waits for a card to be presented.
2. When a card is scanned, its UID is read and matched with pre-defined UIDs in the code.
3. Based on the UID, a message is displayed on the OLED screen:

   * Recognized cards show a message like:

     * "Touch Feeled, a hot object is identified"
     * "Touch Feeled, a cold object is identified"
   * Unknown cards show: "Access Denied, Unknown User!"
4. The display resets after showing the message for 1 second.

## 🧾 Sample Output

```
UID of the card: 5dd37cc3
Message: Touch Feeled, a Cold object is identified touching the prosthetic arm!
```
