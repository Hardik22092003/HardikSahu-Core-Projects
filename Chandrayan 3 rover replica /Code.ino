// Call motor driver library
#include <AFMotor.h>
// Declare motor pins
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
char bt='S';
//First time setup runs only one time
//Set serial communication speed, Intital motor speed and pin mode
// motor speed ranges from 0-255, where 255 is maximum
void setup()
{
  Serial.begin(9600);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
  
}

// This is the main program and runs forever
void loop() {
 
bt=Serial.read();
// Now we will execeute actions depending upon commands we recieve from our phone via bluetooth
// Below are the contidions which will execute certain commands depending upon the instruction recieved
// example if it is 'f' go forward or if it is 'b' go back
//if recieve 'f' OR 'F' from bluetooth call forward function to move forward
if(bt=='f'|| bt=='F')
{
 forward(); 
}
if(bt=='b'|| bt=='B')
{
 backward(); 
}
if(bt=='L'|| bt=='l')
{
 left(); 
}
if(bt=='R'|| bt=='r')
{
 right(); 
}

if(bt=='S')
{
 Stop(); 
}
if(bt=='j'||bt=='J')
{
 Stop(); 
}
if(bt=='W')
{
 lighton(); 
}
if(bt=='w')
{
 lightoff(); 
}
}
//optimized the code
// function for going forwardsc
void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
void right()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void lighton()
{
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
}
void lightoff()
{
digitalWrite(9, LOW);
digitalWrite(10, LOW);
}
