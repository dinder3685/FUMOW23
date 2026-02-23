# MWFU23 - Solar-Powered Rover Robot

A solar-powered rover robot controlled by an ESP8266 microcontroller with wireless motor control via WiFi web server.

## Description

MWFU23 is an autonomous solar-powered rover robot equipped with four DC motors for movement control. The ESP8266 microcontroller runs a web server that allows remote control of the rover's motors via HTTP requests. The robot features solar charging capabilities for sustainable operation.

## Hardware Requirements

- ESP8266 microcontroller
- 4x DC Motors with Driver Module (L298N or similar)
- Solar Panel (5V-12V rated)
- Battery Pack (2-3S LiPo recommended)
- Power Management/Charging Circuit
- Rover chassis with wheels
- USB cable for programming

## Motor Pin Configuration

- Motor A: IN1=GPIO5 (D1), IN2=GPIO4 (D2)
- Motor B: IN1=GPIO0 (D3), IN2=GPIO2 (D4)
- Motor C: IN1=GPIO14 (D5), IN2=GPIO12 (D6)
- Motor D: IN1=GPIO13 (D7), IN2=GPIO16 (D0)

## Software Requirements

- PlatformIO
- Visual Studio Code (recommended)
- Arduino framework for ESP8266

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

1. Connect to the WiFi network specified in the code (default: "iPhone")
2. Access the rover's web interface at `http://<ESP8266_IP_ADDRESS>/`
3. Control the rover using the web server commands:
   - `/forward` - Move forward
   - `/backward` - Move backward
   - `/left` - Turn left
   - `/right` - Turn right
   - `/stop` - Stop all motors

The rover will continue in the selected direction until a different command is received.

## Solar Power

The rover is designed to charge via solar panels during the day and operate autonomously. Ensure the charging circuit is properly configured for your battery setup (LiPo recommended with proper BMS).

## Project Structure

```
MWFU23/
├── src/
│   └── main.cpp              # Main rover control firmware
├── include/                  # Header files
├── lib/                      # Libraries
├── platformio.ini            # PlatformIO configuration
└── README.md                 # This file
```

## Configuration

Edit `platformio.ini` to configure:
- Board type (ESP8266)
- Upload port and speed
- Serial monitor baud rate

Edit `src/main.cpp` to configure:
- WiFi SSID and password
- Motor pin assignments
- Motor control behavior

## Features

- ✅ Four motor control (forward, backward, left, right, stop)
- ✅ WiFi-based web server control
- ✅ Solar power support
- ✅ Real-time status reporting
- ✅ Lightweight and efficient

## License

MIT License

## Author

dinder3685
