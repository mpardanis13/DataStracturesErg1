#include <functional>
#include <iostream>
#include <random>

using std::default_random_engine, std::chi_squared_distribution, std::bind, std::cout, std::cin, std::swap, std::endl, std::out_of_range, std::bad_alloc;

default_random_engine generator;
chi_squared_distribution<float> my_distribution(0.5);
auto random_num = bind(my_distribution, generator);

#include "heap.h"

int main()
{
    cout << "Please enter the size of the heaps: ";
    int N;
    cin >> N; // Diabazoyme to megethos toy pinaka apo ton xrhsth
    ++N;      // Ayksanoyme to megethos kata 1 wste ta stoixeia na einai apothikeymena se morfh
              // dyadikoy symplhrwmenoy dendroy
    float *heap_min = new float[N]; // Desmeboyme dynamika mnhmh gia ton pinaka heap_min

    for (int i = 1; i < N; i++)
    {
        heap_min[i] = random_num() * 10000.0; // Gemizoyme ton pinaka heap_min me tyxaies times 
                                              // opws perigrafetai sthn ekfwnhsh
    }

    float *heap_max = new float[N]; // Desmeboyme dynamika mnhmh gia ton pinaka heap_max

    for (int i = 1; i < N; i++)
    {
        heap_max[i] = heap_min[i]; // Antigrafoyme ta stoixeia toy pinaka heap_min ston heap_max
    }

    MinHeap<float> minHeap(N - 1);          // Dhmioyrgoyme ton swro elaxistwn megethoys N
    minHeap.initialize(heap_min, N - 1, N); // Ton arxikopoioyme me ton pinaka heap_min

    MaxHeap<float> maxHeap(N - 1);          // Dhmioyrgoyme ton swro megistwn megethoys N
    maxHeap.initialize(heap_max, N - 1, N); // Ton arxikopoioyme me ton pinaka heap_max

    minHeap.findSum(); // Vriskoyme to athroisma toy swroy elaxistwn kai megistwn antistoixa
    maxHeap.findSum();

    delete[] heap_min; // Apodesmeboyme th mnhmh poy desmeysame gia toys dyo pinakes
    delete[] heap_max;

    return 0;
}
