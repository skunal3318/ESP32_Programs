#define red_led 22
#define green_led 19
#define blue_led 18

int hallData = 0;
void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  hallData = hallRead();
  Serial.print("Hall Effect Reading :: ");
  Serial.println(hallData);

  if(hallData < 10 || hallData > 80) {
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, HIGH);
    digitalWrite(blue_led, HIGH);
  }else{
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
  }
}
