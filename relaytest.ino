int channel1 = 2;
int channel2 = 3;
int channel3 = 4;
int channel4 = 5;
int channel5 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(channel1, OUTPUT);
  pinMode(channel2, OUTPUT);
  pinMode(channel3, OUTPUT);
  pinMode(channel4, OUTPUT);
  pinMode(channel5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(channel1, HIGH);
  delay(500);
  digitalWrite(channel1, LOW);
  delay(500);
  
}
