// WAP to implement MID-POINT circle

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<process.h>
#include"gfunc.cpp"
void circlepoints(int x,int y,int x1,int y1)
{
	colorpixel(x+x1,y+y1,10);
	colorpixel(-x+x1,y+y1,10);
	colorpixel(y+x1,x+y1,10);
	colorpixel(-y+x1,x+y1,10);
	colorpixel(y+x1,-x+y1,10);
	colorpixel(x+x1,-y+y1,10);
	colorpixel(-x+x1,-y+y1,10);
	colorpixel(-y+x1,-x+y1,10);

}
void midc(int x,int y,int r)
{
	int xp=0,yp=r;
	int h_start,h_old,h_new;
	h_start=1-r;
	h_old=h_start;
	circlepoints(xp,yp,x,y);
	while(yp>=xp)
	{
		if(h_old<0)	//CHOOSE EAST
		{
			h_new=h_old+(2*xp)+3;
			xp++;
		}
		else
		{
			h_new=h_old+(2*(xp-yp))+5;
			xp++;
			yp--;
		}
		circlepoints(xp,yp,x,y);
		h_old=h_new;
	}
}
void main()
{
	int gd=DETECT,gm,x,y,r,op;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(1)
	{
		clrscr();
		cout<<"********** MENU ***********";
		cout<<"\n\t1.INPUT POINT COORDINATES";
		cout<<"\n\t2.GET THE CIRCLE";
		cout<<"\n\t3.EXIT";
		cout<<" \n\tGIVE UR CHOICE";
		cin>>op;
		switch(op)
		{
			case 1:	cout<<"enter the x coordinate of centre  ";
				cin>>x;
				cout<<"enter the y coordinate of centre  ";
				cin>>y;
				cout<<"enter the RADIUS  ";
				cin>>r;
				break;
			case 2: drawaxis();
				midc(x,y,r);
				break;
			case 3:	exit(1);
			default:cout<<"INVALID CHOICE";
		}
		getch();
	}
	closegraph();
}
