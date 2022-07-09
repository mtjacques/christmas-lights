int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;

int i = 0;
int incomingByte[15];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() >= 15);
  {
    for (int i = 0; i < 15; i++)
    {
      incomingByte[i] = Serial.read();
    }
    digitalWrite(A, incomingByte[0]);
    digitalWrite(B, incomingByte[2]);
    digitalWrite(C, incomingByte[3]);
    digitalWrite(D, incomingByte[3]);
    digitalWrite(E, incomingByte[4]);
  }
}
