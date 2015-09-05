#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);        // creating the object for performing functions
                                              // initialize the library with the numbers of the interface pins
int set = A0;
int out = A1;
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  lcd.begin(16, 2);
                                              //To setup LCD's number of rows and columns
}
void loop() 
{
  int val=0,temp,i=0,x=0,m=0,s=0,h=0,z=0,y=0;
  unsigned long previous=0, current=0, next=0,time=0,previoustime=0;
  float distance=0,diff=0,velocity;
  while(1){
         val = analogRead(out);
      current= millis();
       temp=i;
       if(val>250&&(val-x)>250){
         i++;;
         next=millis();}                     //i increments during the shift from black to white
       if(val<=250&&(x-val)>250){
         previous=millis();
         }                                  //i increments during the shift from white to black
    lcd.setCursor(0,1);
     distance=(7.6666667*i)/100.0;
    lcd.print(distance);
   lcd.setCursor(7,1);
    lcd.print("m");
    diff=abs(next-previous);
    if(i>temp&&diff!=0)
       velocity=38.333/diff;             //since millis() is in milliseconds
     if(temp==i&&((current-next)>2000)||(current-previous)>2000){
       velocity=0;}
    lcd.setCursor(0,0);
    lcd.print(velocity);
    lcd.setCursor(7,0);
    lcd.print("m/s");
     x=val;
                                                               // Start of time calculation and its display
   
   
    if((current-previoustime)>=1000)
    {s++;previoustime=millis();}
    if(s>=60){
     m++;
    s=0;}
    if(m>=60){
    h++;
    m=0;}
    if(h>=24)
    h=0;
    lcd.setCursor(8,1);
    if(h<10)lcd.print("0");
    lcd.print(h);
    lcd.print(":");
      if(m<10)lcd.print("0");
    lcd.print(m);
    lcd.print(":");
      if(s<10)lcd.print("0");
    lcd.print(s);
    while(analogRead(set)<250){
      if((millis()-current)>=4000)
{
      lcd.setCursor(12,1);
      lcd.cursor();
      while(analogRead(set)<250);                                          //Control waits till switch is off
       while(analogRead(set)>250)
        {while(analogRead(set)>250);
         time=millis();
         m++;
      if(m>=60)m=0;
      {lcd.setCursor(8,1);
    if(h<10)lcd.print("0");                                                //to display the current varied time
    lcd.print(h);
    lcd.print(":");
      if(m<10)lcd.print("0");
    lcd.print(m);
    lcd.print(":");
      if(s<10)lcd.print("0");
    lcd.print(s);}
      while(analogRead(set)<250); z=1;                                         //to wait until the push switch in turned off
        if((millis()-time)>=2000) 
      {if(millis()-time>=4000){goto exit;}
      else goto next;}
    } m--;
      {while(1){ next:;        
        lcd.setCursor(9,1);
      lcd.cursor();
      while(analogRead(set)<250);                                          //Control waits till switch is off
       while(analogRead(set)>250){
       { while(analogRead(set)>250);
           time=millis();
         h++;
      if(h>=24)h=0;
      {lcd.setCursor(8,1);
    if(h<10)lcd.print("0");                                                //to display the current varied time
    lcd.print(h);
    lcd.print(":");
      if(m<10)lcd.print("0");
    lcd.print(m);
    lcd.print(":");
      if(s<10)lcd.print("0");
    lcd.print(s);}
      while(analogRead(set)<250);
      if((millis()-time)>=4000){h--; goto exit;}
      }
      
    }}
      

}}exit:;
     }
     
   }

  }
