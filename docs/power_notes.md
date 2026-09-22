# Battery and power notes

## Status: NOT YET VERIFIED

The battery subsystem must be designed and verified before physical connection.

- A TP4056 is primarily a charger for one single-cell Li-ion/Li-Po battery. It does **not** provide a regulated 3.3V output.
- Some TP4056 modules include battery protection circuitry; others do not. Identify the exact module and verify its schematic and protection functions.
- A nominal 3.7V Li-Po varies substantially over its charge/discharge range. Do not connect it directly to the ESP32-C3 3.3V pin.
- Match the ESP32-C3 SuperMini input requirements to a correct, verified regulator and power path. A regulator or power-management stage may be required.
- Account for ESP32-C3 Wi-Fi current peaks, microphone and sensor load, buzzer load, voltage drop, charging behavior, and thermal performance.
- Do not assume a development board's USB/5V input and 3.3V pin accept the same voltage ranges.
- Confirm common ground, polarity, connector orientation, battery protection, short-circuit protection, and safe charging current before connection.
- Do not charge or operate a damaged, swollen, punctured, hot, or unverified cell.

Exact battery, charger, regulator, load-sharing, and physical wiring must be reviewed against the actual parts before power is applied. No physical battery wiring is approved by this document.

