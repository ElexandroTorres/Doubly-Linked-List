#include <iostream>
#include "../include/list.h"

int main() { {
	ls::list<int> teste;
	teste.push_front(3);
	teste.push_front(2);
	teste.push_front(1);

	std::cout << "Tamanho da lista: " << teste.size() << "\n";
	teste.print();
	teste.pop_back();
	teste.print();
	teste.clear();
	teste.print();
}	
	return 0;

}