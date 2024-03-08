# Color_following_robot
Color following robot using Arduino
Color following robot

#Components: 1.BO motor & wheels 2.Batteries 3.Chassis 4.Motor Driver (l298N 2A) 5.Arduino UNO 6.Color sensor TCS3200

#Sensor specifications: Pin configuration:

S0: digital pin 4
S1: digital pin 5
VCC: 5V
S3: digital pin 6
S4: digital pin 7
OUT: digital pin 8


#Filter selection To select the color read by the photodiode, you use the control pins S2 and S3. As the photodiodes are connected in parallel, setting the S2 and S3 LOW and HIGH in different combinations allows you to select different photodidodes.

Photodiode type S2 S3 
Red - LOW LOW ;
Blue - LOW HIGH ;
No filter (clear) - HIGH LOW;
Green - HIGH HIGH

#Frequency scaling Pins S0 and S1 are used for scaling the output frequency. It can be scaled to the following preset values: 100%, 20% or 2%. Scaling the output frequency is useful to optimize the sensor readings for various frequency counters or microcontrollers.

Output frequency scaling S0 S1 
Power down - L L ;
2%  - L H ;
20% - H L ;
100% - H H (recommended);

#Callibration Callibrate the sensor by using callibration code... 
#1.After Arduino , color sensor connection upload the callibration code. 
#2.Note the minimum and maximum range values of all three colors RGB (red,green,blue).

#After motor arduino connection #color tracking 
#1.Use the callibration values into this and change the code according to the sensor range (min - max values) 
#2.Change the frequency scaling as per the convenient. 
#3.run the code.
