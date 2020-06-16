int i=0;
void setup()
{
  for(i=0;i<9;i++)
  {
  pinMode(i, OUTPUT);
  }
}

void loop()
{
  for(i=0;i<9;i++)
  {
  digitalWrite(i, HIGH);
  delay(800); // Wait for 1000 millisecond(s)
  digitalWrite(i, LOW);
  delay(800); // Wait for 1000 millisecond(s)
  }
}