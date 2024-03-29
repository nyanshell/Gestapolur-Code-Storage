/*
  CSU 2011 JULY CONTEST PROB C standrad
  write by gestapolur
  2011-07-10
*/
#include<iostream>
#define MAXN 52
using std::cin;
using std::cout;

bool w[ MAXN ][ MAXN ];
int s[ MAXN ][ MAXN ];
int n,m,sc,sr,ec,er;

const int mx[ 4 ] = { 0 , 0 , 1 , -1};
const int my[ 4 ] = { 1 , -1, 0 , 0 };

void bfs( int r , int c , int st )
{
  s[ r ][ c ] = st;
  for(int i = 0 ; i < 4 ; ++ i )
    if( not w[ r + mx[ i ] ][ c + my[ i ] ] and 
	( s[ r + mx[ i ] ][ c + my[ i ] ] == 0 or s[ r + mx[ i ] ][ c + my[ i ] ] > st + 1 ))
      bfs( r + mx[ i ] , c + my[ i ] , st + 1 );
  return ;
}

int main()
{
  int i , j , t;
  char ch;
  cin>>t;
  while( t -- )
    {
      cin>>n>>m;
      cin>>sr>>sc>>er>>ec;
      cin.get();
      for( i = 1 ; i <= n ; ++ i )
	{
	  for( j = 1 ; j <= m ; ++ j )
	    {
	      cin.get(ch);
	      w[ i ][ j ] = ch - 48;
	    }
	  cin.get();
	}

      for( i = 0 ; i <= n ; ++ i )
	w[ i ][ 0 ] = w[ i ][ m + 1 ] = true;
      for( i = 0 ; i <= m ; ++ i )
	w[ 0 ][ i ] = w[ n + 1 ][ i ] = true;
  
      bfs( sr , sc , 0 );
      if( s[ er ][ ec ] not_eq 0 )
	cout<<s[ er ][ ec ]<<"\n";
      else
	cout<<"No Path.\n";
      for( i = n + 1 ; i >= 0 ; -- i )
	for( j = m + 1 ; j >= 0 ; -- j )
	  {
	    w[ i ][ j ] = 0;
	    s[ i ][ j ] = 0;
	  }
    }	    
  return 0;
}
