#include <iostream>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {
	DataNode<int> d4(100);

	DataNode<int> d3(10);
	d3.addDataNode(&d4);

	DataNode<int> d2(5, &d3);

	DataNode<int> d1;
	d1.setValue(1);
	d1.setNextNode(&d2);

	std::cout << d1 << std::endl;

	std::cout << d1[3] << std::endl;

	return 0;
	
}