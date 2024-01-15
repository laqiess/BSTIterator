#pragma once
// author: Ключерев Артемий

#include <iostream>
#include "AbsIterator.h"
#include "TreeNode.h"
#include <stack> // для итератора


// класс бинарного дерева поиска
template <typename T>
class BinSTree
{
private:
	// указатели на корень и на текущий узел
	TreeNode<T>* root;
	TreeNode<T>* current;

	// число элементов дерева 
	int size;


public:
	// конструктор по умолчанию
	BinSTree();

	// конструктор с параметром
	BinSTree(TreeNode<T>* tree);


	// конструктор копирования
	BinSTree(const BinSTree<T>& tree);

	// оператор копирования (присваивания)
	BinSTree<T>& operator= (const BinSTree<T>& rhs);

	// деструктор
	~BinSTree() { deleteTree(this->root); }


	// стандартные методы обработки списков

	// возвращает уровень, на котором находится искомый узел
	// либо -1, если узла с таким значением в дереве нет
	int Find(const T& item) const;
	// вставка узла в дерево
	void Insert(const T& item);
	// удаление узла и дерева
	void Delete(const T& item);
	// очистить дерево
	void ClearList();

	// проверка, пустое ли дерево
	bool ListEmpty() const;

	// количество узлов в дереве
	int ListSize() const;

	TreeNode<T>* GetRoot() const;

	// класс итератора для BinSTree (симметричный обход, т.е. по возрастанию)
	template<typename T>
	class BinSTreeIterator : public AbsIterator<T> {
	private:
		TreeNode<T>* curr;  // Текущий узел
		std::stack<TreeNode<T>*> path;  // Стек для хранения пути к текущему узлу

	public:
		// конструктор с параметром (в качестве параметра передаётся корень дерева)
		// curr присваивается самый левый узел (наименьший)
		BinSTreeIterator(TreeNode<T>* x) {
			TreeNode<T>* tmp = x;//создается временный указатель
			while (tmp != nullptr) {
				path.push(tmp);//помещаем в стек
				tmp = tmp->Left();//идем по левым потомкам
			}
			if (!path.empty()) {
				curr = path.top();//присваиваем curr значения верхнего элемента стека
				path.pop();//удаляем его в стеке
			}
			else {
				curr = nullptr;
			}

		}

		// оператор сравнения
		bool operator==(const AbsIterator<T>& o) const override {
			return curr == dynamic_cast<const BinSTreeIterator<T>&>(o).curr;
		}

		bool operator!=(const AbsIterator<T>& o) const override {
			return !(curr == dynamic_cast<const BinSTreeIterator<T>&>(o).curr);
		}

		// оператор доступа к данным
		T operator*() const override {
			//возвращает данные текущего узла
			return curr->Data();
		}

		// оператор перехода на следующий узел
		BinSTreeIterator& operator++() override {
			if (curr != nullptr) {

				// Если текущий узел имеет правого потомка, идем вправо
				if (curr->Right() != nullptr) {
					curr = curr->Right();

					// Идем влево до последнего левого потомка
					while (curr->Left() != nullptr) {
						path.push(curr);
						curr = curr->Left();
					}
				}
				// Если текущий узел не имеет правого потомка, идем вверх по стеку
				else if (!path.empty()) {
					curr = path.top();
					path.pop();
				}
				// Если стек пуст и нет правого потомка, достигнут конец дерева
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

// конструктор по умолчанию
template <typename T>
BinSTree<T>::BinSTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// конструктор с параметрами
template <typename T>
BinSTree<T>::BinSTree(TreeNode<T>* tree)
{
	this->root = CopyTree(tree);
	this->current = nullptr;
	this->size = treeCount(this->root);
}

// конструктор копирования
template <typename T>
BinSTree<T>::BinSTree(const BinSTree<T>& tree)
{
	this->root = CopyTree(tree.root);

	// присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = tree.size;
}


// оператор копирования (присваивания)
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
{
	// нельзя копировать дерево в само себя
	if (this == &rhs)
		return *this;

	// очистить текущее дерево
	ClearList();

	// скопировать новое дерево в текущий объект
	this->root = CopyTree(rhs.root);

	// присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = rhs.size;

	// возвратить ссылку на текущий объект
	return *this;
}

// очистка дерева
template <typename T>
void BinSTree<T>::ClearList() {
	deleteTree(this->root);
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

//проверка, пустое ли дерево
template<class T>
bool BinSTree<T>::ListEmpty() const {
	return (this->root == nullptr);
}

// количество узлов в дереве
template<class T>
int BinSTree<T>::ListSize() const {
	return this->size;
}


// поиск узла
// возвращает уровень, на котором был найден узел
// либо -1, если узла с искомым значением нет
template<class T>
int BinSTree<T>::Find(const T& item) const {
	return SearchNode(this->root, item);
}

// вставка узла
template<class T>
void BinSTree<T>::Insert(const T& item) {
	this->root = InsertNode(this->root, item);
	size = treeCount(this->root);
}

// удаление узла
template<class T>
void BinSTree<T>::Delete(const T& item) {
	this->root = DeleteNode(this->root, item);
	size = treeCount(this->root);
}

// Возвращает указатель на корень
template <typename T>
TreeNode<T>* BinSTree<T>::GetRoot() const
{
	return this->root;
}
