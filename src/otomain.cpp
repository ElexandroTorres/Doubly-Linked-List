#include <iostream>
#include "../include/list.h"

int main() { {
	sc::list<int> teste{1, 2, 3, 4};
	sc::list<int>::iterator it;
	it = teste.begin();
	
	while(it != teste.end()) {
		std::cout << *it << "<<\n";	
		++it;	
	}
	teste.print();
}	
	return 0;

}