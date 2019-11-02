#include <Arduino.h>
#include "button.h"


#define R_OUT 6
#define G_OUT 7 
#define B_OUT 8

#define PIN_BUTTON 4

unsigned long last_time;

Button start  = Button(PIN_BUTTON);


void setup()
{
    pinMode(R_OUT, OUTPUT);
    pinMode(G_OUT, OUTPUT);
    pinMode(B_OUT, OUTPUT);
}

void loop() 
{
    set_rgb_led(0, 255, 0);
    if (start.wasPressed())
    {   
        time_pressed = millis();
         while (1)
        {
            if (millis() - last_time < 30000)
            {
                set_rgb_led(255, 0, 0);
                if ((millis() - last_time) % 5 == 0 )
                {
                  set_rgb_led(255, 255, 255);
    
                }
            }else {
                set_rgb_led(0, 0, 255);
            }
        };
        return;
    }
} 

void set_rgb_led(int r, int g, int b)
{
      analogWrite(R_OUT, 255 - r);
      analogWrite(G_OUT, 255 - g);
      analogWrite(B_OUT, 255 - b);
}
