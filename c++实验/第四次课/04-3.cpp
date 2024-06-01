#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

// 函数用于输入矩阵元素
void InputMatrix(int d1, int d2, int** matrix) {
	cout << "请输入矩阵元素：";
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			cin >> matrix[i][j];
		}
	}
}

// 函数用于输出矩阵内容
void OutputMatrix(int d1, int d2, int** matrix) {
	cout << "矩阵内容：" << endl;
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// 函数用于旋转矩阵
void RotateMatrix(int d1, int d2, int** matrix) {
	int i, j;
	char flag = 'y';
	while (tolower(flag) == 'y') {
		// 用户选择旋转角度
		int angle;
		cout << "请选择旋转角度（90, 180 或 270度）: ";
		cin >> angle;
		cout << "旋转角度：" << angle << " 度" << endl;
		switch (angle) {
			case 90: {
				// 创建一个新矩阵来存储旋转后的结果
				int** rotatedMatrix = new int*[d2];
				for (i = 0; i < d2; i++) {
					rotatedMatrix[i] = new int[d1];
				}
				
				// 进行90度矩阵旋转操作
				for (i = 0; i < d1; i++) {
					for (j = 0; j < d2; j++) {
						rotatedMatrix[j][d1 - i - 1] = matrix[i][j];
					}
				}
				
				// 输出旋转后的矩阵
				cout << "旋转后的矩阵：" << endl;
				for (i = 0; i < d2; i++) {
					for (j = 0; j < d1; j++) {
						cout << rotatedMatrix[i][j] << " ";
					}
					cout << endl;
				}
				
				// 释放旋转后的矩阵内存
				for (i = 0; i < d2; i++) {
					delete[] rotatedMatrix[i];
				}
				delete[] rotatedMatrix;
				
				break;
			}
			case 180: {
				// 创建一个新矩阵来存储旋转后的结果
				int** rotatedMatrix = new int*[d1];
				for (i = 0; i < d1; i++) {
					rotatedMatrix[i] = new int[d2];
				}
				
				// 进行180度矩阵旋转操作
				for (i = 0; i < d1; i++) {
					for (j = 0; j < d2; j++) {
						rotatedMatrix[d1 - i - 1][d2 - j - 1] = matrix[i][j];
					}
				}
				
				// 输出旋转后的矩阵
				cout << "旋转后的矩阵：" << endl;
				for (i = 0; i < d1; i++) {
					for (j = 0; j < d2; j++) {
						cout << rotatedMatrix[i][j] << " ";
					}
					cout << endl;
				}
				
				// 释放旋转后的矩阵内存
				for (i = 0; i < d1; i++) {
					delete[] rotatedMatrix[i];
				}
				delete[] rotatedMatrix;
				
				break;
			}
			case 270: {
				// 创建一个新矩阵来存储旋转后的结果
				int** rotatedMatrix = new int*[d2];
				for (i = 0; i < d2; i++) {
					rotatedMatrix[i] = new int[d1];
				}
				
				// 进行270度矩阵旋转操作
				for (i = 0; i < d1; i++) {
					for (j = 0; j < d2; j++) {
						rotatedMatrix[d2 - j - 1][i] = matrix[i][j];
					}
				}
				
				// 输出旋转后的矩阵
				cout << "旋转后的矩阵：" << endl;
				for (i = 0; i < d2; i++) {
					for (j = 0; j < d1; j++) {
						cout << rotatedMatrix[i][j] << " ";
					}
					cout << endl;
				}
				
				// 释放旋转后的矩阵内存
				for (i = 0; i < d2; i++) {
					delete[] rotatedMatrix[i];
				}
				delete[] rotatedMatrix;
				
				break;
			}
		default:
			cout << "你输入了错误的角度！" << endl;
			break;
		}
		
		cout << "是否继续进行矩阵旋转操作?(Y/N)";
		cin >> flag;
	}
}

int main() {
	int i, d1, d2, **matrix;
	
	cout << "请输入矩阵的行数和列数：";
	cin >> d1 >> d2;
	
	// 动态分配内存来表示矩阵
	matrix = new int*[d1];
	for (i = 0; i < d1; i++) {
		matrix[i] = new int[d2];
	}
	
	if (matrix == nullptr) {
		cout << "动态分配空间失败，请检查程序！" << endl;
		exit(1);
	}
	
	InputMatrix(d1, d2, matrix);
	cout << "---------------------------------------------------------" << endl;
	OutputMatrix(d1, d2, matrix);
	
	RotateMatrix(d1, d2, matrix);
	
	// 释放内存
	for (i = 0; i < d1; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	
	return 0;
}

