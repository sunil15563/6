// WAP to implement DDA line

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<process.h>
#include"gfunc.cpp"
void both_m_add(int x1,int y1,int x2,int y2,double m)
{
	double y=y1;
	for(int x=x1;x<=x2;x++)
	{
		colorpixel(x,y,10);
		y+=m;
		//y=floor(y+0.5);

	}
}

void both_1_by_m_add(int x1,int y1,int x2,int y2,double m)
{
	double x=x1;
	for(int y=y1;y<=y2;y++)
	{
		colorpixel(x,y,10);
		x+=(1/m);
		//x=floor(x+0.5);
	}
}

void both_m_sub(int x1,int y1,int x2,int y2,double m)
{
	double y=y1;
	for(int x=x1;x>=x2;x--)
	{
		colorpixel(x,y,10);
		y-=m;
		//y=floor(y+0.5);
	}

}

void both_1_by_m_sub(int x1,int y1,int x2,int y2,double m)
{
	double x=x1;
	for(int y=y1;y>=y2;y--)
	{
		colorpixel(x,y,10);
		x-=(1/m);
		//y=floor(y+0.5);
	}

}

void dda(int x1,int y1,int x2,int y2)
{
	double dy=y2-y1;
	double dx=x2-x1;
	double m=dy/dx;
	double y,x;
	int s,b;
	if(dy>0 && dx>0)
	{
		if(abs(m)<1)
			both_m_add(x1,y1,x2,y2,m);
		if(abs(m)>=1)
			both_1_by_m_add(x1,y1,x2,y2,m);
	}
	if(dy>0 && dx<0)
	{
		if(abs(m)<1)
			both_m_sub(x1,y1,x2,y2,m);
		if(abs(m)>=1)
			both_1_by_m_add(x1,y1,x2,y2,m);
	}
	if(dy<0 && dx<0)
	{
		if(abs(m)<1)
			both_m_sub(x1,y1,x2,y2,m);
		if(abs(m)>=1)
			both_1_by_m_sub(x1,y1,x2,y2,m);
	}

	if(dy<0 && dx>0)
	{
		if(abs(m)<1)
			both_m_add(x1,y1,x2,y2,m);
		if(abs(m)>=1)
			both_1_by_m_sub(x1,y1,x2,y2,m);
	}
	if(dy==0)
	{

		if(x1<x2)
		{
			s=x1;
			b=x2;
		}
		else
		{
			s=x2;
			b=x1;
		}
		for(int i=s;i<=b;i++)
			colorpixel(i,y1,10);
	}
	if(dx==0)
	{
		if(y1<y2)
		{
			s=y1;
			b=y2;
		}
		else
		{
			s=y2;
			b=y1;
		}
		for(int i=s;i<=b;i++)
			colorpixel(x1,i,10);
	}

}
void main()
{

	int gd=DETECT,gm,x1,y1,x2,y2,op;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(1)
	{
		clrscr();
		cout<<"********** MENU ***********";
		cout<<"\n\t1.INPUT POINT COORDINATES";
		cout<<"\n\t2.GET THE LINE";
		cout<<"\n\t3.EXIT";
		cout<<" \n\tGIVE UR CHOICE";
		cin>>op;
		switch(op)
		{
			case 1:	cout<<"enter the value of x1  ";
				cin>>x1;
				cout<<"enter the value of y1  ";
				cin>>y1;
				cout<<"enter the value of x2  ";
				cin>>x2;
				cout<<"enter the value of y2  ";
				cin>>y2;
				break;
			case 2: drawaxis();
				dda(x1,y1,x2,y2);
				break;
			case 3:	exit(1);
			default:cout<<"INVALID CHOICE";
		}
		getch();
	}
	closegraph();
}