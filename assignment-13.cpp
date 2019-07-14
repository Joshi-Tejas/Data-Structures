#include<iostream>
using namespace std;

void display(float arr[],int n);
void shell(float arr[],int n);

void insert(float arr[],int n)
{
	int i,j;
	float key;
	for(j=1;j<n;j++)
	{
		key=arr[j];
		i=j-1;
		while(i>=0 && arr[i]>key)
		{
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}		
}

void shell(float arr[],int n)
{
	int i,j,gap;
	float temp;
	for(gap=n/2;gap>0;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			temp=arr[i];
			j=i;
			while(j>=gap && arr[j-gap]>temp)
			{
				arr[j]=arr[j-gap];
				j=j-gap;
			}
			arr[j]=temp;
		}
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
		cout<<"Enter your choice\n1. Insertion sort\n2. Shell sort\n3. Display\n4. Exit with displaying top scores\n";
		cin>>choice;
		switch (choice)
		{
			case 1: insert(per,n);
			break;
			case 2: shell(per,n);
			break;
			case 3: display(per,n);
			break;
		}
	}while(choice!=4);
	cout<<"Top students percentage are :\n";
	top(per,n);
	return 0;
}			
