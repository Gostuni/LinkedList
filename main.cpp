#include <iostream>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {
	ListController<DataNode<int>> llOne(4, 1, 0);

	std::cout << llOne << std::endl;

	llOne.append2D(2);

	std::cout << llOne << std::endl;

	ListController<int> llTwo(5, 0);

	std::cout << llTwo << std::endl;

	llTwo.append(6);

	std::cout << llTwo << std::endl;

	return 0;
	
}