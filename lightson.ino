int gutters = 2;
int bushes = 3;
int arch = 4;
int tree = 5;
int snowman = 6;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(gutters, OUTPUT);
  pinMode(bushes, OUTPUT);
  pinMode(arch, OUTPUT);
  pinMode(tree, OUTPUT);
  pinMode(snowman, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(gutters, HIGH);
  digitalWrite(bushes, HIGH);
  digitalWrite(arch, HIGH);
  digitalWrite(tree, HIGH);
  digitalWrite(snowman, HIGH);
}
