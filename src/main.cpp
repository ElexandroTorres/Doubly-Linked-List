#include <iostream>
#include <list>
#include "../include/list.h"
#include <iterator>
#include <iostream>

int main() { {
	sc::list<int> lista1{1, 2, 3, 4};
	//sc::list<int>::iterator it;
	//it = lista1.begin();
	
	sc::list<int> lista2{9, 10, 11, 12};

	sc::list<int>::iterator it;
	it = lista1.begin();
	it++;
	//auto teste = lista1.insert(it, 88);
	it = lista1.begin();
	it++;
	//lista1.insert(it, 90);
	lista1.print();
	it = lista1.begin();
	///std::cout << "lista1 tamanho> " << lista1.size() << "\n";
	lista1.insert(it, lista2.begin(), lista2.end());
	lista1.print();
	std::cout << "tam: " << lista1.size() << "\n";

}	
	return 0;

}