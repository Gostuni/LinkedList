#include <iostream>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {
	ListController<DataNode<int>> llOne(4, 1, 0);

	std::cout << llOne << std::endl;

	llOne.append2D(2, 0, false);

	std::cout << llOne << std::endl;

	return 0;
	
}