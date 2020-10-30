#ifndef PQUEUE_CLASS
#define PQUEUE_CLASS

using namespace std;

template <class T>
class PQueue
{
    private:
    	// a linked list to hold the queue items
        Node<T>* queueFront;//pointer to the head of the list
        int count;//number of elements in the the queue

    public:
    	// constructor
        PQueue(void);

        // queue access methods
        void PQInsert(const T& item);//inserts the item in the correct position.
        T PQDelete(void);//Deletes the highest priority element at the queue front

        // queue access returns the highest priority element that is in the queue in O(1) time
        T PQFront(void);

        // queue test methods
        int PQLength(void) const;
        int PQEmpty(void) const;// return 1 iff the queue is empty
        void PQClear(void);//dynamically allocated memory for the nodes must be returned
        void ShowPQ (void) const; // prints the content of the priority queue from front to rear on the standard output (with cout)

};



#endif  // PQUEUE_CLASS
