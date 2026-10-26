# ESP32-Light-Switch-Actuator

**A battery powered, ESP32-C3 based actuator that physically toggles an existing light switch.**

This project uses a small servo motor and 3D-printed parts to operate a wall switch without modifying the building's electrical wiring. An ESP32-C3 Super Mini reads a rocker switch input and moves the servo between two calibrated positions. Between activations, the controller enters deep sleep to reduce power consumption.


## How it works

1. The ESP32-C3 wakes in response to the configured input signal.
2. It reads the state of the input rocker switch.
3. It moves the SG90 servo to the corresponding calibrated position, physically toggling the wall switch.
4. It enters deep sleep until the next supported wake up event.


## Bill of materials

| Qty. | Component | Specification / notes | Link |
| --- | --- | --- | --- |
| 1 | ESP32-C3 Super Mini | Microcontroller | — |
| 1 | SG90 micro servo | Light-switch actuator | — |
| 1 | mxuteuk rocker switch | MXU1-5-101NR, illuminated SPST rocker; used as a low-voltage control input | [Amazon](https://www.amazon.com/dp/B07QTPH8QZ) |
| 1 | EEMB LiPo battery | LP603449, 3.7 V, 1100 mAh | [Amazon](https://www.amazon.com/dp/B08FD39Y5R) |
| As needed | Hookup wires | Connections between components | — |
| As needed | 3D-printed parts | Enclosure, bracket and/or servo linkage; see design files | — |

A also available in [`hardware/BOM.csv`](hardware/BOM.csv).

OnShape CAD Design available [here](https://cad.onshape.com/documents/a65a3372ac1a8a6ea4c2d8f1/w/55243c3d919bd193eaca02d5/e/07d58b514f8302c012b788aa)

The servo mount in this project is **based on a design by [carjo3000 on Thingiverse](https://www.thingiverse.com/thing:1156995)**. The original design is credited to carjo3000 and is provided under a **Creative Commons Attribution-NonCommercial (CC BY-NC)** license. The mount used here has been adapted for this project.


## Assembly and setup

1. Print the mounting parts from `hardware/stl/` once those files have been added.
2. Install the servo and position the mechanism so it can toggle the existing wall switch without binding.
3. Mount the ESP32-C3, input rocker switch and battery securely.
4. Wire the components according to the project's wiring diagram **once verified and uploaded**.
5. Flash the firmware to the ESP32-C3.
6. Calibrate the two servo positions in the firmware to match your installation.
7. Test the mechanism and wake-up behavior before leaving the device in service.

## Power consumption

Deep sleep reduces ESP32-C3 power consumption between servo movements. Actual runtime also depends on the board's sleep current, any attached electronics, how often the servo operates, and the power supply design.

A rough illustrative estimate, **not a measured result**, at 0.3 mA average draw is:

```text
Battery life = 1100 mAh / 0.3 mA ≈ 3667 hours ≈ 153 days
```

The 0.3 mA figure is an assumption only. Battery life claims should be updated after measuring total system current in sleep and during actuation.

## Possible future improvements

- Browser-based remote control
- Automatic shutoff timers
- Motion-sensor activation

These additions may increase power consumption and firmware complexity.

## Safety

- This project is intended to **physically actuate** an existing light switch, not to alter or directly connect to household mains wiring.
- Use the rocker switch **only in an appropriately designed low-voltage input circuit**. Its AC rating does not mean the ESP32 can accept AC mains voltage.
- Verify LiPo connector polarity, suitable voltage regulation, servo power requirements, battery protection, and appropriate charging hardware before powering the build. Do not connect a raw LiPo to an unspecified ESP32 board power pin without checking its supported input voltage.
- Keep moving parts clear of fingers and avoid forcing the wall switch mechanism.

## License

This project is released under the following licenses:

Firmware: Licensed under the MIT License.

Original hardware designs: Licensed under the Creative Commons Attribution 4.0 International License (CC BY 4.0).

Documentation: Licensed under CC BY 4.0.
