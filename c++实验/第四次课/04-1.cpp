#include<iostream>
#include<cstdlib>
using namespace std;

void InputMatrix(int d1, int d2, int** matrix)
{
	cout << "请输入矩阵元素：";
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			cin >> matrix[i][j];
		}
	}
}

void OutputMatrix(int d1, int d2, int** matrix)
{
	cout << "矩阵内容：" << endl;
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void MultiplyMatrix(int d1, int d2, int** matrix, int scalar)
{
	// 为了保证每次数乘都是在原始矩阵的基础上，我们必须要新建一个备份矩阵
	// 备份矩阵上面进行操作，输出备份矩阵后对其进行销毁
	// 数乘矩阵，将备份矩阵的每个元素乘以标量
	int** backupMatrix = (int**)malloc(sizeof(int*) * d1);
	
	for (int i = 0; i < d1; i++) {
		backupMatrix[i] = (int*)malloc(sizeof(int) * d2);
	}
	
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			backupMatrix[i][j] = matrix[i][j];
			backupMatrix[i][j] *= scalar;
		}
	}
	
	// 输出数乘结果
	cout << "数乘后的矩阵：" << endl;
	OutputMatrix(d1, d2, backupMatrix);
	
	// 释放备份矩阵的内存
	for (int i = 0; i < d1; i++) {
		free(backupMatrix[i]);
	}
	free(backupMatrix);
}

int main()
{
	int i, d1, d2;
	cout << "请输入矩阵的行数和列数：";
	cin >> d1 >> d2;
	int** matrix = (int**)malloc(sizeof(int*) * d1);
	
	for (i = 0; i < d1; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * d2);
	}
	
	if (matrix == NULL) {
		cout << "动态分配空间失败，请检查程序！" << endl;
		exit(1);
	}
	
	InputMatrix(d1, d2, matrix);
	cout << "---------------------------------------------------------" << endl;
	OutputMatrix(d1, d2, matrix);
	
	int scalar;
	char flag = 'y';
	while (tolower(flag) == 'y') {
		cout << "---------------------------------------------------------" << endl;
		cout << "请输入一个标量值：";
		cin >> scalar;
		
		MultiplyMatrix(d1, d2, matrix, scalar);
		
		cout << "是否继续进行数乘操作?(Y/N)";
		cin >> flag;
	}
	
	for (i = 0; i < d1; i++) {
		free(matrix[i]);
	}
	free(matrix);
	
	return 0;
}

