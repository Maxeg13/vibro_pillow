  const int outPin1 = 3;
  const int outPin2 = 6;
  uint8_t getVal = 0;        // value read from the pot
  int outputValue = 0;        // value output to the PWM (analog out)
  
  
  void setup() {
    // initialize serial communications at 9600 bps:
    Serial.begin(115200);
    
    pinMode(outPin1, OUTPUT);
    pinMode(outPin2, OUTPUT);
  }
  
  
  
  void loop() {
//  analogWrite(outPin,255);
    if (Serial.available())
    {
      getVal = Serial.read();
      
//      analogWrite(outPin,getVal);
      switch (getVal)
      {
        case 0:
        analogWrite(outPin1,0);
        break;
        case 254:
        analogWrite(outPin1,255);
        break;
        case 1:
        analogWrite(outPin2,0);
        break;
        case 255:
        analogWrite(outPin2,255);
        break;

      }
    }
  }
