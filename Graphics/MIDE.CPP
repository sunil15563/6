 // WAP to implement MID-POINT ellipse

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<process.h>
#include"gfunc.cpp"
void ellipse_points(int x,int y,int x1,int y1)
{
	colorpixel(x+x1,y+y1,10);
	colorpixel(-x+x1,y+y1,10);
	colorpixel(x+x1,-y+y1,10);
	colorpixel(-x+x1,-y+y1,10);
}

void mide(int x,int y,int mj,int mi)
{
	int xp=0,yp=mi;
	float rate_x,rate_y;
	float d_start,d_old,d_new;
	d_start=pow(mi,2)-(pow(mj,2)*(mi-0.25));
	d_old=d_start;
	ellipse_points(xp,yp,x,y);
	rate_x=pow(mi,2)*(xp+1);
	rate_y=pow(mj,2)*(yp-(0.5));
	while(rate_y>rate_x)  		// REGION 1
	{
		if(d_old<0)	// CHOOSE EAST
		{
			d_new=d_old+(pow(mi,2)*((2*xp)+3));
			xp++;
		}
		else 		// CHOOSE SOUTH-EAST
		{
			d_new=d_old+(pow(mi,2)*((2*xp)+3))+(pow(mj,2)*((-2*yp)+2));
			xp++;
			yp--;
		}
		ellipse_points(xp,yp,x,y);
		d_old=d_new;
		rate_x=pow(mi,2)*(xp+1);
		rate_y=pow(mj,2)*(yp-0.5);
	}
	d_start=(pow(mi,2)*(xp+0.25))+(pow(mj,2)*(((-2)*yp)+1));
	d_old=d_start;
	while(yp>=0)  		// REGION 2
	{
		if(d_old>0)	// CHOOSE SOUTH
		{
			d_new=d_old+(pow(mj,2)*(((-2)*yp)+3));
			yp--;
		}
		else         	// CHOOSE SOUTH-EAST
		{
			d_new=d_old+(pow(mi,2)*((2*xp)+2))+(pow(mj,2)*(((-2)*yp)+3));
			xp++;
			yp--;
		}
		ellipse_points(xp,yp,x,y);
		d_old=d_new;
	}
}
void main()
{
	int gd=DETECT,gm,x,y,mj,mi,op;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(1)
	{
		clrscr();
		cout<<"********** MENU ***********";
		cout<<"\n\t1.INPUT POINT COORDINATES";
		cout<<"\n\t2.GET THE ELLIPSE";
		cout<<"\n\t3.EXIT";
		cout<<" \n\tGIVE UR CHOICE";
		cin>>op;
		switch(op)
		{
			case 1:	cout<<"enter the x coordinate of vertex  ";
				cin>>x;
				cout<<"enter the y coordinate of vertex  ";
				cin>>y;
				cout<<"enter the length major axis  ";
				cin>>mj;
				cout<<"enter the length of minor axis  ";
				cin>>mi;
				break;
			case 2: drawaxis();
				mide(x,y,mj,mi);
				break;
			case 3:	exit(1);
			default:cout<<"INVALID CHOICE";
		}
		getch();
	}
	closegraph();
}
