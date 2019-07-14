#include<iostream>
using namespace std;

void toop(float arr[],int n);
void display(float arr[],int n);

void bubble(float arr[],int n)
{
	int i,j;
	float temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}	

void select(float arr[],int n)
{
	int i,j,index;
	float key;
	for(i=0;i<n-1;i++)
	{
		key=arr[i];
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<key)
			{
				key=arr[j];
				index=j;
			}	
		}
		arr[index]=arr[i];
		arr[i]=key;
	}
}		

void display(float arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void top(float arr[],int n)
{
	int i=0,m;
	if(n<5)
		m=n;
	else
		m=5;
	i=n-1;	
	while(m>0)
	{
		cout<<arr[i]<<" ";
		i--;
		m--;
	}
	cout<<endl;
}

int main()
{
	int i,n,choice;
	float per[50];
	cout<<"Enter number of students : ";
	cin>>n;
	cout<<"Enter percentage\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter for student "<<i+1<<" : ";
		cin>>per[i];
	}
	do
	{
		cout<<"Enter your choice\n1. Bubble sort\n2. Selection sort\n3. Display\n4. Exit with displaying top scores\n";
		cin>>choice;
		switch (choice)
		{
			case 1: bubble(per,n);
			break;
			case 2: select(per,n);
			break;
			case 3: display(per,n);
			break;
		}
	}while(choice!=4);
	cout<<"Top students percentage are :\n";
	top(per,n);
	return 0;
}			
