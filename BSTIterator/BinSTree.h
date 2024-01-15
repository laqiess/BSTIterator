#pragma once
// author: �������� �������

#include <iostream>
#include "AbsIterator.h"
#include "TreeNode.h"
#include <stack> // ��� ���������


// ����� ��������� ������ ������
template <typename T>
class BinSTree
{
private:
	// ��������� �� ������ � �� ������� ����
	TreeNode<T>* root;
	TreeNode<T>* current;

	// ����� ��������� ������ 
	int size;


public:
	// ����������� �� ���������
	BinSTree();

	// ����������� � ����������
	BinSTree(TreeNode<T>* tree);


	// ����������� �����������
	BinSTree(const BinSTree<T>& tree);

	// �������� ����������� (������������)
	BinSTree<T>& operator= (const BinSTree<T>& rhs);

	// ����������
	~BinSTree() { deleteTree(this->root); }


	// ����������� ������ ��������� �������

	// ���������� �������, �� ������� ��������� ������� ����
	// ���� -1, ���� ���� � ����� ��������� � ������ ���
	int Find(const T& item) const;
	// ������� ���� � ������
	void Insert(const T& item);
	// �������� ���� � ������
	void Delete(const T& item);
	// �������� ������
	void ClearList();

	// ��������, ������ �� ������
	bool ListEmpty() const;

	// ���������� ����� � ������
	int ListSize() const;

	TreeNode<T>* GetRoot() const;

	// ����� ��������� ��� BinSTree (������������ �����, �.�. �� �����������)
	template<typename T>
	class BinSTreeIterator : public AbsIterator<T> {
	private:
		TreeNode<T>* curr;  // ������� ����
		std::stack<TreeNode<T>*> path;  // ���� ��� �������� ���� � �������� ����

	public:
		// ����������� � ���������� (� �������� ��������� ��������� ������ ������)
		// curr ������������� ����� ����� ���� (����������)
		BinSTreeIterator(TreeNode<T>* x) {
			TreeNode<T>* tmp = x;//��������� ��������� ���������
			while (tmp != nullptr) {
				path.push(tmp);//�������� � ����
				tmp = tmp->Left();//���� �� ����� ��������
			}
			if (!path.empty()) {
				curr = path.top();//����������� curr �������� �������� �������� �����
				path.pop();//������� ��� � �����
			}
			else {
				curr = nullptr;
			}

		}

		// �������� ���������
		bool operator==(const AbsIterator<T>& o) const override {
			return curr == dynamic_cast<const BinSTreeIterator<T>&>(o).curr;
		}

		bool operator!=(const AbsIterator<T>& o) const override {
			return !(curr == dynamic_cast<const BinSTreeIterator<T>&>(o).curr);
		}

		// �������� ������� � ������
		T operator*() const override {
			//���������� ������ �������� ����
			return curr->Data();
		}

		// �������� �������� �� ��������� ����
		BinSTreeIterator& operator++() override {
			if (curr != nullptr) {

				// ���� ������� ���� ����� ������� �������, ���� ������
				if (curr->Right() != nullptr) {
					curr = curr->Right();

					// ���� ����� �� ���������� ������ �������
					while (curr->Left() != nullptr) {
						path.push(curr);
						curr = curr->Left();
					}
				}
				// ���� ������� ���� �� ����� ������� �������, ���� ����� �� �����
				else if (!path.empty()) {
					curr = path.top();
					path.pop();
				}
				// ���� ���� ���� � ��� ������� �������, ��������� ����� ������
				else {
					curr = nullptr;
				}
			}

			return *this;
		}



	};


	BinSTreeIterator<T> begin() const {
		return BinSTreeIterator<T>(root);
	}

	BinSTreeIterator<T> end() const {
		return BinSTreeIterator<T>(nullptr);
	}



};

// ����������� �� ���������
template <typename T>
BinSTree<T>::BinSTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// ����������� � �����������
template <typename T>
BinSTree<T>::BinSTree(TreeNode<T>* tree)
{
	this->root = CopyTree(tree);
	this->current = nullptr;
	this->size = treeCount(this->root);
}

// ����������� �����������
template <typename T>
BinSTree<T>::BinSTree(const BinSTree<T>& tree)
{
	this->root = CopyTree(tree.root);

	// ��������� �������� ��������� �������� ����� � ������ ������ ������
	this->current = this->root;
	this->size = tree.size;
}


// �������� ����������� (������������)
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
{
	// ������ ���������� ������ � ���� ����
	if (this == &rhs)
		return *this;

	// �������� ������� ������
	ClearList();

	// ����������� ����� ������ � ������� ������
	this->root = CopyTree(rhs.root);

	// ��������� �������� ��������� �������� ����� � ������ ������ ������
	this->current = this->root;
	this->size = rhs.size;

	// ���������� ������ �� ������� ������
	return *this;
}

// ������� ������
template <typename T>
void BinSTree<T>::ClearList() {
	deleteTree(this->root);
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

//��������, ������ �� ������
template<class T>
bool BinSTree<T>::ListEmpty() const {
	return (this->root == nullptr);
}

// ���������� ����� � ������
template<class T>
int BinSTree<T>::ListSize() const {
	return this->size;
}


// ����� ����
// ���������� �������, �� ������� ��� ������ ����
// ���� -1, ���� ���� � ������� ��������� ���
template<class T>
int BinSTree<T>::Find(const T& item) const {
	return SearchNode(this->root, item);
}

// ������� ����
template<class T>
void BinSTree<T>::Insert(const T& item) {
	this->root = InsertNode(this->root, item);
	size = treeCount(this->root);
}

// �������� ����
template<class T>
void BinSTree<T>::Delete(const T& item) {
	this->root = DeleteNode(this->root, item);
	size = treeCount(this->root);
}

// ���������� ��������� �� ������
template <typename T>
TreeNode<T>* BinSTree<T>::GetRoot() const
{
	return this->root;
}
