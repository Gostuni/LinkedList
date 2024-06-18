// This file defines the structure
// and implementation of the
// classes relating to linked lists.
//
// Author: Giuseppe Daniel Ostuni
//
// Created on 06/07/2024

#pragma once
#include <iostream>
#include <typeinfo>
#include <string>

namespace linkedlist {

	namespace singlelink {

		//DataNode class
		template <typename T>
		class DataNode {
		private:
			linkedlist::singlelink::DataNode<T>* nextNode;
			T* value;

		public:
			DataNode();
			DataNode(T);
			DataNode(T*);
			DataNode(T, linkedlist::singlelink::DataNode<T>*);
			DataNode(T*, linkedlist::singlelink::DataNode<T>*);

			linkedlist::singlelink::DataNode<T>* getNextNode();
			T* getValue();
			T getValueObject();

			void setValue(T);
			void setValue(T*);
			void setNextNode(linkedlist::singlelink::DataNode<T>*);
			void addDataNode(linkedlist::singlelink::DataNode<T>*);

			friend std::ostream& operator<<(std::ostream& os, linkedlist::singlelink::DataNode<T>& dn) {
				linkedlist::singlelink::DataNode<T>* currentNode = &dn;

				while (currentNode != nullptr) {
					T* val = currentNode->getValue();

					if (val == nullptr) {
						os << ' ' << ' ';
					}else {
						os << *val << ' ';
					}

					currentNode = currentNode->getNextNode();
				}

				return os;
			}

		};

		//ListController class
		template <typename T>
		class ListController {
		private:
			int size;
			bool multiDim = false;

			linkedlist::singlelink::DataNode<T>* listHead;
			linkedlist::singlelink::DataNode<T>* listTail;

		public:
			ListController();
			ListController(int, T);
			ListController(int, int, T);
			ListController(linkedlist::singlelink::DataNode<T>*);
			ListController(linkedlist::singlelink::DataNode<T>*, linkedlist::singlelink::DataNode<T>*);

			int getSize();
			bool getMultiDim();
			linkedlist::singlelink::DataNode<T>* getListHead();
			linkedlist::singlelink::DataNode<T>* getListTail();

			void setListHead(linkedlist::singlelink::DataNode<T>*);
			void setListTail(linkedlist::singlelink::DataNode<T>*);
			void setMultiDim(bool);
			void addNode(linkedlist::singlelink::DataNode<T>*);
			void append(T);
			void append2D(T, int row = -1, bool keepDims = true, T padVal = T());

			friend std::ostream& operator<<(std::ostream& os, linkedlist::singlelink::ListController<T>& lc) {
				linkedlist::singlelink::DataNode<T>* currentNode = lc.getListHead();

				if (lc.getMultiDim()) {
					while (currentNode != nullptr) {
						T* colNode = currentNode->getValue();
						os << *colNode << '\n';

						currentNode = currentNode->getNextNode();
					}
				}else {
					os << *currentNode;
				}

				return os;
			}

		};
	}
}

/**********************************************************************************************************/
//                                 Single Link Data Node                                                  //
/**********************************************************************************************************/

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode() {
	nextNode = nullptr;

	value = nullptr;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue) {
	nextNode = nullptr;

	T* valptr = new T(nodeValue);

	value = valptr;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T* nodeValue) {
	nextNode = nullptr;

	value = nodeValue;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue, linkedlist::singlelink::DataNode<T>* nodeptr) {
	nextNode = nodeptr;

	T* valptr = new T(nodeValue);

	value = valptr;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T* nodeValue, linkedlist::singlelink::DataNode<T>* nodeptr) {
	nextNode = nodeptr;

	value = nodeValue;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::DataNode<T>::getNextNode() {
	return nextNode;
}

template <typename T>
T* linkedlist::singlelink::DataNode<T>::getValue() {
	return value;
}

template <typename T>
T linkedlist::singlelink::DataNode<T>::getValueObject() {
	return *value;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::setValue(T nodeValue) {
	T* valptr = new T(nodeValue);

	if (value != nullptr) {
		delete value;
	}

	value = valptr;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::setValue(T* nodeValue) {
	if (value != nullptr) {
		delete value;
	}

	value = nodeValue;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::setNextNode(linkedlist::singlelink::DataNode<T>* newNode) {
	nextNode = newNode;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::addDataNode(linkedlist::singlelink::DataNode<T>* newNode) {
	if (nextNode == nullptr) {
		nextNode = newNode;
	}else {
		linkedlist::singlelink::DataNode<T>* tmpNode = nextNode;
		newNode->setNextNode(tmpNode);
		nextNode = newNode;
	}
}

/**********************************************************************************************************/
//                                 Single Link List Controller                                            //
/**********************************************************************************************************/

template <typename T>
linkedlist::singlelink::ListController<T>::ListController() {
	size = 0;

	listHead = nullptr;
	listTail = nullptr;
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(int n, T val) {
	size = 0;

	listHead = nullptr;
	listTail = nullptr;

	for (int i = 0; i < n; i++) {
		linkedlist::singlelink::DataNode<T>* tmpNode = new linkedlist::singlelink::DataNode<T>(val);

		addNode(tmpNode);
	}
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(int r, int c, T val) {
	size = 0;
	multiDim = true;

	listHead = nullptr;
	listTail = nullptr;

	for (int i = 0; i < r; i++) {
		linkedlist::singlelink::DataNode<T>* rowNode = new linkedlist::singlelink::DataNode<T>();
		T* colTailNode = new T(val);
		rowNode->setValue(colTailNode);
		addNode(rowNode);

		for (int j = 0; j < (c - 1); j++) {
			T* newColNode = new T(val);
			colTailNode->addDataNode(newColNode);
			colTailNode = newColNode;
		}
	}
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(linkedlist::singlelink::DataNode<T>* nodeptrHead) {
	size = 1;

	listHead = nodeptrHead;
	listTail = nodeptrHead;
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(linkedlist::singlelink::DataNode<T>* nodeptrHead, linkedlist::singlelink::DataNode<T>* nodeptrTail) {
	if (nodeptrHead == nodeptrTail) {
		size = 1;
	}
	else {
		size = 2;
	}

	listHead = nodeptrHead;
	listTail = nodeptrTail;
}

template <typename T>
int linkedlist::singlelink::ListController<T>::getSize() {
	return size;
}

template <typename T>
bool linkedlist::singlelink::ListController<T>::getMultiDim() {
	return multiDim;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::ListController<T>::getListHead() {
	return listHead;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::ListController<T>::getListTail() {
	return listTail;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::setListHead(linkedlist::singlelink::DataNode<T>* nodeptrHead) {
	listHead = nodeptrHead;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::setListTail(linkedlist::singlelink::DataNode<T>* nodeptrTail) {
	listTail = nodeptrTail;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::setMultiDim(bool isMultiDim) {
	multiDim = isMultiDim;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::addNode(linkedlist::singlelink::DataNode<T>* newNode) {
	if (listHead == nullptr) {
		listHead = newNode;
	}else {
		listTail->addDataNode(newNode);
	}

	listTail = newNode;
	size += 1;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::append(T value) {
	T* valueAddr = new T(value);
	linkedlist::singlelink::DataNode<T>* newNode = new linkedlist::singlelink::DataNode<T>(valueAddr);

	addNode(newNode);
}

template <typename T>
void linkedlist::singlelink::ListController<T>::append2D(T value, int row, bool keepDims, T padVal) {
	linkedlist::singlelink::DataNode<T>* currentNode = listHead;

	if (row == -1) {
		append(value);
	}
	else {
		for (int i = 0; i < size; i++) {
			if ((keepDims) && (i != row)) {
				T* currentColNode = currentNode->getValue();

				while (currentColNode->getNextNode() != nullptr) {
					currentColNode = currentColNode->getNextNode();
				}

				T* valueAddr = new T(padVal);

				currentColNode->addDataNode(valueAddr);
			}

			if (i == row) {
				T* currentColNode = currentNode->getValue();

				while (currentColNode->getNextNode() != nullptr) {
					currentColNode = currentColNode->getNextNode();
				}

				T* valueAddr = new T(value);

				currentColNode->addDataNode(valueAddr);
			}

			currentNode = currentNode->getNextNode();

		}
	}
}

/**********************************************************************************************************/
//                                 Double Link Data Node                                                  //
/**********************************************************************************************************/