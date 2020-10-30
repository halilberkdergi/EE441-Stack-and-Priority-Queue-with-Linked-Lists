#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>

using namespace std;

template <class T>
class Element
    {
    private:
    T Data;                                           // the data of the element
    int Priority;                                     //non-negative value, similar to the processes in  HW1 a smaller value shows a higher priority

    public:                                          // constructor
    Element(const T data, const int priority)
    {
        if(priority<0)
        {
            cerr<< "Priority can not be a negative integer"<<endl;  // ERROR
            exit(1);
        }
        else
        {
            Priority=priority;
            Data=data;
        }

    }          //returns with    error if priority is initialized a negative integer

    T ShowData(void) {return Data;}

    int ShowPriority (void) const {return Priority;}

    bool operator< (const Element<T>& rhs) const
    {
                return ( Priority>=rhs.ShowPriority()  );       //return as a true or false
    }

};

#endif // ELEMENT_H
