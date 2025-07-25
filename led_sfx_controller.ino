// purchase https://www.amazon.com/gp/product/B07DKD79Y9/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1
// product http://www.hiletgo.com/ProductDetail/2157143.html
// setup https://robotzero.one/heltec-wifi-kit-32/
// neopixel https://learn.adafruit.com/neopixel-painter/test-neopixel-strip

#include <Adafruit_NeoPixel.h>
#define PIXELS_PER_METER 60
#define STRIP_METERS 4
#define NUM_PIXELS STRIP_METERS*PIXELS_PER_METER-125
#define PIN_STRIP 21 //D2
#define PIN_LED LED_BUILTIN
#define PIN_BUTTON 36
#define PIN_PWM 13
#define PWM_SIG_VARIATION 20  //how much signal bounces around
#define TIMER_DELAY 100   //milliseconds

Adafruit_NeoPixel strip=Adafruit_NeoPixel(NUM_PIXELS,PIN_STRIP,NEO_GRB+NEO_KHZ800);
int soundPins[] = {4,16,17,5,18,23,19,22,21};
int numSoundPins = sizeof(soundPins)/sizeof(soundPins[0]);

//signal bounces by about 10-20usec

//PWM signals in usec
int pwmRanges[] = {
  0   ,600,  //mode 0 off
  601 ,700,  //mode 1 red 
  701 ,800,  //mode 2 blue
  801 ,900, //mode 3 green
  901,2500  //mode 4 r,g,b
};
int numPwmRanges = sizeof(pwmRanges)/sizeof(pwmRanges[0]);
unsigned long lastMode=0;
unsigned long duration;         //read from servo position
unsigned long timer=0;          //output timer
int mode = 0;                   //light mode depending on pwm position

void setup() {
  Serial.begin(115200);
  strip.begin();
  pinMode(PIN_LED,OUTPUT);
  pinMode(PIN_PWM,INPUT);
  digitalWrite(PIN_LED,LOW);
  // for(int i=0; i<numSoundPins; i++) {
  //   pinMode(soundPins[i],OUTPUT);
  //   digitalWrite(soundPins[i],HIGH);
  // }
  //pinMode(PIN_BUTTON,INPUT);
  Serial.printf("Starting with %d leds\n",NUM_PIXELS);
}

// void loop() {
//   Serial.println("Hello");
//   digitalWrite(PIN_LED,digitalRead(PIN_BUTTON));
//   delay(500);
// }

void playSound(int index) {
  digitalWrite(PIN_LED,HIGH);
  digitalWrite(soundPins[index],LOW);
  delay(50);
  digitalWrite(PIN_LED,LOW);
  digitalWrite(soundPins[index],HIGH);
}

void loop() {
  long now = millis();
  if(0 == mode) {
    //do nothing, leds off
  } else if(1 == mode) {
    chase(strip.Color(255, 0, 0)); // Red
  } else if(2 == mode) {
    chase(strip.Color(0, 0, 255)); // Green
  } else if(3 == mode) {
    chase(strip.Color(0, 255, 0)); // Blue
  } else if(4 == mode) {
    chase(strip.Color(255, 0, 0)); // Red
    chase(strip.Color(0, 0, 255)); // Green
    chase(strip.Color(0, 255, 0)); // Blue
  }
  duration = pulseIn(PIN_PWM,HIGH);
  //if(now>timer) 
  // {
  //   timer=now+TIMER_DELAY;
  //   Serial.print("duration:");
  //   Serial.print(duration);
  //   Serial.print(",");
  //   Serial.print("mode:");
  //   Serial.print(mode);
  //   Serial.println();
  // }//2479 2480

  handleMode(duration);
}

void handleMode(long duration) {
  for(int i=0; i<numPwmRanges; i+=2) {
    if(duration>=pwmRanges[i] && duration<=pwmRanges[i+1]) {
      mode = i/2;
      return;
    }
  }
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}
