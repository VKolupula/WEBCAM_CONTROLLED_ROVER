# WEBCAM_CONTROLLED_ROVER
 Webcam controlled rover to follow paths, move objects with a forklift, and avoid obstacles.
 
## Project Overview
The Webcam Controlled Rover project consists of a programmable robot that can communicate with MATLAB over Wi-Fi to perform operations using an image processing algorithm. The Rover is built using an Arduino Nano 33 IoT, the Arduino Nano Motor Carrier, two DC motors with encoders and a micro-servo motor. On top of the Rover, there is a color-coded sticker that will serve as a marker to assist the image processing algorithm that uses a webcam to detect the location and orientation of the robot.

## Important parameters associated with differential drive robots

![1616507917-aek-ch5-sc5-2-basic-kinematics-diagram](https://user-images.githubusercontent.com/120835150/221378331-ce6e9b87-0845-4129-a2c4-054cdc7b3953.jpg)

radius of rotation (R), rate of rotation (w), instantaneous center of curvature (ICC), wheel velocities (v1,v2), distance between the wheels (L) and the forward velocity (V). 
For more info on Differential Drive Robots: https://content.arduino.cc/assets/icckinematics.pdf
