#include <DFRobot_DF1201S.h>
#include <SoftwareSerial.h>

int sensorPin = A0;    // select the input pin for the potentiometer
SoftwareSerial DF1201SSerial(D1, D2);  //RX  TX

DFRobot_DF1201S DF1201S;
void setup(void){
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