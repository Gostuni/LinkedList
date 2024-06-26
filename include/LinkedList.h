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
			DataNode<T>* nextNode;
			DataNode<T>* bottomNode;
			T value;

		public:
			DataNode();
			DataNode(T nodeValue);
			DataNode(T nodeValue, DataNode<T>* nodePtrNext);
			DataNode(T nodeValue, DataNode<T>* nodePtrNext, DataNode<T>* nodePtrBottom);

			void setValue(T nodeValue);
			void setNextNode(DataNode<T>* nodePtrNext);
			void setBottomNode(DataNode<T>* nodePtrBottom);
			void addNode(DataNode<T>* nodePtrNew);

			T getValue();
			DataNode<T>* getNextNode();
			DataNode<T>* getBottomNode();

			//Overloaded operators
			DataNode<T>& operator[](int index);
			void operator=(T newValue);
			friend std::ostream& operator<<(std::ostream& outStream, DataNode<T>& node) {
				T nodeValue = node.getValue();

				if (!nodeValue) {
					outStream << ' ' << ' ';
				} else {
					outStream << nodeValue << ' ';
				}

				return outStream;
			}

		};

		//List class
		template <typename T>
		class List {

			private:
				int size;
				bool multiDim = false;

				DataNode<T>* listHead;
				DataNode<T>* listTail;

			public:
				List();
				List(int length, T padValue);
				List(int rowSize, int colSize, T padValue);
				List(DataNode<T>* nodePtrHead);
				List(DataNode<T>* nodePtrHead, DataNode<T>* nodePtrTail);

				void setListHead(DataNode<T>* nodePtrHead);
				void setListTail(DataNode<T>* nodePtrTail);
				void setMultiDim(bool isMultiDim);
				void addElement(DataNode<T>* nodePtrNew);
				void append(T newValue);
				void append2D(T newValue, int row = 0, bool keepDims = true, T padValue = T());

				int getSize();
				int getRowSize(int row = 0);
				bool getMultiDim();
				DataNode<T>* getListHead();
				DataNode<T>* getListTail();

				//Overloaded operators
				DataNode<T>& operator[](int index);

				friend std::ostream& operator<<(std::ostream& outStream, List<T>& list) {
					DataNode<T>* currentNode = list.getListHead();

					if (list.getMultiDim()) {

					} else {
						while (currentNode != nullptr) {
							outStream << currentNode->getValue() << ' ';

							currentNode = currentNode->getNextNode();
						}
					}

					return outStream;
				}

		};

	}

}

/**********************************************************************************************************/
//                                 Single Link Data Node                                                  //
/**********************************************************************************************************/

//-------Constructors-------//

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode() {
	nextNode = nullptr;
	bottomNode = nullptr;
	value = NULL;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue) {
	nextNode = nullptr;
	bottomNode = nullptr;
	value = nodeValue;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue, DataNode<T>* nodePtrNext) {
	nextNode = nodePtrNext;
	bottomNode = nullptr;
	value = nodeValue;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue, DataNode<T>* nodePtrNext, DataNode<T>* nodePtrBottom) {
	nextNode = nodePtrNext;
	bottomNode = nodePtrBottom;
	value = nodeValue;
}

//-------Methods-------//

template <typename T>
void linkedlist::singlelink::DataNode<T>::setValue(T nodeValue) {
	value = nodeValue;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::setNextNode(DataNode<T>* nodePtrNext) {
	nextNode = nodePtrNext;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::setBottomNode(DataNode<T>* nodePtrBottom) {
	bottomNode = nodePtrBottom;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::addNode(DataNode<T>* nodePtrNew) {
	if (nextNode == nullptr) {
		nextNode = nodePtrNew;
	} else {
		nodePtrNew->setNextNode(nextNode);
		nextNode = nodePtrNew;
	}
}

template <typename T>
T linkedlist::singlelink::DataNode<T>::getValue() {
	return value;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::DataNode<T>::getNextNode() {
	return nextNode;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::DataNode<T>::getBottomNode() {
	return bottomNode;
}

//-------Operators-------//

template <typename T>
linkedlist::singlelink::DataNode<T>& linkedlist::singlelink::DataNode<T>::operator[](int index) {
	DataNode<T>* currentNode = this;

	for (int i = 0; i < index; i++) {
		currentNode = currentNode->getNextNode();

		if (currentNode == nullptr) {
			exit(139);
		}
	}

	return *currentNode;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::operator=(T newValue) {
	setValue(newValue);
}

/**********************************************************************************************************/
//                                 Single Link List Controller                                            //
/**********************************************************************************************************/

//-------Constructors-------//

template <typename T>
linkedlist::singlelink::List<T>::List() {
	size = 0;
	listHead = nullptr;
	listTail = nullptr;
}

template <typename T>
linkedlist::singlelink::List<T>::List(int length, T padValue) {
	size = 0;
	listHead = nullptr;
	listTail = nullptr;

	for (int i = 0; i < length; i++) {
		DataNode<T>* newNode = new DataNode<T>(padValue);
		addElement(newNode);
	}
}

template <typename T>
linkedlist::singlelink::List<T>::List(int rowSize, int colSize, T padValue) {
	size = 0;
	multiDim = true;
	listHead = nullptr;
	listTail = nullptr;
}

template <typename T>
linkedlist::singlelink::List<T>::List(DataNode<T>* nodePtrHead) {
	size = 1;
	listHead = nodePtrHead;
	listTail = nodePtrHead;
}

template <typename T>
linkedlist::singlelink::List<T>::List(DataNode<T>* nodePtrHead, DataNode<T>* nodePtrTail) {
	if (nodePtrHead == nodePtrTail) {
		size = 1;
	} else {
		size = 2;
	}

	listHead = nodePtrHead;
	listTail = nodePtrTail;
}

/*-------Methods-------*/

template <typename T>
void linkedlist::singlelink::List<T>::setListHead(DataNode<T>* nodePtrHead) {
	if (listHead != nullptr) {
		delete listHead;
	}

	listHead = nodePtrHead;
}

template <typename T>
void linkedlist::singlelink::List<T>::setListTail(DataNode<T>* nodePtrTail) {
	if (listTail != nullptr) {
		delete listTail;
	}

	listTail = nodePtrTail;
}

template <typename T>
void linkedlist::singlelink::List<T>::setMultiDim(bool isMultiDim) {
	multiDim = isMultiDim;
}

template <typename T>
void linkedlist::singlelink::List<T>::addElement(DataNode<T>* nodePtrNew) {
	if (listHead == nullptr) {
		listHead = nodePtrNew;
	} else {
		listTail->addNode(nodePtrNew);
	}

	listTail = nodePtrNew;
	size += 1;
}

template <typename T>
void linkedlist::singlelink::List<T>::append(T newValue) {
	DataNode<T>* valueNode = new DataNode<T>(newValue);

	addElement(valueNode);
}

template <typename T>
void linkedlist::singlelink::List<T>::append2D(T newValue, int row, bool keepDims, T padValue) {

}

template <typename T>
int linkedlist::singlelink::List<T>::getSize() {
	return size;
}

template <typename T>
int linkedlist::singlelink::List<T>::getRowSize(int row) {
	return 0;
}

template <typename T>
bool linkedlist::singlelink::List<T>::getMultiDim() {
	return multiDim;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::List<T>::getListHead() {
	return listHead;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::List<T>::getListTail() {
	return listTail;
}

//-------Operators-------//

template <typename T>
linkedlist::singlelink::DataNode<T>& linkedlist::singlelink::List<T>::operator[](int index) {
	DataNode<T>* currentNode = listHead;

	if (multiDim) {

	} else {
		return (*currentNode)[index];
	}
}