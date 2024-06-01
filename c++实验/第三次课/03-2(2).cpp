#include <iostream>
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
			cout << current->data << "  ";
			current = current->next;
		}
		cout << endl;
	}
	
	// 获取链表中特定位置的元素
	int getElement(int index) {
		Node* current = head;
		int count = 0;
		
		while (current != nullptr) {
			if (count == index) {
				return current->data;
			}
			current = current->next;
			count++;
		}
		
		// 如果未找到，返回一个特定值（例如 -1）或抛出异常，视情况而定
		return -1;
	}
	
	// 销毁链表，释放内存
	void destroy() {
		Node* current = head;
		while (current != nullptr) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
		head = nullptr;
	}
};

int main() {
	int i, j, d1, d2;
	cout << "请输入矩阵的两个维度: ";
	cin >> d1 >> d2;
	
	// 创建链表数组，每个元素代表矩阵的一行
	LinkedList* matrix = new LinkedList[d1];
	
	cout << "请输入矩阵的元素: ";
	for (i = 0; i < d1; i++) {
		for (j = 0; j < d2; j++) {
			int element;
			cin >> element;
			matrix[i].insert(element);
		}
	}
	
	cout << "原始矩阵:" << endl;
	for (i = 0; i < d1; i++) {
		matrix[i].display();
	}
	
	cout << "转置矩阵:" << endl;
	for (j = 0; j < d2; j++) {
		for (i = 0; i < d1; i++) {
			cout << matrix[i].getElement(j) << "  ";
		}
		cout << endl;
	}
	
	// 释放内存
	for (i = 0; i < d1; i++) {
		matrix[i].destroy();
	}
	delete[] matrix;
	
	return 0;
}

