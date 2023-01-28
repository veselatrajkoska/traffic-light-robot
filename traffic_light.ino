int echoPin = 2;
int trigPin = 3;
int Rsensor = 15;
int Ysensor = 16;
int Gsensor = 17;
int ledB = 13;
int ledG = 8;
int ledR = 7;

long duration;
int distance;
long startTime = 0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(Rsensor, OUTPUT);
  pinMode(Ysensor, OUTPUT);
  pinMode(Gsensor, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(Rsensor, HIGH);
  
  long currentTime = millis();
  while (currentTime - startTime <= 5000)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(3);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    if (distance > 0 && distance < 10)
    {
      while(distance > 0 && distance < 8)
      {
        digitalWrite(ledB, LOW);
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, HIGH);
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
    
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(3);
        digitalWrite(trigPin, LOW);
    
        duration = pulseIn(echoPin, HIGH);
        distance = duration * 0.034 / 2;
      }

      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
    }
     
    if (currentTime - startTime >= 4000)
    {
      digitalWrite(Ysensor, HIGH);
    }
    
    currentTime = millis();
  }

  digitalWrite(ledR, LOW);
  startTime = currentTime;
  digitalWrite(Rsensor, LOW);
  digitalWrite(Ysensor, LOW);
  
  digitalWrite(Gsensor, HIGH);

  currentTime = millis();
  while(currentTime - startTime <= 5000)
  {
    //do nothing
    currentTime = millis();
  }
  digitalWrite(Gsensor, LOW);
  
  while(currentTime - startTime <= 6100)
  {
    digitalWrite(Ysensor, HIGH);
    currentTime = millis();
  }
  startTime = currentTime;
  digitalWrite(Ysensor, LOW);
}
