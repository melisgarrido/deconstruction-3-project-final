/*  Heartbeat
 *   Paul Badger 2009
 *   Demonstates how to use an array with millis to achieve irregular rhythms
 *   This function still uses one delay but it never leaves the LEDpin / LED in 
 *   the ON state.
 */


long heartBeatArray[] = {
    50, 100, 15, 1200};
int hbeatIndex = 1;   // this initialization is important or it starts on the "wrong foot"
long prevMillis;

int LEDpin1 = 6;
int LEDpin2 = 5;
int LEDpin3 = 9;

void setup()                    
{
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT);
}

void loop()                    
{
    heartBeat(1.0);   // try changing the parameter
}

void heartBeat(float tempo){
    if ((millis() - prevMillis) > (long)(heartBeatArray[hbeatIndex] * tempo)){
        hbeatIndex++;
        if (hbeatIndex > 3) hbeatIndex = 0;

        if ((hbeatIndex % 2) == 0){ 
            digitalWrite(LEDpin1, HIGH); 
            delay((int)heartBeatArray[hbeatIndex]) ;   
            digitalWrite(LEDpin1, LOW); 
            digitalWrite(LEDpin2, HIGH); 
            delay((int)heartBeatArray[hbeatIndex]) ;   
            digitalWrite(LEDpin2, LOW);
            digitalWrite(LEDpin3, HIGH); 
            delay((int)heartBeatArray[hbeatIndex]) ;   
            digitalWrite(LEDpin3, LOW);  
        }
        hbeatIndex++;
        // Serial.println(hbeatIndex);
        prevMillis = millis();

    }
}
