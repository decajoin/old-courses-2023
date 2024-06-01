#include <iostream>
#include <ctype.h>
using namespace std;

// 定义一个节点结构
struct Node {
	int data;
	Node* next;
};

// 定义链表类
class LinkedList {
private:
	Node* head;
	
public:
	LinkedList() {
		head = nullptr;
	}
	
	// 插入一个新元素到链表末尾
	void insert(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;
		
		if (head == nullptr) {
			head = newNode;
		} else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	
	// 打印链表中的元素
	void display() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
	}
};

int main() {
	int i, j, d1, d2, angle;
	cout << "请输入矩阵的两个维度: ";
	cin >> d1 >> d2;
	
	// 创建一个二维链表数组来表示矩阵
	LinkedList** matrix = new LinkedList*[d1];
	for (i = 0; i < d1; i++) {
		matrix[i] = new LinkedList[d2];
	}
	
	cout << "请输入矩阵的元素: ";
	for (i = 0; i < d1; i++) {
		for (j = 0; j < d2; j++) {
			int element;
			cin >> element;
			matrix[i][j].insert(element);
		}
	}
	
	cout << "原始矩阵:" << endl;
	for (i = 0; i < d1; i++) {
		for (j = 0; j < d2; j++) {
			matrix[i][j].display();
			cout << " ";
		}
		cout << endl;
	}
	
	char flag = 'y';
	while (tolower(flag) == 'y') {
		cout << "请输入要旋转的角度(90, 180或270): ";
		cin >> angle;
		
		switch (angle) {
			case 90: {
				for (int j = 0; j < d2; j++) {
					for (int i = d1 - 1; i >= 0; i--) {
						matrix[i][j].display();
						cout << " ";
					}
					cout << endl;
				}
				break;
			}
			
			case 180: {
				for (int i = d1 - 1; i >= 0; i--) {
					for (int j = d2 - 1; j >= 0; j--) {
						matrix[i][j].display();
						cout << " ";
					}
					cout << endl;
				}
				break;
			}
			
			case 270: {
				for (int j = d2 - 1; j >= 0; j--) {
					for (int i = 0; i < d1; i++) {
						matrix[i][j].display();
						cout << " ";
					}
					cout << endl;
				}
				break;
			}
			
			default: {
				cout << "您输入了错误的角度！" << endl;
			}
		}
		
		cout << "--------------------------------------------------------------" << endl;
		cout << "是否继续旋转矩阵？(Y/N)";
		cin >> flag;
	}
	
	// 释放内存
	for (i = 0; i < d1; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	
	return 0;
}

