#include <functional>
#include <iostream>
#include <random>

using std::default_random_engine, std::chi_squared_distribution, std::bind, std::cout, std::cin, std::swap, std::endl, std::out_of_range, std::bad_alloc, std::copy;

default_random_engine generator;
chi_squared_distribution<float> my_distribution(0.5);
auto random_num = bind(my_distribution, generator);
#include "heap.h"

int main()
{
    cout << "Please enter the size of the heaps: ";
    int N;
    cin >> N;   // Diabazoyme to megethos toy pinaka apo ton xrhsth
    N++;    // Ayksanoyme to megethos kata 1 wste ta stoixeia na einai apothikeymena se morfh
            // dyadikoy symplhrwmenoy dendroy
    double *heap_min = new double(N); // Desmeboyme dynamika mnhmh gia toys dyo pinakes
    double *heap_max = new double(N);

    for (int i = 1; i < N; i++)
    {
        heap_max[i] = random_num() * 10000.0; // Gemizoyme ton pinaka heap_max me tyxaies times opws perigrafetai sthn ekfwnhsh
        heap_min[i] = heap_max[i];            // Antigrafoyme ta stoixeia toy pinaka heap_max ston heap_min
    }

    MaxHeap<double> maxHeap(N);         // Dhmioyrgoyme ton swro megistwn megethoys N
    maxHeap.initialize(heap_max, N, N); // Ton arxikopoioyme me ton pinaka heap_max

    MinHeap<double> minHeap(N);         // Dhmioyrgoyme ton swro elaxistwn megethoys N
    minHeap.initialize(heap_min, N, N); // Ton arxikopoioyme me ton pinaka heap_min

    double max1, min1, max2, min2; // Arxikopoiyme tis times stis opoies ua apothikeytoyn oi megistes
                                   // times toy swroy megistwn kai oi elaxistes toy swroy elaxistwn

    while (true)
    {
        try
        {
            maxHeap.deleteMax(max1); // Afairoyme ta dyo megista stoixeia toy swroy megistwn
            maxHeap.deleteMax(max2);
            maxHeap.insert(max1 + max2); // Eisagoyme to athroisma toys pali ston swro
        }
        catch (out_of_range) 
        {// Emfanizoyme apotelesmata otan afairethei to teleytaio stoixeio toy swroy 
         // to opoio einai kai to athroisma olwn twn stoixeiwn.
            // To athroisma ua einai apothikeymeno sto max1 kathws ua einai to mono stoixeio poy afaireitai
            cout << "The sum of the numbers using a MaxHeap is: " << max1 << endl;
            maxHeap.deactive(); // Apenergopoioyme ton swro megistwn

        }
        // Omoiws gia ton swro elaxistwn
        try
        {
            minHeap.deleteMin(min1); // Afairoyme ta dyo mikrotera stoixeia toy swroy elaxistwn
            minHeap.deleteMin(min2);
            minHeap.insert(min1 + min2); // Eisagoyme to athroisma toys pali ston swro

        }
        catch (out_of_range)
        {
            minHeap.deactive(); // Apenergopoioyme ton swro elaxistwn
            cout << "The sum of the numbers using a MinHeap is: " << min1 << endl;
            break;
        }
    }
    return 0;
}
