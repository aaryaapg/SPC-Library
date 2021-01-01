/*
This example uses an analog signal from a Force Sensitive Resistor, with a threshold value of 200.
*/

#include <SPC.h>
int fsrRaw; //Input value from Force Sensitive Resistor
int Sq;
int Count;

SPC spc;
void setup() {
  Serial.begin(9600);   
}

void loop() {
  fsrRaw = analogRead(A0);
  Sq = spc.SPC_getSquare(200, fsrRaw);
  Count = spc.SPC_getCount(Sq);
  Serial.print(Sq);
  Serial.print(" | Count: "); Serial.println(Count);
}
