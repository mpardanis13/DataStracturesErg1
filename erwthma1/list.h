// Dhlwsh ths basikhs klashs mona syndedemenhs listas poy ua
// xrhsimopoihsoyme sto programma mas
template <class T>
class ListNode
{
    template <class U>
    friend class List;

private:
    T data[2];         // Ua xreiastoyme 2 theseis sto pedio data kathws h lista histogram
    ListNode<T> *link; // prepei na periexei 2 plhrofories (arithmos kai plithos)
};

template <class T>
class List
{
public:
    List(int size);
    List(const List &L);
    ~List();
    void sort();

private:
    ListNode<T> *first;
    int size;
};

// Dhmioyrgia constructor gia thn lista L
template <class T>
List<T>::List(int size)
{
    first = new ListNode<T>;
    ListNode<T> *current = first;

    for (int i = 0; i < size; i++)
    {
        current->data[0] = random_element(); // Xrhsimopoihtai h gennhtria tyxaiwn arithmwn
        current->link = new ListNode<T>;     // opws perigrafetai sthn ekfwnhsh
        current = current->link;
    }
}

// Taksinomhsh ths listas (sxetika me to prwto stoixeio toy pinaka data)
template <class T>
void List<T>::sort()
{
    ListNode<T> *current = first;
    while (current)
    {
        ListNode<T> *index = current->link;
        while (index)
        {
            if (current->data[0] > index->data[0])
            {
                swap(current->data[0], index->data[0]);
            }
            index = index->link;
        }
        current = current->link;
    }
}

// Constructor ths listas Histogram
template <class T>
List<T>::List(const List &L)
{
    ListNode<T> *currentL = L.first;
    first = new ListNode<T>;
    ListNode<T> *currentH = first;
    int count = 1;

    // Ypologismos toy plithoys kathe stoixeioy ths listas L kai apothikeysh toy sth
    // lista Histogram
    while (currentL)
    {
        if (!currentL->link)
        {
            currentH->data[1] = count;
            currentH->data[0] = currentL->data[0];
            break;
        }
        else if (currentL->data[0] != currentL->link->data[0])
        {
            currentH->data[1] = count;
            currentH->data[0] = currentL->data[0];
            currentH->link = new ListNode<T>;
            currentH = currentH->link;
            count = 1;
        }
        else
        {
            count++;
        }
        currentL = currentL->link;
    }

    // Emfanish apotelesmatwn
    currentH = first;
    while (currentH)
    {
        cout << "The number " << currentH->data[0] << " appears " << currentH->data[1] << ((currentH->data[1] == 1) ? " time" : " times") << " in list L." << endl;
        currentH = currentH->link;
    }
}

// Dhmioyrgia destructor gia tis 2 listes
template <class T>
List<T>::~List()
{
    ListNode<T> *next;
    while (first)
    {
        next = first->link;
        delete first;
        first = next;
    }
}