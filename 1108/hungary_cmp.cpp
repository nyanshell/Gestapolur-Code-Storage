//ural 1109
#include <cstdio>
#include <cstring>

const int maxn=1024;
int M,N;
int g[maxn][maxn];
int e[maxn];
bool vis[maxn];
int link[maxn];

bool find(int v){
	for(int i=0;i<e[v];++i){
		int j=g[v][i];
		if(vis[j])continue;
		vis[j]=true;
		if(link[j]==-1||find(link[j])){
			link[j]=v;
			return true;
		}
	}
	return false;
}
int main(){

	memset(g,0,sizeof(g));
	memset(e,0,sizeof(e));
	memset(link,-1,sizeof(link));
	
	int k;
	scanf("%d%d%d",&M,&N,&k);
	for(int i=0;i<k;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a][e[a]++]=b;
	}

	for( int i = 1 ; i <= N ; ++ i )
	  {
	    for( int j = 1 ; j <= M ; ++ j )
	      printf("%d " , g[ i ][ j ] );
	    printf("\n");
	  }
	
	int res=M+N;
	for(int i=1;i<=M;++i){
		memset(vis,0,sizeof(vis));
		if(find(i))
			--res;
	}
	for( int i = 1 ; i <= N ; ++ i )
	  {
	    for( int j = 0 ; j < e[ i ] ; ++ j )
	      printf( "%d " , g[ i ][ j ]);
	    printf("\n");
	  }
	printf("%d\n",res);
}
