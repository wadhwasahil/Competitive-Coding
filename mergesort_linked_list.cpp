#include<bits/stdc++.h>
#define trace1(x)                    cerr << #x << ": " << x << endl;
#define trace2(x, y)                 cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)              cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)        cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define ll long long int
#define MAXN 100002
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
inline void writeInt(ll x) { if(x==-1) { PUTCHAR('-'); PUTCHAR('1'); PUTCHAR('\n'); } else { int i = 10; char buf[11]; // buf[10] = 0;
buf[10] = ' '; do { buf[--i] = x % 10 + '0'; x/= 10; }while(x); do { PUTCHAR(buf[i]); } while (buf[i++] != ' '); } }
inline void fastInput(ll &x) {
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

struct node{
    int val;
    node *next;
};

void split(node *source,node **a,node **b){
    if(source==NULL || source->next==NULL){
        *a=source;
        *b=NULL;
        return;
    }
    node *slow=source,*fast=source->next;
    while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
          }
    }
    *a=source;
    *b=slow->next;
    slow->next=NULL;
}


void MoveNode(node **dest, node **source){
    node *temp=*source;
    *source=temp->next;
    temp->next=*dest;
    *dest=temp;
}
node *SortedMerge(node* a,node* b){
    node dummy;
    node *temp=&dummy;
    dummy.next=NULL;
    while(1){
        if(a==NULL){
                temp->next=b;
                break;
        }
        if(b==NULL){
            temp->next=a;
            break;
        }
        if(a->val<=b->val){
            MoveNode(&(temp->next),&a);
        }
        else{
                MoveNode(&(temp->next),&b);
        }
        temp=temp->next;
    }
    return dummy.next;
}
void mergesort(node **source){
    if(*source==NULL || (*source)->next==NULL) return;
    node *head=*source;
    node *a=NULL,*b=NULL;
    split(*source,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *source=SortedMerge(a,b);
}
void push(node **a,int val){
    node *temp=(node*)malloc(sizeof(node));
    temp->next=*a;
    temp->val=val;
    *a=temp;
}
void printlist(node *a){
    while(a!=NULL){
        printf("%d ",a->val);
        a=a->next;
    }
    printf("\n");
}
int main(){
node *res,*a=NULL,*b=NULL;
push(&a,15);
push(&a,10);
push(&a,5);
push(&a,20);
push(&a,3);
push(&a,2);
printlist(a);
mergesort(&a);
printlist(a);
return 0;
}
