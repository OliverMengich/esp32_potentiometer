float floatMap(float x, float in_min, float in_max, float out_min, float out_max);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(33, INPUT);
  pinMode(21,OUTPUT);
  pinMode(17, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(33);
  // Rescale to potentiometer's voltage (from 0V to 255):
  float brightness = floatMap(analogValue,0,4095,0,255);
  if(brightness >0 && brightness < 255/2){
    // light the red LED
    Serial.println("RED LED is ON");
    Serial.print("Analog: ");
    Serial.println(brightness);
    analogWrite(21, brightness);
    analogWrite(17,0);
  }else{
    Serial.println("YELLOW LED is ON");
    analogWrite(21, 0);
    analogWrite(17, brightness);
    Serial.print(", Analog: ");
    Serial.println(brightness);
  }
  delay(1000);
}
float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
