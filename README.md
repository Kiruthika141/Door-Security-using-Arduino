# Door Security using Arduino and Proteus

A virtual **Door Security control system** built using **Arduino UNO** and **Proteus simulation**.  
This project demonstrates how authentication and smart locking systems works.

## Overview

This project simulates an **Smart Lock** using the **Serial Monitor** (or Virtual Terminal) to act as a virtual RFID reader.  
When a user enters their "card number" through serial input, the Arduino validates it against a list of authorized users and decides whether to grant or deny access.

## Features

1. Simulated RFID reader using serial input
2. LCD screen displays card status and user name  
3. Green LED for valid access  
4. Red LED and Buzzer for invalid attempts  
5. Customizable user IDs and names  
6. Fully compatible with **Proteus 8.x** simulation

## Components Used

| Component | Specification | Function |
|------------|----------------|-----------|
| **Arduino UNO** | ATmega328P | Main controller |
| **LCD Display** | 16x2 | Message display |
| **LEDs** | Red & Green | Access indicators |
| **Buzzer** | 5V Active Buzzer | Alerts for invalid entry |
| **Virtual Terminal** | (Proteus) | Simulates RFID input |


## Pin Configuration

| Component | Arduino Pin |
|------------|-------------|
| LCD RS | 13 |
| LCD E  | 12 |
| LCD D4 | 11 |
| LCD D5 | 10 |
| LCD D6 | 9 |
| LCD D7 | 8 |
| Red LED | 5 |
| Green LED | 6 |
| Buzzer | 7 |

## Software Requirements

- Arduino IDE  
- Proteus 8  
- LiquidCrystal Library (comes preinstalled)

## How It Works

1. Upload the Arduino code (`SmartHome_Lock.ino`) to your Proteus simulation.
2. Connect a **Virtual Terminal** to Arduino TX (Pin 1) and RX (Pin 0).
3. Run the simulation.
4. In the terminal, type a card number (e.g., `12345`) and press Enter.
5. The LCD and LEDs will respond accordingly:

| Card Number | User Name | Result |
|--------------|------------|--------|
| 11111 | PRIYA | Access Granted |
| 22222 | RIYA | Access Granted |
| 33333 | AMIR | Access Granted |
| 44444 | ARUN | Access Granted |
| 55555 | IMRAN | Access Granted |
| 66666 | MEERA | Access Granted |
| Any other | UNKNOWN | Access Denied |

## Educational Concepts

- Serial Communication  
- LCD Interfacing  
- Digital I/O (LEDs and Buzzer)  
- Conditional Logic  
- Authentication Simulation  
