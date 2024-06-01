#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

void InputMatrix(int d1, int d2, int** matrix) {
	cout << "请输入矩阵元素：" ;
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			cin >> matrix[i][j];
		}
	}
}

void OutputMatrix(int d1, int d2, int** matrix) {
	cout << "矩阵内容：" << endl;
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void TransposeMatrix(int d1, int d2, int** matrix, int** transposedMatrix) {
	cout << "转置后的矩阵：" << endl;
	for (int i = 0; i < d2; i++) {
		for (int j = 0; j < d1; j++) {
			transposedMatrix[i][j] = matrix[j][i];
			cout << transposedMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int i, d1, d2, **matrix, **transposedMatrix;
	char flag = 'y';
	
	while (tolower(flag) == 'y') {
		cout << "请输入矩阵的行数和列数：";
		cin >> d1 >> d2;
		
		// 动态分配内存来表示原始矩阵和转置后的矩阵
		matrix = new int*[d1];
		for (i = 0; i < d1; i++) {
			matrix[i] = new int[d2];
		}
		
		transposedMatrix = new int*[d2];
		for (i = 0; i < d2; i++) {
			transposedMatrix[i] = new int[d1];
		}
		
		if (matrix == NULL || transposedMatrix == NULL) {
			cout << "动态分配空间失败，请检查程序！" << endl;
			exit(1);
		}
		
		InputMatrix(d1, d2, matrix);
		cout << "---------------------------------------------------------" << endl;
		OutputMatrix(d1, d2, matrix);
		TransposeMatrix(d1, d2, matrix, transposedMatrix);
		
		// 释放内存
		for (i = 0; i < d1; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		
		for (i = 0; i < d2; i++) {
			delete[] transposedMatrix[i];
		}
		delete[] transposedMatrix;
		
		cout << "是否继续进行矩阵转置操作?(Y/N)";
		cin >> flag;
	}
	
	return 0;
}

