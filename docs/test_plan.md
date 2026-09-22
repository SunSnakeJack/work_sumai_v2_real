# Future real-hardware test plan

Record hardware revisions, firmware commit, supply voltage, test environment, readings, and results for every run. Prototype thresholds are calibration values, not medical or safety standards.

- [ ] 1. ESP32-C3 boots and prints the startup report.
- [ ] 2. MPU6050 is detected at address `0x68`.
- [ ] 3. INMP441 I2S initializes successfully.
- [ ] 4. Measure the quiet-room sound RMS baseline.
- [ ] 5. Perform a controlled loud-sound test.
- [ ] 6. Calibrate `SOUND_RMS_THRESHOLD` with the real microphone and enclosure.
- [ ] 7. Trigger and clear the motion alert.
- [ ] 8. Trigger and clear the combined alert.
- [ ] 9. Verify steady/flashing/off status LED behavior.
- [ ] 10. Verify the sound buzzer and its driver circuit.
- [ ] 11. Verify the motion buzzer and its driver circuit.
- [ ] 12. Verify monitoring OFF immediately silences both buzzers and turns off the LED.
- [ ] 13. Connect to the intended Wi-Fi network.
- [ ] 14. Confirm the device is online in Blynk.
- [ ] 15. Confirm V0-V4 live telemetry and units.
- [ ] 16. Confirm one `sound_alert` push notification per eligible transition/cooldown.
- [ ] 17. Confirm one `motion_alert` push notification per eligible transition/cooldown.
- [ ] 18. Confirm one `combined_alert` push notification per eligible transition/cooldown.
- [ ] 19. Remove Wi-Fi while confirming local sensing, LED, and buzzers continue.
- [ ] 20. Restore Wi-Fi and confirm automatic Blynk reconnection and telemetry recovery.

Also inspect for unexpected heating, unstable power, resets, acoustic coupling between buzzers and microphone, false triggers, enclosure pressure points, exposed conductors, sharp edges, strap restriction, and battery movement. Do not test the device on a child until appropriate engineering and safety review has been completed.

