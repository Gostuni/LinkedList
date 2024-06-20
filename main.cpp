#include <iostream>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {

	ListController<int> listOne(10, 10, 0);

	std::cout << listOne << std::endl;

	std::cout << listOne[0] << std::endl;

	std::cout << '\n';

	*listOne[0][0] = 9;

	std::cout << listOne[0][0] << std::endl;

	return 0;
	
}