/*
 * Halloween 2016 Music, SFX and Lights for Skull Head
 * Robin and Finley Gambin
 */

#include <arduino.h> //not sure if I need this one or if it is there by default

int eyes = 3; //dio for eyes
int headlight1 = 2; //dio for headlight
int music = 4; //dio for music
int sfx1 = 5; //dio sound fx 1
int sfx2 = 6; //dio sound fx 2
int detect1 = 7; //dio for detect sensor 1
int detect2 = 8; //dio for detect sensor 2
int head_move = 9; //dio for head
int headdir1 = 12; //direction control
int headdir2 = 13; //direction control
int time1;
int time2;
int time3;
int a=0;

void setup() 
{
  // Setup ports
  Serial.begin(9600); //remove this later?
  pinMode(eyes,OUTPUT);
  pinMode(headlight1,OUTPUT);
  pinMode(music,OUTPUT);
  pinMode(sfx1,OUTPUT);
  pinMode(sfx2,OUTPUT);
  pinMode(detect1,INPUT);
  pinMode(detect2,INPUT);
  pinMode(head_move,OUTPUT);
  pinMode(headdir1,OUTPUT);
  pinMode(headdir2,OUTPUT);
  }

void loop() 
{
 if(digitalRead(detect1) == HIGH)
  {
  	digitalWrite(music,HIGH); // turn off music
    head_left();  //call head movemnent and SFX fucntion
  }
  else if (digitalRead(detect2)==HIGH)
  {
    digitalWrite(music,HIGH);
		head_left();
  }
  else 
  {
    digitalWrite(music,LOW); //Play music if no motion detected
    digitalWrite(sfx1,HIGH);
    digitalWrite(sfx2,HIGH);
    analogWrite(eyes,0); //just to make sure they are off
    digitalWrite(headlight1,LOW); //just to make sure they are off
    analogWrite(head_move, 0);// motor speed
  
    
  }
}


void head_left()
{
int i=0;
//move head left and flash lights code here. 4 seconds total
  time1=millis();
  digitalWrite(sfx1,LOW);
  digitalWrite(headlight1,HIGH);
  analogWrite(head_move, 255);// motor speed 
  digitalWrite(headdir1,HIGH);// rotate forward
  digitalWrite(headdir2,LOW); 
  delay(200);
  analogWrite(head_move,0);
  for (int a=0; a<=255;a++)               //loop from 0 to 255
  {
    analogWrite(eyes, a);
        delay(8);                             //wait for 8 milliseconds    
               
  }
    for (int a=255; a>=0;a--)             //loop from 255 down to 0
  {
    analogWrite(eyes, a);               // set the brightness of pin 9:
       delay(8);                             //wait for 8 milliseconds   
  }
 
 	analogWrite(eyes,0); //reset eyes
  digitalWrite(headlight1,LOW); //reset headlight
  digitalWrite(sfx1,HIGH);
  analogWrite(head_move, 255);// motor speed  
  digitalWrite(headdir1,LOW);// rotate forward
  digitalWrite(headdir2,HIGH);
  delay(200); //delay to reset head
  time2=millis();
  time3=(time2-time1);
  Serial.println(time3);
}

