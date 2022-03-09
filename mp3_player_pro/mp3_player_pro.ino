/*!
 *@file play.ino
 *@brief Music Playing Example Program 
 *@copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 *@licence     The MIT License (MIT)
 *@author [fengli](li.feng@dfrobot.com)
 *@version  V1.0
 *@date  2020-12-02
 *@get from https://www.dfrobot.com
 *@https://github.com/DFRobot/DFRobot_PLAY
*/


#include <DFRobot_DF1201S.h>
#include <SoftwareSerial.h>

int sensorPin = A0;    // select the input pin for the potentiometer
SoftwareSerial DF1201SSerial(D3, D4);  //RX  TX

DFRobot_DF1201S DF1201S;
void setup(void){
/*  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second*/
  DF1201SSerial.begin(115200);
  while(!DF1201S.begin(DF1201SSerial)){
    delay(1000);
  }
  DF1201S.setVol(/*VOL = */20);
  DF1201S.switchFunction(DF1201S.MUSIC);
  DF1201S.setPlayMode(DF1201S.ALLCYCLE);

  //Turn on the prompt tone (Power-down save) 
  DF1201S.setPrompt(false);
  //Enable amplifier chip 
  DF1201S.enableAMP();
  //Disable amplifier chip 
  //DF1201S.disableAMP();
  DF1201S.start();
}

void loop(){
  DF1201S.setVol(map(analogRead(sensorPin), 0 , 1023, 0, 30));
  delay(100);
}