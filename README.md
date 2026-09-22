# work_sumai V2 real hardware

ESP32-C3 baby-safety monitoring prototype for an ESP32-C3 SuperMini, INMP441 digital I2S microphone, MPU6050, status LED, two buzzers, monitoring switch, Wi-Fi, and Blynk IoT.

V2 replaces V1's analog potentiometer sound simulation with a real I2S receive path and RMS calculation. `SOUND_RMS_THRESHOLD` is only a compile-time placeholder: it must be calibrated using the actual microphone, enclosure, environment, and desired response.

The firmware keeps sensing and local LED/buzzer alerts independent of Wi-Fi and Blynk. Cloud telemetry uses V0-V4, and edge-triggered Blynk events have per-event cooldown protection.

## Build

1. Copy the credential placeholders from `include/secrets.example.h` into the ignored `include/secrets.h` file.
2. Replace placeholders only when real network testing begins.
3. Run `pio run`.

See `docs/wiring.md`, `docs/blynk_setup.md`, `docs/power_notes.md`, and `docs/test_plan.md` before connecting hardware.

## Safety scope

This is a prototype safety-assistance device. It is **not a medical device**, does not establish that an environment is safe, and must never replace adult supervision. It is not approved or verified for unsupervised infant sleep.

For anything worn by a child, the battery and PCB must be fully enclosed, mechanically protected, and free of exposed conductors or sharp edges. The enclosure must not become hot. A strap must not restrict circulation, and placement must avoid entanglement, choking, pressure, and sleep-related hazards. Physical hardware, battery power, thresholds, and enclosure safety are not yet verified.

