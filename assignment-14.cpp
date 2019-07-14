#include<iostream>
using namespace std;
	
int part(float arr[],int low,int high);
void swap(float *a,float *b);
void printarr(float arr[],int n);
void top(float arr[],int n);

void quick(float arr[],int low,int high)
{
	int p=0;
	if(low<high)
	{
		p=part(arr,low,high);
		quick(arr,low,p-1);
		quick(arr,p+1,high);
	}		
}

int part(float arr[],int low,int high)
{
	int i=0,j;
	float pivot;
	pivot=arr[high];
	i=(low-1);
	for(j=low;j<high;j++)
	{
		if(arr[j]<=pivot)	
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void swap(float *a,float *b)
{
	float temp;
	temp= *a;
	*a= *b;
	*b= temp;
}	

void printarr(float arr[],int n)
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
	float arr[50];
	int i,n;
	cout<<"Enter number of elements : ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter data "<<i+1<<" : ";
		cin>>arr[i];
	}
	quick(arr,0,n-1);	
	cout<<"Sorted array is:\n";
	printarr(arr,n);
	cout<<"Top 5 numbers are :\n";
	top(arr,n);
	return 0;
}	
