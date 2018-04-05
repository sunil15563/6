// QUES 1.) Simulate CRC-12 for a noisy channel

#include<iostream.h>
#include<conio.h>
#include<new.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

// ********* XOR FUNCTION ***********

void XOR(int *divseq ,int *div,int Ldiv)
{
	for(int i=Ldiv-1;i>=0;i--)
	{
		if(divseq[i]==div[i])
			divseq[i]=0;
		else
			divseq[i]=1;
	}
}

// ********* DIVIDE FUNCTION ***********

int divide(int *div,int *bitpat,int *divseq,int &Ldiv,int &Lbit,int &Ldivseq)
{
	int flag=0,rem=0,usedpat;
	usedpat=Ldivseq;
	if(Lbit>=Ldiv)
	{
		for(int i=0;i<Ldiv;i++)
			divseq[i]=bitpat[i];
		Ldivseq=Ldiv;
		usedpat=Ldivseq;
		while((Ldivseq>=Ldiv)&&(usedpat<=Lbit))
		{
			XOR(divseq,div,Ldiv);
			for(int i=0;i<Ldivseq;i++)
			{
				if(divseq[i]==0)
					rem++;
				else
					break;
			}
			Ldivseq-=rem;
			for(i=0;i<Ldivseq;i++)
			{
				divseq[i]=divseq[i+rem];
			}
			for(i=Ldivseq;i<Ldiv;i++)
			{
				if(usedpat<Lbit)
				{
					divseq[i]=bitpat[usedpat];
					Ldivseq++;
					usedpat++;
				}
				else
					break;
			}
			rem=0;
		}
		if(Ldivseq==0)
			flag=1;
		else
			flag=0;
		for(i=0;i<Ldivseq;i++)
		{
			if(divseq[i]==0)
				flag=1;
			else
			{
				flag=0;
				break;
			}
		}
	}
	return flag;
}

// ********* WAIT ***********

void wait(int member)
{
	int x=20;
	gotoxy(20,10);
	cout<<"_________________________";
	gotoxy(20,13);
	cout<<"_________________________";
	for(int i=1;i<=4;i++)
	{
		if(i%2!=0)
		{
			gotoxy(20,8);
			cout<<"CRC is computing........";
		}
		else
		{
			if(member==0)
			{
				gotoxy(20,8);
				cout<<"sender is tranfering msg........";
			}
		}
		for(int j=x;j<43;j++)
		{
		  gotoxy(j,12);
		  cout<<"þþþ";
		  delay(50);
		  gotoxy(j,12);
		  clreol();
		}
	}
	cout<<endl<<endl;
}

// ********* SENDER COMPUTE ***********

void sendercompute(int *div,int *bitpat,int &Ldiv,int &Lbit)
{
	int Ldivseq,k=0,*divseq=new int[Ldiv],flag;
	Ldivseq=Ldiv;
	flag=divide(div,bitpat,divseq,Ldiv,Lbit,Ldivseq);
	k=Lbit-Ldivseq;
	for(int i=0;i<Ldivseq;i++)
	{
		bitpat[k+i]=divseq[i];
	}
	wait(0);
	cout<<"\n\n ur bit pattern to be tranamitted is "<<endl;
	for(i=0;i<Lbit;i++)
	cout<<bitpat[i]<<" ";
}


// ********* RECEIVER COMPUTE ***********

void receivercompute(int *div,int *bitpat,int &Ldiv,int &Lbit)
{
	int Ldivseq,*divseq=new int[Ldiv],flag;
	Ldivseq=Ldiv;
	flag=divide(div,bitpat,divseq,Ldiv,Lbit,Ldivseq);
	wait(1);
	if(flag==1)
		cout<<"\n\n UR MSG IS SUCESSFULLY TRANMITTED TO RECEIVER IN NOISELESS CHANNEL";
}

// ********** GABLE BIT ************

int gablebit(int *bitpat,int n,int &min,int &max)
{
	int gbit;
	clrscr();
	randomize();
	for(int i=1;i<=n;i++)
	{
		gbit=random(14);
		if(gbit<min)
			min=gbit;
		if(gbit>max)
			max=gbit;
		if(bitpat[gbit]==0)
			bitpat[gbit]=1;
		else
			bitpat[gbit]=0;
	}
	return gbit;
}

// ********** ERROR ************

void error(int *div,int *bitpat,int &Ldiv,int &Lbit)
{
	clrscr();
	int max=0,min=18,gbit;
	char err;
	cout<<"give the type of error which has occured"<<endl;
	cout<<"\n\n\n\t S=single bit error"<<endl;
	cout<<"\n\n\n\t D=double bit error"<<endl;
	cout<<"\n\n\n\t O=odd bits error"<<endl;
	cout<<"\n\n\n\t B=burst error"<<endl;
	cin>>err;
	if((err=='S')||(err=='s'))
	{
		gbit=gablebit(bitpat,1,min,max);
		receivercompute(div,bitpat,Ldiv,Lbit);
		cout<<"\n\n UR GAABLED MSG IS:\n\n ";
		for(int i=0;i<Lbit;i++)
			cout<<bitpat[i]<<" ";
		cout<<"\n\n A SINGLE BIT ERROR AT "<<gbit+1<<" BITS";
	}
	else if((err=='D')||(err=='d'))
	{
		gbit=gablebit(bitpat,2,min,max);
		receivercompute(div,bitpat,Ldiv,Lbit);
		cout<<"\n\n UR GAABLED MSG IS:\n\n ";
		for(int i=0;i<Lbit;i++)
			cout<<bitpat[i]<<" ";
		cout<<"\n\n A DOUBLE BIT ERROR AT "<<min+1<<" & "<<max+1<<" BITS";
	}
	else if((err=='O')||(err=='o'))
	{
		gbit=gablebit(bitpat,3,min,max);
		receivercompute(div,bitpat,Ldiv,Lbit);
		cout<<"\n\n UR GAABLED MSG IS:\n\n ";
		for(int i=0;i<Lbit;i++)
			cout<<bitpat[i]<<" ";
		cout<<"\n\n ODD NO. OF BITS  HAS GAABLED";
	}
	else if((err=='B')||(err=='b'))
	{
		gbit=gablebit(bitpat,6,min,max);
		receivercompute(div,bitpat,Ldiv,Lbit);
		cout<<"\n\n UR GAABLED MSG IS:\n\n ";
		for(int i=0;i<Lbit;i++)
			cout<<bitpat[i]<<" ";
		cout<<"\n\n BURST ERROR OCCURED B/W "<<min+1<<" & "<<max+1<<" BITS";
	}
	else
		cout<<"\n UNDEFINED ERROR";
	cout<<"\n\n UR NETWORK HAS A NOISY CHANNEL ";
}

// ********* MAKE PAT ***********

void makepat(char *b)
{
	char ans;
	int div[]={1,1,0,0,0,0,0,0,0,1,1,1,1},Ldiv=13,*bitpat,Lbit;
	Lbit=strlen(b);
	bitpat=new int[Lbit+Ldiv-1];
	for(int i=0;i<Lbit;i++)
		bitpat[i]=b[i]-'0';
	for(i=0;i<Ldiv-1;i++)
		bitpat[Lbit+i]=0;
	Lbit=Lbit+Ldiv-1;
	sendercompute(div,bitpat,Ldiv,Lbit);
	getch();
	clrscr();
	cout<<"sender has sent the msg to the receiver"<<endl;
	cout<<"plz wait until the receiver compute it......."<<endl;
	delay(200);
	receivercompute(div,bitpat,Ldiv,Lbit);
	cout<<"\n\n\n\n IS THERE ANY ERROR OCCURED ????(y/n)"<<endl;
	cin>>ans;
	if(ans=='y')
		error(div,bitpat,Ldiv,Lbit);
	delete[] bitpat;

}

//########## VOID MAIN ############

void main()
{
	clrscr();
	char b[40];
	cout<<"enter the bit pattern to be matched   ";
	cin.getline(b,40);
	makepat(b);
	getch();
}