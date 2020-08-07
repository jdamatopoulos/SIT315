/*
* Defining values/pins
*/
int onBoardLed = 13;               
int input = 2;              
int value = 0;					

/*
* Setup method
*/
void setup() 
{
  /*
  * Setting Input/Output pins, creating interrupt to trigger (detectMotion), initalising serial monitor.
  */
  pinMode(onBoardLed, OUTPUT);      
  pinMode(input, INPUT);     
 
  attachInterrupt(digitalPinToInterrupt(input), detectMotion, HIGH);
  
  Serial.begin(9600);
}

/*
* Loop method
*/
void loop() 
{
  /*
  * Example of how Loop does not always have to be used - interrupt utilised instead.
  */
}

void detectMotion() 
{
  /*
  * Reading input pin for its value.
  */
  value = digitalRead(input);
  /*
  * Checking if the input is 'LOW'.
  */
  if (value == LOW) 
  {
    /*
    * Setting onBoardLed to 'LOW', and writing message.
    */
   	digitalWrite(onBoardLed, LOW);
    Serial.println("NO MOTION DETECTED!");
  }
  else 
  {							
    /*
    * Setting onBoardLed to 'HIGH', and writing message.
    */
    digitalWrite(onBoardLed, HIGH);
    Serial.println("MOTION DETECTED!");
  }
} 
