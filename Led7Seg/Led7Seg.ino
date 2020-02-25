#include "LedControl.h"
#include "Encoding.h"
LedControl lcLedControl = LedControl(12,10,11,2);  // Pins: DIN,CLK,CS, # of Display connected

const unsigned int uiDelayTime = 750;  // Delay between Frames
// 7 6 5 4 3 2 1 0 
// . A B C D E F G
//
const int iButton = 4;

// Put values in arrays
byte invader1a[] =
{
   B00000001,  // First frame of invader #1
   B00000010,
   B00000100,
   B00001000,
   B00010000,
   B00100000,
   B01000000,
   B10000000
};

byte invader1b[] =
{
  B00011000, // Second frame of invader #1
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};

byte invader2a[] =
{
  B00100100, // First frame of invader #2
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
};

byte invader2b[] =
{
  B00100100, // Second frame of invader #2
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};

byte empty[] = 
{
 B00000000,
 B00000000,
 B00000000,
 B00000000,
 B00000000,
 B00000000,
 B00000000,
 B00000000 
};

byte heart[] = 
{
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
};

void setup()
{
  lcLedControl.shutdown(0,false);  // Wake up displays
  lcLedControl.setIntensity(0,5);  // Set intensity levels
  lcLedControl.clearDisplay(0);  // Clear Displays
  lcLedControl.shutdown(1,false);  // Wake up displays
  lcLedControl.setIntensity(1,5);  // Set intensity levels
  lcLedControl.clearDisplay(1);  // Clear Displays
  pinMode(iButton,INPUT_PULLUP);
}


//  Take values in Arrays and Display them
void sinvader1a()
{
  for (int i = 0; i < 8; i++)  
  {
    lcLedControl.setRow(1,i,invader1a[i]);
  }
}

void sinvader1b()
{
  for (int i = 0; i < 8; i++)
  {
    lcLedControl.setRow(0,i,invader1b[i]);
  }
}

void sinvader2a()
{
  for (int i = 0; i < 8; i++)
  {
    lcLedControl.setRow(1,i,invader2a[i]);
  }
}

void sinvader2b()
{
  for (int i = 0; i < 8; i++)
  {
    lcLedControl.setRow(1,i,invader2b[i]);
  }
}

void showHeart()
{
  for (int i=0;i<8;i++)
  {
    lcLedControl.setRow(0,i,heart[i]);
  }
}


void loop()
{
// Put #1 frame on both Display
    lcLedControl.setIntensity(0,1);  // Set intensity levels
    showHeart();
    delay(uiDelayTime);
    //sinvader2a();
    //delay(delayTime);


// Put #2 frame on both Display
    lcLedControl.setIntensity(0,3);  // Set intensity levels
    showHeart();
    delay(uiDelayTime);
    //sinvader2b();
    //delay(delayTime);

    // Put #1 frame on both Display
    lcLedControl.setIntensity(1,3);  // Set intensity levels
    sinvader1a();

}
