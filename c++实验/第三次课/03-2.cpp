#include <iostream>
using namespace std;
int main()
{
	int i, j, d1, d2, matrix[100][100];
	cout<<"Please input two dimensions of the matrix: " ;
	cin>>d1>>d2;
	cout<<"Please input the elements of the matrix: " ;
	for (i = 0; i < d1; i++)
	{
		for (j = 0; j < d2; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout<<"The original matrix you input is:" << endl;
	for (i = 0; i < d1; i++)
	{
		for (j = 0; j < d2; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout<<"The transposed matrix is:"<<endl;
	for(j=0;j<d2;j++)
	{
		for(i=0;i<d1;i++)
		{
			cout<<matrix[i][j]<<"  "; 
		}
		cout<<endl;
	}
}

