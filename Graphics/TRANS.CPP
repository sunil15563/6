#include<iostream.h>
#include<conio.h>
#include"gfunc.cpp"
#include<graphics.h>
#include<process.h>
#include<new.h>
#include<math.h>
float object[10][3],final[10][3];
int n;
void mult(float a[][3],float b[][3])
{
	float sum=0.0;
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
				sum=sum+(a[i][k]*b[k][j]);
			final[i][j]=sum;
			sum=0.0;
		}
}
void input()
{
	cout<<"Enter the no. of vertices of ur object  ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the abscissa of vertex "<<(char)(65+i)<<" ";
		cin>>object[i][0];
		cout<<"Enter the ordinate of vertex "<<(char)(65+i)<<" ";
		cin>>object[i][1];
		object[i][2]=1.0;
		cout<<endl;
	}
	//for(i=0;i<n;i++)
	  //	cout<<"Vertex "<<(char)(65+i)<<" is "<<x_array[i]<<","<<y_array[i]<<endl;
}
void display()
{
	clrscr();
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	//cout<<"Previous object is"<<endl;
	drawaxis();
	for(int i=0;i<n-1;i++)
		line(object[i][0]+x,y-object[i][1],x+object[i+1][0],y-object[i+1][1]);
	line(x+object[n-1][0],y-object[n-1][1],x+object[0][0],y-object[0][1]);
	//cout<<endl<<endl;
	//cout<<"AFTER SCALING OBJECT is"<<endl;
	for(i=0;i<n-1;i++)
		line(x+final[i][0],y-final[i][1],x+final[i+1][0],y-final[i+1][1]);
	line(x+final[n-1][0],y-final[n-1][1],x+final[0][0],y-final[0][1]);
}
void scaling()
{
	float transform[3][3],a,d;
	cout<<"enter the scaling factor for x component";
	cin>>a;
	cout<<"enter the scaling factor for y component";
	cin>>d;
	transform[0][0]=a;
	transform[0][1]=0.0;
	transform[0][2]=0.0;
	transform[1][0]=0.0;
	transform[1][1]=d;
	transform[1][2]=0.0;
	transform[2][0]=0.0;
	transform[2][1]=0.0;
	transform[2][2]=1.0;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			cout<<object[i][j]<<" ";
		cout<<endl;
	}*/
	mult(object,transform);
	display();
}
void shearing()
{
	float transform[3][3],b,c;
	cout<<"enter the shearing factor for x component";
	cin>>b;
	cout<<"enter the shearing factor for y component";
	cin>>c;
	transform[0][0]=1.0;
	transform[0][1]=b;
	transform[0][2]=0.0;
	transform[1][0]=c;
	transform[1][1]=1.0;
	transform[1][2]=0.0;
	transform[2][0]=0.0;
	transform[2][1]=0.0;
	transform[2][2]=1.0;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			cout<<object[i][j]<<" ";
		cout<<endl;
	}*/
	mult(object,transform);
	display();
}
void translation()
{
	float transform[3][3],l,m;
	cout<<"enter the translating factor for x component";
	cin>>l;
	cout<<"enter the translating factor for y component";
	cin>>m;
	transform[0][0]=1.0;
	transform[0][1]=0.0;
	transform[0][2]=0.0;
	transform[1][0]=0.0;
	transform[1][1]=1.0;
	transform[1][2]=0.0;
	transform[2][0]=l;
	transform[2][1]=m;
	transform[2][2]=1.0;
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			cout<<object[i][j]<<" ";
		cout<<endl;
	}*/
	mult(object,transform);
	display();
}
void rotation()
{
	float transform[3][3];
	float theta,cos_t,sin_t;
	int x,y;
	cout<<"enter the abscissa of rotating point";
	cin>>x;
	cout<<"enter the ordinate of rotating point";
	cin>>y;
	cout<<"enter the rotation angle";
	cin>>theta;
	if(theta==90)
	{
		cos_t=0.0;
		sin_t=1.0;

	}
	else if(theta==180)
	{
		cos_t=-1.0;
		sin_t=0.0;

	}
	else if(theta==270 || theta==-90)
	{
		cos_t=0.0;
		sin_t=-1.0;

	}
	else if(theta==360)
	{
		cos_t=1.0;
		sin_t=0.0;

	}
	else
	{
		cos_t=cos((M_PI/180)*theta);
		sin_t=sin((M_PI/180)*theta);
	}
	transform[0][0]=cos_t;
	transform[0][1]=sin_t;
	transform[0][2]=0.0;
	transform[1][0]=-sin_t;
	transform[1][1]=cos_t;
	transform[1][2]=0.0;
	transform[2][0]=(y*sin_t)+x*(1-cos_t);
	transform[2][1]=(y*(1-cos_t))-(x*sin_t);
	transform[2][2]=1.0;
	mult(object,transform);
	display();

}
void reflection()
{
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	float transform[3][3],c,dy,dx,m,cost,sint,v1,v2;
	int x1,y1,x2,y2;
	cout<<"enter the abscissa of first point of line";
	cin>>x1;
	cout<<"enter the ordinate of first point of line";
	cin>>y1;
	cout<<"enter the abscissa of 2nd point of line";
	cin>>x2;
	cout<<"enter the abscissa of 2nd point of line";
	cin>>y2;
	dy=y2-y1;
	dx=x2-x1;
	if(dx!=0)
	{
		m=dy/dx;
		c= -(x1*m)+y1;
		v1=1/(sqrt(1+pow(m,2)));
		v2=m/(sqrt(1+pow(m,2)));
		if(dy>0 && dx>0)
		{
			cost=v1;
			sint=-v2;
		}
		if(dy>0 && dx<0)
		{
			cost=v1;
			sint=-v2;
		}
		if(dy<0 && dx<0)
		{
			cost=-v1;
			sint=v2;
		}
		if(dy<0 && dx>0)
		{
			cost=v1;
			sint=-v2;
		}
		if(dy==0)
		{
			cost=1.0;
			sint=0.0;
		}
		transform[0][0]=(cost*cost)-(sint*sint);
		transform[0][1]=-(2*sint*cost);
		transform[0][2]=0.0;
		transform[1][0]=-(2*sint*cost);
		transform[1][1]=(sint*sint)-(cost*cost);
		transform[1][2]=0.0;
		transform[2][0]=2*c*sint*cost;
		transform[2][1]=2*c*(cost*cost);
		transform[2][2]=1.0;
	}
	else
	{
		transform[0][0]=-1.0;
		transform[0][1]=0.0;
		transform[0][2]=0.0;
		transform[1][0]=0.0;
		transform[1][1]=1.0;
		transform[1][2]=0.0;
		transform[2][0]=2*x1;
		transform[2][1]=0.0;
		transform[2][2]=1.0;
	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
			cout<<object[i][j]<<" ";
		cout<<endl;
	}*/
	getch();
	mult(object,transform);
	display();
	line(x+x1,y-y1,x+x2,y-y2);
}

void main()
{
	int gd=DETECT,gm,op;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(1)
	{
		clrscr();
		cout<<"********** MENU ***********";
		cout<<"\n\t1.INPUT OBJECT's DETAILS";
		cout<<"\n\t2.SCALING";
		cout<<"\n\t3.SHEARING";
		cout<<"\n\t4.TRANSLATION";
		cout<<"\n\t5.ROTATION";
		cout<<"\n\t6.REFLECTION";
		cout<<"\n\t7.EXIT";
		cout<<" \n\tGIVE UR CHOICE";
		cin>>op;
		switch(op)
		{
			case 1:	input();
				break;
			case 2: scaling();
				break;
			case 3: shearing();
				break;
			case 4: translation();
				break;
			case 5: rotation();
				break;
			case 6: reflection();
				break;
			case 7:	break;
			default:cout<<"INVALID CHOICE";
		}
		if(op!=7 & op!=1)
		{
			for(int i=0;i<n;i++)
				for(int j=0;j<3;j++)
					object[i][j]=final[i][j];
		}
		if(op==7)
			break;
		getch();
	}
	closegraph();
}