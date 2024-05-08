# Arduino Smart Eco Box Control System

This project is an Arduino-based smart plant light control system. It uses a DHT11 sensor to monitor environmental humidity and temperature, and controls the brightness and color of LED lights based on the set mode. Additionally, it displays environmental data and the current operating mode on an OLED screen.

## Features

- Monitor environmental humidity and temperature
- Automatically adjust LED light based on environmental data
- Support manual switching of LED light modes
- Real-time display of environmental data and current operating mode on an OLED screen

## Hardware Required

- Arduino board
- DHT11 sensor
- WS2812B LED strip
- SSD1306 OLED screen
- One button

## Usage

1. Connect the required hardware to the Arduino board, ensuring correct connections.
2. Burn the provided code to the Arduino board using the Arduino IDE.
3. Click the button to switch LED light modes. The system will adjust the LED light based on the current environmental data and selected mode.
4. View the OLED screen for real-time environmental data and current operating mode.

## Code Explanation

- The `setup()` function initializes the system and runs once when the system starts.
- The `loop()` function contains the main system logic for continuously monitoring button status, updating screen display, and controlling LED lights.
- The `showScreen()` function updates the OLED screen display, including environmental data and the current operating mode.
- The `light()` function controls the LED light effects based on the mode value.

## Notes

- This project is for learning and demonstration purposes only. It has not been thoroughly tested and may have unknown issues.
- Please exercise caution with electrical safety and ensure correct hardware connections to avoid damaging devices or causing hazards.
- If you have any questions or suggestions, feel free to contact us or submit an issue.

## Contributions

Contributions such as suggestions for improvement, issue reporting, or code contributions are welcome. You can contribute by submitting an issue or pull request.


![4241715150167_ pic](https://github.com/S1m6aX/CyberEcoBox/assets/125509593/4b7b82ed-35e6-42a9-90ac-28d1dcc509e7)
