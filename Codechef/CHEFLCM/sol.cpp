// Problem Link http://www.codechef.com/APRIL15/problems/CHEFLCM/
/***  Patience is above Perfection ***/
/***I believe in ONE GOD ***/
 
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
 
#define sin(i) scanf("%d",&i)
#define sinl(i) scanf("%lld",&i)
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
bool visit[1000001];
vector<ll> b;
int maxn=1000000;
int main(){
    for(int i=2;i*i<=maxn;i++){
        if(!visit[i]){
            for(int j=i;j*i<=maxn;j+=1)
                visit[j*i]=1;
        }
    }
    int x=0;
    for(int i=2;i<=maxn;i++)
        {
            if(!visit[i]){
            b.pb(i);
            x++;
            }
        }
    int t;
    fastInput(t);
    while(t--){
       int n;
       fastInput(n);
       ll ans=0;
       for(int i=1;i*i<=n;i++){
            if(n%i==0){
                ans+=i;
                ll r=n/i;
                if(r!=i) ans+=r;
            }
       }
       cout<<ans<<endl;
 
    }
return 0;
}
 
