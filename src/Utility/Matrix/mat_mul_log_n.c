#define mat_size N


void mat_mul(LL a[][M],LL b[][N],LL temp[][N])
{
    int i,j,k;

    for(i=0;i<M;i++){
         for(j=0;j<N;j++){
           temp[i][j]=0;
           for(l=0;l<N;l++){
              temp[i][j]=(temp[i][j]+(a[i][l]*mt[l][j]));
           }
         }}
}

void mat_copy(LL a[][N] ,LL b[][N])
{ int i,j;

  for(i=0;i<N;i++){
         for(j=0;j<N;j++){
           a[i][j]=b[i][j];}}

}

LL mt[N][N];

void  powmat(LL a[][N],LL k)
{
    mat_copy(mt,a);
    nthpower(a,k);
}

void nthpower(LL a[][N],LL k){
    LL i,j,l,temp[N][N];

    //Base Case
    if(k==0 ||k==1){
        return;
    }
       // a^k = a^(k/2)*a^(k/2)

        nthpower(a,k>>1);

        for(i=0;i<N;i++){
         for(j=0;j<N;j++){
           temp[i][j]=0;
           for(l=0;l<N;l++){
              temp[i][j]=(temp[i][j]+(a[i][l]*a[l][j]));
           }
         }}

         for(i=0;i<N;i++){
         for(j=0;j<N;j++){
           a[i][j]=temp[i][j];}}

     // k is odd
     //then a^(k+1)=a^k * a

    if( k & 1)
    {

        for(i=0;i<N;i++){
         for(j=0;j<N;j++){
           temp[i][j]=0;
           for(l=0;l<N;l++){
              temp[i][j]=(temp[i][j]+(a[i][l]*mt[l][j]));
           }
         }}

         for(i=0;i<N;i++){
         for(j=0;j<N;j++){
           a[i][j]=temp[i][j];}}

    }
}


