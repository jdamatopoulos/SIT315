/*
* Defining all variables
*/
int led = 13;        
int input = 2;              
int motion = LOW;            
int value = 0;				

/*
* Setup method
*/
void setup()
{
  /*
  * Assigning pins, creating interrupt, attaching it to 'detectMotion'
  */
  pinMode(input, INPUT);
  pinMode(led, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(2), detectMotion, CHANGE);

  Serial.begin(9600);
}

/*
* Loop method
*/
void loop()
{
}
                    
/*
* Method created for the interrupt
*/
void detectMotion()
{
  	/*
    * Checking if motion is detected
    */
  	if (digitalRead(input) == HIGH)
  	{
	  /*
      * Prinint that motion is detected, setting LED to 'HIGH'.
      */
      Serial.println("MOTION DETECTED!");
      digitalWrite(led, HIGH);
    }
  	else 
    {
      /*
      * Printing that motion is not detected, setting LED to 'LOW'.
      */
      Serial.println("NO MOTION DETECTED!");
      digitalWrite(led, LOW);
    }
}
