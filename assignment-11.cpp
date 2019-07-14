#include<iostream>
using namespace std;

class stud
{
	int roll[50];
	public:
	
	int getdata()
	{
		int i,n;
		cout<<"Enter number of students present : ";
		cin>>n;
		cout<<"Enter roll number of present students :\n";
		for(i=0;i<n;i++)
		{
			cin>>roll[i];
		}
		return n;
	}
	
	int linear(int num,int r)
	{
		int i;
		for(i=0;i<num;i++)
		{
			if(roll[i]==r)
			{
				cout<<"Roll number "<<r<<" was PRESENT\n";        
				return i;
			}
		}
		cout<<"Roll number was ABSENT\n";
		return -1;
	}
	
	int sentinel(int num,int r)
	{
		int i=0;
		while(--num)
		{
			if(roll[i]==r)
			{
				cout<<"Roll number "<<r<<" was PRESENT\n";
				return i;
			}	
			i++;	
		}
		cout<<"Roll number was ABSENT\n";
		return -1;
	}
	
	int binary(int r,int p,int q)
	{
		if(q>=p)
		{
			int mid;
			mid=p+(q-p)/2;
			if(roll[mid]==r)
			{
				cout<<"Roll number "<<roll[mid]<<" was PRESENT\n";
				return mid;
			}	
			if(roll[mid]>r)
				return binary(r,p,mid-1);
			return binary(r,mid+1,q);
		}
		cout<<"Roll number was ABSENT\n";
		return -1;
	}
	
	int fibonacci(int r,int n)
	{
		int i,offset;
		int fib1 = 0;
		int fib2 = 1;
		int fibM = fib2 + fib1;
		while (fibM < n)
		{
			fib2 = fib1;
			fib1 = fibM;
			fibM  = fib2 + fib1;
		}
		offset = -1;
		while (fibM > 1)
		{
			i=min(offset+fib2,n-1);
			if (roll[i]<r)
			{
				fibM=fib1;
				fib1=fib2;
				fib2=fibM-fib1;
				offset=i;
			}
			else if(roll[i]>r)
			{
				fibM=fib2;
				fib1=fib1-fib2;
				fib2=fibM-fib1;
			}
			else 
			{
				cout<<"Roll number "<<r<<" was PRESENT\n";
				return i;
			}	
	    	}
		if(fib1 && roll[offset+1]==r)
		{	
			cout<<"Roll number "<<r<<" was PRESENT\n";
			return (offset+1);
		}
	cout<<"Roll number was ABSENT\n";		
	return -1;
	}
	
	void sort(int n)
	{
		int i,j,temp;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			{
				if(roll[i]>roll[i+1])
				{
					temp=roll[i];
					roll[i]=roll[i+1];
					roll[i+1]=temp;
				}
			}
		}
	}
	
	int min(int x,int y)
	{
		if(x<=y)
			return x;
		else
			return y;
	}								
};

int main()
{
	int n,roll,choice1,ret;
	char choice2;
	stud list;
	n=list.getdata();
	do
	{
		cout<<"Enter choice\n1. Search\n2. Exit\n";
		cin>>choice1;
		switch (choice1)
		{
			case 1: cout<<"Enter roll number to search : ";
				cin>>roll;
				cout<<"Enter choice\na. Linear search\nb. Sentinel search\nc. Binary search\nd. Fibonacci search\ne. Exit\n";
				cin>>choice2;
				switch (choice2)
				{
					case 'a': ret=list.linear(n,roll);
						  if(ret!=-1)
							cout<<"Roll number is found at "<<ret<<" index.\n\n";
					break;
					case 'b': ret=list.sentinel(n,roll);
						  if(ret!=-1)
							cout<<"Roll number is found at "<<ret<<" index.\n\n";
					break;
					case 'c': list.sort(n);
						  ret=list.binary(roll,0,n);
						  if(ret!=-1)
							cout<<"Roll number is found at "<<ret<<" index.\n\n";
					break;
					case 'd': list.sort(n);
						  ret=list.fibonacci(roll,n);
						  if(ret!=-1)	
						  	cout<<"Roll number is found at "<<ret<<" index.\n\n";
					break;	  								
					default: cout<<"Wrong choice!\n\n";
				}
			break;
		}
	}while(choice1!=2);							
	return 0;
}
