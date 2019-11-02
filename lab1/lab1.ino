#include <Arduino.h>
#include "button.h"


#define R_OUT 6
#define G_OUT 7 
#define B_OUT 8

#define PIN_BUZZER 4
#define PIN_BUTTON_OFF 5

unsigned long last_time;

Button redInc  = Button(PIN_BUZZER);
Button redDec = Button(PIN_BUTTON_OFF);


int RGBSet[] = { 0, 0, 0 };


void setup()
{
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
    set_color("green");
    if (redInc.wasPressed())
    {   
        time_pressed = millis();
        
        return;
    }
} 


void lighthouse()
{
    while (1)
    {
        if (millis() - last_time < 30000)
        {
            set_color("red");
            if ((millis() - last_time) % 5 == 0 )
            {
              set_color("white");

            }
        }else {
            set_color("blue");
        }
    };
}

void set_color(String color){
  for (int i = 0; i < 3; ++i){
    RGBSet[i] = 0;
  }

  if(color == "red"){
    RGBSet[0] = 251;
    
   } else if (color == "blue"){
    RGBSet[2] = 251;
   } else if (color == "green"){
    RGBSet[1] = 251;
   } else {
        for (int i = 0; i < 3; ++i){
            RGBSet[i] = 251;
        }
   }

}


void set_rgb_led()
{
      analogWrite(R_OUT, RGBSet[0]);
      analogWrite(G_OUT, RGBSet[1]);
      analogWrite(B_OUT, RGBSet[2]);
}
