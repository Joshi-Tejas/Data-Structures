//author:tejas joshi
//roll no: 6047
//date:08/07/2017
#include<stdio.h>
#include<string.h>

struct student
{
	int marks;
	char name[20];
};	

void average(int, struct student *s);
void absent(int, struct student *s);
void max(int, struct student *s);					//function prototypes
void min(int, struct student *s);	
void maximum(int, struct student *s);

int main()
{
	int n,i;
	printf("enter number of students.\n");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("\nenter name and marks(ab=-1) of the student %d:",i+1);
		scanf("%s %d",s[i].name,&s[i].marks);
	}
	average(n, s);
	absent(n, s);
	max(n, s);					//function calls
	min(n, s);
	maximum(n, s);
	return 0;
}		

//function to calculate average of the students 
void average(int num, struct student *p)
{
	int i;
	float avg,sum=0,flag=0;
	for(i=0;i<num;i++)
	{
		if((p)->marks!=-1)
		{
			sum=sum+(p)->marks;
			flag++;
		}
		p++;	
	}
	avg=(sum/flag);	
	printf("average of the students is:%f\n",avg);
}	

//function to give number of absent students
void absent(int num, struct student *p)
{
	int i,count=0;
	for(i=0;i<num;i++)
	{
		if((p)->marks==-1)
		{
			count++;
		}
		p++;	
	}		
	printf("number of absent students are:%d\n",count);
}	


void max(int num, struct student *p)
{
	int i,largest;
	char *prn[num];
	largest=(p)->marks;
	for(i=0;i<num;i++)
	{
		if(((p)->marks>largest || (p)->marks==largest) && (p)->marks!=-1)
		{
			largest=(p)->marks;
			prn[num]=(p)->name;
		}
		p++;
	}		
	printf("maximum marks are:%d\n",largest);
}

void min(int num, struct student *p)
{
	int i,smallest;
	char *pro[num];
	smallest=(p)->marks;
	for(i=0;i<num;i++)
	{
		if(((p)->marks<smallest || (p)->marks==smallest) && ((p)->marks!=-1))
		{
			smallest=(p)->marks;
			pro[num]=(p)->name;
		}
		p++;
	}		
	printf("minimum marks are:%d\n",smallest);
}

void maximum(int num, struct student *p)
{	
	int arr[num];
	int freq[num],i,j,count=1,largest;
	for(i=0;i<num;i++)
	{	
		arr[i]=p->marks;
		p++;
	}
	for(i=0;i<num;i++)
	{	
		count=1;
		for(j=i+1;j<num;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
			}	
		}
			freq[i]=count;
		
	}
	largest=freq[0];
	for(i=0;i<num;i++)
	{
		if((freq[i]>largest || freq[i]==largest) && freq[i]!=0 && freq[i]!=-1)
		{
			largest=freq[i];
		}
	}
	printf("marks are scored by most:%d of the students\n",largest);
}	


/*output of the program is:
enter number of students.
5

enter name and marks(ab=-1) of the student 1:rajesh
20

enter name and marks(ab=-1) of the student 2:mahesh
24

enter name and marks(ab=-1) of the student 3:chintan       
24

enter name and marks(ab=-1) of the student 4:rohan
-1

enter name and marks(ab=-1) of the student 5:raj
19
average of the students is:21.750000
number of absent students are:1
maximum marks are:24
minimum marks are:19
marks are scored by most:2 of the students*/
					
