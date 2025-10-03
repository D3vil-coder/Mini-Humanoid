# 🤖 Mini Humanoid Project

## 📌 Overview
This is a **Mini Humanoid Robot** built using Arduino, servo motors, and a Bluetooth module.  
The robot can **walk, turn, and move its hands**, with commands received from a paired Bluetooth device (phone/PC).

---

## 🔧 Hardware Requirements
- Arduino Board (UNO / Nano / Mega)
- Bluetooth Module (HC-05 / HC-06)
- Servo Motors 
- Power Supply (sized for number of servos)
- Jumper wires and chassis

---

## 🦿 Motor Mapping
| Body Part   | Pin  | Home Position | Notes |
|-------------|------|---------------|-------|
| Left Hip    | 3    | 90            | Moves legs forward/backward |
| Right Hip   | 2    | 95            | Turns body left/right |
| Left Foot   | 5    | 80            | Heel: 100, Toe movement |
| Right Foot  | 4    | 90            | Toe: 120, Heel support |
| Left Hand   | -    | -             | Needs valid PWM pin |
| Right Hand  | -    | -             | Needs valid PWM pin |


---

## 🎮 Controls
The humanoid listens for single-character commands via Bluetooth:

| Command | Action            |
|---------|-------------------|
| `1`     | Walk Forward      |
| `2`     | Walk Backward     |
| `3`     | Turn Left         |
| `4`     | Turn Right        |
| `5`     | Dance Move        |
| `0`     | Stand Still       |

---

## 🚶 Walking Movements
The robot already has **basic gait cycles** coded:
- **Forward Walking** → alternating hip & foot movement
- **Backward Walking** → reverse gait

---

## 🛠 Setup Instructions
1. Wire all servos to the Arduino pins as per the mapping.
2. Upload `Robo_bluetooth.ino` using Arduino IDE.
3. Pair your phone with the Bluetooth module (default: `1234` or `0000`).
4. Open a Bluetooth terminal app, connect, and send commands (`1`, `2`, `5`, etc.).

---

## 🚀 Future Improvements
- Add more natural gait cycles
- Neck/head movement
- Gesture-controlled walking
- Battery optimization

---

👨‍💻 **Author**: (Your Name)  
📅 **Version**: 1.0  
