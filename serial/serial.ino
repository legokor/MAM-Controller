#include <math.h>

//PA0 - PA7
int inputs[]={0,1,2,3,4,5,6,7};

int a;

int old_output[9]; 
int old_poti = -11;
int output[9]={};



void setup() {
  for(int i=0;i<8;++i){
    pinMode(inputs[i],INPUT_PULLUP);
    digitalWrite(inputs[i],HIGH);
  }
  Serial.begin(115200);
}

void loop() {
  //digital inputs
  for(int i=0;i<6;++i){
    output[i]=digitalRead(inputs[i]);
  }
  
  //analog input (potmeter)
  a=100*analogRead(inputs[6])/4096;
  
  //ez itt csunya, ne nezd...
  output[6]=a/100;
  output[6+1]=(a/10)%10;
  output[6+2]=a%10;
  
  bool changed = false;
  for(int i =0;i<6;i++){
    if(old_output[i] != output[i]){
      changed = true;
    }
     old_output[i] = output[i];
  }

  if (abs(old_poti - a) >= 10) {
    changed = true;
    old_poti = a;
  }

  if(changed){
    for(int i=0;i<9;++i){
      Serial.print(output[i]);
    }
  }

  delay(100);
}
