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
				T* value;

			public:
				DataNode();
				DataNode(T nodeValue);
				DataNode(T nodeValue, DataNode<T>* nodePtrNext);
				
				void setValue(T nodeValue);
				void setNextNode(DataNode<T>* nodePtrNext);
				void addDataNode(DataNode<T>* nodePtrNew);
				void deleteValue();

				DataNode<T>* getNextNode();
				T* getValue();

				//Overloaded operators
				friend std::ostream& operator<<(std::ostream& outStream, DataNode<T>& node) {
					DataNode<T>* currentDataNode = &node;

					while (currentDataNode != nullptr) {
						T* nodeVal = currentDataNode->getValue();

						if (nodeVal == nullptr) {
							outStream << ' ' << ' ';
						} else {
							outStream << *nodeVal << ' ';
						}

						currentDataNode = currentDataNode->getNextNode();
					}

					return outStream;
				}

				T operator[](int index) {
					DataNode<T>* currentDataNode = this;

					for (int i = 0; i < index; i++) {
						currentDataNode = currentDataNode->getNextNode();
					}
					
					return *currentDataNode->getValue();
				}

				void operator=(T newVal) {
					setValue(val);
				}

		};

		//ListController class
		template <typename T>
		class ListController {

			private:
				int size;
				bool multiDim = false;

				DataNode<T>* listHead;
				DataNode<T>* listTail;

			public:
				ListController();
				ListController(int length, T padValue);
				ListController(int rowSize, int colSize, T padValue);
				ListController(DataNode<T>* nodePtrHead);
				ListController(DataNode<T>* nodePtrHead, DataNode<T>* nodePtrTail);

				void setListHead(DataNode<T>* nodePtrHead);
				void setListTail(DataNode<T>* nodePtrTail);
				void setMultiDim(bool isMultiDim);
				void addElement(DataNode<T>* nodePtrNew);
				void append(T newValue);
				void append2D(T newValue, int row = -1, bool keepDims = true, T padVal = T());

				int getSize();
				bool getMultiDim();
				DataNode<T>* getListHead();
				DataNode<T>* getListTail();

				//Overloaded operators
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

	value = nullptr;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue) {
	nextNode = nullptr;

	T* valPtr = new T(nodeValue);

	value = valPtr;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue, DataNode<T>* nodePtrNext) {
	nextNode = nodePtrNext;

	T* valPtr = new T(nodeValue);

	value = valPtr;
}

//-------Methods-------//

template <typename T>
void linkedlist::singlelink::DataNode<T>::setValue(T nodeValue) {
	T* valPtr = new T(nodeValue);

	if (value != nullptr) {
		delete value;
	}

	value = valPtr;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::setNextNode(DataNode<T>* nodePtrNext) {
	nextNode = nodePtrNext;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::addDataNode(DataNode<T>* nodePtrNew) {
	if (nextNode == nullptr) {
		nextNode = nodePtrNew;
	} else {
		nodePtrNew->setNextNode(nextNode);
		nextNode = nodePtrNew;
	}
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::deleteValue() {
	delete value;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::DataNode<T>::getNextNode() {
	return nextNode;
}

template <typename T>
T* linkedlist::singlelink::DataNode<T>::getValue() {
	return value;
}

/**********************************************************************************************************/
//                                 Single Link List Controller                                            //
/**********************************************************************************************************/

//-------Constructors-------//

template <typename T>
linkedlist::singlelink::ListController<T>::ListController() {
	size = 0;

	listHead = nullptr;
	listTail = nullptr;
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(int length, T padValue) {
	size = 0;

	listHead = nullptr;
	listTail = nullptr;

	for (int i = 0; i < length; i++) {
		DataNode<T>* newNode = new DataNode<T>(padValue);

		addNode(newNode);
	}
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(int rowSize, int colSize, T padValue) {
	size = 0;
	multiDim = true;

	listHead = nullptr;
	listTail = nullptr;


}