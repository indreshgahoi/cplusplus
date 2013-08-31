

#include  "ThreadClass.h"

class MergeThread : public Thread
{
     public:
          // constructor
          MergeThread(char whicharray, int Value, int Index, int Array[],
                      int Result[], unsigned No_elements);

     private:
          void ThreadFunc();       // thread body
          int  value;              // a[i]: value of element index of array a[]
          int  index;              // i   : index in the array a[]
          int  *array;             // another array b[]
          int  *result;            // result array
          char id;                 // identify thread name
          unsigned no_of_elements; // number of elements of array B[]
};
