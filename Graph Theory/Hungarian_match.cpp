#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int vis[N],match[N],n,m,cnt,t;
//match数组可以查看详细的匹配情况
int h[N];
struct line{
	int Nxt,to;
}l[N];

void link(int u,int v){
	l[++cnt]=(line){h[u],v};h[u]=cnt;
}

bool findPath(int u){
	for(int i=h[u],v;i;i=l[i].Nxt){
		v=l[i].to;
		if(!vis[v]){
			vis[v]=true;
			if(!match[v] || findPath(match[v])){
				match[v]=u; //发现增广路，或者直接就可以与邻点匹配
				return true;
			}
		} 
	}return false; //直到遍历完所有的点，都没有发现增广路下
}

int MaxMatch(){
	int ans=0;
	for(int u=1;u<=n;u++){
		memset(vis,0,sizeof(vis));//记得初始化！
		if(findPath(u)) ans++;	//找到增广路，匹配数量+1
	}return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&t);//上面的数量，下面的数量，边的数量
	//左1-n,n+1 - m+n
	for(int i=0,u,v;i<t;i++){
		scanf("%d%d",&u,&v);
		link(u,v+n);
	}


	printf("%d",MaxMatch());
	
	return 0;
}
