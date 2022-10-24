#include<LiquidCrystal.h>


int n = 400;
int* Data = new int[n];
int* res = new int[n];
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);
void setup() {

  pinMode(9, INPUT);
  pinMode(6, OUTPUT);
  LCD.begin(16, 2);
  
}

void loop() {

  for (int j = 0; j < n; j++) {
    int dt = rand() % 2;
    Data[j] = dt;
  }

  for (int i = 0; i < n; i++) {
    digitalWrite(6, Data[i]);
    delayMicroseconds(100);
    int a = digitalRead(9);
    res[i] = a;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (Data[i] != res[i]) {
      count += 1;
    }
  }
  LCD.print("Errors: ");
  LCD.print(count);
  
  delay(10);
  LCD.clear();

}
