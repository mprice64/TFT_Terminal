//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include <stdint.h>
#include <TouchScreen.h> 
#include <TFT.h>

#ifdef SEEEDUINO
  #define YP A2   // must be an analog pin, use "An" notation!
  #define XM A1   // must be an analog pin, use "An" notation!
  #define YM 14   // can be a digital pin, this is A0
  #define XP 17   // can be a digital pin, this is A3 
#endif

#ifdef MEGA
  #define YP A2   // must be an analog pin, use "An" notation!
  #define XM A1   // must be an analog pin, use "An" notation!
  #define YM 54   // can be a digital pin, this is A0
  #define XP 57   // can be a digital pin, this is A3 
#endif 

int y = 10;
char curLine[256];
char * curByte;

char * headline = ">>====---- TFT SERIAL MONITOR ----====<<";

void setup()
{

  Tft.init();  //init TFT library

  // Serial.begin(9600);
  Serial1.begin(9600);

  Tft.setDisplayDirect(DOWN2UP);

  curByte = curLine; 
  
  Tft.drawString(headline, 0, 320, 1, RED);
}

void loop()
{
  if ( Serial1.available()) {
    int inByte = Serial1.read();
    // Serial.write( inByte );
    // Serial.print( inByte, DEC );
    
    *curByte++ = inByte;
    
    if ( inByte == '\n' ) {
      *curByte = 0;

      Tft.drawString( curLine, y, 320, 1, WHITE );
      y += 10;
      curByte = curLine;
      Serial.print( y, DEC );
      if ( y >= 240 ) {
        Tft.clear();
        y = 10;
        Tft.drawString(headline, 0, 320, 1, RED);

      }        
    }
  }

}
