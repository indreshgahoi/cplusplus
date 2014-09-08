#include<stdio.h>
#include<limits.h>

int main() {
	int T;
	int x, y;
	long long X, Y;
	long long min , max ;
	long long target,face,ans,dx;
	X = 0l, Y = 1l;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		min = 0l ;
		ans = 0l ;
		if (abs(x) < abs(y)) {
			min = abs(x);
			dx = abs(y) - min;
			target = Y; // Y
		} else {
			min = abs(y);
			dx = abs(x) - min;
			target = X; // X
		}
        ans = min << 1;
		face = X ;
		while (dx > 0) {

			if (target != face) {
				ans += 1l;
				dx -= 1l;
				target = face;
			} else {
                 if(dx & 1){
                	ans += 3 ;
                	dx -= 1;
                 }else {
                	 ans+= dx << 1;
                	 dx = 0 ;
                 }

			}

		}
		printf("%lld\n",ans);
	}
	return 0;
}
