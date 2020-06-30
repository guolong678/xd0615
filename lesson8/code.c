/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262

//设置旋律中的音符：
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

//记录音符持续时间：4=四分音符，8=第八音符，
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
//用数组记录音符
void setup() {
  //用for循环记录重复旋律的音符：
  for (int thisNote = 0; thisNote < 8; thisNote++) 
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    
    tone(8, melody[thisNote], noteDuration);
//要计算音符持续时间，请花一秒钟 并按音符类型划分，记四分之一音符=1000/4，第八音符=1000/8，等等。

    //要区分音符，并设定它们之间的最短时间。
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    //这里用来停止播放音调：
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}
