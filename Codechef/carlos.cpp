#include<bits/stdc++.h>
 
using namespace std;
 
int dp[201][201],b[201];
int main(){
int t,n,m,k,x,y;
cin>>t;
while(t--){
    cin>>m>>k>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=0;
        }
        dp[i][i]=1;
    }
    for(int i=0;i<k;i++){
        cin>>x>>y;
        dp[x][y]=dp[y][x]=1;
    }
    for(int y=1;y<=m;y++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]|=dp[i][y]& dp[y][j];
            }
        }
    }
    for(int i=1;i<=m;i++) b[i]=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        int cur=1e9;
        for(int j=1;j<=m;j++){
            cur=min(cur,b[j]);
            if(dp[x][j])
            b[j]=cur+(x!=j);
            else b[j]=1e9;
        }
    }
    int ans=1e9;
    for(int i=1;i<=m;i++)
        ans=min(ans,b[i]);
    ans>1e8?cout<<-1:cout<<ans;
    cout<<endl;
}

return 0;
}
 
