int button = 12;
// value to check state of button switch
int pressed = 0;
int counter = 0;

//photosensor
int inputPin = A0;
int anVal = 0;

void setup() {  
  pinMode(10, OUTPUT);

  pinMode(button, INPUT);

  pressed = 0;
  
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

int roll() {
  int randNumber = random(1,7);
  
  #ifdef DEBUG
    Serial.println(randNumber);
  #endif
  
  return randNumber;
}

void blink(int number){
  for(int i=1; i<=number; i++){
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10, LOW);
    delay(500);
  }
}


void loop() {
  // if button is pressed - throw the dice
  pressed = digitalRead(button);
  
  
  if (pressed == LOW) {
    // remove previous number
    counter = 1;        
    int diceFace = roll();
    Serial.println(diceFace);
    
    if(counter == 1){
      blink(diceFace);
    }
  } 

  delay(10);
  anVal = analogRead(inputPin);

  if(anVal <= 2){
    counter = 1;        
    int diceFace = roll();
    Serial.println(diceFace);
    
    if(counter == 1){
      blink(diceFace);
    }
  }
  //Serial.println(anVal);
  
  //analogWrite(10, anVal);

  

}
