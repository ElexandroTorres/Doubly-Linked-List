#include <iostream>  // cout, endl
#include <cassert>   // assert()
#include "list.h"


// The vector/iterator driver.
int main( void )
{
    sc::list<int> lista{1, 2, 3, 4};

    sc::list<int>::const_iterator it;

    it = lista.find(1); 


    std::cout << "valor achado: " << *it << std::endl;  
    std::cout << "lista: " << lista << std::endl;

    return 0;
}
