int led1_pin = D0;
int led2_pin = D1;
int button_pin = D2;

int buttonval;
int lastButtonState = HIGH;
int count = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
}

void loop() {
  buttonval = digitalRead(button_pin);

  if (lastButtonState == HIGH && buttonval == LOW) {
    count++;
    if (count > 3) count = 1;  
    Serial.print("Count is ");
    Serial.println(count);
    delay(200); 
  }
  lastButtonState = buttonval;

  if (count == 1) {

    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, HIGH);
    delay(200);
    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    delay(200);
  }
  else if (count == 2) {
  
    digitalWrite(led1_pin, HIGH);
    digitalWrite(led2_pin, LOW);
    delay(200);
    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, HIGH);
    delay(200);
  }
  else if (count == 3) {

    digitalWrite(led1_pin, LOW);
    digitalWrite(led2_pin, LOW);
    delay(100);
  }
}
