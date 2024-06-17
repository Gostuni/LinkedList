#include <iostream>
#include "LinkedList.h"


int main() {
	linkedlist::singlelink::ListController<linkedlist::singlelink::DataNode<int>> arrayOne(3, 3);
	
	arrayOne.printListData();
	
	return 0;
	
}