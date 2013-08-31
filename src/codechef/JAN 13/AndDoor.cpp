/*
 * AndDoor.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: indresh
 */
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <string.h>
#include <cmath>

#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>

#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>

#define MAX_INT 9999999

#define FOR(i,s,e) for(int i=s;i<e;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define tr(c,i)    for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define dbgi(x)    printf(#x" = %d\n",x);
#define dbgll(x)   printf(#x" = %ll\n",x);
#define dbgd(x)    printf(#x" = %f\n",x);
#define nl         printf("\n");

#define gi(v)      scanf("%d",&v);
#define si(v)       int v; gi(v);
#define gll(v)     scanf("%lld",&v);
#define sll(v)     long long v;gll(v)
#define gd(v)      scanf("%f",&v);
#define sd(v)      ld v;gd(v)
#define sui(v)     scanf("%u",&v);
#define sull(v)    scanf("%ull",&v);

#define gs(s)      scanf("%s",s);
#define ps(s)      puts(s);
#define pi(i)      printf("%d\n",i);
#define pll(i)     printf("%ll\n",i);
#define pd(i)      printf("%f\n",i);

#define sl(s)  strlen(s)
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
#define mp     make_pair
#define pb     push_back
#define EPS 1e-6
#define sqr(a) ((a)*(a))
using namespace std;
typedef  double ld;
//point
class Point{
public:
    ld x;
	ld y;
	Point(ld x=0.0,ld y=0.0){
		this->x=x;
		this->y=y;
	}
/*	Point()
	{
		x=0.0;
		y=0.0;
		//cout<<"default point"<<endl;
	}
    Point(Point &o){
		o.x=x;
		o.y=y;
	}
	Point& operator=(Point &o){
		x=o.x;
		y=o.y;
		return *this;
	}
*/
	~Point(){

		}
	ld distance(Point p){
       	
            
               
	  return sqrt((ld)(sqr(x-p.x)+sqr(y-p.y)));
	}
	ld distance2(Point p)
	{
		return ((ld)(sqr(x-p.x)+sqr(y-p.y)));
	}
    void print(){
    	cout<<"("<<x<<","<<y<<")";
    }
};
//Line
class line{
	/*
	 *  ax+by+c=0;
	 */
public:
	 ld a;
	 ld b;
	 ld c;
	 //
	// line by two point
	 line(Point p1,Point p2){
		 if(p1.x==p2.x){
			 a=1.0;
			 b=0.0;
			 c=-(p1.x);
		 }
		 else{
			  b=1;
			  a=-(p1.y-p2.y)/(p1.x-p2.x);
			  c=-(a*p1.x+b*p1.y);
		 }
	 }
  
//line by point p1 and slope m
	 line(Point p1,ld m){
		 a=-m;
		 b=1.0;
		 c=-(a*p1.x+b*p1.y);
	 }
	 bool parallelQ(line l){
		 return (fabs(a-l.a)<=EPS && fabs(b-l.b)<=EPS);
	 }
	 bool samelineQ(line l){
	  return(parallelQ(l) && fabs(c-l.c)<=EPS);
	 }
 //intersection point of two line
	 Point intersectionPoint(line l)
	 {
       Point res;

		/* if(samelineQ(l)){
			 std::cout<<" all point are intersection";
		 }
		 else if(parallelQ(l))
		 {
			 std::cout<<" never intersect";
		 }*/
		 res.x=(l.b*c-b*l.c)/(l.a*b-a*l.b);
		 if(fabs(b)>EPS)//vertical line
		 res.y=-(a*res.x+c)/b;
		 else
		 res.y=-(l.a*res.x+l.c)/l.b;
        return res;
	 }
	 // return a point on line l which is closet to a given point
	//
	 Point closetPoint(Point p1){
		 Point res;
		 if(fabs(b)==0.0 || fabs(b)<=EPS)//Vertical line
		 {
			res.x=-(c);
			res.y=p1.y;
            return res;
		 }
		 else if(fabs(a)==0.0 || fabs(a)<=EPS) // Horizontal line
		 {
			 res.y=-(c);
			 res.x=p1.x;
			 return res;
		 }
		 line perp(p1,1/a);
		// nl print();nl
		// cout<<" perpendicular line: ";
		// perp.print();nl
		 res=intersectionPoint(perp);
		// cout<<"intersection point of lines: ";
		// res.print();
		return res;

	 }
	 void print(){
		 cout<<a<<"X +"<<b<<"Y + "<<c<<"=0";
	 }
};

// Circle
class Circle{
public:
	Point center;
	ld r;
    Circle(){
    	r=0.0;
    	//cout<<"default circle"<<endl;
    }

	Circle(Point p,ld r=0.0){
		center=p;
		this->r=r;
	}
	bool isInside(Circle c){
	 return (sqr(r-c.r))>=(center.distance2(c.center));
	}
    bool isIntersect(Circle c){
    	return (sqr(r+c.r)>(center.distance2(c.center)));
    }
  void print(){
	  cout<<"center= ";center.print();cout<<" r="<<r;
  }
};

Circle cr[1000];
int W,H,N;
ld ans=0.0;
ld PI=acos(-1.0);
void addTomap(map<ld,int> &m,ld angle,int v)
{
	//if(m.count(angle)>0)
		m[angle]+=v;
	//else
	//	m[angle]=0;
}
void addangle(map<ld,int> &m,ld alpha,ld beta)
{
	addTomap(m,alpha,1);
	addTomap(m,beta,-1);
}

void solve(){
	Point p1(0.0,0.0),p2((ld)H,0.0),p3(0.0,(ld)W),p4((ld)H,(ld)W);
    line l[4]={line(p1,p2),line(p1,p3),line(p2,p4),line(p3,p4)};
   /*   cout<<"lines\n";
      l[0].print();nl
      l[1].print();nl
      l[2].print();nl
      l[3].print();nl
    */
  //  l1=;
   Point recCenter((H/2.0),(W/2.0));
	REP(i,N){
		   bool ok=true;
		   
		   cout<<" "<<endl<<endl;
		   dbgi(i)
		   cr[i].print();
                   cout<<""<<std::endl;	    
		REP(j,N)
		{

			if(i!=j &&((cr[i].isInside(cr[j])&& cr[j].r>cr[i].r)))
			{
			  // cr[j].print();cout<<" "<<endl;
				ok=false;
				break;
			}
		}


		if(!ok)
			continue;
		//if(cr[i].center.x+cr[i].r<=0+EPS) continue;
	  //  if(cr[i].center.x-cr[i].r>=W-EPS) continue;
	  //  if(cr[i].center.y+cr[i].r<=0+EPS) continue;
	  //  if(cr[i].center.y-cr[i].r>=H-EPS) continue;
		  if(fabs(recCenter.x-cr[i].center.x)-EPS<=0 && fabs(recCenter.y-cr[i].center.y)-EPS<=0){
			ld d= (*new Point()).distance(recCenter);
			  if(cr[i].r>=d){
		        	  continue;
		               }
		  }
		  else{
	    ld d=cr[i].center.distance(recCenter);
		ld a=atan2((W/2.0)-cr[i].center.y,(H/2.0)-cr[i].center.x)+(2.0*PI);
		if(a>(2.0*PI))a-=(2.0*PI);
		ld x=cr[i].center.x,y=cr[i].center.y;
		ld x1=x+d*cos(a),x2=x-d*cos(a),y1=x+d*sin(a),y2=x-d*sin(a);
        if(!(((x1>=0.0 && x1<=(double)H) && ((y1>=0.0 && y1<=(double)W))) ||
        		(((x2>=0.0 && x2<=(double)H) && ((y2>=0.0 && y2<=(double)W))))))
        	continue;
		  }

		//dbgi(i)nl
		map<ld,int> angles;
		angles[0.0]=0;
		angles[2.0*PI]=0;
		REP(j,N){
		  if(i!=j && cr[i].isIntersect(cr[j]))
			{
			  ld dist=cr[i].center.distance2(cr[j].center);
			  ld dist1=cr[i].center.distance(cr[j].center);
			//  cout<<"j="<<j<<" angle="<<endl;//2*acos((sqr(cr[i].r)+dist-sqr(cr[j].r))/(2.0*cr[i].r*dist1))<<endl;
              ld med=acos((sqr(cr[i].r)+dist-sqr(cr[j].r))/(2.0*cr[i].r*dist1));
              //
             // Angle from the x-Axis
              ld theta=atan2((cr[i].center.y-cr[j].center.y),(cr[i].center.x-cr[j].center.x))+(2.0*PI);
            //  cout<<"med="<<med<<" theta="<<theta<<endl;
              if(theta>=(2.0*PI))theta-=(2.0*PI);
              ld alpha=theta+med;
              ld beta=theta-med;
              if(alpha>(2.0*PI))alpha-=(2.0*PI);
              if(beta<0)beta+=(2.0*PI);
             // cout<<"alpha="<<alpha<<" beta="<<beta<<" \n";
              if(beta>alpha)
              {
                  addangle(angles,0.0,alpha);
                  addangle(angles,beta,2.0*PI);
              }
              else
               addangle(angles,beta,alpha);

              }
		}
		  //check line circle intersection
		    Point close;
            for(int x=0;x<4;x++){
            	//close.print();nl
                close=l[x].closetPoint(cr[i].center);
             /* ps("data")
                ps("line:")l[x].print();nl
                ps("circle:")cr[i].print();nl
                ps("close point")close.print();nl*/
                ld dist=close.distance(cr[i].center);
                if(dist<cr[i].r)
                {
                	 ld med=acos(dist/cr[i].r);
                	              //
                	             // Angle from the x-Axis

                	 ld theta=atan2(l[x].b,l[x].a);
                	            //  cout<<"med="<<med<<" theta="<<theta<<endl;

                	           //   if(cr[i].center.x>(ld)H || cr[i].center.y>(ld)W)
                	            //	  theta=PI-theta;
                	            //   if(dist==0.0 || dist<=EPS)
                	             //        theta=PI;;
                	                  theta+=(2.0*PI);
                	              if(theta>=(2.0*PI))theta-=(2.0*PI);

                	              ld alpha=theta+med;
                	              ld beta=theta-med;
                	              if(alpha>(2.0*PI))alpha-=(2.0*PI);
                	              if(beta<0.0)beta+=(2.0*PI);
                	              //cout<<"alpha="<<alpha<<" beta="<<beta<<" \n";
                	              if(beta>alpha)
                	              {
                	                  addangle(angles,0.0,alpha);
                	                  addangle(angles,beta,2.0*PI);
                	              }
                	              else
                	               addangle(angles,beta,alpha);

                 }
                }




        ld total=0.0,diff=0.0;
        int sum=0;
   /*      cout<<"{";
        tr(angles,it){
        			cout<<" "<<((*it).first)<<"="<<((*it).second)<<", ";
        		}
        cout<<"}"<<endl;
   */
		tr(angles,it){
			if(sum==0 && (*it).first>0.0) total+=(*it).first-diff;
			sum+=(*it).second;
			diff=(*it).first;
		}

		ans+=(total)*cr[i].r;

		//cr[i].print();nl
	//	printf("\n total segment=%.10f\n",ans);
		//printf("\n peri=%.10f\n",(total)*cr[i].r);
	   // cout<<endl<<"ans="<<temp*cr[i].r<<endl;
	    //*/
    }

}
int main(){

	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	si(T)
	//dbgi(T)
	while(T--){
		ans=0.0;
		gi(H)gi(W)gi(N)
				H*=100;
		        W*=100;
				//dbgi(N)
				REP(i,N)
				{
			      // gd(cr[i].center.x)gd(cr[i].center.y)gd(cr[i].r)
                    cin>>cr[i].center.x>>cr[i].center.y>>cr[i].r;
                    cr[i].center.x=cr[i].center.x*100.0;
                    cr[i].center.y=cr[i].center.y*100.0;
                    cr[i].r=cr[i].r*100.0;
                  //  cr[i].print();cout<<" "<<endl;

                }
		 solve();
		 printf("%.7f\n",(double)ans*0.01);
		 //cout<<ans;
	}
 return 0;
}
