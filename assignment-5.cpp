//author: Tejas Joshi
//Date: 11/09/2017

#include<iostream>
using namespace std;

class chain;

class node
{
	int data;
	node *next;
	node *prev;
	friend class chain;
};

class chain
{
	node *start=NULL;
	public:
	void add_node(int num)
	{
		node *q=start;
		node *temp= new node;
		temp->data=num;
		temp->next=NULL;
		temp->prev=NULL;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=temp;
			temp->prev=q;
		}
	}
	
	void append(int num)
	{
		node *q=start;
		node *temp= new node;
		temp->data=num;
		if(start==NULL)
		{
			start=temp;
			temp->next=NULL;
			temp->prev=NULL;
		}
		else
		{	
			temp->next=start;
			q->prev=temp;
			temp->prev=NULL;
			start=temp;
		}	
	}	
	
	void display()
	{
		node *q=start;
		while(q!=NULL)
		{
			cout<<q->data<<" ";
			q=q->next;
		}
		cout<<endl;
	}
	
	void ones_comp(chain num1)
	{
		node *p=num1.start;
		while(p!=NULL)
		{
			if(p->data==1)
			{
				add_node(0);
			}
			else
			{
				add_node(1);
			}
			p=p->next;
		}			
	}
	
	void twos_comp()
	{
		node *q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		while(q!=NULL)
		{
			if(q->data==1)
				q->data=0;
			else
			{
				q->data=1;
				break;
			}
			q=q->prev;
		}
	}
	
	chain operator+(chain num)
	{
		int carry=0;
		chain add;
		node *q=start;
		node *p=num.start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		while(p->next!=NULL)
		{
			p=p->next;
		}
		while(q!=NULL && p!=NULL)
		{
			if(carry==0)
			{
				if((q->data==0 && p->data==1) || (q->data==1 && p->data==0))
				{
					add.append(1);	
					carry=0;
				}
				else if(q->data==0 && p->data==0)
					add.append(0);
				else if(q->data==1 && p->data==1)
				{
					add.append(0);
					carry=1;
				}
			}
			else
			{
				if((q->data==0 && p->data==1) || (q->data==1 && p->data==0))
				{
					add.append(0);	
					carry=1;
				}
				else if(q->data==0 && p->data==0)
				{
					add.append(1);
					carry=0;
				}	
				else if(q->data==1 && p->data==1)
				{
					add.append(1);
					carry=1;
				}
			}
			q=q->prev;
			p=p->prev;
		}
		if(q==NULL && p==NULL && carry==1)
			add.append(1);
		return add;	
	}									
};

int main()
{
	int bit1,bit2,i,bit,choice;
	chain num1,num2,num3,num4,num5,num6,num7;
	cout<<"enter number of bits for first binary number : ";
	cin>>bit1;
	cout<<"Enter first binary number bit by bit : ";
	for(i=0;i<bit1;i++)
	{
		cin>>bit;
		num1.add_node(bit);
	}
	cout<<"You entered number : ";
	num1.display();
	cout<<"enter number of bits for second binary number : ";
	cin>>bit2;
	cout<<"Enter second binary number bit by bit : ";
	for(i=0;i<bit2;i++)
	{
		cin>>bit;
		num2.add_node(bit);
	}					
	cout<<"You entered number : ";
	num2.display();
	do
	{
		cout<<"Enter choice\n1. One's complement of first number\n2. One's complement of second number\n";
		cout<<"3. Two's complement of first number\n4. Two's complement of second number\n5. Addition\n6. Exit\n";
		cin>>choice;
		switch (choice)
		{
			case 1: num3.ones_comp(num1);
				cout<<"Ones complement of first number is : ";
				num3.display();
				cout<<endl;
			break;
			case 2: num4.ones_comp(num2);
				cout<<"Ones complement of second number is : ";
				num4.display();
				cout<<endl;
			break;
			case 3: num5.ones_comp(num1);
				num5.twos_comp();
				cout<<"Two's complement of first number is : ";
				num5.display();
				cout<<endl;
			break;
			case 4: num6.ones_comp(num2);
				num6.twos_comp();
				cout<<"Two's complement of second number is : ";
				num6.display();
				cout<<endl;
			break;
			case 5:
				if(bit1!=bit2)
				{
					if(bit1>bit2)
					{
						for(i=0;i<bit1-bit2;i++)
						{
							num2.append(0);
						}
					}
					else if(bit1<bit2)
					{
						for(i=0;i<bit2-bit1;i++)
						{
							num1.append(0);
						}
					}
				} 
				num7=num1+num2;
				cout<<"Addition of these numbers is : ";
				num7.display();
				cout<<endl;
			break;	
		}
	}while(choice!=6);		
	return 0;
}

/*output of program

enter number of bits for first binary number : 4
Enter first binary number bit by bit : 1 1 0 1
You entered number : 1 1 0 1 
enter number of bits for second binary number : 3
Enter second binary number bit by bit : 1 0 1
You entered number : 1 0 1 
Enter choice
1. One's complement of first number
2. One's complement of second number
3. Two's complement of first number
4. Two's complement of second number
5. Addition
6. Exit
1
Ones complement of first number is : 0 0 1 0 

Enter choice
1. One's complement of first number
2. One's complement of second number
3. Two's complement of first number
4. Two's complement of second number
5. Addition
6. Exit
2
Ones complement of second number is : 0 1 0 

Enter choice
1. One's complement of first number
2. One's complement of second number
3. Two's complement of first number
4. Two's complement of second number
5. Addition
6. Exit
3
Two's complement of first number is : 0 0 1 1 

Enter choice
1. One's complement of first number
2. One's complement of second number
3. Two's complement of first number
4. Two's complement of second number
5. Addition
6. Exit
4
Two's complement of second number is : 0 1 1 

Enter choice
1. One's complement of first number
2. One's complement of second number
3. Two's complement of first number
4. Two's complement of second number
5. Addition
6. Exit
5
Addition of these numbers is : 1 0 0 1 0 

Enter choice
1. One's complement of first number
2. One's complement of second number
3. Two's complement of first number
4. Two's complement of second number
5. Addition
6. Exit
6
*/

