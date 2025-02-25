# Arduino Volume Control

A simple Arduino-Python project that allows you to control your PC's volume using a physical potentiometer. It also includes a mute button and LED indicators for volume status. The Python script reads data from the Arduino via serial communication and adjusts the system volume accordingly.

## Features
- Adjust system volume using a physical potentiometer.
- Mute/unmute functionality via a button.
- LED indicators for mute and volume status.
- Uses `pycaw` for volume control.

## Hardware Requirements
- Arduino Uno (or compatible)
- Potentiometer (10kΩ recommended)
- Push button
- LED indicators (optional)
- 10kΩ Resistor for LEDs

## Software Requirements
- Python 3.x
- `pyserial`
- `pycaw`
- Arduino IDE (for uploading code)

## Installation
1. Upload the Arduino sketch to your board.
2. Choose the appropriate COM port.
3. Install Python dependencies:
   pip install pyserial pycaw
4. python volumer.py

## Wiring Diagram
Connect the potentiometer to A0, button to D4, and LEDs to their respective digital pins.

## Usage
- Turn the potentiometer to adjust volume.
- Press the button to toggle mute.
- LEDs indicate mute and volume status.

## Potential Issues
- **Port unavailable**: You selected the wrong COM port. Double-check the correct port in the Arduino IDE.  
- **Port busy or in use**: The port might be occupied by another application (e.g., Arduino IDE). Close it after uploading the code and try again.  

## License
This project is open-source and available under the MIT License.