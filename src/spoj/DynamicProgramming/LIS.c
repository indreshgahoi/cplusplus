#include <stdio.h>
#include<stdlib.h>
/*
 add O(n log n) method
*/

//
//  Lis.c
//  practice_problem
//
//  Created by Indresh on 9/26/13.
//
//
/*
 ------------------------------------------------------------------#
 L = 0                                                             #
 for i = 1, 2, ... n:                                              #
 binary search for the largest positive j ≤ L                      #
 such that X[M[j]] < X[i] (or set j = 0 if no such value exists)   #
 P[i] = M[j]                                                       #
 if j == L or X[i] < X[M[j+1]]:                                    #
 M[j+1] = i                                                        #
 L = max(L, j+1)                                                   #
 ------------------------------------------------------------------#
 */

#define ARRAYSIZE(A)   (sizeof(A)/sizeof(A[0]))
#define FOR(i,a,b)      for(i = (a) ; i < (b) ; ++i)
#define max(a,b)         (((a)> (b)) ? (a) : (b))


typedef  int Integer;

struct Array{
    int *array;
    int *path_array;
    size_t size;
};

Integer upper_bound(int *array ,int *X , size_t size ,Integer key){
    
    size_t len;
    size_t start=0;
    size_t m ;
    while (size!=0){
        len = size>>1;
        m=start;
        m=start+len;
    #ifdef DEBUG
        printf("m: %d\n",(int)(m));
    #endif
        if(key<X[array[m]]){
            size=len;
        }
        else{
            start=++m;
            size -= len +1;
        }
    #ifdef DEBUG
        printf("size: %d \n",(int)(size));
        printf("start: %d \n",(int)(start));
    #endif
    }
    return (Integer)start ;
}


struct Array LIS(int *array , size_t size){
    int L=1,j,i;
    int *M,*P;
    M = (int *) malloc(size);
    P = (int *) malloc(size);
    M[0]=0;
    P[0]=M[0];
    

    FOR(i, 1, size){
        j = upper_bound(M,array, L, array[i]);
   
#ifdef DEBUG
        printf("j: %d \n Data array : ", j);
        FOR(k, 0, L){
            printf(" k:%d %d",k,array[M[k]]);
        }
        printf("\n");
#endif
        P[i]=M[j-1];
        if(j==L){
            M[j]=i;
            L++;
        }
        else if(array[M[j]] > array[i]){
            M[j]=i;
        }
    }
    struct Array lis_data;
    lis_data.array =  M;
    lis_data.path_array = P ;
    lis_data.size = L ;
    return lis_data;
}

void solve(){
    Integer *array;
    int n,i;
    scanf("%d",&n);
    array = (int *) malloc(n);
    FOR(i, 0, n){
        scanf("%d",array+i);
    }
    struct Array a = LIS(array, n);
    FOR(i, 0, a.size){
        printf("%d\n",(int)a.size);
    }
    
}

int main()
{
    solve();
    return 0;
}


