#include<iostream.h>
#include<conio.h>
#include"gfunc.cpp"
#include<graphics.h>
#include<process.h>
#include<new.h>
#include<math.h>
struct point
{
	int x,y;
};
void hermite()
{
	point p1,p4,r1,r4;
	double x,y,t_cube,t_square;
	cout<<"Enter the Extremities of Hermite curve"<<endl;
	cout<<"abscissa of Starting point";
	cin>>p1.x;
	cout<<"ordinate of Starting point";
	cin>>p1.y;
	cout<<"abscissa of Ending point";
	cin>>p4.x;
	cout<<"ordinate of Ending point";
	cin>>p4.y;
	cout<<"abscissa of slope vector of tangent at P1";
	cin>>r1.x;
	cout<<"ordinate of slope vector of tangent at P1";
	cin>>r1.y;
	cout<<"abscissa of slope vector of tangent at P4";
	cin>>r4.x;
	cout<<"ordinate of slope vector of tangent at P4";
	cin>>r4.y;
	drawaxis();
	for(float t=0.0;t<=1.0;t=t+0.001)
	{
		t_cube=pow(t,3);
		t_square=pow(t,2);
		x=((2*t_cube)-(3*t_square)+1)*p1.x+((-2*t_cube)+(3*t_square))*p4.x+(t_cube-(2*t_square)+t)*r1.x+(t_cube-t_square)*r4.x;
		y=((2*t_cube)-(3*t_square)+1)*p1.y+((-2*t_cube)+(3*t_square))*p4.y+(t_cube-(2*t_square)+t)*r1.y+(t_cube-t_square)*r4.y;
		//cout<<x<<","<<y<<endl;
		colorpixel(x,y,6);
	}
}
void bezier()
{
	point p1,p4,p2,p3;
	double x,y,t_cube,t_square;
	cout<<"Enter the Extremities of Bezier curve"<<endl;
	cout<<"abscissa of Starting point";
	cin>>p1.x;
	cout<<"ordinate of Starting point";
	cin>>p1.y;
	cout<<"abscissa of Ending point";
	cin>>p4.x;
	cout<<"ordinate of Ending point";
	cin>>p4.y;
	cout<<"abscissa of direction vector at P1";
	cin>>p2.x;
	cout<<"ordinate of direction vector at P1";
	cin>>p2.y;
	cout<<"abscissa of direction vector at P4";
	cin>>p3.x;
	cout<<"ordinate of direction vector at P4";
	cin>>p3.y;
	drawaxis();
	for(float t=0.0;t<=1.0;t=t+0.001)
	{
		t_cube=pow(t,3);
		t_square=pow(t,2);
		x=((-t_cube)+(3*t_square)-(3*t)+1)*p1.x+((3*t_cube)-(6*t_square)+(3*t))*p2.x+((-3*t_cube)+(3*t_square))*p3.x+(t_cube)*p4.x;
		y=((-t_cube)+(3*t_square)-(3*t)+1)*p1.y+((3*t_cube)-(6*t_square)+(3*t))*p2.y+((-3*t_cube)+(3*t_square))*p3.y+(t_cube)*p4.y;
		//cout<<x<<","<<y<<endl;
		colorpixel(x,y,6);
	}
}


void main()
{
	int gd=DETECT,gm,op;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(1)
	{

		clrscr();
		cout<<"********** MENU ***********";
		cout<<"\n\t1.HERMITE";
		cout<<"\n\t2.BEZIER";
		cout<<"\n\t3.EXIT";
		cout<<" \n\tGIVE UR CHOICE";
		cin>>op;
		switch(op)
		{
			case 1: hermite();
				break;
			case 2: bezier();
				break;
			case 3:	break;
			default:cout<<"INVALID CHOICE";
		}
		if(op==3)
			break;
		getch();
	}
	closegraph();
}