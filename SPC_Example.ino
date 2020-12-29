#include <SPC.h>
int fsrRaw;
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
