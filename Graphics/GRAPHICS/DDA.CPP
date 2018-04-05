#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

int round( float a)
{
 float b=(int)a;
 b+=0.5;
 if(a<b)
  b-=0.5;
 else
  b+=0.5;
 return b;
}

void main()
{
 clrscr();
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
 float x1,x2,y1,y2,xi,yi,x,y;
 int m1,m2,step;
 cout<<"enter x1 and y1";
 cin>>x1>>y1;
 cout<<"enter x2 and y2";
 cin>>x2>>y2;
 m1=abs(x1-x2);
 m2=abs(y1-y2);
 if(m1>m2)
   step=m1;
 else
   step=m2;
 xi=(float)m1/step;
 yi=(float)m2/step;
 x=x1;
 y=y1;
 cout<<step<<" "<<xi<<" "<<yi<<" ";
 getch();
 clrscr();
 for(int i=0;i<=step;i++)
 {
	putpixel(round(x),round(y),RED);
	delay(100);
	x+=xi;
	y+=yi;
 }
 getch();
 cin.ignore();
}