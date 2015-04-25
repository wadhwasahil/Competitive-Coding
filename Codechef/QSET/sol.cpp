// Problem Link : http://www.codechef.com/JAN15/problems/QSET/

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
 
 
const int maxn=100001;
struct stu{long long  maxsum[3],prefsum[3],sufsum[3],sum;} t[4*maxn];
int n,m,co=0;
char a[maxn];
void build (int v,int tl,int tr){
   // cout<<tl<<" "<<tr<<endl;
   // co++; if(co>11) return;
    if(tl==tr){
            int rt=(a[tr])%3;
        t[v].prefsum[rt]=t[v].sufsum[rt]=t[v].maxsum[rt]=1;
        t[v].sum=rt;
        return ;
    }
    int mid=(tl+tr)>>1;
    build(2*v,tl,mid); build(2*v+1,mid+1,tr);
    t[v].sum=(t[2*v].sum+t[2*v+1].sum)%3;
 
    //max=total
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int rt=(i+j)%3;
            t[v].maxsum[rt]+=t[2*v].sufsum[i]*t[2*v+1].prefsum[j];
        }
    }
    for(int i=0;i<3;i++)
        t[v].maxsum[i]+=t[2*v].maxsum[i]+t[2*v+1].maxsum[i];
 
 
   // prefix
        for(int j=0;j<3;j++){
            int rt=(t[2*v].sum+j)%3,pr=1;
            t[v].prefsum[rt]+=pr*t[2*v+1].prefsum[j];
        }
    for(int i=0;i<3;i++)
        t[v].prefsum[i]+=t[2*v].prefsum[i];
 
   //suffix
        for(int j=0;j<3;j++){
            int rt=(t[2*v+1].sum+j)%3,pr=1;
            t[v].sufsum[rt]+=pr*t[2*v].sufsum[j];
        }
    for(int i=0;i<3;i++)
        t[v].sufsum[i]+=t[2*v+1].sufsum[i];
 
 
 
    /*int r=max(t[2*v].sufsum+t[2*v+1].prefsum,t[2*v].maxsum),q=max(r,t[v].sum);
    t[v].maxsum=max(t[2*v+1].maxsum,q);
    t[v].prefsum=max(t[2*v].prefsum,t[2*v].sum+t[2*v+1].prefsum);
    t[v].sufsum=max(t[2*v+1].sufsum,t[2*v+1].sum+t[2*v].sufsum);*/
}
 
stu getmax(int v,int tl,int tr,int l,int r){
     if(tl==l && tr==r){
           // cout<<v<<"=>";
            return t[v];
     }
    int mid=(tl+tr)>>1;
    if(r<=mid)
        return getmax(2*v,tl,mid,l,r);
    else if(l>mid) return getmax(2*v+1,mid+1,tr,l,r);
    else{
        stu p,q,res;
        p=getmax(2*v,tl,mid,l,mid),q=getmax(2*v+1,mid+1,tr,mid+1,r);
        for(int i=0;i<3;i++)
            res.maxsum[i]=res.prefsum[i]=res.sufsum[i]=0;
         res.sum=(p.sum+q.sum)%3;
               //max=total
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int rt=(i+j)%3;
            res.maxsum[rt]+=p.sufsum[i]*q.prefsum[j];
        }
    }
    for(int i=0;i<3;i++)
        res.maxsum[i]+=p.maxsum[i]+q.maxsum[i];
 
 
   // prefix
        for(int j=0;j<3;j++){
            int rt=(p.sum+j)%3,pr=1;
            res.prefsum[rt]+=pr*q.prefsum[j];
        }
    for(int i=0;i<3;i++)
        res.prefsum[i]+=p.prefsum[i];
 
   //suffix
        for(int j=0;j<3;j++){
            int rt=(q.sum+j)%3,pr=1;
            res.sufsum[rt]+=pr*p.sufsum[j];
        }
    for(int i=0;i<3;i++)
        res.sufsum[i]+=q.sufsum[i];
 
    return res;
    }
}
 
void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){
           // cout<<"tl "<<tl<<"v="<<v<<endl;
            for(int i=0;i<3;i++){
                t[v].maxsum[i]=t[v].prefsum[i]=t[v].sufsum[i]=0;
            }
            t[v].sum=0;
            int rt=(val)%3;
        t[v].prefsum[rt]=t[v].sufsum[rt]=t[v].maxsum[rt]=1;
        t[v].sum=rt;
    }
        /*if(tl==tr){
            t[v].prefsum=t[v].sum=t[v].sufsum=t[v].maxsum=val;
        }*/
        else{
            int mid=(tl+tr)>>1;
            if(pos<=mid) update(2*v,tl,mid,pos,val);
            else update(2*v+1,mid+1,tr,pos,val);
            for(int i=0;i<3;i++){
                t[v].maxsum[i]=t[v].prefsum[i]=t[v].sufsum[i]=0;
            }
            t[v].sum=0;
            t[v].sum=(t[2*v].sum+t[2*v+1].sum)%3;
               //max=total
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int rt=(i+j)%3;
            t[v].maxsum[rt]+=t[2*v].sufsum[i]*t[2*v+1].prefsum[j];
        }
    }
    for(int i=0;i<3;i++)
        t[v].maxsum[i]+=t[2*v].maxsum[i]+t[2*v+1].maxsum[i];
 
 
   // prefix
        for(int j=0;j<3;j++){
            int rt=(t[2*v].sum+j)%3,pr=1;
            t[v].prefsum[rt]+=pr*t[2*v+1].prefsum[j];
        }
    for(int i=0;i<3;i++)
        t[v].prefsum[i]+=t[2*v].prefsum[i];
 
   //suffix
        for(int j=0;j<3;j++){
            int rt=(t[2*v+1].sum+j)%3,pr=1;
            t[v].sufsum[rt]+=pr*t[2*v].sufsum[j];
        }
    for(int i=0;i<3;i++)
        t[v].sufsum[i]+=t[2*v+1].sufsum[i];
    /*int r=max(t[2*v].sufsum+t[2*v+1].prefsum,t[2*v].maxsum),q=max(r,t[v].sum);
    t[v].maxsum=max(t[2*v+1].maxsum,q);
    t[v].prefsum=max(t[2*v].prefsum,t[2*v].sum+t[2*v+1].prefsum);
    t[v].sufsum=max(t[2*v+1].sufsum,t[2*v+1].sum+t[2*v].sufsum);*/
        }
}
int main(){
    int i=0;
    char s[maxn];
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
        cin>>n>>m;
        cin>>s;
        for(int i=0;i<n;i++)
            a[i]=s[i]-'0';
        build(1,0,n-1);
        /*for(i=1;i<8;i++){
                cout<<i<<" "<< t[i].sum<<"\n";
            for(int j=0;j<3;j++)
            cout<<t[i].maxsum[j]<<" "<<t[i].prefsum[j]<<" "<<t[i].sufsum[j]<<endl;
          printf("\n");
        }*/
        while(m--){
           int x,A,b;
           scanf("%d%d%d",&x,&A,&b);
            if(x==1){
                    update(1,0,n-1,--A,b);
                    //cout<<"here\n";
                    /*for(i=1;i<8;i++){
                cout<<i<<" "<< t[i].sum<<"\n";
            for(int j=0;j<3;j++)
            cout<<t[i].maxsum[j]<<" "<<t[i].prefsum[j]<<" "<<t[i].sufsum[j]<<endl;
          printf("\n");
        }*/
            }
            else {stu res=getmax(1,0,n-1,--A,--b); cout<<res.maxsum[0]<<endl;}
    }
return 0;
}
 
