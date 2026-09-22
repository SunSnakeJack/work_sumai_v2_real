# Proposed real-hardware wiring

This pin plan is for a common ESP32-C3 SuperMini layout. Published SuperMini pinouts expose GPIO0-10, GPIO20, and GPIO21, so all selected signal pins are normally broken out. Board variants exist: verify the labels and schematic for the exact board before wiring.

GPIO2, GPIO8, and GPIO9 are ESP32-C3 strapping pins and are intentionally avoided. GPIO18 and GPIO19 are associated with native USB and are not used. The PlatformIO `esp32-c3-devkitm-1` target is a compile-compatible target, not a claim that its PCB is identical to the SuperMini.

| Type | ESP32-C3 SuperMini | Destination | Destination pin / detail |
|---|---:|---|---|
| SIGNAL | GPIO4 | MPU6050 GY-521 | SDA |
| SIGNAL | GPIO5 | MPU6050 GY-521 | SCL |
| SIGNAL | GPIO6 | INMP441 | SCK/BCLK |
| SIGNAL | GPIO7 | INMP441 | WS/LRCLK |
| SIGNAL | GPIO10 | INMP441 | SD data output |
| SIGNAL | GPIO0 | External status LED | GPIO0 -> 220 ohm resistor -> LED anode; LED cathode -> GND |
| SIGNAL | GPIO1 | Sound buzzer interface | Control input |
| SIGNAL | GPIO3 | Motion buzzer interface | Control input |
| SIGNAL | GPIO20 | Monitoring switch | Switch between GPIO20 and GND; firmware uses `INPUT_PULLUP` |
| POWER | 3.3V | INMP441 | VDD |
| POWER | 3.3V-compatible supply | MPU6050 GY-521 | VCC; verify the exact breakout board |
| GROUND | GND | INMP441 | GND |
| GROUND | GND | INMP441 | L/R, selecting the LEFT channel used by firmware |
| GROUND | GND | MPU6050 GY-521 | GND |
| GROUND | GND | LED, buzzer interfaces, switch | Common ground |

The INMP441 is a **digital I2S microphone**, not an analog sensor. Do not connect its SD output to an ADC or use `analogRead()` for it.

GPIO pins must not directly drive a buzzer that exceeds the board's GPIO current capability. Verify whether each selected buzzer is an active module, passive piezo, or higher-current device; add an appropriate transistor/MOSFET driver and protection components when required.

All signal voltage levels must remain 3.3V-compatible. Confirm the exact SuperMini and sensor-module pin labels before power is applied.

