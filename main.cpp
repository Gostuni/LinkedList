#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {

	List<int> lone(5, 4);

	lone[0] = 9;

	std::cout << lone[1] << std::endl;

	return 0;

}