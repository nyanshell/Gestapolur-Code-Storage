#include<iostream>
using namespace std;

int const MaxN = 30000;

int f[MaxN],d[MaxN],last[MaxN];
int i,j,k,t;
char ch;

int Getf(int x)
{
    if ( f[x] == 0) return x;
    d[ x ] = d[ f[ x ] ];
    f[ x ] = Getf( f[ x ]);
}

void Move()
{
　　i = Getf(i); j = Getf(j);
　　f[i] = last[j];
　　last[j] = last[i];
　　d[i] = 1;
}

void Count()
　{
　　if (getf(i) == getf(j))
　　　return( abs( d[ i  ]- d[ j ] ) - 1)
　　　　else return -1;
　}

int main()
{
　for (i =1 ; i<=MaxN ; ++ i) last[i] = i; // of each line
　cin>>t;
　for (k = 1; k <= t ; ++ k;)
　　{
　　　cin>>ch>>i>>j;
　　　if(ch == 'M') Move();
　　　else cout<<Count()<<"\n";
　　}
  system("pause");
  return 0;
}
 

