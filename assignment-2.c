//author:tejas joshi
//date:08/08/2017
#include<stdio.h>

int a,b,m,n;

void upper(float matrix1[a][b],float matrix2[m][n]);
void display(float matrix1[a][b],float matrix2[m][n]);
void diagonal(float matrix1[a][b],float matrix2[m][n]);
void transpose(float matrix1[a][b],float matrix2[m][n]);
void addition(float matrix1[a][b],float matrix2[m][n]);
void subtraction(float matrix1[a][b],float matrix2[m][n]);
void multi(float matrix1[a][b],float matrix2[m][n]);

int main()
{
	int choice,i,j;
	printf("Enter rows and columns for matrix 1 : ");
	scanf("%d %d",&a,&b);
	float matrix1[a][b];
	printf("Enter elements of matrix 1 row by row\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("Enter for data %d, %d: ",i,j);
			scanf("%f",&matrix1[i][j]);
		}
	}		
	printf("Enter rows and columns for matrix 2 : ");
	scanf("%d %d",&m,&n);
	float matrix2[m][n];
	printf("Enter elements of matrix 2 row by row\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter for data %d, %d: ",i,j);
			scanf("%f",&matrix2[i][j]);
		}
	}
	printf("\nYou entered matrices :\n");
	display(matrix1,matrix2);
	do
	{
		printf("\nEnter your choice\n1. Find upper triangular or not for matrix 1 and 2\n");
		printf("2. Find sum of diagonal elements of matrix 1 and 2\n");
		printf("3. Find transpose of matrix 1 and 2\n4. Addition\n5. Subtraction\n6. Multiplication\n7. Exit\n");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1: upper(matrix1,matrix2);
			break;
			case 2: diagonal(matrix1,matrix2);
			break;
			case 3: transpose(matrix1,matrix2);
			break;
			case 4: addition(matrix1,matrix2);
			break;
			case 5: subtraction(matrix1,matrix2);
			break;
			case 6: multi(matrix1,matrix2);
			break;
		}
	}while(choice!=7);
	return 0;
}

void display(float matrix1[a][b],float matrix2[m][n])
{
	int i,j;
	printf("First matrix :\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("%.1f   ",matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\nsecond matrix :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%.1f   ",matrix2[i][j]);
		}
		printf("\n");
	}
}		

void upper(float matrix1[a][b],float matrix2[m][n])
{
	int flag=0,i,j;
	if(a!=b)
		printf("The matrix 1 is not square matrix, hence can not find.\n");
	else
	{
		for(i=1;i<a;i++)
		{
			for(j=0;j<i;j++)
			{
				if(matrix1[i][j]!=0)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
			printf("The matrix 1 IS upper triangular matrix\n");
		else
			printf("The matrix 1 is NOT upper triangular matrix\n");
	}
	flag=0;
	if(m!=n)
		printf("The matrix 2 is not square matrix, hence can not find.\n");
	else
	{
		for(i=1;i<m;i++)
		{
			for(j=0;j<i;j++)
			{
				if(matrix2[i][j]!=0)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
			printf("The matrix 2 IS upper triangular matrix\n");
		else
			printf("The matrix 2 is NOT upper triangular matrix\n");
	}
}			
					
void diagonal(float matrix1[a][b],float matrix2[m][n])
{
	int i,sum=0;
	if(a!=b)
		printf("Can not find because matrix 1 is not square matrix\n");
	else
	{
		for(i=0;i<a;i++)
		{
			sum=sum+matrix1[i][i];
		}
		printf("Sum of diagonal elements of matrix 1 is : %d\n",sum);
	}
	sum=0;
	if(m!=n)
		printf("Can not find because matrix 2 is not square matrix\n");
	else
	{
		for(i=0;i<m;i++)
		{
			sum=sum+matrix2[i][i];
		}
		printf("Sum of diagonal elements of matrix 2 is : %d\n",sum);
	}
	
}

void transpose(float matrix1[a][b],float matrix2[m][n])
{
	int i,j;
	float mat1[b][a],mat2[n][m];
	for(i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
		{
			mat1[i][j]=matrix1[j][i];
		}
	}
	printf("The transpose of matrix 1 is ;\n");
	for(i=0;i<b;i++)
	{
		for(j=0;j<a;j++)
		{
			printf("%.1f   ",mat1[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			mat2[i][j]=matrix2[j][i];
		}
	}
	printf("The transpose of matrix 2 is ;\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%.1f   ",mat2[i][j]);
		}
		printf("\n");
	}
}	

void addition(float matrix1[a][b],float matrix2[m][n])
{
	int i,j;
	if(a!=m || b!=n)
		printf("the addition is not possible as matrices are not of same order\n");
	else if(a==m && b==n)
	{
		printf("Addition of these matrices is :\n");
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				printf("%.1f   ",matrix1[i][j]+matrix2[i][j]);
			}
			printf("\n");
		}
	}
}				

void subtraction(float matrix1[a][b],float matrix2[m][n])
{
	int i,j;
	if(a!=m || b!=n)
		printf("the subtraction is not possible as matrices are not of same order\n");
	else if(a==m && b==n)
	{
		printf("subtraction of these matrices is :\n");
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				printf("%.1f   ",matrix1[i][j]-matrix2[i][j]);
			}
			printf("\n");
		}
	}
}

void multi(float matrix1[a][b],float matrix2[m][n])
{
	int i,j,k;
	float sum=0.0;
	if(b!=m)
		printf("The multiplication is not possible\n");
	else if(b==m)
	{
		float matrix[a][n];
		for(k=0;k<a;k++)
		{
			for(i=0;i<n;i++)
			{
				sum=0.0;
				for(j=0;j<n;j++)
				{
					sum=sum+matrix1[k][j]*matrix2[j][i];
				}
				matrix[k][i]=sum;
			}
		}
		printf("The multiplied matrix is :\n");
		for(i=0;i<a;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%.1f   ",matrix[i][j]);
			}
			printf("\n");
		}
	}
}				

/*output of this program :

[exam@localhost S.E. Comp_F150070181]$ gcc assignment-2.c
[exam@localhost S.E. Comp_F150070181]$ ./a.out
Enter rows and columns for matrix 1 : 2 3
Enter elements of matrix 1 row by row
Enter for data 0, 0: 1
Enter for data 0, 1: 2
Enter for data 0, 2: 3
Enter for data 1, 0: 4
Enter for data 1, 1: 5
Enter for data 1, 2: 6
Enter rows and columns for matrix 2 : 3 3
Enter elements of matrix 2 row by row
Enter for data 0, 0: 1
Enter for data 0, 1: 2
Enter for data 0, 2: 3
Enter for data 1, 0: 0
Enter for data 1, 1: 4
Enter for data 1, 2: 5
Enter for data 2, 0: 0
Enter for data 2, 1: 0
Enter for data 2, 2: 6

You entered matrices :
First matrix :
1.0   2.0   3.0   
4.0   5.0   6.0   

second matrix :
1.0   2.0   3.0   
0.0   4.0   5.0   
0.0   0.0   6.0   

Enter your choice
1. Find upper triangular or not for matrix 1 and 2
2. Find sum of diagonal elements of matrix 1 and 2
3. Find transpose of matrix 1 and 2
4. Addition
5. Subtraction
6. Multiplication
7. Exit
1
The matrix 1 is not square matrix, hence can not find.
The matrix 2 IS upper triangular matrix

Enter your choice
1. Find upper triangular or not for matrix 1 and 2
2. Find sum of diagonal elements of matrix 1 and 2
3. Find transpose of matrix 1 and 2
4. Addition
5. Subtraction
6. Multiplication
7. Exit
2
Can not find because matrix 1 is not square matrix
Sum of diagonal elements of matrix 2 is : 11

Enter your choice
1. Find upper triangular or not for matrix 1 and 2
2. Find sum of diagonal elements of matrix 1 and 2
3. Find transpose of matrix 1 and 2
4. Addition
5. Subtraction
6. Multiplication
7. Exit
3
The transpose of matrix 1 is ;
1.0   4.0   
2.0   5.0   
3.0   6.0   
The transpose of matrix 2 is ;
1.0   0.0   0.0   
2.0   4.0   0.0   
3.0   5.0   6.0   

Enter your choice
1. Find upper triangular or not for matrix 1 and 2
2. Find sum of diagonal elements of matrix 1 and 2
3. Find transpose of matrix 1 and 2
4. Addition
5. Subtraction
6. Multiplication
7. Exit
4
the addition is not possible as matrices are not of same order

Enter your choice
1. Find upper triangular or not for matrix 1 and 2
2. Find sum of diagonal elements of matrix 1 and 2
3. Find transpose of matrix 1 and 2
4. Addition
5. Subtraction
6. Multiplication
7. Exit
5
the subtraction is not possible as matrices are not of same order

Enter your choice
1. Find upper triangular or not for matrix 1 and 2
2. Find sum of diagonal elements of matrix 1 and 2
3. Find transpose of matrix 1 and 2
4. Addition
5. Subtraction
6. Multiplication
7. Exit
6
The multiplied matrix is :
1.0   10.0   31.0   
4.0   28.0   73.0   

Enter your choice
1. Find upper triangular or not for matrix 1 and 2
2. Find sum of diagonal elements of matrix 1 and 2
3. Find transpose of matrix 1 and 2
4. Addition
5. Subtraction
6. Multiplication
7. Exit
7

*/				
