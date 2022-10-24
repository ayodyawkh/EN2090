int bitsize = 150;
int Data[300];
int Result[300];
int clockc[300];
int signalc[300];
void setup() {

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  pinMode(6, OUTPUT);
  digitalWrite(8, 1);
}

void loop() {
  for (int j = 0; j < bitsize; j++) {
    int dt = rand() % 2;

    Data[2 * j] = dt;
    Data[2 * j + 1] = dt;
    clockc[2 * j] = 1;
    clockc[2 * j + 1] = 0;

  }
  for (int j1 = 0; j1 < bitsize * 2; j1++) {
    signalc[j1] = Data[j1] ^ clockc[j1];
  }


  for (int i = 0; i < bitsize * 2; i++) {
    digitalWrite(8, clockc[i]);
    digitalWrite(7, signalc[i]);
    digitalWrite(6, Data[i]);

    delayMicroseconds(45);
    //delay(5);
    //digitalWrite(8, 0);
    //delayMicroseconds(50);
    //delay(5);
    int a = digitalRead(9);
    Result[i] = a;
    //Serial.print(a);
    //Serial.print(" ");


  }
  //Serial.println();
  int count = 0;
  for (int i = 0; i < bitsize*2; i++) {
    if (Data[i] != Result[i]) {
      count += 1;
    }
  }
//  Serial.print("Number of Errors: ");
//  Serial.println(count);
  //  delay(1000);


}
