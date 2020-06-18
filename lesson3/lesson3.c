char ch=' ';/*设置一个变量用来承载端口命令*/
void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);/*设定6,7,8,9为输出口*/
  Serial.println("ok!");/*通过Arduion 向端口发送准备的指令*/
}

/*
预定
'f':表示前进
'b':表示后退
'r':表示右转
'l':表示左转
's':表示停止
*/
void loop()
{
  if(Serial.available()>0)
  {
    ch=Serial.read();/*将端口的指令存储在设定的变量中*/
    switch(ch)
    {
    case 'f':
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      break;
    case 'b':
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      break;
    case 'r':
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      break;
    case 'l':
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      break;
    case 's':
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      break;/*这是一个选择结构，根据不同的指令执行不同的命令*/
    default:
      break;
    }
  }
}
