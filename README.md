# HelloLED

A simple LED blinking project for ESP8266 using PlatformIO.

## Description

This project demonstrates basic GPIO control on an ESP8266 microcontroller, implementing a simple LED blinking pattern.

## Hardware Requirements

- ESP8266 microcontroller
- LED (with appropriate resistor for current limiting)
- USB cable for programming

## Software Requirements

- PlatformIO
- Visual Studio Code (recommended)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/dinder3685/FUMOW23.git
   cd FUMOW23
   ```

2. Open the project in VS Code with PlatformIO installed

3. Build the project:
   ```bash
   pio run
   ```

4. Upload to your ESP8266:
   ```bash
   pio run -t upload
   ```

## Usage

Once uploaded, the LED will blink at regular intervals. Modify the `delay()` parameters in `src/main.cpp` to adjust the blink rate.

## Project Structure

```
helloled/
├── src/
│   └── main.cpp          # Main firmware code
├── include/              # Header files
├── lib/                  # Libraries
├── platformio.ini        # PlatformIO configuration
└── README.md             # This file
```

## Configuration

Edit `platformio.ini` to configure:
- Board type
- Upload port
- Serial monitor baud rate

## License

MIT License

## Author

dinder3685
