int state = 0;

void setup() {

  // Setup HC05
  Serial.begin(9600);
  Serial.println("Ok");

  // Moteur 1
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  

  // Moteur 2
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    state = Serial.read();
    Serial.println(state);
  }

  if (state == '49'){
    avant();
    state = 0;
  }
  else if (state == '50'){
    arriere();
    state = 0;
  }
  else if (state == '52'){
    gauche();
    state = 0;
  }
  else if (state == '51'){
    droite();
    state = 0;
  }
  
  

}

void avant(){
  //avant
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  analogWrite(9, 80);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  analogWrite(6, 80);
}

void droite(){
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  analogWrite(9, 80);
}

void gauche(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  analogWrite(6, 80);
}

void arriere(){
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  analogWrite(9, 80);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  analogWrite(6, 80);
}
