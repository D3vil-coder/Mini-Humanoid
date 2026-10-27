# Mini Humanoid

An Arduino sketch for a small servo-driven humanoid. It reads single-character commands from the board's serial port and runs predefined hip and foot movements. The original project describes Bluetooth control, but the sketch itself reads `Serial`, so a compatible serial connection is required whether commands come from Bluetooth or a wired serial terminal.

## Repository contents

- [`Robo_bluetooth.ino`](Robo_bluetooth.ino): serial command handling and movement sequences.
- [`LICENSE`](LICENSE): MIT license.

The repository does not include a parts list for a specific build, chassis files, wiring diagram, or measured movement results. The following descriptions are based on the source code; this documentation update has not been tested on physical hardware.

## Servo connections and starting positions

The sketch attaches four servos and writes these positions in `homeposition()`:

| Servo | Arduino pin | Home angle |
| --- | --- | --- |
| Left hip | 3 | 90° |
| Right hip | 4 | 90° |
| Left foot | 5 | 75° |
| Right foot | 6 | 90° |

Left and right arm `Servo` objects are declared in the sketch, but no pins are attached to them and no arm movement is implemented. The angles are program values, not calibrated limits for every chassis. Calibrate the mechanism for the actual servo orientation and mechanical range before allowing it to move freely.

## Serial commands

The sketch initializes the board's hardware serial connection at **9600 baud** and reads a single character at a time.

| Character | Sequence in the sketch |
| --- | --- |
| `1` | Runs `leftturn()` followed by `rightturn()`; the code labels this forward movement. |
| `2` | Runs `leftback()` followed by `rightback()`; the code labels this backward movement. |
| `3` | Runs `leftturn()`. |
| `4` | Runs `rightturn()`. |
| `5` | Runs a foot movement labelled dance. |
| `6` | Runs a simultaneous left and right foot movement. |
| `0` | Writes the home angles to the four servos. |

Actual direction, balance and range depend on the physical assembly. Each movement uses blocking loops and delays, so `0` is not an immediate emergency stop. `homeposition()` writes the servo angles but does not reset the sketch's stored angle variables; this can matter if the code is modified or a movement ends with changed variables.

## Setup outline

1. Use an Arduino-compatible board supported by the Arduino Servo library, four suitably powered servos, and a serial connection. Select and verify the board, power supply and communication hardware for the specific build; their exact models are not recorded here.
2. Connect the servo signal leads according to the source mapping above. Size the servo supply for the hardware and check voltage, current, common-ground requirements and the Bluetooth module's serial voltage levels before connecting it. A wiring diagram is not provided in this repository.
3. Open `Robo_bluetooth.ino` in the Arduino IDE, select the correct board and port, and compile and upload it. The sketch includes `<Servo.h>`.
4. Use a suitable serial terminal configured for 9600 baud. If using a Bluetooth serial module, pair and connect it according to that module's documentation. Send one of the command characters above and test movements with the mechanism supported and clear of obstructions.

The exact board, Bluetooth wiring, upload process and hardware behavior have not been verified for this documentation update. In particular, a Bluetooth module sharing the board's hardware serial pins can interfere with uploading or serial monitoring on some boards.

## License

This project is available under the [MIT license](LICENSE).

