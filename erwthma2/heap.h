// Dhlwnoyme th klash toy swroy megistwn
template <class T>
class MaxHeap
{
public:
    MaxHeap(int maxHeapSize = 10);
    ~MaxHeap() { delete[] heap; }
    int size() const { return currentSize; }
    void initialize(T a[], int size, int arraySize);
    MaxHeap<T> &insert(const T &x);
    MaxHeap<T> &deleteMax(T &x);
    void deactive() { heap = 0; }
    void output() const;
    void findSum();

private:
    int currentSize,
        maxSize;
    T *heap; // pinakas twn stoixeiwn
};

// Constructor swroy megistwn
template <class T>
MaxHeap<T>::MaxHeap(int maxHeapSize)
{
    maxSize = maxHeapSize;
    heap = new T[maxSize + 1];
    currentSize = 0;
}

// Arxikopoihsh swroy megistwn ston pinaka a
template <class T>
void MaxHeap<T>::initialize(T a[], int size, int arraySize)
{
    delete[] heap;
    heap = a;
    currentSize = size;
    maxSize = arraySize;

    // Metatroph se swro megistwn
    for (int i = currentSize / 2; i >= 1; i--)
    {
        T y = heap[i]; // Riza toy ypodendroy

        // Eyresh xwroy gia to y
        int c = 2 * i; // Theloyme na topothetisoyme to y ston gonea toy c

        while (c <= currentSize)
        {
            // heap[c] prepei na einai to megalytero
            if (c < currentSize &&
                heap[c] < heap[c + 1])
                c++;
            // Elegxoyme ean mporoyme na topothethsoyme to y sto heap[c/2]
            if (y >= heap[c])
                break; // nai
            // oxi
            heap[c / 2] = heap[c]; // Metakinoyme to paidi epanw
            c *= 2;                // Katebainoyme ena epipedo
        }
        heap[c / 2] = y;
    }
}

// Eisagwgh stoixeioy ston swro
template <class T>
MaxHeap<T> &MaxHeap<T>::insert(const T &x)
{
    if (currentSize == maxSize)
        throw bad_alloc(); // Aneparkhs xwros

    // Vriskoyme xwro gia to x
    // Arxikopoioyme to i se ena kainoyrio filo kai ayto "anebainei" sto dendro
    int i = ++currentSize;
    while (i != 1 && x > heap[i / 2])
    {
        // Den mporoyme na topothetisoyme to x sto heap[i]
        heap[i] = heap[i / 2]; // Metakinhsh stoixeioy pros ta katw
        i /= 2;                // Metakinhsh ston gonea
    }
    heap[i] = x;
    return *this;
}

// Eksagwgh kai apothikeysh toy megistoy stoixeioy
template <class T>
MaxHeap<T> &MaxHeap<T>::deleteMax(T &x)
{
    // Elegxoyme ean o swros einai adeios
    if (currentSize == 0)
        throw out_of_range("");

    x = heap[1]; // Megisto stoixeio

    // Anadiorthwsh toy swroy
    T y = heap[currentSize--]; // Teleytaio stoixeio

    // Eyresh xwroy gia to y ksekinwntas apo th riza
    int i = 1,  // Trexwn kombos
        ci = 2; // Paidi toy i

    while (ci <= currentSize)
    {
        // To heap[ci] prepei na einai to megaytero paidi toy i
        if (ci < currentSize && heap[ci] < heap[ci + 1])
            ci++;

        // Elegxoyme an mporoyme na eisagoyme to y sto heap[ci]
        if (y >= heap[ci])
            break; // Ean nai bgainoyme apo ton broxo

        // Diaforetika
        heap[i] = heap[ci]; // Metakinoyme to paidi pros ta panw
        i = ci;             // Katebainoyme ena epipedo
        ci *= 2;
    }
    heap[i] = y;
    return *this;
}

// Eyresh athroismatos swroy megistwn
template <class T>
void MaxHeap<T>::findSum()
{
    float max1, max2;  // Dhlwnoyme dyo metablhtes stis opoies ua apothikeboyme kathe fora ta
                       // dyo megalytera stoixeia toy swroy megistwn
    while (true)
    {
        try
        {
            deleteMax(max1); // Afairoyme ta dyo megalytera stoixeia toy swroy megistwn
            deleteMax(max2);
            insert(max1 + max2); // Eisagoyme to athroisma toys pali ston swro
        }
        catch (out_of_range)
        { // Emfanizoyme apotelesmata otan afairethei to teleytaio stoixeio toy swroy
          // to opoio einai kai to athroisma olwn twn stoixeiwn.
            // To athroisma ua einai apothikeymeno sto max1 kathws ua einai to mono stoixeio poy afaireitai
            cout << "The sum of the numbers using a MaxHeap is: " << max1 << endl;
            deactive(); // Apenergopoioyme ton swro megistwn
            break; // Termatizoyme th diadikasia
        }
    }
}

// Dhlwnoyme th klash toy swroy elaxistwn
template <class T>
class MinHeap
{
public:
    MinHeap(int minHeapSize = 10);
    ~MinHeap() { delete[] heap; }
    int size() const { return currentSize; }
    void initialize(T a[], int size, int arraySize);
    MinHeap<T> &insert(const T &x);
    MinHeap<T> &deleteMin(T &x);
    void deactive() { heap = 0; }
    void output() const;
    void findSum();

private:
    int currentSize, maxSize;
    T *heap; // element array
};

// Constructor swroy elaxistwn
template <class T>
MinHeap<T>::MinHeap(int minHeapSize)
{
    maxSize = minHeapSize;
    heap = new T[maxSize + 1];
    currentSize = 0;
}

// Arxikopoihsh swroy elaxistwn ston pinaka a
template <class T>
void MinHeap<T>::initialize(T a[], int size, int arraySize)
{
    delete[] heap;
    heap = a;
    currentSize = size;
    maxSize = arraySize;

    // Metatroph se swro elaxistwn
    for (int i = currentSize / 2; i >= 1; i--)
    {
        T y = heap[i]; // Riza toy ypodendroy

        // Eyresh xwroy gia to y
        int c = 2 * i; // Theloyme na topothetisoyme to y ston gonea toy c

        while (c <= currentSize)
        {
            // To heap[c] prepei na einai to mikrotero paidi
            if (c < currentSize && heap[c] > heap[c + 1])
                c++;

            // Elegxoyme an mporoyme na eisagoyme to y sto heap[c]
            if (y <= heap[c])
                break; // Ean nai bgainoyme apo ton broxo

            // Diaforetika
            heap[c / 2] = heap[c]; // Metakinoyme to paidi pros ta panw
            c *= 2;                // Katebainoyme ena epipedo
        }
        heap[c / 2] = y;
    }
}

// Eisagwgh stoixeioy ston swro
template <class T>
MinHeap<T> &MinHeap<T>::insert(const T &x)
{
    if (currentSize == maxSize)
        throw bad_alloc(); // Aneparkhs xwros

    // Vriskoyme xwro gia to x
    // Arxikopoioyme to i se ena kainoyrio filo kai ayto "anebainei" sto dendro
    int i = ++currentSize;
    while (i != 1 && x < heap[i / 2])
    {
        // Den mporoyme na topothetisoyme to x sto heap[i]
        heap[i] = heap[i / 2]; // Metakinhsh stoixeioy pros ta katw
        i /= 2;                // Metakinhsh ston gonea
    }
    heap[i] = x;
    return *this;
}

// Eksagwgh kai apothikeysh toy megistoy stoixeioy
template <class T>
MinHeap<T> &MinHeap<T>::deleteMin(T &x)
{
    // Elegxoyme ean o swros einai adeios
    if (currentSize == 0)
        throw out_of_range("");

    x = heap[1]; // Elaxisto stoixeio
    // cout << x << endl;

    // Anadiorthwsh toy swroy
    T y = heap[currentSize--]; // Teleytaio stoixeio

    // Eyresh xwroy gia to y ksekinwntas apo th riza
    int i = 1,  // Trexwn kombos
        ci = 2; // Paidi toy i

    while (ci <= currentSize)
    {
        // To heap[ci] prepei na einai to megaytero paidi toy i
        if (ci < currentSize && heap[ci] > heap[ci + 1])
            ci++;

        // Elegxoyme an mporoyme na eisagoyme to y sto heap[ci]
        if (y <= heap[ci])
            break; // Ean nai bgainoyme apo ton broxo

        // Diaforetika
        heap[i] = heap[ci]; // Metakinoyme to paidi pros ta panw
        i = ci;             // Katebainoyme ena epipedo
        ci *= 2;
    }
    heap[i] = y;
    return *this;
}

// Eyresh athroismatos swroy elaxistwn
template <class T>
void MinHeap<T>::findSum()
{
    float min1, min2; // Dhlwnoyme dyo metablhtes stis opoies ua apothikeboyme kathe fora ta
                      // dyo mikrotera stoixeia toy swroy elaxistwn
    while (true)
    {
        try
        {
            deleteMin(min1); // Afairoyme ta dyo mikrotera stoixeia toy swroy elaxistwn
            deleteMin(min2);
            insert(min1 + min2); // Eisagoyme to athroisma toys pali ston swro
        }
        catch (out_of_range)
        {
            cout << "The sum of the numbers using a MinHeap is: " << min1 << endl;
            deactive(); // Apenergopoioyme ton swro elaxistwn
            break; // Termatizoyme th diadikasia
        }
    }
}