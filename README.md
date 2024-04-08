The Distance Measuring System is a mini-project of Standard Embedded Systems Diploma at Edges for Training Academy, under the expert guidance of Mohamed Tarek.

The project involves Developing a system that measure the distance and display it on LCD. It utilizes various drivers including GPIO, ICU, Ultrasonic Sensor and LCD for functionality.

> HMI_ECU MCAL: GPIO and ICU.

> HMI_ECU HAL: LCD and ULTRASONIC.

The HC-SR04 ultrasonic sensor is a popular choice for distance measurement in various projects due to its affordability, simplicity, and reliability. It utilizes ultrasonic waves to determine the distance between the sensor and an object by measuring the time it takes for the sound waves to bounce back after being emitted. This sensor typically consists of two main components: a transmitter and a receiver.

To use the HC-SR04 sensor with an AVR ATMega32 microcontroller, you need to interface it properly. The HC-SR04 requires a trigger signal to start the measurement and then produces an echo signal proportional to the distance detected. The AVR ATMega32 microcontroller can generate the trigger signal and measure the time between sending the trigger and receiving the echo.

Here is some screenshots from the system:
![image](https://github.com/dev-Youssef-Ahmed/Distance-Measuring-System/assets/153888401/50961ab3-aec3-4894-93d8-dbe46c633e6c)

![image](https://github.com/dev-Youssef-Ahmed/Distance-Measuring-System/assets/153888401/7abf6794-3f2f-4e6e-8e3c-94da4900dbb3)

Note: The proteus file contain two sheets, the user interface sheet, and the background sheet.
