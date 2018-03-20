#include <iostream>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#include <cstdio>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <vector>  
#define DEBUGMODE
#define EPS 1e-6  
#define LL long long  
using namespace std;  
  
const int N = 5000+10;  
int sum[N];  
  
struct point {  
    double x;  
    double y;  
};  
  
struct Line {  
    point a;  
    point b;  
} line[N];  
  
double multi(point p0,point p1,point p2) {  
    return (p0.x-p1.x)*(p2.y-p1.y)-(p2.x-p1.x)*(p0.y-p1.y);  
}  
  
void B_search(point p,int n) { 
    int l=0,r=n-1;  
    int mid;  
    while(l<r) {  
        mid=(l+r)>>1;  
        if(multi(p,line[mid].b,line[mid].a)>0) l=mid+1;  
        else r=mid;  
    }  
    if(multi(p,line[l].b,line[l].a)>0) sum[l+1]++;  
    else sum[l]++;  
}  
  
int main() {  
    int n,m;  
    double x1,y1,x2,y2;  
    int jud=1;  
    while(~scanf("%d",&n) && n) {  
        memset(sum, 0, sizeof(sum));  
        if(jud == 0) puts("");
        scanf("%d %lf %lf %lf %lf",&m,&x1,&y1,&x2,&y2);  
        for(int i=0; i<n; i++) {  
            double p_x1,p_x2;  
            scanf("%lf %lf",&p_x1,&p_x2);  
            line[i].a.x=p_x1;  
            line[i].a.y=y1;  
            line[i].b.x=p_x2;  
            line[i].b.y=y2;  
        }  
        for(int i=0; i<m; i++) {  
            double x,y;  
            scanf("%lf %lf",&x,&y);  
            point p;  
            p.x=x;  
            p.y=y;  
            B_search(p,n);  
        }  
        jud=0;
        for(int i=0; i<=n; i++) {  
            printf("%d: %d\n",i,sum[i]);  
        }  
    }  
    return 0;  
}  