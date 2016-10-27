// This #include statement was automatically added by the Particle IDE.
#include "neopixel/neopixel.h"

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D1
#define PIXEL_COUNT 16
#define SPEAKER_PIN D2
unsigned long elapsedTime = 0UL;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN);

#define FSR_PIN A0
int fsrReading;
char pressureData[10];

void setup () {
 pinMode(FSR_PIN, INPUT);
 pinMode(SPEAKER_PIN, OUTPUT);
 Serial.begin(9600);
 strip.begin();
 strip.show();
 strip.setBrightness(8);
 Particle.subscribe("fsrValue",myhandler,MY_DEVICES);
}

int val;
void myhandler(const char *event, const char *data){
    val = atoi(data);
    
}

void loop(){
    //scale fsr readings to a range of 0 to 1024
    fsrReading = analogRead(FSR_PIN)/4;
    unsigned long currentTime = millis();
    if(currentTime-elapsedTime > 2000UL){
    sprintf(pressureData,"%d",(int)fsrReading);
    String fsrValue = pressureData;
    Particle.publish("fsrValue",fsrValue,PRIVATE);
    }
    neoPressure(val,1000);
}

void neoPressure(int x, int y){
    if(x >= 0 && x < 192){
        //Serial.println("No");
        //clear all pixels
        for (int i = 1; i < 16; i++){
            strip.setPixelColor(i,0,0,0);
                }
                //light blinking red on neopixel
        for(int i =0; i<4; i++){
            strip.setPixelColor(i, 255,0,0);
            }
            strip.show();
            delay(y);
            for(int i = 0; i<4; i++){
            strip.setPixelColor(i,0,0,0);
            }
            strip.show();
            delay(y/2);
        
    }
    else if(x > 192 && x < 384){
        //Serial.println("Low");
        //light cyan on neopixel
        for(int i = 0; i < 8; i++){
            strip.setPixelColor(i, 224,255,255);
            }
        strip.show();
        delay(y);
    }
    else if(x > 384 && x < 576){
        //light blue on neopixel
        for(int i = 0; i < 12; i++){
            strip.setBrightness(32);
            strip.setPixelColor(i, 0,0,255);
        }
            strip.show();
           delay(y);
    }
    else if(x > 576){
        //light green on neopixel
        for(int i = 0; i < 16; i++){
            strip.setBrightness(32);
            strip.setPixelColor(i, 0,255,0);
        }
            strip.show();
           delay(y);
           playGOT();
           
    }
}

//piano references - Youtube GOT theme piano tutorial - https://www.youtube.com/watch?v=LULbxLdBT3M. Piano key frequencies - http://www.sengpielaudio.com/calculator-notenames.htm

//tone(pinNumber, frequency, duration)

void playGOT(){
    //starting note is G3
    tone(D2, 196, 425);
    delay(400);
    
    //**************follow the pattern C3, D#3, F3, G3 and back to C3 four times*******************
    //C3  
    tone(D2, 131, 425);
    delay(400);
 
    //DS3
    tone(D2, 156, 175);
    delay(200);
 
    //F3
    tone(D2, 175, 175);
    delay(200);
 
    //G3
    tone(D2, 196, 425);
    delay(400);
    
    //***************repeat second time*****************
    //C3  
    tone(D2, 131, 425);
    delay(400);
 
    //DS3
    tone(D2, 156, 175);
    delay(200);
 
    //F3
    tone(D2, 175, 175);
    delay(200);
 
    //G3
    tone(D2, 196, 425);
    delay(400);
    
    //**************repeat third time****************
    //C3  
    tone(D2, 131, 425);
    delay(400);
 
    //DS3
    tone(D2, 156, 175);
    delay(200);
 
    //F3
    tone(D2, 175, 175);
    delay(200);
 
    //G3
    tone(D2, 196, 425);
    delay(400);
    
    //*************repeat fourth time************
    //C3  
    tone(D2, 131, 425);
    delay(400);
 
    //DS3
    tone(D2, 156, 175);
    delay(200);
 
    //F3
    tone(D2, 175, 175);
    delay(200);
 
    //G3
    tone(D2, 196, 425);
    delay(400);

//***************follow pattern C3, E3, F3, G3 thrice******************
    //C3  
    tone(D2, 131, 425);
    delay(400);
 
    //E3
    tone(D2, 165, 175);
    delay(200);
 
    //F3
    tone(D2, 175, 175);
    delay(200);
 
    //G3
    tone(D2, 196, 425);
    delay(400);
    
    //***********second time***************
    //C3  
    tone(D2, 131, 425);
    delay(400);
 
    //E3
    tone(D2, 165, 175);
    delay(200);
 
    //F3
    tone(D2, 175, 175);
    delay(200);
 
    //G3
    tone(D2, 196, 425);
    delay(400);
    
    //**************third time*************
    
    //C3  
    tone(D2, 131, 425);
    delay(400);
 
    //E3
    tone(D2, 165, 175);
    delay(200);
 
    //F3
    tone(D2, 175, 175);
    delay(200);
 
    //G3
    tone(D2, 196, 425);
    delay(400);
    
    
}



