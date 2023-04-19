#include <Arduino.h>

#define START '#'
#define STOPP '*'

byte Daten[4];
bool lesend, frameOK;
int pos = 0;

void setup()
{
  Serial.begin(115200);
  lesend = false;
  frameOK = false;
  pos = 0;
}

void loop()
{

  if (Serial.available() > 0)
  {
    byte info = Serial.read();
    if (info == START && !lesend)
    {
      //*** Neues Frame beginnt
      pos = 0;
      Daten[pos] = info;
      lesend = true;
    }
    else
    {
      if (lesend)
      {
        //*** nächstes Byte abspeichern
        Daten[++pos] = info;
        //** Frame fertig?
        if (pos == 3)
        {
          lesend = false;
          if (info == STOPP)    //*** Frame ist in Ordnung
            frameOK = true;
        }
      }
    }
  }
  //** Falls Frame fertig gelsen -> Auswertung der Information im Frame
  if (frameOK)
  {
    //** Auswerten
    //** Mach was.....
    frameOK=false;
  }
}