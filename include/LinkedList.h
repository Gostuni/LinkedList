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
				DataNode(T* nodeValue);
				DataNode(T nodeValue, DataNode<T>* nodePtrNext);
				
				void setValue(T nodeValue);
				void setValue(T* nodeValue);
				void setNextNode(DataNode<T>* nodePtrNext);
				void addDataNode(DataNode<T>* nodePtrNew);
				void deleteValue();

				DataNode<T>* getNextNode();
				T* getValue();

				//Overloaded operators
				friend std::ostream& operator<<(std::ostream& outStream, DataNode<T>* node) {
					T* nodeVal = node->getValue();

					if (nodeVal == nullptr) {
						outStream << ' ' << ' ';
					} else {
						outStream << *nodeVal << ' ';
					}

					return outStream;
				}

				friend std::ostream& operator<<(std::ostream& outStream, DataNode<T>& node) {
					T* nodeVal = node.getValue();

					if (nodeVal == nullptr) {
						outStream << ' ' << ' ';
					} else {
						outStream << *nodeVal << ' ';
					}

					return outStream;
				}

				DataNode<T>* operator[](int index) {
					DataNode<T>* currentDataNode = this;

					for (int i = 0; i < index; i++) {
						currentDataNode = currentDataNode->getNextNode();
					}
					
					return currentDataNode;
				}

				void operator=(T newValue) {
					T* newValueAddr = new T(newValue);
					setValue(newValueAddr);
				}

		};

		//ListController class
		template <typename T>
		class ListController {

			private:
				int size;
				bool multiDim = false;

				DataNode<DataNode<T>>* listHead;
				DataNode<DataNode<T>>* listTail;

			public:
				ListController();
				ListController(int length, T padValue);
				ListController(int rowSize, int colSize, T padValue);
				ListController(DataNode<DataNode<T>>* nodePtrHead);
				ListController(DataNode<DataNode<T>>* nodePtrHead, DataNode<DataNode<T>>* nodePtrTail);

				void setListHead(DataNode<DataNode<T>>* nodePtrHead);
				void setListTail(DataNode<DataNode<T>>* nodePtrTail);
				void setMultiDim(bool isMultiDim);
				void addElement(DataNode<DataNode<T>>* nodePtrNew);
				void append(T newValue);
				void append2D(T newValue, int row = 0, bool keepDims = true, T padValue = T());

				int getSize();
				int getRowSize(int row = 0);
				bool getMultiDim();
				DataNode<DataNode<T>>* getListHead();
				DataNode<DataNode<T>>* getListTail();

				//Overloaded operators
				friend std::ostream& operator<<(std::ostream& outStream, ListController<T>& lc) {
					DataNode<DataNode<T>>* rowNode = lc.getListHead();
					DataNode<T>* currentColNode = nullptr;

					if (lc.getMultiDim()) {
						while (rowNode != nullptr) {
							currentColNode = rowNode->getValue();

							while (currentColNode->getNextNode() != nullptr) {
								outStream << currentColNode;

								currentColNode = currentColNode->getNextNode();
							}

							outStream << currentColNode << '\n';

							rowNode = rowNode->getNextNode();
						}
					} else {
						currentColNode = rowNode->getValue();

						while (currentColNode->getNextNode() != nullptr) {
							outStream << currentColNode;

							currentColNode = currentColNode->getNextNode();
						}
					}

					return outStream;
				}

				DataNode<T>* operator[](int index) {
					DataNode<DataNode<T>>* rowNode = listHead;

					if (multiDim) {
						for (int i = 0; i < index; i++) {
							rowNode = rowNode->getNextNode();
						}

						return rowNode->getValue();
					}

					return (*rowNode->getValue())[index];
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

	value = nullptr;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue) {
	nextNode = nullptr;

	T* valPtr = new T(nodeValue);

	value = valPtr;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T* nodeValue) {
	nextNode = nullptr;

	value = nodeValue;
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
void linkedlist::singlelink::DataNode<T>::setValue(T* nodeValue) {
	//if (value != nullptr) {
	//	std::cout << "Old value: " << *value << std::endl;;
	//}

	value = nodeValue;
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

	DataNode<DataNode<T>>* rowNode = new DataNode<DataNode<T>>();
	DataNode<T>* rowTailNode = new DataNode<T>(padValue);
	rowNode->setValue(rowTailNode);
	addElement(rowNode);

	for (int i = 0; i < (length - 1); i++) {
		DataNode<T>* valueNode = new DataNode<T>(padValue);
		
		rowTailNode->addDataNode(valueNode);

		size += 1;

		rowTailNode = valueNode;
	}
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(int rowSize, int colSize, T padValue) {
	size = 0;
	multiDim = true;

	listHead = nullptr;
	listTail = nullptr;

	for (int i = 0; i < rowSize; i++) {
		DataNode<DataNode<T>>* rowNode = new DataNode<DataNode<T>>();
		DataNode<T>* colTailNode = new DataNode<T>(padValue);
		rowNode->setValue(colTailNode);
		addElement(rowNode);

		for (int j = 0; j < (colSize - 1); j++) {
			DataNode<T>* newColNode = new DataNode<T>(padValue);
			colTailNode->addDataNode(newColNode);
			colTailNode = newColNode;
		}
	}
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(DataNode<DataNode<T>>* nodePtrHead) {
	size = 1;

	listHead = nodePtrHead;
	listTail = nodePtrHead;
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(DataNode<DataNode<T>>* nodePtrHead, DataNode<DataNode<T>>* nodePtrTail) {
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
void linkedlist::singlelink::ListController<T>::setListHead(DataNode<DataNode<T>>* nodePtrHead) {
	listHead = nodePtrHead;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::setListTail(DataNode<DataNode<T>>* nodePtrTail) {
	listTail = nodeptrTail;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::setMultiDim(bool isMultiDim) {
	multiDim = isMultiDim;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::addElement(DataNode<DataNode<T>>* nodePtrNew) {
	if (listHead == nullptr) {
		listHead = nodePtrNew;
	} else {
		listTail->addDataNode(nodePtrNew);
	}

	listTail = nodePtrNew;
	size += 1;
}

template <typename T>
void linkedlist::singlelink::ListController<T>::append(T newValue) {
	DataNode<T>* valueNode = new DataNode<T>(newValue);

	if (multiDim) {
		DataNode<DataNode<T>>* listNode = new DataNode<DataNode<T>>(valueNode);

		addElement(listNode);
	} else {
		DataNode<T>* currentColNode = listHead->getValue();

		while (currentColNode->getNextNode() != nullptr) {
			currentColNode = currentColNode->getNextNode();
		}

		currentColNode->addDataNode(valueNode);

		size += 1;
	}
}

template <typename T>
void linkedlist::singlelink::ListController<T>::append2D(T newValue, int row, bool keepDims, T padValue) {
	DataNode<DataNode<T>>* rowNode = listHead;
	DataNode<T>* currentColNode = nullptr;

	for (int i = 0; i < size; i++) {
		int rowIndex = 0;
		currentColNode = rowNode->getValue();

		while (currentColNode->getNextNode() != nullptr) {
			currentColNode = currentColNode->getNextNode();
			rowIndex += 1;
		}

		if ((i != row) && (keepDims)) {
			DataNode<T>* padNode = new DataNode<T>(padValue);
			currentColNode->addDataNode(padNode);
		}
		else if (i == row) {
			DataNode<T>* valueNode = new DataNode<T>(newValue);
			currentColNode->addDataNode(valueNode);
		}

		rowNode = rowNode->getNextNode();
	}
}

template <typename T>
int linkedlist::singlelink::ListController<T>::getSize() {
	return size;
}

template <typename T>
int linkedlist::singlelink::ListController<T>::getRowSize(int row) {
	if (multiDim) {
		DataNode<DataNode<T>>* rowNode = listHead;

		for (int i = 0; i < row; i++) {
			rowNode = rowNode->getNextNode();
		}

		DataNode<T>* currentColNode = rowNode->getValue();
		int rowSize = 1;

		while (currentColNode->getNextNode() != nullptr) {
			currentColNode = currentColNode->getNextNode();
			rowSize += 1;
		}

		return rowSize;

	} else {
		return size;
	}
}

template <typename T>
bool linkedlist::singlelink::ListController<T>::getMultiDim() {
	return multiDim;
}

template <typename T>
linkedlist::singlelink::DataNode<linkedlist::singlelink::DataNode<T>>* linkedlist::singlelink::ListController<T>::getListHead() {
	return listHead;
}

template <typename T>
linkedlist::singlelink::DataNode<linkedlist::singlelink::DataNode<T>>* linkedlist::singlelink::ListController<T>::getListTail() {
	return listTail;
}