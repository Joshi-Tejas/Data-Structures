//author: Tejas Joshi
#include<iostream>
using namespace std;

class chain;

class node
{
	int data;
	node *next;
	friend class chain;
};	

class chain
{
	node *tail=NULL;
	public:
	void add_node(int num)
	{
		node *q=tail;
		node *temp= new node;
		temp->data=num;
		if(tail==NULL)
		{
			tail=temp;
			tail->next=tail;
		}
		else
		{
			temp->next=q->next;
			tail->next=temp;
			tail=temp;
		}
	}
	
	void display()
	{
		node *q;
		if(tail==NULL)
		{
			cout<<"The list is empty.\n";
		}
		else
		{	
			q=tail->next;
			while(q!=tail)
			{
				cout<<q->data<<" ";
				q=q->next;
			}
			cout<<q->data<<" ";
			cout<<endl;
		}	
	}
	
	void sort_list(int x)
	{
		int i;
		node *q;
		int temp;
		for(i=0;i<x;i++)
		{
			q=tail->next;
			while(q!=tail)
			{
				if(q->data>=q->next->data)
				{
					temp=q->data;
					q->data=q->next->data;
					q->next->data=temp;
				}
				q=q->next;
			}
		}	
	}
	
	void merge(chain list1,chain list2)
	{
		node *q=list1.tail->next;
		while(q!=list1.tail)
		{
			add_node(q->data);
			q=q->next;
		}
		add_node(q->data);
		q=list2.tail->next;
		while(q!=list2.tail)
		{
			add_node(q->data);
			q=q->next;
		}
		add_node(q->data);
	}	
	
	void del()
	{
		node *q=tail->next;
		node *temp=q;
		while(q!=tail)
		{
			q=q->next;
			delete(temp);
			temp=q;
		}
		delete(tail);
		tail=NULL;
	}		
};

int main()
{
	int i,num,num1,num2,choice;
	chain list1,list2,list3;
	cout<<"Enter number of nodes for list x : ";
	cin>>num1;
	for(i=0;i<num1;i++)
	{
		cout<<"Enter data "<<i+1<<" : ";
		cin>>num;
		list1.add_node(num);
	}
	cout<<"List x is : ";
	list1.display();
	cout<<"Enter number of nodes for list y : ";
	cin>>num2;
	for(i=0;i<num2;i++)
	{
		cout<<"Enter data "<<i+1<<" : ";
		cin>>num;
		list2.add_node(num);
	}
	cout<<"List 2 is : ";
	list2.display();
	do
	{
		cout<<"Enter your choice\n1. Display sorted list x\n2. Display sorted list y\n3. Display merged list z\n";
		cout<<"4. Display sorted merged list\n5. Delete lists x and y\n6. Exit\n";
		cin>>choice;
		switch (choice)
		{
			case 1: list1.sort_list(num1);
				cout<<"Sorted list x is : ";
				list1.display();
			break;
			case 2: list2.sort_list(num2);
				cout<<"Sorted list y is : ";
				list2.display();
			break; 
			case 3: list3.merge(list1,list2);
				cout<<"Merged list z is : ";
				list3.display();
			break;
			case 4: list3.sort_list(num1+num2);
				cout<<"Sorted merged list z is : ";
				list3.display();
			break;
			case 5: list1.del();
				list1.display();
				list2.del();
				list2.display();
			break;
		}
	}while(choice!=6);		
	return 0;
}			

/*output of this program is :

[exam@localhost S.E. Comp_F150070181]$ g++ assignment-6.cpp
[exam@localhost S.E. Comp_F150070181]$ ./a.out
Enter number of nodes for list x : 4
Enter data 1 : 7
Enter data 2 : 1
Enter data 3 : 5
Enter data 4 : 3
List x is : 7 1 5 3 
Enter number of nodes for list y : 4
Enter data 1 : 8
Enter data 2 : 2
Enter data 3 : 6
Enter data 4 : 4
List 2 is : 8 2 6 4 
Enter your choice
1. Display sorted list x
2. Display sorted list y
3. Display merged list z
4. Display sorted merged list
5. Delete lists x and y
6. Exit
1
Sorted list x is : 1 3 5 7 
Enter your choice
1. Display sorted list x
2. Display sorted list y
3. Display merged list z
4. Display sorted merged list
5. Delete lists x and y
6. Exit
2
Sorted list y is : 2 4 6 8 
Enter your choice
1. Display sorted list x
2. Display sorted list y
3. Display merged list z
4. Display sorted merged list
5. Delete lists x and y
6. Exit
3
Merged list z is : 1 3 5 7 2 4 6 8 
Enter your choice
1. Display sorted list x
2. Display sorted list y
3. Display merged list z
4. Display sorted merged list
5. Delete lists x and y
6. Exit
4
Sorted merged list z is : 1 2 3 4 5 6 7 8 
Enter your choice
1. Display sorted list x
2. Display sorted list y
3. Display merged list z
4. Display sorted merged list
5. Delete lists x and y
6. Exit
5
The list is empty.
The list is empty.
Enter your choice
1. Display sorted list x
2. Display sorted list y
3. Display merged list z
4. Display sorted merged list
5. Delete lists x and y
6. Exit
6

*/
