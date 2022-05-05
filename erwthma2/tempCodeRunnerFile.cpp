while (true)
    {
        try
        {
            maxHeap.deleteMax(max1); // Afairoyme ta dyo megista stoixeia toy swroy megistwn
            maxHeap.deleteMax(max2);
            maxHeap.insert(max1 + max2); // Eisagoyme to athroisma toys pali ston swro
        }
        catch (out_of_range)
        {
            cout << "The sum of the numbers using a MaxHeap is: " << (max1 > max2 ? max1 : max2) << endl;
            maxHeap.deactive(); // Apenergopoioyme ton swro megistwn
        }

        try
        {
            minHeap.deleteMin(min1);
            minHeap.deleteMin(min2);
            minHeap.insert(min1 + min2);
        }
        catch (out_of_range)
        {
            cout << "The sum of the numbers using a MinHeap is: " << (min1 > min2 ? min1 : min2) << endl;
            break;
        }
    }