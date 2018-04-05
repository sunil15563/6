// WAP to implement MID-POINT line

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<process.h>
#include"gfunc.cpp"
int only_x_increase(int &xp,int a,int d_old)
{
	int d_new;
	xp+=1;
	d_new=d_old+a;
	return d_new;
}

int only_x_decrease(int &xp,int a,int d_old)
{
	int d_new;
	xp-=1;
	d_new=d_old-a;
	return d_new;
}

int only_y_increase(int &yp,int b,int d_old)
{
	int d_new;
	yp+=1;
	d_new=d_old+b;
	return d_new;
}

int only_y_decrease(int &yp,int b,int d_old)
{
	int d_new;
	yp-=1;
	d_new=d_old-b;
	return d_new;

}

int both_increase(int &xp,int &yp,int a,int b,int d_old)
{
	int d_new;
	xp=xp+1;
	yp=yp+1;
	d_new=d_old+a+b;
	return d_new;
}

int x_dec_y_inc(int &xp,int &yp,int a,int b,int d_old)
{
	int d_new;
	xp=xp-1;
	yp=yp+1;
	d_new=d_old-a+b;
	return d_new;
}

int x_inc_y_dec(int &xp,int &yp,int a,int b,int d_old)
{
	int d_new;
	xp=xp+1;
	yp=yp-1;
	d_new=d_old+a-b;
	return d_new;
}


int x_dec_y_dec(int &xp,int &yp,int a,int b,int d_old)
{
	int d_new;
	xp=xp-1;
	yp=yp-1;
	d_new=d_old-a-b;
	return d_new;
}

void midp(int x1,int y1,int x2,int y2)
{
	int dy=y2-y1,dx=x2-x1,xp=x1,yp=y1,flag=0;
	int d_start,d_old,d_new,a,b,small,big,m;
	a=2*dy;
	b=-2*dx;

	if(dy==0)
	{
		if(x1<x2)
		{
			small=x1;
			big=x2;
		}
		else
		{
			small=x2;
			big=x1;
		}
		for(int i=small;i<=big;i++)
			colorpixel(i,y1,10);
	}
	if(dx==0)
	{
		flag=1;
		if(y1<y2)
		{
			small=y1;
			big=y2;
		}
		else
		{
			small=y2;
			big=y1;
		}
		for(int i=small;i<=big;i++)
			colorpixel(x1,i,10);
	}

	if(flag!=1)
		m=dy/dx;	// CALCULATING SLOPE

	if(dy>0 && dx>0)
	{
		if(abs(m)<1)
		{
			d_start=a+(b/2);
			d_old=d_start;
			while(xp<x2)
			{
				if(d_old>0)		//CHOOSE NE
					d_new=both_increase(xp,yp,a,b,d_old);
				else                    // CHOOSE E
					d_new=only_x_increase(xp,a,d_old);
				d_old=d_new;
				colorpixel(xp,yp,10);
			}
		}
		else
		{
			d_start=(a/2)+b;
			d_old=d_start;
			while(yp<y2)
			{
				if(d_old>0)   		//CHOOSE N
					d_new=only_y_increase(yp,b,d_old);
				else                    // CHOOSE NE
					d_new=both_increase(xp,yp,a,b,d_old);
				d_old=d_new;
				colorpixel(xp,yp,10);
			}
		}
	}

	if(dy>0 && dx<0)
	{
		if(abs(m)<1)
		{
			d_start=-a+(b/2);
			d_old=d_start;
			while(xp>x2)
			{
				if(d_old<0)		//CHOOSE NW
					d_new=x_dec_y_inc(xp,yp,a,b,d_old);
				else                    // CHOOSE W
					d_new=only_x_decrease(xp,a,d_old);
				d_old=d_new;
				colorpixel(xp,yp,10);
			}
		}
		else
		{
			d_start=(-(a)/2)+b;
			d_old=d_start;
			while(yp<y2)
			{
				if(d_old<0)   		//CHOOSE N
					d_new=only_y_increase(yp,b,d_old);
				else                    // CHOOSE NW
					d_new=x_dec_y_inc(xp,yp,a,b,d_old);
				d_old=d_new;
				colorpixel(xp,yp,10);
			}
		}
	}

	if(dy<0 && dx<0)
	{
		if(abs(m)<1)
		{
			d_start=-a+(-(b)/2);
			d_old=d_start;
			while(xp>x2)
			{
				if(d_old>0)		//CHOOSE SW
					d_new=x_dec_y_dec(xp,yp,a,b,d_old);
				else                    // CHOOSE W
					d_new=only_x_decrease(xp,a,d_old);
				d_old=d_new;
				colorpixel(xp,yp,10);
			}
		}
		else
		{
			d_start=(-(a)/2)+b;
			d_old=d_start;
			while(yp>y2)
			{
				if(d_old>0)   		//CHOOSE S
					d_new=only_y_decrease(yp,b,d_old);
				else                    // CHOOSE SW
					d_new=x_dec_y_dec(xp,yp,a,b,d_old);
				d_old=d_new;
				colorpixel(xp,yp,10);
			}
		}
	}

	if(dy<0 && dx>0)
	{
		if(abs(m)<1)
		{
			d_start=a+(-(b)/2);
			d_old=d_start;
			while(xp<x2)
			{
				if(d_old<0)		//CHOOSE SE
					d_new=x_inc_y_dec(xp,yp,a,b,d_old);
				else                    // CHOOSE E
					d_new=only_x_increase(xp,a,d_old);
				d_old=d_new;
				colorpixel(xp,yp,10);
			}
		}
		else
		{
			d_start=((a)/2)-b;
			d_old=d_start;
			while(yp>y2)
			{
				if(d_old<0)   		//CHOOSE S
					d_new=only_y_decrease(yp,b,d_old);
				else                    // CHOOSE SE
					d_new=x_inc_y_dec(xp,yp,a,b,d_old);
				d_old=d_new;
				colorpixel(xp,yp,10);
			}
		}
	}
	flag=0;
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
				midp(x1,y1,x2,y2);
				break;
			case 3:	exit(1);
			default:cout<<"INVALID CHOICE";
		}
		getch();
	}
	closegraph();
}