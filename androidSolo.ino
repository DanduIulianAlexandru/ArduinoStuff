const int buttonPin =  4;     
const int danceButton = 3;
const int ledPin        = 13; 
const int ledPin1      = 12;
const int ledPin2      = 11;

int  initial    = 0;       
int oldstate    = 0;       
int buttonstate = 0;       
int dancestate = 0;

void setup() {
  pinMode(ledPin, OUTPUT);   
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);  
  pinMode(danceButton, INPUT);  
}
void loop(){ 
  buttonstate = digitalRead(buttonPin);  
  dancestate = digitalRead(danceButton);   
  if(buttonstate == HIGH){             
    delay(50);
    buttonstate = digitalRead(buttonPin); 
    if(buttonstate == LOW){       
     initial = oldstate + 1;         
    }
  }else{                   
      delay(100);
      }
   switch (initial){            
     case 1:                   
       digitalWrite(ledPin, HIGH);//on
       digitalWrite(ledPin1, LOW);//off
       digitalWrite(ledPin2, LOW);//off
       oldstate =  initial;              
       break;
     case 2:
       digitalWrite(ledPin, LOW);
       digitalWrite(ledPin1, HIGH);
       digitalWrite(ledPin2, LOW);
       oldstate =  initial;
       break;
     case 3:
       digitalWrite(ledPin, LOW);
       digitalWrite(ledPin1, LOW);
       digitalWrite(ledPin2, HIGH);
       oldstate =  initial;
       break;         
     default:                 
       digitalWrite(ledPin, LOW);  //off
       digitalWrite(ledPin1, LOW);
       digitalWrite(ledPin2, LOW);
       oldstate = 0;                    //reset to all off/initial 0
       break;         
     }
     buttonstate = digitalRead(danceButton);  

    if(dancestate == HIGH){               
      delay(100);
      dancestate = digitalRead(danceButton);
      if(dancestate == LOW){              
        digitalWrite(ledPin, HIGH);
        delay(700);
        digitalWrite(ledPin1, HIGH);
        delay(700);
        digitalWrite(ledPin2, HIGH);
        delay(600);
        digitalWrite(ledPin, LOW);  //off
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        delay(400);
        digitalWrite(ledPin, HIGH); 
        digitalWrite(ledPin1, HIGH);
        digitalWrite(ledPin2, HIGH);
        delay(1000);
        digitalWrite(ledPin, LOW);  //off
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
    }
  }
}