    #include <stdio.h>
    int main(){
    register int ncases = 0, c = getchar_unlocked();
    while ('0'<=c && c<='9') {
    ncases = (ncases<<3) + (ncases<<1) + c-'0';
    c = getchar_unlocked();
    }
    while (ncases--) {
    register int m = 0, alen = 0;
    while ('0'>c || c>'9') c = getchar_unlocked();
    while ('0'<=c && c<='9') {
    m = (m<<3) + (m<<1) + c-'0';
    c = getchar_unlocked();
    }
    while ('0'>c || c>'9') c = getchar_unlocked();
    while ('0'<=c && c<='9') {
    alen = (alen<<3) + (alen<<1) + c-'0';
    c = getchar_unlocked();
    }
    register long asum = 0;
    while (alen--) {
    register long atmp = 0;
    c = getchar_unlocked();
    while ('0'>c || c>'9') c = getchar_unlocked();
    while ('0'<=c && c<='9') {
    atmp = (atmp<<3) + (atmp<<1) + c-'0';
    c = getchar_unlocked();
    }
    asum += atmp;
    }
    int t;
    scanf("%d",&t);
    if (m%2){
    m++;
    if (t)
    printf("%.4f\n",((m>>1)-t)*((m-1)-(asum+.0)/(m>>1)));
    else
    printf("%.4f\n",(m>>1)*(m-1)-(asum+.0));
    }
    else {
    if (t)
    printf("%.4f\n",((m>>1)-t)*((m+1)-(asum+.0)/(m>>1)));
    else
    printf("%.4f\n",(m>>1)*(m+1)-(asum+.0));
    }
    }
    return 0;
    } 