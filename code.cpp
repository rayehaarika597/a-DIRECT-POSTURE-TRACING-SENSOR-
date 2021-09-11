#include<LiquidCrystal.h>


//viberation motor
int back_1react= 2;
int back_2react= 3;
int back_3react= 4;

//Buzzers
int buzzer_back1=5;
int buzzer_back2=6;
int buzzer_back3=7;

//sensors
int back_1=A0;
int back_2=A1;
int back_3=A2;

int pressure_1=0;
int pressure_2=0;
int pressure_3=0;

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int count=1,flag=1;

void setup(void)
{
  //vibration motor
  pinMode(back_1react,OUTPUT);
  pinMode(back_2react,OUTPUT);
  pinMode(back_3react,OUTPUT);
  
  //sensor
  pinMode(back_1,INPUT);
  pinMode(back_2,INPUT);
  pinMode(back_3,INPUT);
  
  //Buzzer
  pinMode(buzzer_back1,OUTPUT);
  pinMode(buzzer_back2,OUTPUT);
  pinMode(buzzer_back3,OUTPUT);
  
  //crystal display
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  
  Serial.begin(9600);
}

void loop(void)
{
  pressure_1 = analogRead(back_1);
  pressure_2 = analogRead(back_2);
  pressure_3 = analogRead(back_3);
  Serial.println(pressure_1);
  Serial.println(pressure_2);
  Serial.println(pressure_3);
  
  if(pressure_1==0)
  {
    tone(buzzer_back1,200,100);
  }
  else if(pressure_1 <= 100)
  {
    digitalWrite(back_1react, HIGH);
  }
  else
  {
    digitalWrite(back_1react, LOW);
  }
  
  if(pressure_2==0)
  {
    tone(buzzer_back2,200,100);
  }
  else if(pressure_2 <= 100)
  {
    digitalWrite(back_2react, HIGH);
  }
  else
  {
    digitalWrite(back_2react, LOW);
  }
  
  if(pressure_3==0)
  {
     tone(buzzer_back3,200,100);
  }
  else if(pressure_3 <= 100)
  {
    digitalWrite(back_3react, HIGH);
  }
  else
  {
    digitalWrite(back_3react, LOW);
  }
 
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  
  
  if(pressure_1 >= 100 && pressure_2 >= 100 && pressure_3 >= 100)
  {
    lcd.print(count);
    delay(1000);
    count++;
  }
  }