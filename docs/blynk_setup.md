# Blynk IoT setup

1. Create or sign in to a Blynk account.
2. Create a Blynk Template for the ESP32-C3 device.
3. Create a Device from that template.
4. Copy the Template ID.
5. Copy the Template Name.
6. Copy the Device Auth Token.
7. Configure these virtual-pin datastreams:
   - V0: sound RMS (double)
   - V1: acceleration magnitude in g (double)
   - V2: gyro magnitude in degrees/second (double)
   - V3: alert-state enum value (integer)
   - V4: monitoring enabled, 0 or 1 (integer)
8. Create events with the exact codes `sound_alert`, `motion_alert`, and `combined_alert`.
9. Enable push notification delivery for those events in Blynk.
10. Put Wi-Fi, Template, and Device credentials only in `include/secrets.h`. Never add real values to `secrets.example.h`, documentation, logs, or source control.
11. Rebuild and upload the firmware.

The firmware sends telemetry no faster than once per second. Events are edge-triggered and independently rate-limited to at least 30 seconds by default. Local sensing, LED, and buzzers continue when Wi-Fi or Blynk is unavailable; reconnect attempts are periodic and short.

Real credentials have not been provided, so Blynk connectivity and phone notifications are not yet tested.

V3 values are: 0 `MONITORING_OFF`, 1 `NORMAL`, 2 `SOUND_ALERT`, 3 `MOTION_ALERT`, and 4 `COMBINED_ALERT`.

