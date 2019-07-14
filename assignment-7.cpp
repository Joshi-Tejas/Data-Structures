#include<iostream>
#include<string.h>
using namespace std;

class chain;

class node
{
	char data;
	node *link;
	friend class chain;
};

class chain
{
	node *start=NULL;
	public:
	
	void push(char ch)
	{
		node *q=start;
		node *temp= new node;
		temp->data=ch;
		temp->link=NULL;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			temp->link=start;
			start=temp;
		}			
	}
	
	void add_node(char num)								
	{
		node *q=start;
		node *temp= new node;
		temp->data=num;
		temp->link=NULL;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			while(q->link!=NULL)
			{
				q=q->link;
			}
			q->link=temp;
		}
	}
	
	void display()
	{
		node *q=start;
		if(start==NULL)
		{
			cout<<"List is empty.\n";
		}
		else
		{
			while(q!=NULL)
			{
				cout<<q->data;
				q=q->link;
			}
		}
	}
	
	int compare(chain list)
	{
		node *q=start;
		node *p=list.start;
		while(q!=NULL)
		{
			if(q->data!=p->data)
			{
				return 1;
			}
			q=q->link;
			p=p->link;
		}
		return 0;
	}			
};

int main()
{
	int n,i,k,choice,num;
	chain list1,list2,list3;
	char input[50];
	do
	{
		cout<<"Enter your choice\n1. Input string\n2. Display\n3. To find palindrome or not\n4. Display reversed string\n 5. Exit\n";
		cin>>choice;
		switch (choice)
		{
			case 1: {cout<<"Enter string input : ";
					cin.get();
					cin.getline(input,50);
					n=strlen(input);
					cout<<"You entered string : ";
					for(i=0;i<n;i++)
					{
						list3.push(input[i]);
						cout<<input[i];
					}	
					cout<<endl;}
			break;
			case 2: cout<<"You entered string : ";
					for(i=0;i<n;i++)
					{
						cout<<input[i];
					}	
					cout<<endl;
			break;
			case 3: for(i=0;i<n;i++)
					{
						if((input[i]>='A' && input[i]<='Z') || (input[i]>='a' && input[i]<='z'))
						{
							if(input[i]>='A' && input[i]<='Z')
							{
								list1.push(input[i]+32);
								list2.add_node(input[i]+32);
							}	
							else
							{
								list1.push(input[i]);
								list2.add_node(input[i]);
							}	
						}			
					}
					k=list1.compare(list2);
					if(k==0)
					{
						cout<<"The input string is palindrome\n";
					}
					else if(k==1)
					{
						cout<<"The list is not a palindrome\n";
					}
			break;	
			case 4: cout<<"Reversed string is : ";
					list3.display();
					cout<<endl;
			break;
		}
	}while(choice!=5);									
	return 0;
}	
