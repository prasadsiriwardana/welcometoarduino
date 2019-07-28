/*=============================================
Program : vu display
Author : Prasad Siriwardana
Time : 10:00 PM
Date : 7/28/2019
=============================================*/

#include <LiquidCrystal.h>

byte p3[8] = {
        B11111,
        B00000,
        B10000,
        B10000,
        B10000,
        B10000,
        B00000,
        B11111
};

byte p4[8] = {
        B11111,
        B00000,
        B11000,
        B11000,
        B11000,
        B11000,
        B00000,
        B11111
};

byte p5[8] = {
        B11111,
        B00000,
        B11100,
        B11100,
        B11100,
        B11100,
        B00000,
        B11111
};

byte p6[8] = {
        B11111,
        B00000,
        B11110,
        B11110,
        B11110,
        B11110,
        B00000,
        B11111
};

byte p7[8] = {
        B11111,
        B00000,
        B11111,
        B11111,
        B11111,
        B11111,
        B00000,
        B11111
};

byte L[8] = {
        B11111,
        B00000,
        B11111,
        B10000,
        B10000,
        B10000,
        B00000,
        B11111
};

byte R[8] = {
        B11111,
        B00000,
        B11111,
        B00101,
        B00101,
        B11010,
        B00000,
        B11111
};

byte K[8] = {
        B11100,
        B11110,
        B11111,
        B11111,
        B11111,
        B11111,
        B11110,
        B11100
};

byte LEEG[8] = {
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111
};

int leftChannel = 0;    
int rightChannel = 0;  

int left,left2,right,right2;                
const int numReadings = 3;    

int readings[numReadings];      
int index = 0;                  
int total= 0;                   
int maxi=0;
int index2 = 0;                 
int total2= 0;                     
int maxi2=0;
int inputPin = A2;              
int inputPin2 = A4;             
int volL=0;
int volR=0;
int carL=0;
int carR=0;
int vul;
int vul2;
int laad;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   

void setup() {
  
   Serial.begin(9600);
   lcd.begin(16, 2); 
   for (int thisReading = 0; thisReading < numReadings; thisReading++)
   readings[thisReading] = 0;
  
   lcd.createChar(1, p3);
   lcd.createChar(2, p4);
   lcd.createChar(3, p5);
   lcd.createChar(4, p6);
   lcd.createChar(5, p7);
   lcd.createChar(6, L);
   lcd.createChar(7, R);
   lcd.createChar(8, K);
   lcd.createChar(9, LEEG);
  
  
   
    for(vul=0;vul<80;vul++)
    {
      for(laad=0;laad<vul/5;laad++)
      {
        lcd.setCursor(laad, 1); 
        lcd.write(5);
      }
     if(laad<1)
       {
       lcd.setCursor(0, 1); 
        lcd.write(5);
       }
    
     lcd.setCursor(laad+1, 1); 
     lcd.write((vul-vul/5*5)+1);
     for(laad=laad+2;laad<16;laad++)
      {
        lcd.setCursor(laad, 1); 
        lcd.write(9);
      }
    lcd.setCursor(0, 0); 
    lcd.print("loading.........");
    delay(50);
    }
    lcd.clear();
    delay(500);
  
  
  
  
  
}

void loop()

{
    lcd.setCursor(0, 0);       
    lcd.write(6);
    lcd.setCursor(0, 1);
    lcd.write(7);
    lcd.setCursor(15, 0);       
    lcd.write(8);
    lcd.setCursor(15, 1);
    lcd.write(8);
   
    total=analogRead(inputPin);
    if(total > maxi)
    {
      maxi=total;
    }
   
    index++;
   
    if (index >= numReadings)               
    {             
     index = 0;                         
     left=maxi;
     maxi=0;
    }
   
   
    total2=analogRead(inputPin2);
    if(total2 > maxi2)
    {
      maxi2=total2;
    }
   
    index2++;
   
    if (index2 >= numReadings)               
    {             
     index2 = 0;                         
     right=maxi2;
     maxi2=0;
    }
   
   
   
    volR=right/3;
   
    
     if(volR>14)
    {
      volR=14;
    }
    for(vul = 0 ; vul < volR ; vul++)
    {
      lcd.setCursor(vul+1, 1);
      lcd.write(5);
    }
   
    for(vul = volR+1 ; vul < 15 ; vul++)
    {
      lcd.setCursor(vul, 1);
      lcd.write(9);
    }
   
  
    volL=left/3;   
   
    if(volL>14)
    {
      volL=14;
    }
    for(vul2 = 0 ; vul2 < volL ; vul2++)
    {
      lcd.setCursor(vul2+1, 0);
      lcd.write(5);
    }
   
    for(vul2 = volL+1 ; vul2 < 15 ; vul2++)
    {
      lcd.setCursor(vul2, 0);
      lcd.write(9);
    }
    Serial.println(left);
}

