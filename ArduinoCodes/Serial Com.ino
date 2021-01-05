void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000);
}

void loop() {
  if(Serial.available() > 0)
  {
    String data = Serial.readString();
    StringSplitter *splitter = new StringSplitter(data, '/', 5);
    q1 = (splitter->getItemAtIndex(1)).toFloat();
    q2 = (splitter->getItemAtIndex(2)).toFloat();
    q3 = (splitter->getItemAtIndex(3)).toFloat();
    q4 = (splitter->getItemAtIndex(4)).toFloat();
    q5 = (splitter->getItemAtIndex(5)).toFloat();
    mover();
  }

}
