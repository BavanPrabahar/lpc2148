#include<lpc214x.h>
int i=1;
int j=1;
void ein(void)__irq{

char a[9]={' ','o','p','e','n','e','d'};
PWMTCR=0;
PWMMR2=12500;
PWMTCR=9;
if(j==1){
for(i=0;i<7;i++)
{
U1THR = a[i];
while(!(U1LSR & 0x20));

}
j++;
i=1;}

EXTINT=2;
VICVectAddr=0;
}
int main(){

char a[9]={' ','c','l','o','s','e','d'};
PINSEL0=(3<<6)|(2<<14)|(5<<16);
U1LCR = 0x83;
U1DLL = 97;
U1DLM = 0;
U1LCR = 0x03;
PWMPR=2;
PWMPC=0;
PWMTC=0;
PWMMR0=100000;
PWMTCR=9;
PWMLER=0;
PWMPCR=(1<<10)|(0<<2);
PWMMCR=1<<1;


EXTMODE=0;
EXTPOLAR=2;
VICVectAddr0=(unsigned long)ein;
VICVectCntl0=0X2F;
VICIntEnable=1<<15;
while(1){
PWMTCR=0;
PWMMR2=7500;
PWMTCR=9;

if(i==1){
for(i=0;i<7;i++)
{
U1THR = a[i];
while(!(U1LSR & 0x20));
}
i++;
j=1;}

}
return 0;
}

