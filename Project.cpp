/* Names : Shabih Ul Hasnain & Muhammad Ali Mushtaq 
Roll No.s : 22i-2220 & 22i-2185
Section : C */
#include <iostream>
using namespace std;
void display(int,int);
void symmetric(int,int,int);
void identity(int,int,int);
void determinant(int,int,int);
void adjoint(int,int,int);
void inverse(int,int,int);
void solution(int,int,int);

int main()
{
	short n,p=0,N;
	while (true)
	{
		cout<<"Enter the order of a matrix"<<endl;
		cin>>N;
		if (N==2 || N==3)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	short rows=N;
	short columns=N;
	
	do
	{
		cout<<"1) Display a matrix"<<endl;
		cout<<"2) Check whether the entered matrix is symmetric matrix or not"<<endl;
		cout<<"3) Check whether the entered matrix is identity matrix or not"<<endl;
		cout<<"4) Determine the determinant of matrix"<<endl;
		cout<<"5) Determine the adjoint of matrix"<<endl;
		cout<<"6) Determine the inverse of matrix"<<endl;
		cout<<"7) Determine the solution of matrix"<<endl;
		cout<<endl;
		cout<<"Enter the number of the task you want to perform (1-7), enter 8 to exit"<<endl;
		cin>>n;
		
		if (n==1)
		{
			display(rows,columns);
		}	
		
		else if (n==2)
		{
			symmetric(rows,columns,N);
		}
		
		else if (n==3)
		{
			identity(rows,columns,N);
		}
		
		else if (n==4)
		{
			determinant(rows,columns,N);
		}
		
		else if (n==5)
		{
			adjoint(rows,columns,N);
		}
		
		else if (n==6)
		{
			inverse(rows,columns,N);
		}
		
		else if (n==7)
		{
			solution(rows,columns,N);
		}
		
		else if (n==8)
		{
			cout<<"The program was exited!"<<endl;
			break;
		}
		
		else
		{
		cout<<"Entered number was not between (1-8)!"<<endl;
		cout<<endl;
		}	
	}
	while (p==0);
	return 0;
}

void display(int x,int y)
{
	int a[x][y];
	cout<<"Enter a matrix to display its contents: "<<endl;
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void symmetric(int x,int y,int q)
{
	int a[x][y];
	int trans[y][x];
	int count=0;
	cout<<"Enter a matrix to check if its symmetric or not: "<<endl;
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for (int j=0;j<y;j++)
			{
				for (int i=0;i<x;i++)
				{
					trans[j][i]=a[i][j];
				}
			}
			for (int i=0;i<x;i++)
			{
				for (int j=0;j<y;j++)
				{
					if (trans[i][j]==a[i][j])
					{
						count++;
					}
				}
			}
			if (q==2)
			{
				if (count==4)
				{
					cout<<"The matrix is symmetric"<<endl;
				}
				else
				{
					cout<<"The matrix is not symmetric"<<endl;
				}
			}
			else if (q==3)
			{
				if (count==9)
				{
					cout<<"The matrix is symmetric"<<endl;
				}
				else
				{
					cout<<"The matrix is not symmetric"<<endl;
				}
			}
}

void identity(int x,int y,int q)
{
	int count = 0;
	int a[x][y];
	cout<<"Enter a matrix to check if its identity or not: "<<endl;
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			cin>>a[i][j];
		}
	}
	
			for ( int i=0; i<x; i++ )
			{
				for ( int j=0; j<y; j++ )
				{
					if (i == j )
					{
						if (a[i][j] == 1)
						{
							count++;
						}
					}
					else
					{
						if (a[i][j]== 0)
						{
							count++;
						}
					}
				}
			}
			
			if ( q==2 )
			{
				if ( count == 4 )
				{
					cout << "The matrix is an identity matrix"<<endl;
				}
				else
				{
					cout << "The matrix is not an identity matrix"<<endl;
				}
			}
			if ( q==3 )
			{
				if ( count == 9)
				{
					cout << "The matrix is an identity matrix"<<endl;
				}
				else
				{
					cout << "The matrix is not an identity matrix"<<endl;
				}
			}
}

void determinant(int x,int y,int q)
{
	int a,b,c,d;
	int A[x][y];
	cout<<"Enter a matrix to check its determinant: "<<endl;
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			cin>>A[i][j];
		}
	}
	
			if (q==2)
			{
				a=(A[0][0]*A[1][1])-(A[0][1]*A[1][0]);
				cout<<"Determinant of the entered matrix is: "<<a<<endl;
			}
			else if(q==3)
			{
	 			b=A[0][0] * ((A[1][1]*A[2][2])-(A[1][2]*A[2][1]));
	 			c=A[0][1] * ((A[1][0]*A[2][2])-(A[1][2]*A[2][0]));
	 			d=A[0][2] * ((A[1][0]*A[2][1])-(A[1][1]*A[2][0]));
				a=b-c+d;
				cout<<"Determinant of the entered matrix is: "<<a<<endl;
			}
}

void adjoint(int x,int y,int q)
{
	int array[x][y];
	int array1[x][y];
	int cofac[x][y];
	int trans[x][y];
	cout<<"Enter a matrix to find its adjoint: "<<endl;
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			cin>>array[i][j];
		}
	}
	//we introduced another array and compare its elements with the main array
	if(q==2)
	{
		array1[0][0]=(array[0][0]);
		array1[1][1]=(array[1][1]);
		array[0][0]=(array1[1][1]);
		array[1][1]=(array1[0][0]);
		array[0][1]=-(array[0][1]);
		array[1][0]=-(array[1][0]);
		cout<<"Adjoint of the matrix is: "<<endl;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				cout<<array[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	if (q==3)
	{
	//we first find its cofactor
	cofac[0][0]=+((array[1][1]*array[2][2])-(array[1][2]*array[2][1]));
	cofac[0][1]=-((array[1][0]*array[2][2])-(array[1][2]*array[2][0]));
	cofac[0][2]=+((array[1][0]*array[2][1])-(array[1][1]*array[2][0]));
	cofac[1][0]=-((array[0][1]*array[2][2])-(array[0][2]*array[2][1]));
	cofac[1][1]=+((array[0][0]*array[2][2])-(array[0][2]*array[2][0]));		
	cofac[1][2]=-((array[0][0]*array[2][1])-(array[0][1]*array[2][0]));
	cofac[2][0]=+((array[0][1]*array[1][2])-(array[0][2]*array[1][1]));
	cofac[2][1]=-((array[0][0]*array[1][2])-(array[0][2]*array[1][0]));
	cofac[2][2]=+((array[0][0]*array[1][1])-(array[0][1]*array[1][0]));
	//after that we then find its transpose

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            trans[j][i] = cofac[i][j];	
        }
    }
		
	//then we get the adjoint
	cout<<"Adjoint of the matrix is: "<<endl;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				cout<<trans[i][j]<<" ";
			}
			cout<<endl;
		}	
	}
}

void inverse(int x,int y,int q)
{
	float array[x][y];
	float array1[x][y];
	float array2[x][y];
	float a,b,c,d;
	cout<<"Enter a matrix to find its inverse: "<<endl;
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			cin>>array[i][j];
		}
	}
	
	if (q==2)
	{
	//determinant of matrix
		a=(array[0][0]*array[1][1])-(array[0][1]*array[1][0]);
		
	//adjoint of matrix through swaping
		array1[0][0]=(array[1][1]);
		array1[1][1]=(array[0][0]);
		array1[0][1]=-(array[0][1]);
		array1[1][0]=-(array[1][0]);
		
	//inverse of matrix
	array2[0][0]=array1[0][0]/a;
	array2[0][1]=array1[0][1]/a;
	array2[1][0]=array1[1][0]/a;
	array2[1][1]=array1[1][1]/a;
	
	cout<<"Inverse of the matrix is: "<<endl;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				cout<<array2[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	else if(q==3)
	{
		//determinant of entered matrix
		b=array[0][0] * ((array[1][1]*array[2][2])-(array[1][2]*array[2][1]));
		c=array[0][1] * ((array[1][0]*array[2][2])-(array[1][2]*array[2][0]));
		d=array[0][2] * ((array[1][0]*array[2][1])-(array[1][1]*array[2][0]));
		a=b-c+d;
		
		//adjoint of a matrix
		array1[0][0]=+((array[1][1]*array[2][2])-(array[1][2]*array[2][1]));
		array1[0][1]=-((array[1][0]*array[2][2])-(array[1][2]*array[2][0]));
		array1[0][2]=+((array[1][0]*array[2][1])-(array[1][1]*array[2][0]));
		array1[1][0]=-((array[0][1]*array[2][2])-(array[0][2]*array[2][1]));
		array1[1][1]=+((array[0][0]*array[2][2])-(array[0][2]*array[2][0]));		
		array1[1][2]=-((array[0][0]*array[2][1])-(array[0][1]*array[2][0]));
		array1[2][0]=+((array[0][1]*array[1][2])-(array[0][2]*array[1][1]));
		array1[2][1]=-((array[0][0]*array[1][2])-(array[0][2]*array[1][0]));
		array1[2][2]=+((array[0][0]*array[1][1])-(array[0][1]*array[1][0]));
		//inverse of matrix	
		cout<<"Inverse of the matrix is: "<<endl;
		array2[0][0]=array1[0][0]/a;
		array2[0][1]=array1[0][1]/a;
		array2[0][2]=array1[0][2]/a;
		array2[1][0]=array1[1][0]/a;
		array2[1][1]=array1[1][1]/a;
		array2[1][2]=array1[1][2]/a;
		array2[2][0]=array1[2][0]/a;
		array2[2][1]=array1[2][1]/a;
		array2[2][2]=array1[2][2]/a;
		//transpose of adjoint will taken aswell
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
			cout<<array2[j][i]<<" ";
			}
		cout<<endl;
		}
	}
}

void solution(int x,int y,int q)
{
	float array[x][y];
	float array1[x][y];
	float array2[x][y];
	float array3[x][y];
	float arrayb[x][y];
	float trans[x][y];
	float a,b,c,d;
	
	cout<<"Enter a matrix to find its solution: "<<endl;
	for (int i=0;i<x;i++)
	{
		for (int j=0;j<y;j++)
		{
			cin>>array[i][j];
		}
	}
	
	if (q==2)
	{
	cout<<"Enter a matrix of 2 rows and one column: "<<endl;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<1;j++)
			{
				cout<<"Enter matrix of["<<i+1<<"] and ["<<j+1<<"]"<<endl;
				cin>>arrayb[i][j];
			}
		}
	//determinant of matrix
		a=(array[0][0]*array[1][1])-(array[0][1]*array[1][0]);
	//adjoint of matrix through swaping
		array1[0][0]=(array[0][0]);
		array1[1][1]=(array[1][1]);
		array[0][0]=(array1[1][1]);
		array[1][1]=(array1[0][0]);
		array[0][1]=-(array[0][1]);
		array[1][0]=-(array[1][0]);
	//inverse of matrix
	array2[0][0]=array[0][0]/a;
	array2[0][1]=array[0][1]/a;
	array2[1][0]=array[1][0]/a;
	array2[1][1]=array[1][1]/a;
	//multiplication of an inverse
	array3[0][0]=((array2[0][0]*arrayb[0][0]) + (array2[0][1]*arrayb[1][0]));
	array3[1][0]=((array2[1][0]*arrayb[0][0]) + ( array2[1][1]* arrayb[1][0]));
	cout<<"Inverse of matrix through equation is: "<<endl;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<1;j++)
			{
				cout<<array3[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else if(q==3)
	{	
	cout<<"Enter a matrix of 3 rows and one column: "<<endl;
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<1;j++)
		{
			cout<<"Enter matrix of["<<i+1<<"] and ["<<j+1<<"]"<<endl;
			cin>>arrayb[i][j];
		}
	}
		//determinant of entered matrix
		b=array[0][0] * ((array[1][1]*array[2][2])-(array[1][2]*array[2][1]));
		c=array[0][1] * ((array[1][0]*array[2][2])-(array[1][2]*array[2][0]));
		d=array[0][2] * ((array[1][0]*array[2][1])-(array[1][1]*array[2][0]));
		a=b-c+d;
		
		//adjoint of a matrix
		array1[0][0]=+((array[1][1]*array[2][2])-(array[1][2]*array[2][1]));
		array1[0][1]=-((array[1][0]*array[2][2])-(array[1][2]*array[2][0]));
		array1[0][2]=+((array[1][0]*array[2][1])-(array[1][1]*array[2][0]));
		array1[1][0]=-((array[0][1]*array[2][2])-(array[0][2]*array[2][1]));
		array1[1][1]=+((array[0][0]*array[2][2])-(array[0][2]*array[2][0]));		
		array1[1][2]=-((array[0][0]*array[2][1])-(array[0][1]*array[2][0]));
		array1[2][0]=+((array[0][1]*array[1][2])-(array[0][2]*array[1][1]));
		array1[2][1]=-((array[0][0]*array[1][2])-(array[0][2]*array[1][0]));
		array1[2][2]=+((array[0][0]*array[1][1])-(array[0][1]*array[1][0]));
		//inverse of matrix	
		cout<<"Inverse of the matrix is: "<<endl;
		array2[0][0]=array1[0][0]/a;
		array2[0][1]=array1[0][1]/a;
		array2[0][2]=array1[0][2]/a;
		array2[1][0]=array1[1][0]/a;
		array2[1][1]=array1[1][1]/a;
		array2[1][2]=array1[1][2]/a;
		array2[2][0]=array1[2][0]/a;
		array2[2][1]=array1[2][1]/a;
		array2[2][2]=array1[2][2]/a;
		//transpose of adjoint will taken aswell
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				trans[i][j]=array2[j][i];
			}
		}
	//multiplication of an inverse
	cout<<"Multiplication of a matrix is: "<<endl;
	array3[0][0]=(trans[0][0]*arrayb[0][0] + trans[0][1]*arrayb[1][0] + trans[0][2]*arrayb[2][0]);
	array3[1][0]=(trans[1][0]*arrayb[0][0] + trans[1][1]*arrayb[1][0] + trans[1][2]*arrayb[2][0]);
	array3[2][0]=(trans[2][0]*arrayb[0][0] + trans[2][1]*arrayb[1][0] + trans[2][2]*arrayb[2][0]);
	
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<1;j++)
			{
				cout<<array3[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
