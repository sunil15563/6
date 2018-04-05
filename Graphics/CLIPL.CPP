#include<iostream.h>
#include<conio.h>
#include"gfunc.cpp"
#include<graphics.h>
#include<new.h>
#include<math.h>
int opcod(int x1,int y1,int *opcode,int xmin,int xmax,int ymin,int ymax)
{
	int flag;
	if(y1>ymax)
		opcode[0]=1;
	else
		opcode[0]=0;
	if(y1<ymin)
		opcode[1]=1;
	else
		opcode[1]=0;
	if(x1>xmax)
		opcode[2]=1;
	else
		opcode[2]=0;
	if(x1<xmin)
		opcode[3]=1;
	else
		opcode[3]=0;

	for(int i=0;i<4;i++)
	{
		if(opcode[i]==0)
			flag=1;
		else
		{
			flag=0;
			break;
		}
	}
	return flag;


}
void clipline(int x1,int y1,int x2,int y2,int xmin,int xmax,int ymin,int ymax)
{
	int opcode1[4],opcode2[4],f1,f2,f3=0,a,b;
	int x=getmaxx()/2;
	float m,c;
	int y=getmaxy()/2;
	//line(x1+x,y-y1,x+x2,y-y2);
	for(int i=0;i<4;i++)
	{
		opcode1[i]=0;
		opcode2[i]=0;
	}
	f1=opcod(x1,y1,opcode1,xmin,xmax,ymin,ymax);
	f2=opcod(x2,y2,opcode2,xmin,xmax,ymin,ymax);
	if(f1==1 && f2==1)
		line(x1+x,y-y1,x+x2,y-y2);
	else
	{
		for(int i=0;i<4;i++)
		{
			if(opcode1[i] && opcode2[i]!=0)
			{
				cout<<"UR LINE IS TRIVIALLY REJECTED,NO CLLIPINTG CAN BE DONE";
				f3=1;
				break;
			}
		}
		if(f3!=1)
		{
			cout<<"hello";
			a=-(y2-y1);
			b=x2-x1;
			m=(float)((y2-y1)/(x2-x1));
			c=-(x1*m)+y1;
			while(f1!=1 || f2!=1)
			{
				if(opcode1[0]!=0)
				{
					y1=ymax;
					x1=-((b*y1)+c)/a;
					f1=opcod(x1,y1,opcode1,xmin,xmax,ymin,ymax);
				}
				if(opcode1[1]!=0)
				{
					y1=ymin;
					x1=-((b*y1)+c)/a;
					f1=opcod(x1,y1,opcode1,xmin,xmax,ymin,ymax);
				}
				if(opcode1[2]!=0)
				{
					x1=xmax;
					y1=-((a*x1)+c)/b;
					f1=opcod(x1,y1,opcode1,xmin,xmax,ymin,ymax);
				}
				if(opcode1[3]!=0)
				{
					x1=xmin;
					y1=-((a*x1)+c)/b;
					f1=opcod(x1,y1,opcode1,xmin,xmax,ymin,ymax);
				}


				if(opcode2[0]!=0)
				{
					y2=ymax;
					x2=-((b*y2)+c)/a;
					f2=opcod(x2,y2,opcode2,xmin,xmax,ymin,ymax);
				}
				if(opcode2[1]!=0)
				{
					y2=ymin;
					x2=-((b*y2)+c)/a;
					f2=opcod(x2,y2,opcode2,xmin,xmax,ymin,ymax);
				}
				if(opcode2[2]!=0)
				{
					x2=xmax;
					y2=-((a*x2)+c)/b;
					f2=opcod(x2,y2,opcode2,xmin,xmax,ymin,ymax);
				}
				if(opcode2[3]!=0)
				{
					x2=xmin;
					y2=-((a*x2)+c)/b;
					f2=opcod(x2,y2,opcode2,xmin,xmax,ymin,ymax);
				}
			}
			cout<<x1<<","<<y1<<"   "<<x2<<","<<y2;
			getch();
			if((xmin>x1)||(xmax<x1)||(xmin>x2)||(xmax<x2)||(ymin>y1)||(ymax<y2)||(ymin>y2)||(ymax<y2))
				cout<<"UR LINE IS TRIVALLY REJECTED"<<endl;
			else
				line(x1+x,y-y1,x+x2,y-y2);
		}

	}

}
void main()
{
	int gd=DETECT,gm,op,x1,x2,y1,y2,xmin,xmax,ymin,ymax;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int x=getmaxx()/2;
	int y=getmaxy()/2;
	while(1)
	{
		clrscr();
		cout<<"********** MENU ***********";
		cout<<"\n\t1.INPUT CLIP WINDOW AND LINE DETAILS";
		cout<<"\n\t2.GET CLIPPED LINE";
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
				cout<<"enter the value of xmin  ";
				cin>>xmin;
				cout<<"enter the value of ymin  ";
				cin>>ymin;
				cout<<"enter the value of xmax  ";
				cin>>xmax;
				cout<<"enter the value of ymax  ";
				cin>>ymax;
				break;
			case 2: drawaxis();
				rectangle(xmin+x,y-ymax,xmax+x,y-ymin);
				clipline(x1,y1,x2,y2,xmin,xmax,ymin,ymax);
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