/*
 * merge.cpp
 *
 *  Created on: May 12, 2013
 *      Author: Indresh Gahoi
 */


#include  <iostream>
#include  "merge.h"

MergeThread::MergeThread(char whicharray, int Value, int Index, int Array[],
                         int Result[], unsigned No_elements)
                        :id(whicharray), value(Value), index(Index),
                         result(Result), array(Array), no_of_elements(No_elements)
{
     ThreadName.seekp(0, ios::beg);
     ThreadName << "Merging" << id << '-' << index << '\0';
}

void MergeThread::ThreadFunc()
{
     Thread::ThreadFunc();
     int lower, upper, middle;

     if (this->value < array[0])
          result[index] = this->value;
     else if (this->value > array[no_of_elements - 1])
          result[no_of_elements + index] = this->value;
     else {
          lower = 0;
          upper = no_of_elements - 1;
          while (upper > lower) {
               middle = (upper + lower)/2;
               if(value > array[middle] && value < array[middle + 1])
                    break;
               else if(value < array[middle])
                    upper = middle;
               else if(value > array[middle])
                    lower = middle + 1;
          }
          result[index + middle + 1] = this->value;
     }
     // thread exit
     Exit();
}

