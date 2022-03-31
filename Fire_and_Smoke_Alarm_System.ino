          // Author : Yash Pawar 
          // Project Name : Fire and Smoke Alarm System 

          // Code Starts from here -->


          // Define the Input and Output pins for the Arduino Uno Board , Gas Sensor ,IR Receiver , HC-05 Bluetooth Module , Buzzer and LED's 
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
          }


          void loop() {
            if(Serial.available() > 0){       // Checks whether data is comming from the serial port
                btSwitch = Serial.read();     // Reads the data from the serial port
            }
            if(btSwitch=='1'){digitalWrite(greenLed,HIGH);digitalWrite(redLed,LOW);}        //If the bluetooth button is On then Green LED will be High and Red LED will be Low
            else if(btSwitch=='0'){digitalWrite(redLed,HIGH);digitalWrite(greenLed,LOW);}   //And If the bluetooth button is Off then Green LED will be Low and Red LED will be High
            
            flameVal=analogRead(flamePin);    // Read Input from the Analog pin of the Arduino Uno Board 
            gasVal=analogRead(gasPin);        // Read Input from the Analog pin of the Arduino Uno Board 
            
            if (flameVal<1015 && gasVal>380 && btSwitch=='1'){    //If the threshold value of the flameVal is less than 1015 and gasValis greater than 380 then buzzerCall() function is called only if the  btSwitch=='1' is on
              buzzerCall();
            }
            else if(gasVal>400 && btSwitch=='1'){                 //If the threshold value of the gasValis greater than 400 then buzzerCall() function is called only if the  btSwitch=='1' is on
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
