#include <iostream>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {
	ListController<int> listOne(200, 200, 0);

	int value = 1;

	for (int i = 0; i < listOne.getSize(); i++) {
		for (int j = 0; j < listOne.getRowSize(); j++) {
			listOne[i][j] = value;
			value += 1;
		}
	}

	return 0;
	
}