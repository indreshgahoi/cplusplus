#include"cstdio"
#include"vector"
#include"algorithm"
#include"cassert"
#include"iostream"
#include"set"
#include"tuple"
using namespace std;
int N;
double xcoeff, ycoeff, constcoeff;
struct set_of_points {
    double xsq, ysq, x, y, xy, n;
    set_of_points(double X=0, double Y=0, int n0=1) {
        xsq = X*X;
        ysq = Y*Y;
        x = X;
        y = Y;
        xy = X*Y;
        n = n0;
    }
    void operator+=(const set_of_points I) {
        xsq += I.xsq;
        ysq += I.ysq;
        xy += I.xy;
        x += I.x;
        y += I.y;
        n += I.n;
    }
    set_of_points operator+(const set_of_points I) const {
        set_of_points J = *this;
        J += I;
        return J;
    }
    void operator-=(const set_of_points I) {
        xsq -= I.xsq;
        ysq -= I.ysq;
        xy -= I.xy;
        x -= I.x;
        y -= I.y;
        n -= I.n;
    }
    double solve() {
        double p = ysq, q = xsq, r = 2*xy, s = 2*y, t = 2*x;
        double alpha = q - (t*t)/(4*n), beta = (s*t)/(2*n)-r, gamma = p - (s*s)/(4*n);   // optimize (alpha * m^2 + beta * m + gamma) / (1+ m^2)
        // handle beta = 0;
        if(beta>-1e-8 and beta <1e-8)
            return min(gamma, alpha);  // m=0 or infinity
        // apply standard procdeure for quadratic
        double a = (alpha - gamma)/beta, b = sqrt(a*a + 1);
        double m0 = a+b, m1 = a-b;
        auto fn = [alpha, beta, gamma](double m){ return (alpha*m*m + beta * m + gamma) / (1+m*m); };
        return min(min(fn(m0), fn(m1)), alpha);
    }
};
set_of_points pts[500];
int main() {
    vector<int> partition;
    double ans = 1e100;
    scanf("%d", &N);
    double x[N], y[N];
    for(int i=0; i<N;i++)
        scanf("%lf%lf", &x[i], &y[i]), pts[i] = set_of_points(x[i], y[i]);
    for(int i=N; --i;)
        for(int j=i; j--; ) {
            vector<tuple<double, int, bool>> All;
            //            vector<int> cur_part;
            set_of_points A(0, 0, 0), B(0, 0, 0);
            for(int k=0; k<N; k++) {
                if(k==i or k==j)
                    continue;
                double d = ((x[j]-x[i]) * x[k] + (y[j]-y[i]) * y[k]); // projection of vector (x[k], y[k]) on the line from i to j/
                bool t = (x[j]-x[i]) * (y[k]-y[i]) - (y[j]-y[i]) * (x[k]-x[i])>0; // on which side it is, above or below
                All.push_back(tuple<double, int, bool>(d, k, t));
                if(t)
                    A += pts[k];
                else
                    B += pts[k];
            }
            sort(All.begin(), All.end()); // sort by projection on  line
            double tmp;
            tmp = (A+pts[i]).solve()+(B+pts[j]).solve();
            if(tmp<ans)
                ans = tmp;
            tmp = (A+pts[j]).solve()+(B+pts[i]).solve();
            if(tmp<ans)
                ans = tmp;
            set_of_points tmp1, tmp2;
            unsigned int idx = 0;
            for(auto z: All) {
                int k=get<1>(z);
                if(++idx<All.size() and get<0>(All[idx]) < get<0>(All[idx-1])+1e-10) {
                    tmp1 = A, tmp2 = B;
                    int kk = get<1>(All[idx]);
                    if(get<2>(All[idx]))
                        tmp1 -= pts[kk], tmp2 += pts[kk];
                    else
                        tmp1 += pts[kk], tmp2 -= pts[kk];
                    ans = min(ans, (tmp1+pts[j]).solve() + (tmp2+pts[i]).solve());
                    ans = min(ans, (tmp1+pts[i]).solve() + (tmp2+pts[j]).solve());
                }
                if(get<2>(z))
                    A -= pts[k], B += pts[k];
                else
                    A += pts[k], B -= pts[k];
                ans = min(ans, (A+pts[j]).solve()+ (B+pts[i]).solve());
                ans = min(ans, (A+pts[i]).solve()+ (B+pts[j]).solve());
            }
        }
    printf("%.9lf\n", ans/N);
    return 0;
}
