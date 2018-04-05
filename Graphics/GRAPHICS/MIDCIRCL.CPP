#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void midpoint(int r)
{  int d,x=0,y=r,d1;
   d=1-r;
  //first octant
   while(x!=y)
   {
      if(d>0)
      {
      d1=d+2*x-2*y+5;
       x=x+1;
       y=y-1;
       putpixel(x+250,y+250,RED);
       putpixel(-x+250,y+250,RED);
       putpixel(x+250,-y+250,RED);
       putpixel(-x+250,-y+250,RED);
       putpixel(-y+250,x+250,RED);
       putpixel(y+250,-x+250,RED);
       putpixel(-y+250,-x+250,RED);
       putpixel(y+250,x+250,RED);
      }
      else
      {
      d1=d+2*x+3;
      x=x+1;
      putpixel(x+250,y+250,RED);

       putpixel(-x+250,y+250,RED);
       putpixel(x+250,-y+250,RED);
       putpixel(-x+250,-y+250,RED);
       putpixel(-y+250,x+250,RED);
       putpixel(y+250,-x+250,RED);
       putpixel(-y+250,-x+250,RED);
       putpixel(y+250,x+250,RED);
      }
    d=d1;
   }


}


void main()
{       clrscr();
int gd= DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
int r;
cout<<"enter radius  of circle\n";
cin>>r;
	clrscr();
midpoint(r);

getch();
}