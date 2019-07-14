//Author: Tejas Sanjay joshi

#include<iostream>
using namespace std;

class chain;

class node
{
	int data;
	node *link;
	friend class chain;
};

node *start=NULL;
node *start1=NULL;	
node *start2=NULL;

class chain
{
	public:
	void getdata(int num)									//taking input for linked list
	{
		node *q=start;
		node *temp= new node;
		if(start==NULL)
		{
			temp->data=num;
			temp->link=NULL;
			start=temp;
		}
		else
		{
			temp->data=num;
			temp->link=NULL;
			while(q->link!=NULL)
			{
				q=q->link;
			}
			q->link=temp;
		}
	}
	
	void display(node *st)										//to display any linked list
	{
		node *q=st;
		if(q==NULL)
		{
			cout<<"The list is empty.\n";
		}
		else
		{
			cout<<"the list is:\n";
			while(q!=NULL)
			{
				cout<<q->data<<endl;
				q=q->link;
			}
		}
	}	
	
	void more()													//to creat positive and negative list
	{
		struct node *q=start,*p=start1,*r=start2,*temp;
		while(q!=NULL)
		{
			temp=new node;
			if(q->data>=0)
			{
				p=start1;
				if(start1==NULL)				
				{	
					temp->data=q->data;
					temp->link=NULL;
					start1=temp;
				}
				else					
				{
					temp->data=q->data;
					temp->link=NULL;
					while(p->link!=NULL)		 
					{
						p=p->link;
					}
					p->link=temp;			
				}							
			}
			else if(q->data<0)
			{	
				r=start2;
				if(start2==NULL)				
				{	
					temp->data=q->data;
					temp->link=NULL;
					start2=temp;
				}
				else					
				{
					temp->data=q->data;
					temp->link=NULL;
					while(r->link!=NULL)		 
					{
						r=r->link;
					}
					r->link=temp;			
				}
			}
			q=q->link;		
		}			
	}
	
	void sort(struct node *st,int n)								//to sort list	
	{
		struct node *q=st;
		int temp,i;
		for(i=0;i<n;i++)
		{
			q=st;
			while(q->link!=NULL)
			{
				if(q->data>q->link->data)
				{
					temp=q->data;
					q->data=q->link->data;
					q->link->data=temp;
				}
				q=q->link;
			}
		}			
	}
	
	void merge(struct node *x,struct node *y)						//to merge sorted lists
	{
		struct node *p=y;
		while(p->link!=NULL)
		{
			p=p->link;
		}			
		p->link=x;				 
	}
	
	void del()													//to delete negative nodes
	{
		node *q=start,*temp;
		while(q->link!=NULL)
		{
			if(q->link->data<0)
			{					
				temp=q->link;
				q->link=q->link->link;
				delete(temp);
			}
			else
				q=q->link;
		}
		if(start->data<0)
		{
			temp=start;
			start=start->link;
			delete(temp);
		}			
	}										
};	
	
int main()
{
	int i,num,n,ch;
	chain list;
	cout<<"enter number of nodes\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter data:";
		cin>>num;
		list.getdata(num);
	}
	list.display(start);
	list.more();
	do
	{
		cout<<"enter your choice\n1. display positive integers\n2. display negative integers\n3. Display sorted positive list\n 4. display sorted negative list\n5. display list after deleting negative nodes\n6. display merged list\n7. Exit\n\n";
		cin>>ch;
		switch (ch)
		{
			case 1: cout<<"the positive list is:\n";
				list.display(start1);
			break;
			case 2: cout<<"the negative list is:\n";
				list.display(start2);
			break;
			case 3:cout<<"sorted positive list is:\n";
				list.sort(start1,n);
				list.display(start1);
			break;
			case 4:cout<<"sorted negative list is:\n";
				list.sort(start2,n);
				list.display(start2);
			break;	
			case 5: list.del();
				list.display(start);
			break;
			case 6: cout<<"Merged list is:\n";
				list.merge(start1,start2);
				list.display(start2);
			case 7: break;
			break;	
			default: cout<<"wrong choice\n";
		}
	}while(ch!=7);	
	return 0;
}	


/*output of this program:
enter number of nodes
4
enter data:-1
enter data:2
enter data:1
enter data:-2
the list is:
-1
2
1
-2
enter your choice
1. display positive integers
2. display negative integers
3. Display sorted positive list
 4. display sorted negative list
5. display list after deleting negative nodes
6. display merged list
7. Exit

1
the positive list is:
the list is:
2
1
enter your choice
1. display positive integers
2. display negative integers
3. Display sorted positive list
 4. display sorted negative list
5. display list after deleting negative nodes
6. display merged list
7. Exit

2
the negative list is:
the list is:
-1
-2
enter your choice
1. display positive integers
2. display negative integers
3. Display sorted positive list
 4. display sorted negative list
5. display list after deleting negative nodes
6. display merged list
7. Exit

3
sorted positive list is:
the list is:
1
2
enter your choice
1. display positive integers
2. display negative integers
3. Display sorted positive list
 4. display sorted negative list
5. display list after deleting negative nodes
6. display merged list
7. Exit

4
sorted negative list is:
the list is:
-2
-1
enter your choice
1. display positive integers
2. display negative integers
3. Display sorted positive list
 4. display sorted negative list
5. display list after deleting negative nodes
6. display merged list
7. Exit

5
the list is:
2
1
enter your choice
1. display positive integers
2. display negative integers
3. Display sorted positive list
 4. display sorted negative list
5. display list after deleting negative nodes
6. display merged list
7. Exit

6
Merged list is:
the list is:
-2
-1
1
2
enter your choice
1. display positive integers
2. display negative integers
3. Display sorted positive list
 4. display sorted negative list
5. display list after deleting negative nodes
6. display merged list
7. Exit

7*/			
