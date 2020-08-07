/*
* Initializing values
*/
int value = 0;
int motion = 0;

/*
* Setup method
*/
void setup()
{
  /*
  * Setting the Input/Outputs of the board.
  */ 
  pinMode(13, OUTPUT);
  pinMode(4, INPUT);
  
  /*
  * Initialization of Serial monitor.
  */
  Serial.begin(9600);
}

/*
* Loop method
*/
void loop() 
{
  /*
  * Read sensor value.
  */
  value = digitalRead(4);
  
  /*
  * Check motion state to only update when motion occurs.
  */
  if (motion != value)
  {
    /*
	* Updating motion value, printing motion value to console.
    */
	motion = value;
    Serial.println(motion);
  }
  
  /*
  * Checking if motion is active
  */
  if (value == HIGH) 
  {
    /*
	* Writing to console, outputting the motion to the LED
	*/
    Serial.println("MOTION DETECTED!");
    digitalWrite(13, HIGH);
  }
  else
  {
    /*
	* Outputting when motion ends to the LED
	*/
  	digitalWrite(13, LOW);
  }
}
