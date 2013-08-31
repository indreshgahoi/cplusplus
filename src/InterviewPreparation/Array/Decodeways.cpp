/*
 * Decodeways.cpp
 *
 *  Created on: Mar 17, 2013
 *      Author: indresh
 */

#include <iostream>
#include <string>
using namespace std;
int numDecodings(string s) {

       if(s.size()==0) return 0;
       if(s[0]=='0') return 0;
       if(s.size()<2) return 1;
       int pi=1,pi_1=1;
       int num=((s[0]-'0')*10+(s[1]-'0'));
       if(s[1]!='0' && num<=26)
          pi++;
       if(num>26 && s[1]=='0')
        pi=0;
       for(int i=2;i<s.size();i++){
          // if(s[i]=='0') return 0;
           int temp=pi;
           num=((s[i-1]-'0')*10+(s[i]-'0'));
           if(s[i]=='0' && s[i-1]=='0')
               return 0;
           pi=((s[i]=='0')?0:pi)+((num<=26 && s[i-1]!='0' && num!=0)?(pi_1):0);
           pi_1=temp;
       }
       return pi;
   }
