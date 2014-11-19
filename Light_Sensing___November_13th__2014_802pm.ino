/*
LED sensing for Laser Harp - Prototype
Destinee Fraser
November 13th, 2014    

The code so far before adding the piezo buzzers to make sound. Mainly used to make LED's function as light sensors for the lasers.
*/
int speakerOut = 1;
int speakerOut2 = 9;
int speakerOut3 = 10;
int speakerOut4 = 11;
int speakerOut5 = 12;
int speakerOut6 = 13;
byte names[] = {'c', 'd', 'e', 'f' , 'g', 'a'}; 
int tones[] = {1915, 1700, 1519, 1432, 1275, 1136};

// Sensors are the LEDS that react to a change in light

int sensor1 = 0;        // Sensing LED connected to analog0
int sensor2 = 1;        // Sensing LED connected to analog1
int sensor3 = 2;        // Sensing LED connected to analog2 
int sensor4 = 3;        // Sensing LED connected to analog3
int sensor5 = 4;        // Sensing LED connected to analog4
int sensor6 = 5;        // Sensing LED connected to analog5
                                                
int Laser1 = 3;          // LED connected to digital3
int Laser2 = 4;          // LED connected to digital4
int Laser3 = 5;          // LED connected to digital5
int Laser4 = 6;          // LED connected to digital6
int Laser5 = 7;          // LED connected to digital7
int Laser6 = 8;          // LED connected to digital8
                       
int value1 = 0;          // Stores values from sensor1
int value2 = 0;          // Stores values from sensor2
int value3 = 0;          // Stores values from sensor3
int value4 = 0;          // Stores values from sensor4
int value5 = 0;          // Stores values from sensor5
int value6 = 0;          // Stores values from sensor6

int light = 210;         // Light threshold

void setup()
{
  Serial.begin(9600);          // Serial time
  
  pinMode(Laser1, OUTPUT);     // Sets Laser1 as an output
  pinMode(Laser2, OUTPUT);     // Sets Laser2 as an output
  pinMode(Laser3, OUTPUT);     // Sets Laser3 as an output
  pinMode(Laser4, OUTPUT);     // Sets Laser4 as an output
  pinMode(Laser5, OUTPUT);     // Sets Laser5 as an output
  pinMode(Laser6, OUTPUT);     // Sets Laser6 as an output
  
  pinMode(speakerOut, OUTPUT);     // Sets speakerOut as an output
  pinMode(speakerOut2, OUTPUT);     // Sets speakerOut2 as an output
  pinMode(speakerOut3, OUTPUT);     // Sets speakerOut3 as an output
  pinMode(speakerOut4, OUTPUT);     // Sets speakerOut4 as an output
  pinMode(speakerOut5, OUTPUT);     // Sets speakerOut5 as an output
  pinMode(speakerOut6, OUTPUT);     // Sets speakerOut6 as an output
}

void loop()
{
  value1 = analogRead(sensor1);      // Read LED sensor1
  value2 = analogRead(sensor2);      // Read LED sensor2
  value3 = analogRead(sensor3);      // Read LED sensor3
  value4 = analogRead(sensor4);      // Read LED sensor4
  value5 = analogRead(sensor5);      // Read LED sensor5
  value6 = analogRead(sensor6);      // Read LED sensor6
  
  Serial.println(value1);            // Keep track of readings
  Serial.println(value2);            // Keep track of readings
  Serial.println(value1);            // Keep track of readings
  Serial.println(value1);            // Keep track of readings
  Serial.println(value1);            // Keep track of readings
  
  if (value1 >= light) {             
      digitalWrite(Laser1, LOW);     // If the light is on, the LED sensor will turn off
    } else {                      
      digitalWrite(Laser1, HIGH);    // If the light is blocked, the LED sensor will turn on
    }
  if (value2 >= light) {              
      digitalWrite(Laser2, LOW);     
    } else {                      
      digitalWrite(Laser2, HIGH);    
    }   
  if (value3 >= light) {
     digitalWrite(Laser3, LOW);
   } else {
     digitalWrite(Laser3, HIGH);
     }
  if (value4 >= light) {
     digitalWrite(Laser4, LOW);
   } else {
     digitalWrite(Laser4, HIGH);
     }
  if (value5 >= light) {
     digitalWrite (Laser5, LOW);
     } else {
     digitalWrite (Laser5, HIGH);
     }
  if (value6 >= light) {
     digitalWrite (Laser6, LOW);
     } else {
     digitalWrite (Laser6, HIGH);
     }
 }
 
 // PLAY Note
 void play_note(byte p_note_cd) {
 
    noTone(speakerOut);
    noTone(speakerOut1);
    noTone(speakerOut2);
    noTone(speakerOut3);
    noTone(speakerOut4);
    noTone(speakerOut5);
    noTone(speakerOut6);
   
     switch (p_note_cd) { //Play Note
       case 'c':
                   tone(speakerOut, tones[names[p_note_cd]]) ;
       break; //End Case
       case 'd':
                   tone(speakerOut2, tones[names[p_note_cd]]) ;
       break;
       case 'e':
                   noTone(speakerOut3);
                   tone(speakerOut3, tones[names[p_note_cd]]) ;
       break;
       case 'f':
                   noTone(speakerOut4);
                   tone(speakerOut4, tones[names[p_note_cd]]) ;
       break;
       case 'g':
                    digitalWrite(speakerOut5,HIGH);
                    delayMicroseconds(tones[names[p_note_cd]]);

                    // DOWN
                    digitalWrite(speakerOut5, LOW);
                    delayMicroseconds(tones[names[p_note_cd]]);
       break;
       case 'a':
                    digitalWrite(speakerOut6,HIGH);
                    delayMicroseconds(tones[names[p_note_cd]]);

                    // DOWN
                    digitalWrite(speakerOut6, LOW);
                    delayMicroseconds(tones[names[p_note_cd]]);
       break;
       }                                                            
}

 
 // STOP Note
 void stop_note(p_note_cd) {
     switch (p_note_cd) { //Play Note
       case 'c':
              digitalWrite(speakerOut,LOW);
       break; //End Case
       case 'd':
              digitalWrite(speakerOut2,LOW);
       break;
       case 'e':
              digitalWrite(speakerOut3,LOW);
       break;
       case 'f':
              digitalWrite(speakerOut4,LOW);
       break;
       case 'g':
              digitalWrite(speakerOut5,LOW);
       break;
       case 'a':
              digitalWrite(speakerOut6,LOW);
       break;
       }                                                            
}

