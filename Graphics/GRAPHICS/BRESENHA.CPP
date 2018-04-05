#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
    void bresenhams(int x1,int x2,int y1,int y2)
    { int dx,dy,pk,pk1;
      dx=x2-x1;
      dy=y2-y1;
      pk=2*dy-dx;

	for(int i=0;i<dx;i++)
	{
	 if(pk<0)
	 {
	 pk1=pk+2*dy;
	 x1=x1+1;

	 putpixel(x1,y1,WHITE);

	 }
	 else
	 {
	 pk1=pk+2*dy-2*dx;
	 x1=x1+1;
	 y1=y1+1;
	// cout<<"("<<x1<<","<<y1<<")";
	 putpixel(x1,y1,WHITE);

	 }
	 pk=pk1;
	}
    }
void main()
{   clrscr();
 int x1,y1,x2,y2;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 cout<<"enter initial coordinate(x1,y1)\n";
 cin>>x1>>y1;
 cout<<"\n\n";
 cout<<"enter terminating coordinate(x2,y2)\n";
 cin>>x2>>y2;
 clrscr();
   bresenhams(x1,x2,y1,y2);
 getch();
}
