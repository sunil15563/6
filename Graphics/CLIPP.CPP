//toclip a polygon
#include<iostream.h>
#include<conio.h>
#include"gfunc.cpp"
#include"list.cpp"
#include<graphics.h>
#include<process.h>
#include<new.h>
#include<math.h>
int n;
float x_array[40],y_array[40],final_x[40],final_y[40];
void input()
{
	cout<<"Enter the no. of vertices of ur polygon  ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"Enter the abscissa of vertex "<<(char)(65+i)<<" ";
		cin>>x_array[i];
		cout<<"Enter the ordinate of vertex "<<(char)(65+i)<<" ";
		cin>>y_array[i];
		cout<<endl;
	}
}
void clippoly(float xmin,float ymax,float xmax,float ymin)
{
	int j=0;
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	float m;

 // ************* CLIPPING ABOUT X_MIN****************

	for(int i=0;i<n;i++)
	{
		if(x_array[i]>=xmin)
		{
			final_x[j]=x_array[i];
			final_y[j]=y_array[i];
			cout<<"Inside vertex is "<<final_x[j]<<","<<final_y[j]<<endl;
			j++;
		}
		if((x_array[i%n]<xmin && x_array[(i+1)%n]>xmin) || (x_array[i%n]>xmin && x_array[(i+1)%n]<xmin))
		{
			m=(y_array[(i+1)%n]-y_array[i%n])/(x_array[(i+1)%n]-x_array[i%n]);
			final_y[j]=m*(xmin-x_array[i%n])+y_array[i%n];	// here point satisfying the line has abscissa as xmin
			final_x[j]=xmin;// i%n and (i+1)%n is used to make circular array.

			cout<<"Calculated is vertex is "<<final_x[j]<<","<<final_y[j]<<endl;
			j++;
		}

	}
// *****************CLIPPING ABOUT Y_MAX ****************

	n=j;
	for(i=0;i<n;i++)
	{
		x_array[i]=final_x[i];      // using the clipped polygon
		y_array[i]=final_y[i];      // output as input for next clip line
	}
	j=0;
	for(i=0;i<n;i++)
	{
		if(y_array[i]<=ymax)
		{
			final_x[j]=x_array[i];
			final_y[j]=y_array[i];
			cout<<"Inside vertex is "<<final_x[j]<<","<<final_y[j]<<endl;
			j++;
		}
		if((y_array[i%n]<ymax && y_array[(i+1)%n]>ymax) || (y_array[i%n]>ymax && y_array[(i+1)%n]<ymax))
		{
			m=(y_array[(i+1)%n]-y_array[i%n])/(x_array[(i+1)%n]-x_array[i%n]);
			final_x[j]=((1.0/m)*(ymax-y_array[i%n]))+x_array[i%n];  // here point satisfying the line has ordinate as ymax
			final_y[j]=ymax;// i%n and (i+1)%n is used to make circular array

			cout<<"Calculated final vertex is "<<final_x[j]<<","<<final_y[j]<<endl;
			j++;
		}

	}
// *****************CLIPPING ABOUT X_MAX ****************

	n=j;
	for(i=0;i<n;i++)
	{
		x_array[i]=final_x[i];      // using the clipped polygon
		y_array[i]=final_y[i];      // output as input for next clip line
	}
	j=0;

	for(i=0;i<n;i++)
	{
		if(x_array[i]<=xmax)
		{
			final_x[j]=x_array[i];
			final_y[j]=y_array[i];
			cout<<"Inside vertex is "<<final_x[j]<<","<<final_y[j]<<endl;
			j++;
		}
		if((x_array[i%n]<xmax && x_array[(i+1)%n]>xmax) || (x_array[i%n]>xmax && x_array[(i+1)%n]<xmax))
		{
			m=(y_array[(i+1)%n]-y_array[i%n])/(x_array[(i+1)%n]-x_array[i%n]);
			final_y[j]=m*(xmax-x_array[i%n])+y_array[i%n];	// here point satisfying the line has abscissa as xmax
			final_x[j]=xmax;// i%n and (i+1)%n is used to make circular array

			cout<<"Calculated vertex is "<<final_x[j]<<","<<final_y[j]<<endl;
			j++;
		}

	}

// ************* CLIPPING ABOUT Y_MIN****************

	n=j;
	for(i=0;i<n;i++)
	{
		x_array[i]=final_x[i];      // using the clipped polygon
		y_array[i]=final_y[i];      // output as input for next clip line
	}
	j=0;


	for(i=0;i<n;i++)
	{
		if(y_array[i]>=ymin)
		{
			final_x[j]=x_array[i];
			final_y[j]=y_array[i];
			cout<<"Inside vertex is "<<final_x[j]<<","<<final_y[j]<<endl;
			j++;
		}
		if((y_array[i%n]<ymin && y_array[(i+1)%n]>ymin) || (y_array[i%n]>ymin && y_array[(i+1)%n]<ymin))
		{
			m=(y_array[(i+1)%n]-y_array[i%n])/(x_array[(i+1)%n]-x_array[i%n]);
			final_x[j]=((1.0/m)*(ymin-y_array[i%n]))+x_array[i%n];  // here point satisfying the line has ordinate as ymin
			final_y[j]=ymin;// i%n and (i+1)%n is used to make circular array.

			cout<<"Calculated final vertex is "<<final_x[j]<<","<<final_y[j]<<endl;
			j++;
		}

	}

//************ DRAWING THE CLIPPED POLYGON ALONG THE WINDOW************

	rectangle(xmin+x,y-ymax,xmax+x,y-ymin);
	for(i=0;i<j;i++)
	{
		line(x+final_x[i%j],y-final_y[i%j],x+final_x[(i+1)%j],y-final_y[(i+1)%j]);
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
		cout<<"\n\t1.INPUT CLIP WINDOW AND LINE DETAILS";
		cout<<"\n\t2.GET CLIPPED POLYGON";
		cout<<"\n\t3.EXIT";
		cout<<" \n\tGIVE UR CHOICE";
		cin>>op;
		switch(op)
		{
			case 1:	input();
				break;
			case 2: drawaxis();
				clippoly(30,150,90,100);
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