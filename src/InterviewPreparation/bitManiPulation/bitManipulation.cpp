/*
 * bitManipulation.cpp
 *
 *  Created on: Oct 2, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include <cstdio>
#include <cstring>
#include <string>


using namespace std;

class BitManiPulation{

public:
	BitManiPulation(){

	}

	~BitManiPulation(){

	}

	int BitswapReqd(int A,int B);
	int SwapOddEvenBits(int x);
	int Max(int A, int B);
    string ConvertDecimalIntegerStrToBinaryStr(string str);
};
/*
Quest 3.1:
	Write a function int BitSwapReqd(int A, int B) to determine the number of bits
	required to convert integer A to integer B.
 */

int BitManiPulation::BitswapReqd(int A,int B){
	int count = 0;
	for(int c=A^B ; c!=0 ; c>>=1){
		count += c & 1;
	}
	return count;
}

void testBitswapedReqd(){
	BitManiPulation obj;
	int count = obj.BitswapReqd(31,14);
	std::cout<<"\ntestBitswapedReqd Result:  "<<count<<std::endl;
}

/*
 *  Quest 3.2 :-
 *  If you were to write a program to swap odd and even bits in integer,
	what is the minimum number of instructions required?
	(eg, bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).
	EXAMPLE:
	 Mask all odd bits with 10101010 in binary (which is 0xAA), then
 * 	shift them left to put them in the even bits. Then, perform a
 * 	similar operation for even bits. This takes a total 5
 * 	instructions.
 */
int BitManiPulation::SwapOddEvenBits(int x){

	return ((x & 0xaaaaaaaa)>>1) | ((x & 0x55555555)<<1);
}

void testSwapOddEvenBits(int x){
	BitManiPulation obj;
	int chNum = obj.SwapOddEvenBits(x);
	std::cout<<"\ntestSwapOddEvenBits Result:\n"<<chNum<<std::endl;
}
/*
  Write a method which finds the maximum of two numbers. You should not
  use if-else or any other comparison operator

 */

int BitManiPulation::Max(int A ,int B){
	int C= A-B,k;

	if((C>>31) & 1){
		k=1;
	}
	else{
		k = 0;
	}

	return A-k*C;
}

void testMax(){
	BitManiPulation obj;
	int A,B,max;
	int t=10;
	std::cout<<"\ntestMax Result:\n";
	while(t-->0){
		std::cin>>A;
		std::cin>>B;
		int M=obj.Max(A,B);
		std::cout<<"MAX("<<A<<","<<B<<")="<<M<<"\n";
	}
}

/*
 *  Quest:- Convert String string to binary format
 */




int main(){
	//testBitswapedReqd();
	//testSwapOddEvenBits(5);
	testMax();
	char ch;
   // while(getchar()!='e');
	while(true);
}
