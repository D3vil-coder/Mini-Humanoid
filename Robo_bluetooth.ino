char data ;
#include<Servo.h>
Servo r_hip , l_hip ,r_foot ,l_foot ,l_arm,r_arm;
int rh = 90,lh=90,lf=75,rf=90;
int x = 0;
void setup() {
  
Serial.begin(9600); //Bluetooth
pinMode(13,OUTPUT);
r_hip.attach(4);
l_hip.attach(3);
r_foot.attach(6);
l_foot.attach(5);
convert();
homeposition();
}

void loop() {
data = Serial.read();
if (data == '1')  //Forward
{
  leftturn();
  rightturn();
}
else if (data == '0')
{
  homeposition(); //Stop
}
else if (data == '2')
{
  leftback();
  rightback(); //Back
}
else if (data == '3')
{
  leftturn(); //Left turn
}
else if (data == '4')
{
  rightturn(); //Right turn
}
else if (data == '5')  //Dance
{
  for(int a=0;a<=20;a++)
{
  lf++;
  delay(50);
  convert();    
}


 for(int a=20;a>=0;a--)
{
  lf--;
  delay(50);
  convert();
}
for(int a=0;a<=20;a++)
{
  rf--;
  delay(50);
  convert();
}


 for(int a=20;a>=0;a--)
{
  rf++;
  delay(50);
  convert();
}
}
else if (data == '6')
{
  for(int a=0;a<=20;a++)
{
  lf++;
  rf--;
  delay(50);
  convert();
}
  for(int a=0;a<=20;a++)
{
  lf--;
  rf++;
  delay(50);
  convert();
}
}

}

void homeposition(){
  r_hip.write(90);
  l_hip.write(90);
  r_foot.write(90);
  l_foot.write(75);
}

void convert() {
  r_hip.write(rh);
  l_hip.write(lh);
  r_foot.write(rf);
  l_foot.write(lf);
}

void rightturn() {
  for(int a=0;a<=20;a++)                 //step 1 to make left foot on toe
{
  lf--;
  delay(10);
  convert();
}


 for(int a=0;a<=20;a++)              //step2 ,to balance robot,adjust right foot to go to heel
{
  rf--;
  delay(10);
  convert();
}
for(int a=0;a<=20;a++)               //step 3 rotate both hips so that body turns 
{
  rh--;
  lh--;
  delay(10);
  convert();
}


for(int a=0;a<=20;a++)                 //step 4 right foot back on homeposition
{
  lf++;
  delay(10);
  convert();
}


 for(int a=0;a<=20;a++)              //step 5 ,left foot back to homeposition
{
  rf++;
  delay(10);
  convert();
}
for(int a=0;a<=20;a++)               //step 6 rotate both hips so that body returns to homeposition
{
  rh++;
  lh++;
  delay(10);
  convert();
}
}

void leftturn() {
  for(int a=0;a<=20;a++)                 //step 1 to make right foot on toe
{
  rf++;
  delay(10);
  convert();
}


 for(int a=0;a<=20;a++)              //step2 ,to balance robot,adjust left foot to go to heel
{
  lf++;
  delay(10);
  convert();
}
for(int a=0;a<=20;a++)               //step 3 rotate both hips so that body turns 
{
  rh++;
  lh++;
  delay(10);
  convert();
}


for(int a=0;a<=20;a++)                 //step 4 right foot back on homeposition
{
  rf--;
  delay(10);
  convert();
}


 for(int a=0;a<=20;a++)              //step 5 ,left foot back to homeposition
{
  lf--;
  delay(10);
  convert();
}
for(int a=0;a<=20;a++)               //step 6 rotate both hips so that body returns to homeposition
{
  rh--;
  lh--;
  delay(10);
  convert();
}
}
void rightback() {
  for(int a=0;a<=20;a++)                 //step 1 to make left foot on toe
{
  lf--;
  delay(10);
  convert();
}


 for(int a=0;a<=10;a++)              //step2 ,to balance robot,adjust right foot to go to heel
{
  rf--;
  delay(10);
  convert();
}
for(int a=0;a<=20;a++)               //step 3 rotate both hips so that body turns 
{
  rh++;
  lh++;
  delay(10);
  convert();
}


for(int a=0;a<=20;a++)                 //step 4 right foot back on homeposition
{
  lf++;
  delay(10);
  convert();
}


 for(int a=0;a<=10;a++)              //step 5 ,left foot back to homeposition
{
  rf++;
  delay(10);
  convert();
}
for(int a=0;a<=20;a++)               //step 6 rotate both hips so that body returns to homeposition
{
  rh--;
  lh--;
  delay(10);
  convert();
}
}

void leftback() {
  for(int a=0;a<=20;a++)                 //step 1 to make right foot on toe
{
  rf++;
  delay(10);
  convert();
}


 for(int a=0;a<=10;a++)              //step2 ,to balance robot,adjust left foot to go to heel
{
  lf++;
  delay(10);
  convert();
}
for(int a=0;a<=20;a++)               //step 3 rotate both hips so that body turns 
{
  rh--;
  lh--;
  delay(10);
  convert();
}


for(int a=0;a<=20;a++)                 //step 4 right foot back on homeposition
{
  rf--;
  delay(10);
  convert();
}


 for(int a=0;a<=10;a++)              //step 5 ,left foot back to homeposition
{
  lf--;
  delay(10);
  convert();
}
for(int a=0;a<=20;a++)               //step 6 rotate both hips so that body returns to homeposition
{
  rh++;
  lh++;
  delay(10);
  convert();
}
}
