// This file defines the structure
// and implementation of the
// classes relating to linked lists.
//
// Author: Giuseppe Daniel Ostuni
//
// Created on 06/07/2024

/**
*
* @file LinkedList.h
*
* Header file describing classes used for linked lists.
*
* This file contains three namespaces: linkedlist (toplevel), singlelink (for singly linked lists),
* and doublelink (for doubly linked lists). Each of the inner namespaces defines two classes: DataNode
* and ListController.
*
*/

#pragma once

namespace linkedlist {
	// Two namespaces: One for singly
	// linked lists and another for
	// doubly linked lists.
	
	namespace singlelink {
		
		/**
		*
		* A templated class used to describe the
		* atomic unit of the linked list.
		*
		* To declare a singly linked DataNode: linkedlist::singlelink::DataNode<type>
		*
		*/
		
		template <typename T>
		class DataNode {
			
			private:
				linkedlist::singlelink::DataNode<T>* nextNode; ///< A pointer to the next DataNode in the list.
				
				T value; ///< The value of the data node of a general type.
				
			public:
				DataNode(); ///< Default constructor.
				DataNode(T); ///< This constructor sets the value of the datanode. @param[in] T nodeValue
				DataNode(T, linkedlist::singlelink::DataNode<T>*); ///< This constructgor sets the value of the datanode and the pointer to the next node. @param[in] T nodeValue @param[in] linkedlist::singlelink::DataNode<T>* nodeptrNext
				
				linkedlist::singlelink::DataNode<T>* getNextNode(); ///< This function returns the value of the next node. @param[out] linkedlist::singlelink::DataNode<T>* nextNode
				T getValue(); ///< This function return the value of the data node. @param[out] T value
				
				void setValue(T); ///< This function sets the value of the data node. @param[in] T nodeValue
				
				void addDataNode(linkedlist::singlelink::DataNode<T>*); ///< This function adds a new data node to the linked list. @param[in] linkedlist::singlelink::DataNode<T>* newNode
			
		};
		
		/**
		*
		* A templated class used to describe the
		* linked list controller.
		*
		* This class performs high level functions on the linked list. Like accessing values
		* at specific indexes, keeping track of the list head and tail, removing list elements,
		* keeping track of list size, etc. To declare a singly linked list controller:
		* linkedlist::singlelink::ListController<T>
		*
		*/
		
		template <typename T>
		class ListController {
			
			private:
				int size; ///< An int value that tracks list size.
				
				linkedlist::singlelink::DataNode<T>* listHead; ///< A pointer to the list head node.
				linkedlist::singlelink::DataNode<T>* listTail; ///< A pointer to the list tail node.
				
			public:
				ListController(); ///< Default constructor.
				ListController(int); ///< This constructor creates a linked list of length n filled with NULL values.
				ListController(int, int); ///< This constructor creates a linked list of shape [r, c] filled with NULL values.
				ListController(linkedlist::singlelink::DataNode<T>*); ///< This constructor sets the listHead and listTail pointers to the same DataNode. @param[in] linkedlist::singlelink::DataNode<T>* nodeptr
				ListController(linkedlist::singlelink::DataNode<T>*, linkedlist::singlelink::DataNode<T>*); ///< This constructor sets the listHead and listTail pointers. @param[in] linkedlist::singlelink::DataNode<T>* nodeptrHead @param[in] linkedlist::singlelink::DataNode<T>* nodeptrTail
				
				int getSize(); ///< This function return the list size. @param[out] int size
				linkedlist::singlelink::DataNode<T>* getListHead(); ///< This function returns a pointer to the list head node. @param[out] linkedlist::singlelink::DataNode<T>* listHead
				linkedlist::singlelink::DataNode<T>* getListTail(); ///< This function returns a pointer to the list tail node. @param[out] linkedlist::singlelink::DataNode<T>* listTail
				
				void setListHead(linkedlist::singlelink::DataNode<T>*); ///< This function sets the list head node. @param[in] linkedlist::singlelink::DataNode<T>* nodeptrHead
				void setListTail(linkedlist::singlelink::DataNode<T>*); ///< This function sets the list tail node. @param[in] linkedlist::singlelink::DataNode<T>* nodeptrTail
				
				void addNode(linkedlist::singlelink::DataNode<T>*); ///< This function add a new data node to the end of the list. @param[in] linkedlist::singlelink::DataNode<T>* newNode
				
				
				//Test function -- Erase
				void printListData() {
					linkedlist::singlelink::DataNode<T>* currentNode = listHead;
					
					// std::cout << "Row 1 node address: " << currentNode << std::endl;
					// std::cout << "Row 1 node value  : " << &currentNode->getValue() << std::endl;
					// std::cout << "Row 1 node nxt add: " << currentNode->getNextNode() << std::endl;
					// std::cout << '\n';
					
					// T dataNode = currentNode->getValue();
					
					// std::cout << "\tCol 1 node address: " << &dataNode << std::endl;
					// std::cout << "\tCol 1 node value  :" << dataNode.getValue() << std::endl;
					// std::cout << "\tCol 1 node nxt add: " << dataNode.getNextNode() << std::endl;
					// std::cout << '\n';
					
					// currentNode = currentNode->getNextNode();
					
					// std::cout << "Row 2 node address: " << currentNode << std::endl;
					// std::cout << "Row 2 node value  : " << &currentNode->getValue() << std::endl;
					// std::cout << "Row 2 node nxt add: " << currentNode->getNextNode() << std::endl;
					// std::cout << '\n';
					
					// dataNode = currentNode->getValue();
					
					// std::cout << "\tCol 1 node address: " << &dataNode << std::endl;
					// std::cout << "\tCol 1 node value  :" << dataNode.getValue() << std::endl;
					// std::cout << "\tCol 1 node nxt add: " << dataNode.getNextNode() << std::endl;
					// std::cout << '\n';
					
					// currentNode = currentNode->getNextNode();
					
					// std::cout << "Row 3 node address: " << currentNode << std::endl;
					// std::cout << "Row 3 node value  : " << &currentNode->getValue() << std::endl;
					// std::cout << "Row 3 node nxt add: " << currentNode->getNextNode() << std::endl;
				}
			
		};
		
	}
	
	namespace doublelink {
		
		template <typename T>
		class DataNode {
			
			private:
				linkedlist::doublelink::DataNode<T>* prevNode;
				linkedlist::doublelink::DataNode<T>* nextNode;
				
				T value;
				
			public:
				DataNode();
				DataNode(T);
				DataNode(T, linkedlist::doublelink::DataNode<T>*);
				DataNode(T, linkedlist::doublelink::DataNode<T>*, linkedlist::doublelink::DataNode<T>*);
				
				linkedlist::doublelink::DataNode<T>* getPrevNode();
				linkedlist::doublelink::DataNode<T>* getNextNode();
				T getValue();
				
				void setPrevNode(linkedlist::doublelink::DataNode<T>*);
				void setNextNode(linkedlist::doublelink::DataNode<T>*);
				void setValue(T);
				
				void addDataNode(linkedlist::doublelink::DataNode<T>*);
			
		};
		
		template <typename T>
		class ListController {
			
			private:
				int size;
				
				linkedlist::doublelink::DataNode<T>* listHead;
				linkedlist::doublelink::DataNode<T>* listTail;
				
			public:
				ListController();
				ListController(linkedlist::doublelink::DataNode<T>*);
				ListController(linkedlist::doublelink::DataNode<T>*, linkedlist::doublelink::DataNode<T>*);
				
				int getSize();
				linkedlist::doublelink::DataNode<T>* getListHead();
				linkedlist::doublelink::DataNode<T>* getListTail();
				
				void setListHead(linkedlist::doublelink::DataNode<T>*);
				void setListTail(linkedlist::doublelink::DataNode<T>*);
				
				void addNode(linkedlist::doublelink::DataNode<T>*);
			
		};
		
	}
}

// Singly linked class

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode() {
	nextNode = nullptr;
	
	value = NULL;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue) {
	nextNode = nullptr;
	
	value = nodeValue;
}

template <typename T>
linkedlist::singlelink::DataNode<T>::DataNode(T nodeValue, linkedlist::singlelink::DataNode<T>* nodeptr) {
	nextNode = nodeptr;
	
	value = nodeValue;
}

template <typename T>
linkedlist::singlelink::DataNode<T>* linkedlist::singlelink::DataNode<T>::getNextNode() {
	return nextNode;
}

template <typename T>
T linkedlist::singlelink::DataNode<T>::getValue() {
	return value;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::setValue(T nodeValue) {
	value = nodeValue;
}

template <typename T>
void linkedlist::singlelink::DataNode<T>::addDataNode(linkedlist::singlelink::DataNode<T>* newNode) {
	nextNode = newNode;
}

// Doubly linked class

template <typename T>
linkedlist::doublelink::DataNode<T>::DataNode() {
	prevNode = nullptr;
	nextNode = nullptr;
	
	value = NULL;
}

template <typename T>
linkedlist::doublelink::DataNode<T>::DataNode(T nodeValue) {
	prevNode = nullptr;
	nextNode = nullptr;
	
	value = nodeValue;
}

template <typename T>
linkedlist::doublelink::DataNode<T>::DataNode(T nodeValue, linkedlist::doublelink::DataNode<T>* nodeptrPrev, linkedlist::doublelink::DataNode<T>* nodeptrNext) {
	prevNode = nodeptrPrev;
	nextNode = nodeptrNext;
	
	value = nodeValue;
}

template <typename T>
linkedlist::doublelink::DataNode<T>* linkedlist::doublelink::DataNode<T>::getPrevNode() {
	return prevNode;
}

template <typename T>
linkedlist::doublelink::DataNode<T>* linkedlist::doublelink::DataNode<T>::getNextNode() {
	return nextNode;
}

template <typename T>
T linkedlist::doublelink::DataNode<T>::getValue() {
	return value;
}

template <typename T>
void linkedlist::doublelink::DataNode<T>::setPrevNode(linkedlist::doublelink::DataNode<T>* nodeptrPrev) {
	prevNode = nodeptrPrev;
}

template <typename T>
void linkedlist::doublelink::DataNode<T>::setNextNode(linkedlist::doublelink::DataNode<T>* nodeptrNext) {
	nextNode = nodeptrNext;
}

template <typename T>
void linkedlist::doublelink::DataNode<T>::setValue(T nodeValue) {
	value = nodeValue;
}

template <typename T>
void linkedlist::doublelink::DataNode<T>::addDataNode(linkedlist::doublelink::DataNode<T>* newNode) {
	if(nextNode == nullptr) {
		newNode->setNextNode(this);
		nextNode = newNode;
	}else {
		newNode->setNextNode(nextNode);
		newNode->setPrevNode(this);
		
		nextNode->setPrevNode(newNode);
		this->setNextNode(newNode);
	}
}

// List controller class singly linked

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
	
	for(int i = 0; i < n; i++) {
		linkedlist::singlelink::DataNode<T>* tmpNode = new linkedlist::singlelink::DataNode<T>(NULL);
		
		addNode(tmpNode);
	}
}

template <typename T>
linkedlist::singlelink::ListController<T>::ListController(int r, int c) {
	size = 0;
	
	listHead = nullptr;
	listTail = nullptr;
	
	for(int i = 0; i < 1; i++) {
		linkedlist::singlelink::DataNode<T>* rowNode = new linkedlist::singlelink::DataNode<T>(NULL);
		std::cout << "New node: " << rowNode << std::endl;
		addNode(rowNode);
		std::cout << &rowNode->getValue() << std::endl;
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
	if(nodeptrHead == nodeptrTail) {
		size = 1;
	}else {
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
void linkedlist::singlelink::ListController<T>::addNode(linkedlist::singlelink::DataNode<T>* newNode) {
	// Case 1: Adding to empty list.
	// Case 2: Adding to list of size 1.
	// Case 3: Adding to list greater than size 1.
	
	if(listHead == nullptr) {
		listHead = newNode;
	}else {
		listTail->addDataNode(newNode);
	}
	
	listTail = newNode;
	size += 1;
}

// List controller class doubly linked

template <typename T>
linkedlist::doublelink::ListController<T>::ListController() {
	size = 0;
	
	listHead = nullptr;
	listTail = nullptr;
}

template <typename T>
linkedlist::doublelink::ListController<T>::ListController(linkedlist::doublelink::DataNode<T>* nodeptrHead) {
	size = 1;
	
	listHead = nodeptrHead;
	listTail = nodeptrHead;
}

template <typename T>
linkedlist::doublelink::ListController<T>::ListController(linkedlist::doublelink::DataNode<T>* nodeptrHead, linkedlist::doublelink::DataNode<T>* nodeptrTail) {
	if(nodeptrHead == nodeptrTail) {
		size = 1;
	}else {
		size = 2;
	}
	
	listHead = nodeptrHead;
	listTail = nodeptrTail;
}

template <typename T>
int linkedlist::doublelink::ListController<T>::getSize() {
	return size;
}

template <typename T>
linkedlist::doublelink::DataNode<T>* linkedlist::doublelink::ListController<T>::getListHead() {
	return listHead;
}

template <typename T>
linkedlist::doublelink::DataNode<T>* linkedlist::doublelink::ListController<T>::getListTail() {
	return listTail;
}

template <typename T>
void linkedlist::doublelink::ListController<T>::setListHead(linkedlist::doublelink::DataNode<T>* nodeptrHead) {
	listHead = nodeptrHead;
}

template <typename T>
void linkedlist::doublelink::ListController<T>::setListTail(linkedlist::doublelink::DataNode<T>* nodeptrTail) {
	listTail = nodeptrTail;
}

template <typename T>
void linkedlist::doublelink::ListController<T>::addNode(linkedlist::doublelink::DataNode<T>* newNode) {
	// Case 1: Adding to empty list.
	// Case 2: Adding to list of size 1.
	// Case 3: Adding to list greater than size 1.
	
	if(listHead == nullptr) {
		newNode->setPrevNode(nullptr);
		newNode->setNextNode(nullptr);
		listHead = newNode;
	}else {
		listTail->addDataNode(newNode);
	}
	
	listTail = newNode;
	size += 1;
}