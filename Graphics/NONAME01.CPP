// To implement sorted link list
#include<iostream.h>
#include<conio.h>
class node
{
public:
	int info;
	node *next;
	node(int val)
	{
		info=val;
		next=NULL;
	}

};
class linklist
{
public:
	node *head,*tail;
	linklist()
	{
		head=tail=NULL;
	}
	void insert(int val)
	{
		node *p=new node(val);
		if(head==NULL)
			head=tail=p;
		else if(p->info<head->info)
		{
			p->next=head;
			head=p;
		}
		else if(p->info>tail->info)
		{
			tail->next=p;
			tail=p;
		}
		else
		{
			node *temp,*prev;
			temp=prev=head;
			while(temp->info<=p->info)
			{
				prev=temp;
				temp=temp->next;
			}
			p->next=temp;
			prev->next=p;
		}
	}
	void traverse()
	{
		node *temp;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->info<<"    ";
			temp=temp->next;
		}
	}
};