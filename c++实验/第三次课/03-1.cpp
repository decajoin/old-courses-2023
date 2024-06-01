#include <iostream>
using namespace std;

int main()
{
	int i, dimn, num, matrix[100];
	cout<<"Please input the dimension of the matrix: ";
	cin>>dimn;
	cout<<"Please input the elements of the matrix: ";
	for(i=0;i<dimn*dimn;i++) cin>>matrix[i];
	cout<<"The original matrix you input is:" << endl;
	for(i=0;i<dimn*dimn;i++)
	{
		cout << matrix[i] << " ";
		if ((i + 1) % dimn == 0) cout << endl;
	}

	cout<<endl<<"Please input the number that will multiply the matrix:";
	cin>>num;
	cout<<"The matrix multiplied by the number is:" << endl;
	for(i=0;i<dimn*dimn;i++)
	{
		matrix[i] *= num;
		cout << matrix[i] << " ";
		if ((i + 1) % dimn == 0) cout << endl;	
	}
	cout<<endl;
}

