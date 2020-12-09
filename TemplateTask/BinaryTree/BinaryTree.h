#include<vector>
#include<iostream>

using namespace std;

#pragma once

template<class T>
class BinaryTree
{
private:
	struct Node {
		T data;
		Node* left;
		Node* right;

		//при создании узла ему присваивается значение, а потомки становятся нулевыми
		Node(T value) {
			data = value;
			left = nullptr;
			right = nullptr;
		};
	};

	Node* root=nullptr;

	void add(T value, Node*& node) {
		//если мы в пустом узле то создаём его
		if (node == nullptr)
			node = new Node(value);
		else {
			//сравнение нового значения с созданными и поиск места под новый узел
			if (value < node->data)
				add(value, node->left);
			else if (value > node->data)
				add(value, node->right);
			else throw "Already here\n";
		}
	}

	void freeMemory(Node*& node) {
		//освобождение памяти
		if (node->left)
			freeMemory(node->left);
		if (node->right)
			freeMemory(node->right);
		delete node;
	}

	void deleting(T value, Node*& node) {
		//поиск удаляемого узла
		if (value > node->data)
			deleting(value, node->right);
		else if (value < node->data)
			deleting(value, node->left);
		else if (value == node->data) {
			Node* elementForDeleting = node;

			//если потомков нет то просто очищаем память
			if (elementForDeleting->left == nullptr && elementForDeleting->right == nullptr)
				node = nullptr;

			//если потомок один то запомниаем его, удаляем нужный элемент и связываем родителя и потомка удаляемого узла
			else if (elementForDeleting->left == nullptr && elementForDeleting->right != nullptr) {
				Node* temp= elementForDeleting->right;
				delete elementForDeleting;
				node = temp;
			}
			else if (elementForDeleting->left != nullptr && elementForDeleting->right == nullptr) {
				Node* temp = elementForDeleting->left;
				delete elementForDeleting;
				node = temp;
			}
			else {
				//если потомка два

				//идём влево
				Node* maxRightNode = elementForDeleting->left;

				//ищем самого правового потомка
				while (maxRightNode->right)
					maxRightNode = maxRightNode->right;

				//значение удаляемого элемента становится значением самого правового потомка слева от него
				elementForDeleting->data = maxRightNode->data;

				//если у самого правого потомка слева есть потомки слева то связываем родителей и потомков, освобождаем память
				if (maxRightNode->left) {
					Node* temp = maxRightNode->left;

					maxRightNode->data = temp->data;
					maxRightNode->left = temp->left;
					maxRightNode->right = temp->right;

					delete temp;
				}
				else
					maxRightNode = nullptr;
			}
		}
		else
			throw "element is not here";
	}

	void getList(vector<T>& list, Node*& node) {
		//ищем до конца влево, потом запоминаем, потом идём вправо. всё это рекурсией

		if (node->left)
			getList(list, node->left);

		list.push_back(node->data);

		if (node->right)
			getList(list, node->right);
	}

	bool contains(T value, Node*& node) {
		if (node==nullptr)
			return false;
		else if (value > node->data)
			return contains(value, node->right);
		else if (value < node->data)
			return contains(value, node->left);
		else if(node->data==value)
			return true;
	}

	void printTree(Node*& node) {
		if (node->left)
			printTree(node->left);

		cout << node->data << "\t";

		if (node->right)
			printTree(node->right);
	}

public:
	BinaryTree(){	}

	~BinaryTree() {
		if (root)
			freeMemory(root);
	}

	void add(T value) {
		if (root == nullptr)
			root = new Node(value);
		else
			add(value, root);
	}

	void deleting(T value) {
		deleting(value, root);
	}

	vector<T> getBinaryTreeList() {
		vector<T> list;
		getList(list,root);
		return list;
	}
	
	bool contains(T value) {
		return contains(value, root);
	}

	void printTree() {// traversing
		printTree(root);
	}

};

