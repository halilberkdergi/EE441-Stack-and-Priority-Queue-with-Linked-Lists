#ifndef PQUEUE_H
#define PQUEUE_H
#include <iostream>
#include "Element.h"
#include "Node.h"
using namespace std;

template <class T>
class PQueue
{
    private:                                // a linked list to hold the queue items
    Node<T>* queueFront;                    //pointer to the head of the list, head pointer of the linked list
    int count;                              //number of elements in the queue

    public:                                 // constructor


    PQueue(void);                              // queue access methods

    void PQInsert(const T& item);               //inserts the item in the correct position according to its priority.

    T PQDelete(void);                           //Deletes the highest priority item at the queue front and returns it
                                                // queue access returns the highest priority element that is     in the queue in O(1) time

    T PQFront(void);                                // queue test methods

    int PQLength(void);                      // returns the length of the queue

    int PQEmpty(void);                    // returns 1 if the queue is empty

    void PQClear(void);                         //dynamically allocated memory for the    nodes must be returned

    void ShowPQ (void); // prints the content of the priority queue from front to rear on the standard output (with cout)

};

    template <class T>
    PQueue<T>::PQueue(void)
    {
        count=0;
         T obj('first',count);            //define a obj like a Element
        queueFront = new Node<T>(obj) ;   //then point it in Node

    }

    template <class T>
    void PQueue<T>::PQInsert(const T& item)
    {

    T obj('first',queueFront->data.ShowPriority()+1);
    queueFront->data = obj ;

    Node<T>* currPtr = queueFront;
    Node<T>* p;
    p = new Node<T>(item);
    if(queueFront->NextNode()== NULL)
    {
     currPtr->InsertAfter(p);   //insert the node right after the currPtr
    }
    else
    {
        while(  (currPtr->NextNode()!= NULL))      //while the currPtr has a node after it
        {
            if( (currPtr->NextNode()->data.ShowPriority() <= p->data.ShowPriority()) )
            {
            currPtr = currPtr->NextNode();
            }
            else break; //otherwise, break
        }
        currPtr->InsertAfter(p);
    }

    }


      template <class T>
      T PQueue<T>::PQDelete(void)
      {     if(queueFront==NULL)
            cout<<"Queue Underflow\n";          // ERROR occurs
          else
            {
            T obj('first',queueFront->data.ShowPriority()-1);
            queueFront->data = obj ;
            return queueFront->DeleteAfter()->data; //Because we are deleting an item
            }

      }

      template <class T>
      T PQueue<T>::PQFront(void)
      {
          return queueFront->NextNode()->data;          //next of queueFront is the FIRST
      }

      template <class T>
      int PQueue<T>::PQLength(void)
      {
         return queueFront->data.ShowPriority();            //show length as the priority of this data because "count" is stored in queueFront
      }


      template <class T>
      int PQueue<T>::PQEmpty(void)
      {
          return queueFront->data.ShowPriority()==0; //if length == 0 , queue is empty
      }

      template <class T>
      void PQueue<T>::PQClear(void)
      {
            Node<T> * temp;
            while(!PQEmpty())
                {
                    temp=queueFront;
                    queueFront=temp->NextNode();
                    delete temp;                //delete the temp
                }
      }

      template <class T>
      void PQueue<T>::ShowPQ(void)
      {
            Node<T>* temp;
            if(PQEmpty())
            {
                cout<<"\nQueue empty";              //warning
                exit(1);
            }
            else
            {
                temp=queueFront->NextNode();
                while (temp != NULL)
                    {
                        cout<<temp->data.ShowData()<<endl;              //show data of item
                        temp = temp->NextNode();                        //go next
                    }
            }
      }





#endif // PQUEUE_H
