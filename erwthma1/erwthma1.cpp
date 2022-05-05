#include <functional>
#include <iostream>
#include <random>
using std::default_random_engine, std::uniform_int_distribution, std::bind, std::cout, std::cin, std::swap, std::endl;

default_random_engine generator;
uniform_int_distribution<int> data_element_distribution(0, 20);
auto random_element = bind(data_element_distribution, generator);

#include "list.h"

int main()
{
    cout << "Please provide the size of list L: ";
    int size;
    cin >> size;            // Pairnoyme apo ton xrhsth to megethos ths listas L
    List<int> L(size);      // Dhmioyrgoyme th lista L
    L.sort();               // Taksinomoyme th lista L gia eykoloterh epeksergasia
    List<int> Histogram(L); // Dhmioyrgoyme th lista histogram
    return 0;
}
