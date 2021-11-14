#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 15; //馬達旋轉速度


//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  
Stepper myStepper2(stepsPerRevolution, 26, 33, 25, 32);  

void setup() {  
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速

  pinMode(23, INPUT); //設定腳位為輸入用

  ledcSetup(0, 5000, 8);   //頻率5000，頻道0，解析度8;
  //ledcAttachPin(14, 0);  //將上述頻道0附加到ledPin腳位14上
}

void loop() {
  int input = analogRead(23);
  int input_map = map(input, 0, 900, 0, 255);
  if(input_map<=0)input_map=0;
  Serial.println(input_map);
  //ledcWrite(0, input_map);
  
  //旋轉
  if(input_map >= 100){
      myStepper.step(stepsPerRevolution);
      myStepper2.step(-stepsPerRevolution);
  }

}
