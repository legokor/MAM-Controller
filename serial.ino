int inputs[]={0,1,2,3,4,5,6,7};

int old_output[8]; 
int output[8]={};

void setup() {
  
  //PA0 - PA7

  for(int i=0;i<8;++i){
    pinMode(inputs[i],INPUT_PULLUP);
    digitalWrite(inputs[i],HIGH);
  }
  
  Serial.begin(115200);
}


void loop() {
  
  for(int i=0;i<8;++i){
    output[i]=digitalRead(inputs[i]);
  }
 

  bool changed = false;
  for(int i =0;i<8;i++){
    if(old_output[i] != output[i]){
      changed = true;
    }
     old_output[i] = output[i];
  }

  if(changed){
    for(int i=0;i<8;++i){
      Serial.print(output[i]);
    }
  }

  delay(10);
}
