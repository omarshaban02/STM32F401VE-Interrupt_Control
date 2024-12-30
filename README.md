# 7-Segment Counter with External Interrupts

This project demonstrates a simple embedded system that uses a 7-segment display to show a counter value, with external interrupts for incrementing and decrementing the counter. The counter is displayed on the 7-segment display, and two external GPIO pins (PA9 and PB4) are used to control the counter:

- **PA9**: Increases the counter value.
- **PB4**: Decreases the counter value.

[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/HIidFvan)

## Link to Google Drive

[Video of the code](https://drive.google.com/drive/folders/1WGO0e9CR9d_w61Yyfu1jdyh-JUnWhdVs?usp=sharing)

## Lab 8 GIF

![Lab 8](lab8.gif)

## Features:
- **7-Segment Display Control**: Displays numbers 0-9 on a 7-segment display.
- **External Interrupts**: Uses external interrupts on PA9 and PB4 to increment and decrement the counter.
- **GPIO Configuration**: Configures GPIO pins for the 7-segment display and input buttons.
- **Simple Delay Mechanism**: Implements a basic delay function to control display updates.

## How it works:
- The program continuously updates the 7-segment display with the current counter value.
- When an interrupt occurs on PA9, the counter increments.
- When an interrupt occurs on PB4, the counter decrements.
- The program uses external interrupts and GPIO to interact with the system and modify the counter.
