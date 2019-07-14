#include<iostream>
using namespace std;

class chain;

class node
{
	string job;
	node *link;
	friend class chain;
};

class chain
{
	node *start=NULL;
	public:
	void add_node(string name)
	{
		node *q=start;
		node *temp= new node;
		temp->job=name;
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
			cout<<"the list is empty\n";
		}
		else
		{
			while(q!=NULL)
			{
				cout<<q->job<<"\n";
				q=q->link;
			}
		}
	}
	
	string del()
	{
		if(start==NULL)
		{
			return ("The list is empty\n");
		}
		else
		{	
			node *q=start;
			string temp=q->job;
			start=q->link;
			delete(q);
			return temp;
		}	
	}				
};

int main()
{
	int n,i,choice;
	string name;
	chain queue;
	cout<<"Enter number of jobs you want to enter : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the job : ";
		cin>>name;
		queue.add_node(name);
	}	
	cout<<"The list is:\n";
	queue.display();
	do
	{
		cout<<"Enter your choice\n1. Enter job profile\n2. Delete job\n3. Display updated job list\n4. Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter the job : ";
					cin>>name;
					queue.add_node(name);
			break;
			case 2: cout<<"Deleted job is : "<<queue.del()<<endl;
			break;
			case 3: cout<<"\nThe updated job list is :\n";
					queue.display();
			break;
		}
	}while(choice!=4);				
	return 0;
}	

/*output of this program:

[exam@localhost S.E. Comp_F150070181]$ g++ assignment-9.cpp
[exam@localhost S.E. Comp_F150070181]$ ./a.out
Enter number of jobs you want to enter : 3
Enter the job : CEO
Enter the job : programmer
Enter the job : manager
The list is:
CEO
programmer
manager
Enter your choice
1. Enter job profile
2. Delete job
3. Display updated job list
4. Exit
1
Enter the job : janitor
Enter your choice
1. Enter job profile
2. Delete job
3. Display updated job list
4. Exit
3

The updated job list is :
CEO
programmer
manager
janitor
Enter your choice
1. Enter job profile
2. Delete job
3. Display updated job list
4. Exit
2
Deleted job is : CEO
Enter your choice
1. Enter job profile
2. Delete job
3. Display updated job list
4. Exit
2
Deleted job is : programmer
Enter your choice
1. Enter job profile
2. Delete job
3. Display updated job list
4. Exit
3

The updated job list is :
manager
janitor
Enter your choice
1. Enter job profile
2. Delete job
3. Display updated job list
4. Exit
4
*/
