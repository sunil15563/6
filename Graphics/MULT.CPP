#include<iostream.h>
#include<conio.h>
int c[10][10];
void mult(int a[][10],int b[][10],int row_a,int col_a,int row_b,int col_b)
{
	int sum=0;
	if(col_a==row_b)
	{
		for(int i=0;i<row_a;i++)
			for(int j=0;j<col_b;j++)
			{
				for(int k=0;k<=col_a;k++)
					sum=sum+(a[i][k]*b[k][j]);
				c[i][j]=sum;
				sum=0;
			}
	}
}
void main()
{
	clrscr();
	int a[10][10],b[10][10],row_a,col_a,row_b,col_b;
	cout<<"enter row of a  ";
	cin>>row_a;
	cout<<"enter col of a  ";
	cin>>col_a;
	cout<<"enter row of b  ";
	cin>>row_b;
	cout<<"enter col of b  ";
	cin>>col_b;
	cout<<"\n COUT ENTER MATRIX A";
	for(int i=0;i<row_a;i++)
	{
		for(int j=0;j<col_a;j++)
		{
			cin>>a[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
	cout<<"\n COUT ENTER MATRIX B";
	for(i=0;i<row_b;i++)
	{
		for(int j=0;j<col_b;j++)
		{
			cin>>b[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
	mult(a,b,row_a,col_a,row_b,col_b);
	for(i=0;i<row_a;i++)
	{
		for(int j=0;j<col_b;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
	getch();

}