#ifndef ELEMENT_CLASS
#define ELEMENT_CLASS

using namespace std;

template <class T>
class Element
{
    private:
    	// a linked list object to hold the stack items
    	T Data;
        int Priority;//non-negative value, similar to the processes in HW1 a smaller value shows a higher priority
	public:
    	// constructor
		Element(const T data, const int priority);//returns with error if priority is initialized a negative integer
        T ShowData(void){
            return Data;
            }
        int ShowPriority (void) const {
            return Priority;
            }
        //overload the comparison operator < such that < returns true for
        //element1<element2 if element2.Priority<= element1.Priority
        bool operator< (const Element<T>& rhs) const;

};

#endif // ELEMENT_CLASS
