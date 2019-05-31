#include <iostream>
#include "../include/list.h"

int main() { {
	sc::list<int> lista1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	//sc::list<int>::iterator it;
	//it = lista1.begin();
	
	sc::list<int> lista2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};


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

	lista1 = lista2;

	std::cout << "teste comparação: \n";
	if(lista1 != lista2) {
		std::cout << "As listas são diferentes.\n";
		
	}
	else {
		std::cout << "As listas são iguais.\n";
	}

	lista1 = {1, 2, 3, 4, 2, 2, 2, 2};
	sc::list<int>::iterator it;
	it = lista1.begin();
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	it++;
	lista1.insert(it, 88);

	lista1.print();
	std::cout << "lista1 tamanho> " << lista1.size() << "\n";

}	
	return 0;

}