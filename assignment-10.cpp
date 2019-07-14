#include<iostream>
#define MAX 100
using namespace std;

class dequeue
{
	int arr[MAX],count=0;
	int front,rear;
	public:
	dequeue()
	{
		front=-1;
		rear=0;
	}
	
	bool isfull()
	{
		return ((front==0 && rear==MAX-1) || (front==rear+1));
	}	
	
	bool isempty()
	{
		return (front==-1);
	}	
	
	void add_front(int num)
	{
		if(isfull())
		{
			cout<<"Overflow\n";
			return;
		}
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		else if(front==0)
		{
			front=MAX-1;
		}
		else
			front--;
		arr[front]=num;					
	}
	
	void add_back(int num)
	{
		if(isfull())
		{
			cout<<"Overflow\n";
			return;
		}
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		else if(rear==MAX-1)
			rear=0;	
		else
			rear++;
		arr[rear]=num;		
	}			
	
	void del_front()
	{
		if(isempty())
		{
			cout<<"Underflow\n";
			return;
		}	
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(front==MAX-1)
			front=0;
		else
			front++;		
	}
	
	void del_back()
	{
		if(isempty())
		{
			cout<<"Underflow\n";
			return;
		}
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else if(rear==0)
		{
			rear=MAX-1;
		}
		else
			rear--;
	}
	
	int get_front()
	{
		if(isempty())
		{
			cout<<"Underflow\n";
			return -1;
		}
		else
			return arr[front];
	}
	
	int get_back()
	{
		if(isempty() || rear<0)
		{
			cout<<"Underflow\n";
			return -1;
		}
		else
			return arr[rear];
	}													
};

int main()
{
	int choice,num,get;
	char choice2;
	dequeue d1;
	do
	{
		cout<<"Enter the type of Dequeue\na. Input restricted\nb. Output restricted\nc. Exit\n";
		cin>>choice2;
		switch (choice2)
		{
		case 'a':	do
			{
				cout<<"Enter your choice\n1. Add at back\n2. Remove from start\n3. Remove from back\n4. Get element from front\n5. Get element from back\n6. Exit\n";
				cin>>choice;
				switch (choice)
				{
					case 1: cout<<"Enter number : ";
						cin>>num;
						d1.add_back(num);
					break;	
					case 2: d1.del_front();
					break;
					case 3:	d1.del_back();
					break;
					case 4: get=d1.get_front();
						if(get!=-1)
							cout<<"Element is : "<<get<<endl;
					break;		
					case 5: get=d1.get_back();
						if(get!=-1)
							cout<<"Element is : "<<get<<endl;		
					break;
				}
			}while(choice!=6);
		break;
		case 'b': 	do
			{
				cout<<"Enter your choice\n1. Add at start\n2. Add at back\n3. Remove from start\n4. Get element from front\n5. Get element from back\n6. Exit\n";
				cin>>choice;
				switch (choice)
				{
					case 1: cout<<"Enter number : ";
						cin>>num;
						d1.add_front(num);
					break;
					case 2: cout<<"Enter number : ";
						cin>>num;
						d1.add_back(num);
					break;		
					case 3: d1.del_front();
					break;
					case 4: get=d1.get_front();
						if(get!=-1)
							cout<<"Element is : "<<get<<endl;
					break;		
					case 5: get=d1.get_back();
						if(get!=-1)
							cout<<"Element is : "<<get<<endl;		
					break;
				}
			}while(choice!=6);
		break;
		}
	}while(choice2!='c');				
	return 0;
}	
