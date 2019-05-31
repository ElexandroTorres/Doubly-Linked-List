#include <iostream>
#include "../include/list.h"

int main() { {
	sc::list<int> lista1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	//sc::list<int>::iterator it;
	//it = lista1.begin();
	
	sc::list<int> lista2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


	/*
	while(it != lista1.end()) {
		std::cout << *it << "<<\n";	
		++it;	
	}
	
	*/

	//
	std::cout << "teste comparação: \n";
	if(lista1 != lista2) {
		std::cout << "As listas são diferentes.\n";
		
	}
	else {
		std::cout << "As listas são iguais.\n";
	}

}	
	return 0;

}