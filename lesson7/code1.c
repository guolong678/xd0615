#include<reg51.h>
void delay(int x);
#define SEG P2
void main()
{
  int k;
  char TAB[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//共阴极
  while(1)
  {
    for(k=0;k<10;k++)
 {
   SEG=TAB[k];
   delay(500);
 }
  }
}  
void delay(int x)
{
  int i,j;
  for(i=0;i<x;i++)
    for(j=0;j<600;j++);
}  
