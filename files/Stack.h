#ifndef STACK_CLASS
#define STACK_CLASS

using namespace std;

template <class T>
class Stack
{
    private:
        // a linked list to hold the stack items
        Node<T>* stackTop; // deepmost element of the stack unless the stack is empty

    public:
    	// constructor
        Stack(void);

        // stack access methods
        void Push(const T& item);
        T Pop(void);
        T Peek(void);

        // stack test and clear methods
        int StackEmpty(void) const; // return 1 iff the stack is empty
        void ClearStack(void); //dynamically allocated memory for the nodes must be returned
        void ShowStack (void) const; // prints the content of the stack from top to bottom on the standard output (with cout)


};



#endif  // STACK_CLASS
