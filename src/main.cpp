#include <iostream>
#include "../include/list.h"

int main() { {
	ls::list<int> teste;
	teste.push_front(3);
	teste.push_front(2);
	teste.push_front(1);
	teste.push_back(4);
	teste.push_back(5);
	teste.push_front(0);
	teste.pop_front();
	teste.pop_back();
	std::cout << "Tamanho da lista: " << teste.size() << "\n";
	teste.print();
	std::cout << "Item no final da lista: " << teste.back() << "\n";
	std::cout << "Item no inicio da lista: " << teste.front() << "\n";
	//teste.clear();
	std::cout << "EMpty?: " << teste.empty() << "\n";

	std::cout << "assign com 4 elementos com valor 6: \n";
	teste.assign(20, 6);
	teste.print();
}	
	return 0;

}