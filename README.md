# Smart Vehicle Safety System (Arduino Project)

## About this project
I built a **mini vehicle safety system** using an Arduino and an ultrasonic distance sensor.  
Think of it like a tiny version of a car’s obstacle detection system. The system measures the distance to objects in front of it and shows whether it’s **safe, warning, or danger** using three LEDs.  

Although small, this project teaches **embedded programming, sensor interfacing, and control logic**, which are essential skills for robotics, automotive electronics, and ICE systems.

---

## How it works
1. The **ultrasonic sensor** sends out a sound pulse.  
2. The Arduino measures how long it takes for the pulse to bounce back.  
3. Based on the distance, it turns on the LEDs:
   - **Green LED** → Safe  
   - **Yellow LED** → Warning  
   - **Red LED** → Danger  

This process runs **continuously**, simulating real-time decision-making like a car’s safety system.

---

## Hardware used
- Arduino UNO (or Nano)  
- 3-pin Ultrasonic Distance Sensor  
- 3 LEDs: Red, Yellow, Green  
- 3 × 220Ω resistors  
- Jumper wires  

---

## Software used
- Arduino IDE  
- Tinkercad for simulation

    <img width="798" height="746" alt="image" src="https://github.com/user-attachments/assets/9100cdf2-8800-45c7-bfd8-bacff2cf9b4d" />

---

## Learning outcomes
- Understanding **embedded systems** and real-time sensor reading  
- Programming in **Arduino C/C++**  
- Designing **control logic for safety systems**  
- Hands-on experience with **automotive/robotics-style projects**  

---

## Future improvements
- Add a **motor** to simulate braking automatically  
- Convert the LED logic into a **Finite State Machine** for industry-style design  
- Implement the system on **FPGA** for hardware-level control  
- Extend to **multi-sensor obstacle detection**  

---
