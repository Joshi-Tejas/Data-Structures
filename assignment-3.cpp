//author:Tejas Joshi
//roll no: 6047
//date:17/07/2017

#include<iostream>
#include<string>
using namespace std;

class str
{
	private:
		string s1;
	public:	
	void getstr()
	{
		cout<<"enter the string.\n";
		cin>>s1;
	}
	void freq()
	{
		int n,i,j,count;
		n=s1.length();
		int frq[n],cnt[n];
		for(i=0;i<n;i++)
		{
			count=0;
			for(j=0;j<n;j++)
			{
				if(s1[i]==s1[j])
				{
					count++;
				}
			}
			frq[i]=count;
		}
		for(i=0;i<n;i++)
		{
			
		for(i=0;i<n;i++)
		{
			cout<<"frequency of "<<s1[i]<<" is:"<<frq[i]<<endl;
		}	 		
	}
}	
	void del()
	{
		int i,a,b;
		cout<<"enter start and length for extraction the characters.\n";
		cin>>a>>b;
		for(i=a-1;i<a+b-1;i++)
		{
			cout<<s1[i];
		}
		cout<<endl; 
	}
	void delc()
	{
	 	int i,n;
	 	n=s1.length();
		char a;
		cout<<"enter a charecter.\n";
		cin>>a;
		cout<<"string after removal of charecter.\n";
		for(i=0;i<n;i++)
		{
			if(s1[i]!=a)
				cout<<s1[i];
		}
		cout<<endl;
	}				
	void replace()
	{
		int i,n,n1,n2,k,j,count=0;
		string old,str1;
		cout<<"enter substring to replace.\n";
		cin>>old;
		cout<<"enter new string to replace.\n";
		cin>>str1;
		n=s1.length();
		n1=old.length();
		n2=str1.length();
		for(i=0;i<n;i++)
		{
			j=0;
			if(s1[i]==old[j])
			{
				for(k=0;k<n1;k++)
				{
					if(s1[i+k]==old[k])
						count++;
				}
				if(count==n1)
				{
					cout<<str1;
					i=i+n1-1;
				}
			}
			else
				cout<<s1[i];	
		}
		cout<<endl;			
	}					
	void pal()
	{
		int n,i,flag=0;
		n=s1.length();
		for(i=0;i<n;i++)
		{
			if(s1[i]!=s1[n-i-1])
				flag=1;	
		}
		if(flag==0)
			cout<<"its is a palindrome.\n";
		else
			cout<<"its not a palindrome.\n";
	}
};	
int main()
{
	str s;
	s.getstr();
	s.freq();
	s.del();
	s.delc();
	s.pal();
	s.replace();
	return 0;
}		
