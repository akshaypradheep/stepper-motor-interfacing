byte CCW[8] = {0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};
byte CW[8] = {0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09}; 
int up=7;
int down=6;
int inBit;
byte  change_angle=64;  //change the parameter to change the angle of the stepper
void Motor_CCW()    //the steper move 360/64 angle at CouterClockwise 
{
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
    {
      PORTB = CCW[j];
      delayMicroseconds(1150);
    }    
}
void Motor_CW()  //the steper move 360/64 angle at Clockwise
{
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
    { 
      PORTB = CW[j];
      delayMicroseconds(1150);
    }
}
void setup()
{ 
  pinMode(up,INPUT);
  pinMode(down,INPUT);
  Serial.begin(9600);
  DDRB=0xff;
  PORTB = 0xf0;  
 }
void loop()
{
// Motor_CCW();  
// Motor_CW(); 
if(digitalRead(down)==HIGH){
  Motor_CCW();
  Serial.println("Clock");
}
if(digitalRead(up)==HIGH){
  Motor_CW();
  Serial.println("AntiClock");
}
else{
  Serial.println("stop");
}
}
