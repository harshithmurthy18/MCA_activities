//Name: Harshith R
//Roll number: 211039004
//Team members: Harsha SK(211039011), Karthik MN(210981012, Manasa MK(211039034)
//Task: (MCA group task) Interfacing Arduino Uno with Water flow sensor (Model: YF-S201)

float vol = 0.0, l_minute; 
unsigned char flowsensor = 2;//Sensor Input Digital pin (multiplexed functionality INT0)
unsigned long currentTime; //to measure and print values per sesond
unsigned long cloopTime; //to measure and print values per sesond
unsigned long flow_frequency; //rate of change of hall sensor value

void flow () // Interrupt function to increment flow
{
   flow_frequency++; //each time the 
}

void setup()
{
   Serial.begin(9600);//to print data serially over serial monitor 
   pinMode(flowsensor, INPUT); //pin configurations
   digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
   attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup Interrupt with INT0(pin 2)
}

void loop ()
{
   currentTime = millis(); // Every second, calculate and print litres/hour
   
   if(currentTime >= (cloopTime + 1000)) //enters only after each second
   {
      cloopTime = currentTime; // Updates cloopTime
      
      if(flow_frequency != 0) //when there is water flow
      {
        Serial.print("***Flow Freqquency: ");
        Serial.println(flow_frequency);
        l_minute = (flow_frequency / 7.5); // (Pulse frequency x 60 min) / 7.5  
        
        Serial.print("Rate: ");
        Serial.print(l_minute);
        Serial.println(" L/M");
        
        l_minute = l_minute/60;//to convert to liters/hours
        vol = vol + l_minute;
        
        Serial.print("Vol: ");
        Serial.print(vol);
        Serial.println(" L");
        flow_frequency = 0; // Reset counter to newly check flow frequency 
        Serial.print(l_minute, DEC); // prints litres/hour (DEC does the type casting to decimal)
        Serial.println(" L/Sec");
      }
      
     else //when there is no water flow
      {
        Serial.println("**********No data**********");
      }
   }
}
