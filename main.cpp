#include <iostream>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {
	DataNode<int> nodeOne(1);
	DataNode<int> nodeTwo(2);
	ListController<int> llOne = ListController<int>(&nodeOne, &nodeTwo);

	std::cout << llOne << std::endl;

	return 0;
	
}