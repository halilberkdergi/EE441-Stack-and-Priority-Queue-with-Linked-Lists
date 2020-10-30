#ifndef NODE_H
#define NODE_H
#include "Element.h"
#include <iostream>

using namespace std;

template <class T>
class Node
{

    private:
    Node <T> *next;

    public :

    T data;

    Node (const T &item, Node<T>* ptrNext=0);

    Node<T> *NextNode(void) const;

    void InsertAfter(Node<T> *p);
    Node<T> *DeleteAfter(void);

    Node<T> *GetNode(const T& item,Node<T> *nextPtr=NULL )

        {

        Node<T> *newNode; //declare pointer

        newNode=new Node<T>(item, nextPtr );

        //allocate memory and pass item and nextptr to the constructor which creates the object

        //terminate program if allocation not successful

        if (newNode==NULL)
        {cerr<<"Memory allocation failed"<<endl;
        exit(1); }

        return newNode;
        }


};

    template <class T>                  //constructor
    Node <T>::Node(const T &item, Node<T>* ptrNext): data(item), next(ptrNext)
    { }

    template <class T>
    Node <T> *Node<T>::NextNode(void) const             //we use this function because *next is private.
    {
        return next;
    }

    template <class T>
    void Node<T>::InsertAfter(Node<T>* p)
    {

        p->next = next;
        next = p;
    }

    template <class T>
    Node<T> *Node<T>::DeleteAfter(void)
{

    Node<T> *tempPtr = next; // copy *next to *tempPtr


    if (next == NULL)
        return NULL;
    next = tempPtr->next;
    return tempPtr;
}




#endif // NODE_H
