// This file defines the structure
// and implementation of the
// classes relating to linked lists.
//
// Author: Giuseppe Daniel Ostuni
//
// Created on 06/07/2024

#pragma once
#include <iostream>

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
			void addDataNode(linkedlist::singlelink::DataNode<T>*);

			friend std::ostream& operator<<(std::ostream& os, linkedlist::singlelink::DataNode<T>& dn) {
				os << dn.getValueObject();
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
			ListController(int);
			ListController(int, int);
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
			void append(T*);
			void append(T);

			friend std::ostream& operator<<(std::ostream& os, linkedlist::singlelink::ListController<T>& lc) {
				if (lc.getMultiDim()) {
					linkedlist::singlelink::DataNode<T>* currentNode = lc.getListHead();

					while (currentNode != nullptr) {
						T* colNode = currentNode->getValue();

						while (colNode != nullptr) {
							os << colNode.getValueObject() << ' ';

							colNode = colNode->getNextNode();
						}

						os << '\n';

						currentNode = currentNode->getNextNode();
					}

				}else {
					linkedlist::singlelink::DataNode<T>* currentNode = lc.getListHead();

					while (currentNode != nullptr) {
						os << currentNode.getValueObject();

						currentNode = currentNode->getNextNode();
					}
				}

				return os;
			}
			
			//Replace with << operator overload
			void printList() {
				if (multiDim == false) {
					linkedlist::singlelink::DataNode<T>* currentNode = listHead;

					while (currentNode != nullptr) {
						if (currentNode->getValue() == nullptr) {
							std::cout << "Empty" << std::endl;
						}else {
							std::cout << currentNode->getValueObject() << std::endl;
						}

						currentNode = currentNode->getNextNode();
					}
				}else {
					std::cout << "Multidim" << std::endl;
				}
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
void linkedlist::singlelink::DataNode<T>::addDataNode(linkedlist::singlelink::DataNode<T>* newNode) {
	nextNode = newNode;
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
linkedlist::singlelink::ListController<T>::ListController(int n) {
	size = 0;

	listHead = nullptr;
	listTail = nullptr;

	for (int i = 0; i < n; i++) {
		linkedlist::singlelink::DataNode<T>* tmpNode = new linkedlist::singlelink::DataNode<T>(nullptr);

		addNode(tmpNode);
	}
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(int r, int c) {
	size = 0;
	multiDim = true;

	listHead = nullptr;
	listTail = nullptr;

	for (int i = 0; i < r; i++) {
		linkedlist::singlelink::DataNode<T>* rowNode = new linkedlist::singlelink::DataNode<T>();
		T* colTailNode = new T();
		rowNode->setValue(colTailNode);
		addNode(rowNode);

		for (int j = 0; j < c; j++) {
			T* newColNode = new T(NULL);
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
void linkedlist::singlelink::ListController<T>::append(T* value) {
	linkedlist::singlelink::DataNode<T>* newNode = new linkedlist::singlelink::DataNode<T>(value);
	addNode(newNode);
}

template <typename T>
void linkedlist::singlelink::ListController<T>::append(T value) {
	linkedlist::singlelink::DataNode<T>* newNode = new linkedlist::singlelink::DataNode<T>(&value);
	addNode(newNode);
}

/**********************************************************************************************************/
//                                 Double Link Data Node                                                  //
/**********************************************************************************************************/