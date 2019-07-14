#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class chain;

class node
{
	char data;
	node *link;
	friend class chain;
};

class chain
{
	node *start=NULL;
	public:
	void push(char ch)
	{
		node *temp,*q=start;
		temp= new node;
		temp->data=ch;
		temp->link=NULL;
		if(start==NULL)
		{
			start=temp;
		}
		else
		{
			temp->link=q;
			start=temp;
		}
	}
	
	char pop()
	{
		char temp;
		node *q=start;
		temp=q->data;
		start=q->link;
		delete(q);
		return temp;
	}
	
	int preced(char ch)
	{
		if(ch=='+' || ch=='-')
			return 1;
		else if(ch=='*' || ch=='/')
			return 2;
	}				
	
	int check(char exp[],char ans[],int n)
	{
		node *q=start;
		start=NULL;
		int i=0,m=0,j,k;
		while(m<n && exp[i]!='\0')
		{
			q=start;
			if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
			{
				ans[m]=exp[i];
				m++;
			}	
			else
			{
				if(start==NULL)
					push(exp[i]);
				else if(preced(q->data)<preced(exp[i]))
					push(exp[i]);
				else if(preced(q->data)>=preced(exp[i]))
				{
					cout<<"sw\n";
					while(start!=NULL)
					{
						ans[m]=pop();
						m++;
					}
					push(exp[i]);
				}
			}
			i++;
		}
		while(start!=NULL)
		{
			ans[m]=pop();
			m++;
		}	
		cout<<"Postfix expression is :\n";
		for(j=0;j<m;j++)
		{
			cout<<ans[j];
		}	
		cout<<endl;
		return m;
	}
	
	void eval(char ans[],int m)
	{
		int i;
		char val[50],num;
		for(i=0;i<m;i++)
		{
			if((ans[i]>='a' && ans[i]<='z') || (ans[i]>='A' && ans[i]<='Z'))
			{
				cout<<"Enter value(one digit only) for "<<ans[i]<<" : ";
				cin>>val[i];
			}
			else
			{
				val[i]=ans[i];
			}
		}
		for(i=0;i<m;i++)
		{
			if(val[i]!='+' && val[i]!='-' && val[i]!='/' && val[i]!='*')
				push(val[i]-'0');
			else
			{
				int val1,val2;
				val1=pop();
				val2=pop();
				switch(val[i])
				{
					case '+': push(val2+val1);
					break;
					case '-': push(val2-val1);
					break;
					case '*': push(val2*val1);
					break;
					case '/': push(val2/val1);
					break;
				}
			}
		}
		cout<<"Evaluation of this expression is : "<<(int)pop()<<endl;
	}				
};

int main()
{
	int i,n,m;
	char exp[50],ans[50];
	chain list1,list2;
	cout<<"Enter expression :\n";
	cin>>exp;
	n=strlen(exp);
	m=list1.check(exp,ans,n);
	list2.eval(ans,m);
	return 0;
}	
