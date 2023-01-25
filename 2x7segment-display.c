#include<reg51.h>
sbit red=P1^0;
sbit yellow=P1^1;
sbit green=P1^2;
void ssd_delay(int y); 
void main(){
		P2=0xc0;
		P3=0xc0;
	red=yellow=green=0;
	while(1){
		red=1;
		ssd_delay(1);
		red=0;
		yellow=1;
		ssd_delay(2);
		yellow=0;
		green=1;
		ssd_delay(3);
		green=0;
	}
}
void ssd_delay(int y){
	unsigned char
	ssd[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
	unsigned char x;
	unsigned int i,j;


		for(x=0;x<=y;x++){
		P3=ssd[x];
		for(i=0;i<35000;i++);
			for(j=0;j<=9;j++){
				P2=ssd[j];
				for(i=0;i<35000;i++);
				if(j==9)
					P2=ssd[0];
				
			}
		}
}