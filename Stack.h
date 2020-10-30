#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class Stack
{
    private:                         // a linked list to store the stack items
        Node<T>* stackTop;          // top item of the stack, head pointer of   the linked list

    public:                         // constructor

    Stack(void);                    // stack access methods

    void Push(const T& item);

    T Pop(void);                    // deletes the top item and returns it

    T Peek(void);                   // returns the top item without deleting it stack test and clear methods

    int StackEmpty(void);     // return 1 if the stack is    empty


    void ClearStack(void);          //dynamically allocated memory for    the nodes must be returned

    void ShowStack (void);    // prints the content of the stack from top to bottom on the standard output (with cout)

};

template <class T>
Stack<T>::Stack(void)
{
	stackTop=NULL;
}


template <class T>
void Stack<T>::Push(const T& item)
{
	Node<T> *temp;
	temp=stackTop;
	stackTop=new Node<T>(item,temp);
}

template <class T>
T Stack<T>::Pop(void)
    {
        if(stackTop==NULL)
        {
            cerr<<"Stack is empty";             //erorr
            exit(1);
        }
       else
       {
           T popped= stackTop->data;
           Node<T>* temp=stackTop;
           stackTop=stackTop->NextNode();
           delete temp;
           return popped;
       }

    }
template <class T>
T Stack<T>::Peek(void)
{
    if(stackTop==NULL)
        {
            cerr<<"Stack is empty";
            exit(1);
        }
       else
       {
           T x =stackTop->data;             //return data of top of stack
           return x;
       }
}
template <class T>
int Stack<T>::StackEmpty()
{
    if(stackTop==NULL)                  //if stacktop== 0 , stack is empty
    {
        return 1;
    }
    else
        return 0;
}
template <class T>
void Stack<T>::ClearStack(void)
{
	Node<T> * temp;
	while(stackTop!=NULL){
		temp=stackTop;
		stackTop=temp->NextNode();
		delete temp;
	}
}


template <class T>
void Stack<T>::ShowStack(void)
{
    Node<T>* temp;
    if(stackTop==NULL)
    {
        cout<<"\nStack Underflow";
        exit(1);
    }
    else
    {
        temp=stackTop;
        while (temp != NULL)
            {
                cout<<temp->data<<endl;
                temp = temp->NextNode();
            }
    }
}


#endif // STACK_H
