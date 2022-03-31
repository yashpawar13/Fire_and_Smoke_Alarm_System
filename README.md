# Fire and Smoke Alarm System
The main objective of this project is detecting the fire, gas leakages and ensuring security.

## About the Project -
* Fire Alarm System is designed to alert us to an emergency so
that we can take action to protect ourselves from fire or gas
leakages
* Nowadays we found these Fire alarms and smoke detectors in
Offices, Factories, and public buildings.
* Whatever the method of detection is, if the alarm is triggered,
sounders will operate to warn people in the building that there
may be a fire and to evacuate.

## Features and Objectives -
The main objective of this project is detecting fire, gas leakages
and ensuring security.
1. Users can switch on or off any application using Bluetooth using
their phones.
2. Can detect LPG, Smoke, Alcohol, Propane, Hydrogen, Methane,
and Carbon Monoxide and makes emergency sounds that can
prevent massive fire accidents.
3. System interface is so much interactive that it can help to
control this fire system by elder people also.

## Softwares Used -
#### 1. Arduino IDE -
* The Arduino Integrated Development Environment (IDE) is a
cross-platform application (for Windows, macOS, Linux) that is written in
functions from C and C++ It is used to write and upload programs to
Arduino compatible boards, but also, with the help of third-party cores,
other vendor development boards
* What about the interface? -
Arduino IDE is easy-to-use coding software, making it simpler for
beginners to get started with programming. In simple terms, it’s a text
processor with coding-specific functions. An important function is
auto-formatting, which can be quite helpful for people who don’t
understand how to format code. With a single click of the mouse, you can
arrange the code in an understandable format. Additionally, the program
features multiple templates, which can be for complex sketches in the text
processor.
* What are the features? - 
Compared to other similar programs, Arduino IDE performs as an
on-premise application as well as a comprehensive online editor. The
coding software comes with advanced functionalities, including board
module options, direct sketching, online sharing, integrated libraries, etc.
Some of the important features include

1. Board Module Functionality
The programming environment comes with a useful board
management module, which lets users choose a specific board for their
creations. In case users need a different board, they can easily select
another one from the dropdown menu. Whenever modifications are made
in the program, PORT data gets automatically updated.
2. Sketching with the Text Editor
While using Arduino IDE, users can create sketches right within the
text editor. The process is quite simple and straightforward. In addition to
this, the editor comes with extra features to promote an interactive user
experience.
3. Project Documentation
While using the programming software, you can easily get the
projects documented. With this feature, it becomes easier to track
progress. Moreover, hassle-free documentation allows you to utilize
sketches on multiple boards without any issues.
4. Online Sharing
Arduino IDE lets you share sketches with other programmers in
the community. In fact, each sketch comes with a unique online link.
Online sharing is, however, only available in the program’s Cloud version.
5. Integrated Libraries
The programming software supports numerous integrated
libraries, which have been exclusively built for the Arduino community.
With this feature, you don’t need third-party tools to finish complex
projects.
![](/Images/Arduino%20UNO.PNG)
![](/Images/Arduino%20UNO%20Code.PNG)

#### 2. MIT App Inventor (web application) -
MIT App Inventor is a web application integrated development
environment originally provided by Google, and now maintained by
the Massachusetts Institute of Technology (MIT). It allows
newcomers to computer programming to create application
software(apps) for two operating systems (OS): Android, and iOS
It uses a graphical user interface (GUI) very similar to the
programming languages Scratch (programming language) and the
StarLogo, which allows users to drag and drop visual objects to
create an application that can run on Android devices, while an
App-Inventor Companion (The program that allows the app to run
and debug on) that works on iOS running devices are still under
development. In creating App Inventor, Google drew upon significant
prior research in educational computing, and work done within
Google on online development environments.
App Inventor and the other projects are based on and informed
by constructionist learning theories, which emphasize that
programming can be a vehicle for engaging powerful ideas through
active learning.
![](/Images/MIT%20App%20Inventor.PNG)
## Hardware Used -
![](/Images/Hardware.PNG)
### Design and Implementation
#### Tinkercad Design
![](/Images/Tinkercad.PNG)
#### Hardware Design
![](/Images/Hardware%20Design.PNG)
## App Interface -
![](/Images/App%20Interface.PNG)
## App Logic -
![](/Images/Logic.PNG)

## Code Explanation -
```
// Author : Yash Pawar
// Project Name : Fire and Smoke Alarm System
// Code Starts from here -->

// Define the Input and Output pins for the Arduino Uno Board , Gas Sensor ,IR Receiver , HC-05
Bluetooth Module , Buzzer and LED's
#define flamePin A0
#define gasPin A1
#define buzzer1 10
#define buzzer2 9
#define greenLed 2
#define redLed 3
int flameVal;
int gasVal;
int btSwitch=49;
unsigned long curTime;

// Define the Output (Devices)
void setup() {
Serial.begin(9600);
pinMode(buzzer1, OUTPUT);
pinMode(buzzer1, OUTPUT);
pinMode(buzzer2, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(redLed, OUTPUT);
curTime=millis();

void loop() {
if(Serial.available() > 0){ // Checks whether data is comming from the serial port
btSwitch = Serial.read(); // Reads the data from the serial port
}
if(btSwitch=='1'){digitalWrite(greenLed,HIGH);digitalWrite(redLed,LOW);}
//If the bluetooth button is On then Green LED will be High and Red LED will be Low
else if(btSwitch=='0'){digitalWrite(redLed,HIGH);digitalWrite(greenLed,LOW);}
//And If the bluetooth button is Off then Green LED will be Low and Red LED will be High
flameVal=analogRead(flamePin); // Read Input from the Analog pin of the Arduino Uno Board
gasVal=analogRead(gasPin); // Read Input from the Analog pin of the Arduino Uno Board

if (flameVal<1015 && gasVal>380 && btSwitch=='1'){
//If the threshold value of the flameVal is less than 1015 and gasValis greater than 380 then
buzzerCall() function is called only if the btSwitch=='1' is on
buzzerCall();
}
else if(gasVal>400 && btSwitch=='1'){
//If the threshold value of the gasValis greater than 400 then buzzerCall() function is called only ifthe btSwitch=='1' is on
buzzerCall();
}
}

// buzzerCall() function Starts from here -->
void buzzerCall(){
digitalWrite(greenLed,LOW);
digitalWrite(redLed,HIGH);
tone(buzzer1, 6000);
delay(500);
noTone(buzzer1);
tone(buzzer2, 1000);
digitalWrite(redLed,LOW);
delay(500);
noTone(buzzer2);
}
```
## Simulation -
* Simulation Link - https://bit.ly/32PxKuF
* Code Link - https://bit.ly/3qZf8jQ
* App Link - https://bit.ly/3G0PzFc

## Steps to Connect HC-05 Module with App -
1. Turn on the Bluetooth of the mobile.
2. Open Fire and Smoke Alarm System App.
3. Click on Bluetooth, it will show the list of the Bluetooth devices
available near the devices.
4. Select the HC-05 Bluetooth Module and connect it.
5. Once it gets connected to the device it will show “Connected” in
green color and if not then it will show “Not Connected” in red
color and it will again show the devices available.
6. By clicking on Turn On and Turn Off we can control the On and
Off the Circuit and Buzzer.

## Existing Features -
* Users can switch on or off any application using Bluetooth using
their phones.
* System interface is so interactive that it can help to control this
fire system by elder people also.
* It will glow Greenlight when the circuit is On and glow Red light
when the circuit Off
* It will turn on the Buzzer and red light (Blinking Mode) when fire
or smoke is detected in the area of sensors are connected
* Threshold value is chosen in such way that circuit will detect fire
and smoke easily in low flame and smoke also.

## Future Scope -
* We can make the app UI more user-friendly.
* Can interface Temperature sensor and LCD display to detect the
temperature of the fire area.
* Can add a small camera to get the picture of the area where the
fire is more and it also helps to detect whether anyone is in
danger.
* To protect this System from fire the cover of this system should
be made up of fire-resistant material.

## Conclusion -
* This Fire and Smoke Alarm System is cheaply made from
low-cost available components.
* This system is easily adjustable at any home or office space.
* This system not only gives easy access to devices to the user but
also keeps the home secure by continuously detecting any fire or
gas leakage in the home/ industries.
* So, our system saves energy and provides security to the user.
Hence, this system is scalable and flexible.

## Reference -
1. Arduino IDE -
2. MIT App Inventor (web application) -
3. Tinkercad -
4. Project Hub -

## Members -
1. Yash Pawar 
2. Prathamesh Pashte 
3. Rutunjay Karbhal 
4. Kedar Keripale 
