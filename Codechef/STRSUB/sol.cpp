// problem link http://www.codechef.com/problems/STRSUB
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define ll long long
 
 
 
#define REP(i,a,n) for(i=a;i<n;i++)
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked
using namespace std;
inline void writeInt(ll x) { if(x==-1) { PUTCHAR('-'); PUTCHAR('1'); PUTCHAR('\n'); } else { int i = 10; char buf[11]; // buf[10] = 0;
buf[10] = ' '; do { buf[--i] = x % 10 + '0'; x/= 10; }while(x); do { PUTCHAR(buf[i]); } while (buf[i++] != ' '); } }
long long int input()
    {char c;
    long long int t=0;
    c=GETCHAR();
    while(c<'0'||c>'9')
    c=GETCHAR();
    while(c>='0'&&c<='9')
    {
    t=t*10+c-48;
    c=GETCHAR();
    }
    return t;
    }
ll freq[100002][2];
ll valid[100002],invalid[100002];
ll x[100002],c_invalid[100002],y[100002];
int main(){
    //freopen("op1.txt","w",stdout);
ll t;
t=input();
while(t--){
    ll n,q,k;
    char s[100002];
    n=input();
    k=input();
    q=input();
    gets(s);
    int i,len=n;
    REP(i,0,n+1){
        //invalid[i]=
        freq[i][0]=freq[i][1]=0;
        x[i]=-1;
        y[i]=n;
    }
    REP(i,0,n){
        if(i==0)
            freq[i][s[i]-'0']++;
        else {
            freq[i][s[i]-'0']++;
            freq[i][0]+=freq[i-1][0];
            freq[i][1]+=freq[i-1][1];
        }
    }
    int last=0,first=0;
    while(last<len)
        {
           /* if(last==0)
            invalid[last]=0;
        else{
            invalid[last]+=invalid[last-1];
        }*/
        //cout<<first<<" "<<last<<" "<<invalid[last]<<"\n";
            int d[2]={0};
            if(first>0){
                d[0]=freq[first-1][0];
                d[1]=freq[first-1][1];
            }
            int fr0=freq[last][0]-d[0],fr1=freq[last][1]-d[1];
            if(fr0>k || fr1>k){
                int tmp=0;
            //    cout<<fr0<< " "<<fr1<<endl;
                while(fr0>k || fr1>k){
                    fr0-=(s[first]=='0');
                    fr1-=(s[first]=='1');
                    tmp++;
                    first++;
                }
                //invalid[last]+=tmp;
            }
    // cout<<first<<" "<<last<<" "<<invalid[last]<<"\n\n";
            x[last]=first;
            last++;
    }
    first=last=n-1;
    while(first>=0){
        int d[2]={0};
        if(first==0)
            int fr0=freq[last][0],fr1=freq[last][1];
        int fr0=freq[last][0]-freq[first-1][0],fr1=freq[last][1]-freq[first-1][1];
        int rm=0;
        while(fr0>k || fr1>k){
            rm++;
            fr0-=(s[last]=='0');
            fr1-=(s[last]=='1');
            last--;
        }
        y[first]=last;
        first--;
    }
    for(i=0;i<n;i++){
   // printf("%lld %lld \n",x[i],y[i]);
        c_invalid[i]=i>0?c_invalid[i-1]+x[i]:x[i];
    }
    while(q--){
        int l,r;
        l=input();
        r=input();
        ll ans=0;
        ll df=r-l+1;
        ans+=(df*(df+1))/2;
     
                ll st=y[l-1];
 
        ll ans1=0,rr=r-1-st;
        if(rr<=r-1 && rr>=0)
         ans1=(c_invalid[r-1]-c_invalid[st])-((l-1)*rr);
        ll ans1=(c_invalid[r-1]-c_invalid[st-1])-((l-1)*rr);
        ans-=ans1;
    ans-=ans1;
    writeInt(ans);
    printf("\n");
    }
}
return 0;
}
