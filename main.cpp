#include <iostream>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {

	ListController<int> listOne(10, 10, 1);

	std::cout << listOne << std::endl;

	DataNode<int>* d = &listOne[0][1];

	std::cout << d << std::endl;

	std::cout << listOne << std::endl;

	return 0;
	
}