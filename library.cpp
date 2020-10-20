#include <iostream>

using namespace std;

class Matrix
{
	public:
		//Data Members
		int r; //number of rows
		int c; //number of columns
		float m[100][100]; //matrix

		//Constructor
		Matrix(int row,int column);

		//Utility functions
		void printMatrix();

		//Member functions
		int *gaussElimination();
		Matrix columnSpace();
		Matrix transpose();
};

Matrix::Matrix(int row,int column)
{
	r=row;
	c=column;
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
		{
			float x;
			cin>>x;
			m[i][j]=x/1.0;
		}
}

void Matrix::printMatrix()
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			// Prints ' ' if j != n-1 else prints '\n'           
          		cout << m[i][j] << " \n"[j == c-1]; 
}

int *Matrix::gaussElimination()
{
	int x_arr[100];
	int *ptr=x_arr;
	for(int i=0;i<c;i++)
		for(int j=i+1;j<r;j++)
		{
			int x=m[j][i]/m[i][i];
			*ptr=x;
			ptr++;
			for(int k=0;k<c;k++)
				m[j][k]=m[j][k]-(x*m[i][k]);
			printMatrix();
			cout<<"\n";
		}
	return x_arr;
}

Matrix Matrix::columnSpace()
{
	gaussElimination();
	int k;
	for(int i=0;i<r;i++)
		if(m[i][i]==0)
		{
			k=i;
			break;
		}
	Matrix out(r,k);
	for(int i=0;i<r;i++)
		for(int j=0;j<k;j++)
		out.m[i][j]=m[i][j];
	return out;
}

Matrix Matrix::transpose()
{
	Matrix out(c,r);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			out.m[j][i]=m[i][j];
	return out;
}

int main()
{
	Matrix m(4,4);
	cout<<"\n";
	m.printMatrix();
	cout<<"\n";
	
	Matrix out=m.transpose();
	out.printMatrix();
	cout<<"\n";
	
	int *y=m.gaussElimination();
	m.printMatrix();
	cout<<"\n";
	
	Matrix out1=m.columnSpace();
	out1.printMatrix();
	return 0;
}
