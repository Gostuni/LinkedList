#include <iostream>
#include "LinkedList.h"

using namespace linkedlist::singlelink;

int main() {

	//ListController<int> listOne(10, 10, 1);

	//*listOne[0][0] = 9;
	//*listOne[0][1] = 9;
	//*listOne[0][2] = 9;
	//*listOne[0][3] = 9;
	//*listOne[0][4] = 9;
	//*listOne[0][5] = 9;

	//std::cout << listOne[0][0] << std::endl;

	//std::cout << listOne << std::endl;

	ListController<int> listOne(10, 0);

	std::cout << listOne << std::endl;

	listOne[1] = 9;

	std::cout << listOne << std::endl;

	return 0;
	
}