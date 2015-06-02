
#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;

int q1[MAXN][MAXN],q2[MAXN][MAXN],par[MAXN*MAXN],type[MAXN*MAXN],x[MAXN*MAXN],y[MAXN*MAXN],X[MAXN*MAXN],Y[MAXN*MAXN],sz[MAXN*MAXN];

void init(int i){
	par[i]=i;
	sz[i]=0;
}

int find_par(int i){
	if(par[i]==i) return i;
	par[i]=find_par(par[i]);
	return par[i];
}

int union_tree(int i,int j){
	i=find_par(i);
	j=find_par(j);
	if(i==j) return 0;
	par[i]=j;
	return 1;
}

int main(){
//freopen("input.txt","r",stdin);
int t,n,m,q;
scanf("%d",&t);
while(t--){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		q1[i][j]=q2[i][j]=0;
	for(int i=0;i<q;i++){
		scanf("%d",&type[i]);
		if(type[i]==1){
			scanf("%d %d",&x[i],&y[i]);
			x[i]--; y[i]--;
			q1[x[i]][y[i]]++;
		}
		else if(type[i]==2){
			scanf("%d %d",&x[i],&y[i]);
			x[i]--; y[i]--;
			q2[x[i]][y[i]]++;
		}
		else if(type[i]==3){
			scanf("%d %d %d %d",&x[i],&y[i],&X[i],&Y[i]);
			x[i]--; y[i]--; X[i]--; Y[i]--;
		}
	}
	for(int i=0;i<m*n;i++) init(i);
	for(int i=0;i<n;i++)
		for(int j=0;j<m-1;j++)
			if(!q1[i][j]) union_tree(i*m+j,i*m+j+1);
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m;j++)
			if(!q2[i][j]) union_tree(i*m+j,i*m+j+m);
	int mx=0;
	for(int i=0;i<m*n;i++){
		int k=find_par(i);
		sz[k]++;
		mx=max(mx,sz[k]);
	}
	long long ans=0;
	for(int i=q-1;i>=0;i--){
		if(type[i]==1){
			if(--q1[x[i]][y[i]]==0){
				int a=find_par(x[i]*m+y[i]),b=find_par(x[i]*m+y[i]+1);
				if(union_tree(a,b)){
					sz[b]+=sz[a];
					mx=max(sz[b],mx);
				}

			}
		}
		if(type[i]==2){
			if(--q2[x[i]][y[i]]==0){
				int a=find_par(x[i]*m+y[i]),b=find_par(x[i]*m+y[i]+m);
				if(union_tree(a,b)){
					sz[b]+=sz[a];
					mx=max(sz[b],mx);
				}

			}
		}
		if(type[i]==3){
			if(find_par(x[i]*m+y[i])== find_par(X[i]*m+Y[i])) ans++;
		}
		if(type[i]==4)
		ans+=mx;
		//cout<<ans<<" "<<mx<<endl;
	}
	printf("%lld\n",ans);
}
return 0;
}
