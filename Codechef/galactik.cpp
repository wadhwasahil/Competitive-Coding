/***  Patience is above Perfection ***/
/***I believe in ONE GOD ***/
 
 /*** Galactic Codechef **/
#include<vector>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<climits>
#include<set>
#include<fstream>
#include<cmath>
#include<stack>
#include<bitset>
#include<map>
#include<time.h>
#include<list>
#include<iostream>
#include<queue>
#include<iomanip>
#include<assert.h>
#define ll long long
 
#define s(i) scanf("%d",&i)
#define sl(i) scanf("%lld",&i)
#define sout(i) printf("%d",i)
#define soutl(i) printf("%lld",i)
#define mp make_pair
#define REP(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define GETCHAR getchar
#define PUTCHAR putchar
 
/***MAH Templates MAH Rules **/
 
template <class T>T sabs(T x){ if(x<0) return x*-1; else return x;}
template<class T> T sgcd(T x ,T y){ if(y==0) return x; else return sgcd(y,x%y);}
template<class T> T smax(T x,T y){ if(x>y) return x; else return y;}
template<class T> T smin(T x,T y){ if(x>y) return y; else return x;}
template <class T> T smod(T a, T b ,T m){T res=1,x=b;while(b>0){if(x&1) res=((res%m)*(x%m))%m;x=(x*x)%m;b=(b>>1);}return res;}
 
 
using namespace std;
inline void writeInt(int x) { if(x==-1) { PUTCHAR('-'); PUTCHAR('1'); PUTCHAR('\n'); } else { int i = 10; char buf[11]; // buf[10] = 0;
buf[10] = ' '; do { buf[--i] = x % 10 + '0'; x/= 10; }while(x); do { PUTCHAR(buf[i]); } while (buf[i++] != ' '); } }
inline void fastInput(int &x) {
register int c = getchar();
x = 0;
int neg = 0;
for(; ((c<48 || c>57) && c != '-'); c = getchar());
if(c=='-') {
neg = 1;
c = getchar();
}
for(; c>47 && c<58 ; c = getchar()) {
x = (x<<1) + (x<<3) + c - 48;
}
if(neg)
x = -x;
}
int a,b,n,m,x[1000001],y[1000001],sum,k;
int d[100001],cost[100001],cnt[100001],mini=INT_MAX;
void init(){
    for(int i=0;i<n;i++){
        d[i]=i;
    }
}
 
int _find(int i){
    if(d[i]==i) return d[i];
    d[i]=_find(d[i]);
    return d[i];
}
 
int _union(int i,int j){
    int a=_find(i),b=_find(j); 
    if(a==b) return 0;
    d[b]=a;
    return 1;
}
int main(){
    //freopen("input.txt","r",stdin);
    int flag=0;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; ++i)
    {
        s(x[i]); s(y[i]);
        x[i]--;
        y[i]--;
    }
    for(int i=0;i<n;i++){
        s(cost[i]);
    }
    init();
    for(int i=0;i<m;i++){
        if(_find(x[i])!=_find(y[i]))
           _union(x[i],y[i]);
    }
    for(int i=0;i<n;i++)
        d[i]=_find(i);
    for(int i=0;i<n;i++){
         a=d[i];
        cnt[a]++;
    }
    for(int i=0;i<n;i++)
    if(cnt[i]==n){
        printf("0\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(cost[i]<0)
        cost[i]=INT_MAX;
        cnt[i]=cost[i];
    }
    
    for(int i=0;i<n;i++){
        if(cost[i]>=0){
            cnt[d[i]]=min(cnt[d[i]],cost[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(d[i]==i && cnt[i]==INT_MAX){
            printf("-1\n");
            return 0;
        }
        if(d[i]==i){
                k++;
                sum+=cnt[i];
            mini=min(mini,cnt[i]);
        }
    }
    sum=(k-2)*mini+sum;
    printf("%d\n",sum);
return 0;
}
 
