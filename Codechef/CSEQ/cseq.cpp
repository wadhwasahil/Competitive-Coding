// Problem Link : http://www.codechef.com/problems/CSEQ

/***  Patience is above Perfection ***/
/***I believe in ONE GOD ***/
 
#include<vector>
#include<cstring>
#include<stdio.h>
#define ll long long
 
/***MAH Templates MAH Rules **/
 
template <class T>T sabs(T x){ if(x<0) return x*-1; else return x;}
template<class T> T sgcd(T x ,T y){ if(y==0) return x; else return sgcd(y,x%y);}
template<class T> T smax(T x,T y){ if(x>y) return x; else return y;}
template<class T> T smin(T x,T y){ if(x>y) return y; else return x;}
template <class T> T smod(T a, T b ,T m){T res=1,x=a;while(b>0){if(b&1) res=((res%m)*(x%m))%m;x=(x*x)%m;b=(b>>1);}return res%m;}
 
 
using namespace std;
inline void writeInt(ll x) { if(x==-1) { PUTCHAR('-'); PUTCHAR('1'); PUTCHAR('\n'); } else { int i = 10; char buf[11]; // buf[10] = 0;
buf[10] = ' '; do { buf[--i] = x % 10 + '0'; x/= 10; }while(x); do { PUTCHAR(buf[i]); } while (buf[i++] != ' '); } }

inline void fastInput(int &x) {
register int c = getchar_unlocked();
x = 0;
int neg = 0;
for(; ((c<48 || c>57) && c != '-'); c = getchar());
if(c=='-') {
neg = 1;
c = getchar_unlocked();
}
for(; c>47 && c<58 ; c = getchar_unlocked()) {
x = (x<<1) + (x<<3) + c - 48;
}
if(neg)
x = -x;
}
#define mod 1000003
int countFact(int n, int p)
{
    int k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
} 
// calculate a^b % c
long long pow(int a, int b, int MOD){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
 
long long InverseEuler(ll n, ll MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long factMOD(ll n, ll MOD)
{
    long long res = 1; 
    while (n > 0)
    {
        for (int  i=2, m=n%MOD; i<=m; i++)
            res = (res *i) % MOD;
        if ((n/=MOD)%2 > 0) 
            res = MOD - res;
    }
    return res;
}
 
long long Comb(int n, int r, int MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;
 
    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) * 
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}
 
int main()
{    
    int t;
       int n,r,l;
 
    fastInput(t);
    while(t--){
    fastInput(n); fastInput(l);  fastInput(r);
    int x=r-l+1;
       // writeInt((Comb(n+x,n,1000003)+1000002)%1000003);
        printf("%lld\n",(Comb(n+x,n,mod)+mod-1)%mod);
}
return 0;
}
 
