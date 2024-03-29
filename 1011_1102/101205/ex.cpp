//SAP exercise
#include<iostream>
#define MAXN 1001
#define MAXE 100001 // max edge
#define INF 2141483647
using namespace std;

bool flag;//
int h[MAXE]; // 
int pre[MAXE],vh[MAXE]; // 
int di[MAXE];
//int w[MAXN][MAXN];
int d[MAXE]; // 
int mint,flow,aug,m,n;

class VERX
{
public:
  int v,c;
  VERX *next;
};

VERX *ind[MAXE] = {NULL};

void dis()
{
  VERX *p;
  for(int i = 1 ;i <= n ; ++ i)
    {
      p = ind[i];
      cout<<i<<" : ";
      while(p not_eq NULL )
	{
	  cout<<p->v<<" ";
	  p = p->next;
	}
      cout<<"\n";
    }
  return ;
}

void verx_add(int u, int v , int c)
{
  VERX *p;
  p = new VERX ;
  p->next = NULL;
  p->v = v;
  p->c = c; 
  if(ind[u] == NULL)
    ind[u] = p;
  else
    {
      VERX *t,*pre;

      t = ind[u];pre = NULL;
      
      while(t not_eq NULL and t->v < p->v)
	{pre = t;t = t->next;}
      
      if(t not_eq NULL and t->v == p->v)//same edge with two time description
	t->c += p->c;
      else
	{
	  p->next = t;
	  if(pre == NULL)
	    ind[u] = p;
	  else
	    pre->next = p;
	}
    }
  //dis();
  return ;
};

void dfs(int source , int sink )
{
  int i,j,tmp,rec = 0;
  VERX *p,*t;
  vh[0] = n;

  for(i = 1 ; i <= n ; ++ i)
    di[i] = 1;
  
  i = source;
  aug = INF;
  
  while(d[ source ] < n)
    {
      h[i] = aug;
      flag = false;
      //cout<<"flow : "<<flow<<" "<<i<<" "<<di[i]<<"\n";
      p = ind[i];
      
      while(p not_eq NULL)
	{
	  //cout<<"scanning : "<<i<<" "<<p->v<<" "<<p->c<<" "<<d[ p->v ]<<" "<<d[i]<<"\n";
	  if(p->c > 0  and p->v >= di[i] and d[ p->v ] + 1 == d[i]) 
	    {
	      flag = true;
	      di[i] = p->v;
	      //cout<<"verx : "<<p->v<<"\n";
	      if(p->c < aug)
		aug = p->c;
	      pre[p->v] = i;
	      i = p->v;
	      //cout<<i<<"\n";
	      if(i == sink)
		{
		  //cout<<"path found \n";
		  flow+=aug;
		  while(i not_eq source)
		    {
		      tmp = i;
		      i = pre[i];
		      //w[tmp][i]+=aug;
		      //w[i][tmp]-=aug;
		      
		      t = ind[i];
		      while(t not_eq NULL and t->v not_eq tmp)
			t = t->next;
		      if(not p)
			verx_add(i,tmp,-aug);
		      else
			t->c -= aug;

		      t = ind[tmp];
		      while(t not_eq NULL and t->v not_eq i)
			t = t->next;
		      if(not t)
			verx_add(tmp,i,aug);
		      else
			t->c += aug;
		    }
		  aug = INF;
		}
	      break;
	    }
	  p = p->next;
	}

      if( flag ) continue;
      mint = n - 1;
      /*
      for(j = 1; j <= n; ++ j)
	if(w[i][j] > 0 and d[j] < mint)
	  { mint = d[j] ; rec = j ; }
      */
      p = ind[i];
      while(p not_eq NULL)
	{
	  if(p->c > 0 and d[p->v] < mint )
	    {mint = d[p->v] ; rec = p->v ; }
	  p = p->next;
	}
      //cout<<"nopath con"<<i<<" "<<mint<<" "<<rec<<"\n";
      di[ i ] = rec;
      vh[ d[i] ]--;
      if(vh[ d[i] ] == 0) break;
      d[ i ] = mint + 1;
      vh[ d[i] ]++;

      if(i not_eq source)
	{i = pre[i] ; aug = h[i];}
      //cin.get();
    }
  
  return ;
}

int main()
{
  int u,v,c,i;

  cin>>m>>n;
  for(i = 1 ; i <= m ; ++ i)
    {
      cin>>u>>v>>c;
      verx_add(u,v,c);
      //w[u][v]+=c;
    }
    
  dfs( 1 , n );
  cout<<flow<<"\n";
  return 0;
}
