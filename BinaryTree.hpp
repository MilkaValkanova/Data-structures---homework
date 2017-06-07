/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Milka Valkanova
* @idnumber 45155
* @task 1
* @compiler VC
*
*/
#pragma once
#include <iostream>
#include <fstream>
#include"DynamicArr.hpp"

template <class T>
class BinaryTree
{
	private:
		struct Node
		{
			T data;
			Node* left;
			Node* right;
			Node(const T& input) : left(nullptr), right(nullptr), data(input) {};
		};
		Node* root;

	public:
		BinaryTree() : root(nullptr) {};
		~BinaryTree();
		BinaryTree(const BinaryTree<T>&);
		BinaryTree& operator=(const BinaryTree<T>&);

	private:
		void cleanNode(Node*);
		Node* _copy(Node*) {};// v nqkoj drug jivot moje i da go napisha!
		bool _search(const Node*, const T&) const;
		void _insert(Node*&, const T&);
		void _remove(Node*&, const T&);
		Node* findMinInSubRight(Node*&)const;
		void _print(const Node*) const;
		Node* _createPBT(DynamicArr<T>&, int, int);	

	public:
		bool search(const T& data) const { return _search(root, data); }
		void insert(const T& data) { _insert(root, data); }
		void remove(const T& data) { _remove(root, data); }
		void Print() const { _print(root); std::cout << "\n"; }
		void createPBT(DynamicArr<T> arr) { this->root = _createPBT(arr, 0, arr.getsize() - 1); }
};

template <class T>
BinaryTree<T>::~BinaryTree()
{
	cleanNode(root);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& tree) : root(copy(tree.root)), size(tree.size) {};

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& tree)
{
	if (&tree != this)
	{
		clean(root);
		root = _copy(tree.root);
		size = tree.size;
	}
	return *this;
}

template <class T>
void BinaryTree<T>::cleanNode(Node* el)
{
	if (el != nullptr)
	{
		cleanNode(el->left);
		cleanNode(el->right);
		delete el;
	}
}


template <class T>
void BinaryTree<T>::_print(const Node* el)const
{
	if (el)
	{
		_print(el->left);
		std::cout << el->data<<" ";
		_print(el->right);
	}
}

template <class T>
void BinaryTree<T>::_insert(Node*& el, const T& data)
{
	if (el == nullptr)
	{
		el = new Node(data);
		return;
	}

	if (data < el->data)
	{
		_insert(el->left, data);
	}
	else
	{
		_insert(el->right, data);
	}
}

template <class T>
bool BinaryTree<T>::_search(const Node* el, const T& data) const
{
	if (el == nullptr)
	{
		return false;
	}
	
	else if (el->data == data)
	{
		return true;
	}

	else if (data < el->data)
	{
		return _search(el->left, data);
	}
	else 
	{
		return _search(el->right, data);
	}
}

template <class T>
void BinaryTree<T>::_remove(Node*& el, const T& data)
{
	//no such node
	if (el == nullptr) return;

	//this node is the search one
	if (el->data == data)
	{
		//no child
		if (el->left == nullptr && el->right == nullptr)
		{
			delete el;
			el = nullptr;
			return;
		}
		else 
		{
			Node* garbage = el;
			//one child
			if (el->left == nullptr && el->right != nullptr)
			{
				el = el->right;
			}
			else if (el->left != nullptr && el->right == nullptr)
			{
				el = el->left;
			}
			//two children
			else
			{
				//nqkakva prostotiq za namirane na minimalen element v dqsno poddurvo
				Node* replace = findMinInSubRight(el->right);
				replace->left = el->left;
				replace->right = el->right;
				el = replace;
			}
		delete garbage;
		}
	}
	//search in next root(children)
	else if (data < el->data)
	{ 
		_remove(el->left, data);
	}
		
	else
	{ 
		_remove(el->right, data);
	}
}

template <class T>
typename BinaryTree<T>::Node* BinaryTree<T>::findMinInSubRight(Node*& el)const// find min element in right subtree
{
	if (el->left != nullptr)
	{
		return findMinInSubRight(el->left);
	}
	//this is min
	Node* min = el;
	el = el->right;
	return min;
}

template <class T>
typename BinaryTree<T>::Node* BinaryTree<T>::_createPBT(DynamicArr<T>& arr,int start , int end)
{
	if (start > end) return nullptr;
	size_t mid = start + (end - start) / 2;

	Node* node = new Node(arr[mid]);
	node->left = _createPBT(arr, start, mid - 1);
	node->right = _createPBT(arr, mid + 1, end);
	return node;
}