int S_A = 5;  //speed motor a
int M_A1 = 4; //motor a = +
int M_A2 = 2; //motor a = -
int M_B1 = 8; //motor b = -
int M_B2 = 7; //motor b = +
int S_B = 6;  //speed motor b

int L_S = A0; //sincer R
int S_S = A1; //sincer S
int R_S = A2; //sincer L

const int trigPin = 14;
const int echoPin = 15;
long duration;
int distance ;
bool obstacle=false;

void setup() 
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);

pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);
  analogWrite(S_A, 30); 
analogWrite(S_B, 30); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT); 
delay(100);
}
int distanceCalcul() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
return distance= duration*0.034/2;
}

void loop()
{  
 distance = distanceCalcul();
 if(distance < 5){
 obstacle = true;
 Stop(); 
  }
 else {
  obstacle = false; 
 }

while (obstacle==false){

if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forward();}
Serial.println("Forward"); 


if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==0)&&(digitalRead(R_S) == 0)) {turnLeft();}

if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}

//if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){Stop();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnLeft();}
}

 
}

void forward(){

digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}


void turnRight(){
 
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}

void turnLeft(){

digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}

void Stop(){

digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}
