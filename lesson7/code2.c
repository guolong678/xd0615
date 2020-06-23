#include <reg51.h>
unsigned int num,a;
sbit key0=P1^0;
sbit key2=P1^2;

bit  flag;

unsigned char code led_code[20] = {
    0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,
    0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};

void delay(unsigned char i)
{
    unsigned char j;
    for(;i>0;i--) for(j=110;j>0;j--);
}

void keyscan()
{
    if(key0==0)   {
      delay(7); 
      if(key0==0)      {
        num++;
        if(num==10)  num=0;
        while(key0==0);
      }
   }
    if(key2==0)  {
      delay(7); 
      if(key2==0)   {
        num=0;
        while(key2==0);
      }
    }
    if(key3==0)   {  
      delay(7); 
      if(key3==0)   {
        flag = ~flag;
        while(key3==0);
      }
    }
}
void T1_ini()
{
   TMOD=0X10;
   TH1=(65536-50000)/256;
   TL1=(65536-50000)%256;
   EA=1;
   ET1=1;
   TR1=1;
}
void timer1() interrupt 3
{
   a++; 
   TH1=(65536-50000)/256;
   TL1=(65536-50000)%256;
}
void display()
{
   P3=led_code[num];
}
void main()
{
   T1_ini();
   while(1)
   {
      keyscan();
      display();
      if(a >= 20 && flag) {
        a = 0;
        num++;
        if(num==10)  num=0;
      }
   }
} 
