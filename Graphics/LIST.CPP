// To implement sorted link list
#include<iostream.h>
#include<conio.h>
class node
{
public:
	int y_max;
	float x_min,reci_slope;
	node *next;
	node(int ymax,float xmin,float recislope)
	{
		y_max=ymax;
		x_min=xmin;
		reci_slope=recislope;
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
	void insert(int val1,float val2,float val3)
	{
		node *p=new node(val1,val2,val3);
		if(head==NULL)
			head=tail=p;
		else if(p->x_min<head->x_min)
		{
			p->next=head;
			head=p;
		}
		else if(p->x_min>tail->x_min)
		{
			tail->next=p;
			tail=p;
		}
		else
		{
			node *temp,*prev;
			temp=prev=head;

			while(temp->x_min<=p->x_min)
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
			cout<<temp->y_max<<" "<<temp->x_min<<" "<<temp->reci_slope<<"    ";
			temp=temp->next;
		}
	}
	void remove(node *r,node *rp)
	{
		if(r==head)
			head=head->next;
		else
		{
			rp->next=r->next;
			r->next=NULL;
		}
	}
};