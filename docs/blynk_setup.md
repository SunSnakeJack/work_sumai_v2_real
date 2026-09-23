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
   - V3: alert state (String)
   - V4: monitoring enabled, 0 or 1 (integer)
8. Create events with the exact codes `sound_alert`, `movement_alert`, and `combined_alert`.
9. Enable push notification delivery for those events in Blynk.
10. Put Wi-Fi, Template, and Device credentials only in `include/secrets.h`. Never add real values to `secrets.example.h`, documentation, logs, or source control.
11. Rebuild and upload the firmware.

The firmware sends telemetry no faster than once per second. Events are edge-triggered and independently rate-limited by a 30-second firmware cooldown. Any Blynk Console notification/rate limit is a separate cloud-side setting and must be verified independently.

Alerts that occur while Blynk is offline are retained as RAM-only pending events and are delivered after reconnect when their event cooldown permits. `combined_alert` has priority over lower-priority pending events from the same continuous incident. After a Combined state occurs, lower-priority Sound and Movement cloud events are suppressed until the incident reaches `NORMAL` or `MONITORING_OFF`. Local sensing, LED, buzzers, and telemetry remain independent of this cloud-event suppression.

V3 values are exactly: `NORMAL`, `SOUND_ALERT`, `MOTION_ALERT`, `COMBINED_ALERT`, and `MONITORING_OFF`.
The REAL firmware uses Blynk's default cloud endpoint/GeoDNS through `Blynk.config(BLYNK_AUTH_TOKEN)`; it does not hardcode a regional hostname or port. Confirm the device's template, region, datastreams, events, and notification settings in Blynk Console without exposing the Auth Token.

Status: software verified; hardware validation and live Blynk Console validation pending.
