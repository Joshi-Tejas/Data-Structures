//author: Tejas Joshi
//date: 28/08/2017

#include<stdio.h>
#include<string.h>

void freq(char str[],int x);
void del(char str[],int x);
void delc(char str[],int x);				//function prototypes
void replace(char str[],int x);
void pal(char str[],int x);

int main()
{
	int i,n;
	char str[40];
	printf("enter the string.\n");
	scanf("%s",str);
	n=strlen(str);
	freq(str, n);
	del(str, n);
	delc(str, n);							//function calls
	replace(str, n);
	pal(str, n);
	return 0;
}	

//function to obtain frequency of charecters in string
void freq(char str[],int x)
	{
		int i,j,count;
		int frq[x],cnt[x];
		for(i=0;i<x;i++)
		{
			count=0;
			for(j=0;j<x;j++)
			{
				if(j<i && str[i]==str[j])
				{
					break;
				}
				if(str[i]==str[j])
				{
					count++;
				}
				if(j==x-1)
					printf("frequency of %c is: %d\n",str[i],count);	
			}
			
		}
}	

//function to extract a substring 
void del(char str[],int x)
	{
		int i,a,b;
		printf("enter start and length for extraction the characters.\n");
		scanf("%d%d",&a,&b);
		for(i=a-1;i<a+b-1;i++)
		{
			printf("%c",str[i]);
		}
		printf("\n"); 
	}

//function to delete a character from string	
void delc(char str[],int x)
	{
	 	int i,n;
		char a;
		printf("enter a charecter.\n");
		scanf(" %c",&a);
		printf("string after removal of character.\n");
		for(i=0;i<x;i++)
		{
			if(str[i]!=a)
				printf("%c",str[i]);
		}
		printf("\n");
	}	

//function to replace a substring from original string to input string	
void replace(char str[],int x)
{
	int a,b,i,k,j,count=0;
	char old[40],new[40]; 
	printf("enter the substring to replace\n");
	scanf("%s",old);
	printf("enter new string to replace.\n");
	scanf("%s",new);
	a=strlen(old);
	b=strlen(new);
	if(a>1)
	{
	for(i=0;i<x;i++)
		{
			j=0;
			if(str[i]==old[j])
			{
				for(k=0;k<a;k++)
				{
					if(str[i+k]==old[k])
						count++;
				}
				if(count==a)
				{
					printf("%s",new);
					i=i+a-1;
				}
				else
					printf("%c",str[i]);
			}
			else
				printf("%c",str[i]);	
		}
		printf("\n");
	}
	else if(a==1)
	{
		for(i=0;i<x;i++)
		{
			if(str[i]==new[0])
			{
				printf("%c",str[i]);
			}
			else 
			{
				printf("%c",old[0]);
			}
		}	
			printf("\n");	
	}
							
}		

//function to find out string is palindrome or not
void pal(char str[],int x)
	{
		int i,flag=0;
		for(i=0;i<x;i++)
		{
			if(str[i]!=str[x-i-1])
				flag=1;	
		}
		if(flag==0)
			printf("its is a palindrome.\n");
		else
			printf("its not a palindrome.\n");
	}
	
	
/*output of this program is:
enter the string.
malayalam
frequency of m is: 2
frequency of a is: 4
frequency of l is: 2
frequency of y is: 1
enter start and length for extraction the characters.
1
4
mala
enter a charecter.
a
string after removal of character.
mlylm
enter the substring to replace
mala
enter new string to replace.
calm
calmyalam
its is a palindrome.*/
	
