#include<iostream.h>
#include<conio.h>
#include"gfunc.cpp"
#include"list.cpp"
#include<graphics.h>
#include<process.h>
#include<new.h>
#include<math.h>
int n,x_array[40],y_array[40];
int get_y_max()
{
	int max=y_array[0];
	for(int i=1;i<n;i++)
	{
		if(y_array[i]>max)
			max=y_array[i];
	}
	return max;
}
int get_y_min()
{
	int min=y_array[0];
	for(int i=1;i<n;i++)
	{
		if(y_array[i]<min)
			min=y_array[i];
	}
	return min;
}
int max(int a,int b)
{
	return((a>b)?a:b);
}
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
void active_edge_table(linklist &active_node,int Lnode)
{
	int n=0,flag=0;
	float final_point[30];
	node *temp1,*prev;
	temp1=active_node.head;
	prev=active_node.head;
	while(temp1!=NULL)
	{
		flag=0;
		if(temp1->y_max==Lnode)
		{
			flag=1;
			active_node.remove(temp1,prev);
			temp1=prev->next;
		}
		else
		{
			final_point[n]=temp1->x_min;
			n++;
		}
		if(flag==0)
		{
			prev=temp1;
			temp1=temp1->next;
		}
	}
	for(int i=ceil(final_point[0]);i<=floor(final_point[1]);i++)
			 colorpixel(i,Lnode,10);
}

void global_edge_table(linklist *L,int Lnode,int y_min)
{
	int node_ymax,prev,aftr;
	float node_xmin,node_slope,dy,dx;
	if(Lnode!=y_min)
	{
		node *temp;
		temp=L[Lnode-1-y_min].head;
		while(temp!=NULL)
		{
			node_xmin=temp->x_min+temp->reci_slope;
			L[Lnode-y_min].insert(temp->y_max,node_xmin,temp->reci_slope);
			temp=temp->next;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(y_array[i]==Lnode)
		{
			// getting the previous and after vertex without
			// making the array circular
			prev=(i+n-1)%n;
			aftr=(i+1)%n;
			node_ymax=max(y_array[i],y_array[prev]);
			node_xmin=x_array[i];    //using library max fn.
			dy=y_array[i]-y_array[prev];   // making an edge
			dx=x_array[i]-x_array[prev];   // by taking previous
			if(dy==0)                     // node
				node_slope=100.0;
			else
				node_slope=(float)(dx/dy);
			L[Lnode-y_min].insert(node_ymax,node_xmin,node_slope);


			node_ymax=max(y_array[i],y_array[aftr]);
			node_xmin=x_array[i];    //using libraty max fn.
			dy=y_array[aftr]-y_array[i];   // making edge by
			dx=x_array[aftr]-x_array[i];   // taking next node
			if(dy==0)
				node_slope=100.0;
			else
				node_slope=(float)(dx/dy);
			L[Lnode-y_min].insert(node_ymax,node_xmin,node_slope);
		}
	}
	active_edge_table(L[Lnode-y_min],Lnode);
}
void fillp()
{
	int y_max,y_min,x_max,x_min,Lnode;
	y_max=get_y_max();		//Getting Y_max and Y-min
	y_min=get_y_min();
	linklist *L=new linklist[y_max-y_min+1];
	Lnode=y_min;
	global_edge_table(L,Lnode,y_min);
	for(int i=1;i<=y_max-y_min;i++)
	{
		Lnode=i+y_min;
		global_edge_table(L,Lnode,y_min);
	}
	delete L;
}
void main()
{
	int gd=DETECT,gm,op;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(1)
	{
		clrscr();
		cout<<"********** MENU ***********";
		cout<<"\n\t1.INPUT POLYGON's DETAILS";
		cout<<"\n\t2.GET THE FILLED POLYGON";
		cout<<"\n\t3.EXIT";
		cout<<" \n\tGIVE UR CHOICE";
		cin>>op;
		switch(op)
		{
			case 1:	input();
				break;
			case 2: drawaxis();
				fillp();
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