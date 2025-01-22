# Milliammeter with High Precision using a Reference Instrument and Linear Regression

This project was developed using the PIC12F685, but it can be implemented with any other microcontroller by applying the same concepts and techniques.

## Steps to Develop This Project

### 1. Implement the Non-inverting Amplifier:

- Implement the non-inverting amplifier with a gain of approximately 10 or 12 times the input voltage (for the measurement range used).

### 2. Use a Milliammeter as a Reference Instrument:

- Use a milliammeter as a reference instrument and take two measurements: current in the shunt resistor with the milliammeter, and read ADC value in the microcontroller.

### 3. Get the Equation of the Line:

- Get the equation of the line using the method of least squares or with the Excel tool.

### 4. Program the Microcontroller:

- Put the obtained equation in the microcontroller and program it, adding a display to visualize the measurement in mA.

### 5. Verify the Measurements (Optional):

- Compare the measurements between the reference instrument and the value on the display in your circuit to verify the measurements.


## Final Notes

- The project was developed to read milliamps up to 1 amp. If you desire another range of measurement, adjust the amplifier and the shunt resistor.

- Consider the power dissipation for the shunt resistor and use a resistor with adequate power dissipation capacity.

- The project uses electronic components that are easily accessible in the market.

- Remember that my data collection is unique to my circuit. You need to gather your own data collection and use it for programming the microcontroller.

- For best performance, you can use electronic components with higher precision and features.

- Consider that the current can vary in the shunt resistor if it starts to heat up.


[![Texto alternativo](https://img.youtube.com/vi/xf6562S__Sg/maxresdefault.jpg)](https://www.youtube.com/watch?v=xf6562S__Sg)

Watch the explanation and demonstration video on YouTube by clicking the image!
