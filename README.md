# vehicle_console
Microcontroller : Atmega168

DISTANCE MEASURING USING MICROCONTROLLER (ODOMETRY)

ABSTRACT
The idea is to measure the distance travelled by a wheel by counting the number of black lines it passes during each rotation. Black lines in white background will be drawn parallel to the shaft along the circumference of the wheel. The distance between 2 black lines will be same.
Wheel is allowed to rotate freely and an IR-LED sensor is used to track the black line.
The microcontroller basically acts as a counter which counts the lines sensed by the sensor in each revolution of the wheel and it also interface the LCD for display. The input to counter is the output signal from the sensor. The microcontroller can be programmed to calculate the distance measured as
Distance=2*3.14*r*n*x
Where     r-  radius of the wheel
                 n-number of revolutions-counter output
	      x- resolution (proportional no. of black lines)
This idea can be extended to calculate the area of a surface by Simpon’s rule or Trapezoidal rule. To realize that, angle measurement should be taken between 2 consecutive readings.
