//TIMUS 1076 AC 
#include<iostream>
#include<cstring>
#define MAXN 160
#define INF 2141483647
using namespace std;

int n ;
int w[ MAXN ][ MAXN ];
bool visx[ MAXN ] , visy[ MAXN ];
int lx[ MAXN ] , ly[ MAXN ] ;
int lnky[ MAXN ];
//int slack[ MAXN ];
int del;

void init( )
{
  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    for( int j = 1 ; j <= n ; ++ j )
        cin>>w[ i ][ j ];
  return ;
}

bool find( int x )
{
  int y ;
  visx[ x ] = true;
  for( y = 1 ; y <= n ; ++ y )
    if( not visy[ y ] )
      {
        int tmp = lx[ x ] + ly[ y ] - w[ x ][ y ];
        if( tmp == 0 )
          {
            visy[ y ] = true;
            if( lnky[ y ] == 0 or find( lnky[ y ] ) )
              {
                lnky[ y ] = x;
                return true;
              }
          }
        else //slack[ y ] = tmp < slack[ y ] ? tmp : slack[ y ];  
          del = tmp < del ? tmp : del ;
      }
  return false ;
}

void km()
{
  int x , y , i , j ;
  memset( lnky , 0 , sizeof( lnky ));
  for( i = 1 ; i <= n ; ++ i )
    for( j = 1 ; j <= n ; ++ j )
      lx[ i ] = w[ i ][ j ] > lx[ i ] ? w[ i ][ j ] : lx[ i ];
  for( i = 1 ; i <= n ; ++ i )
    ly[ i ] = 0 ;
  
  for( x = 1 ; x <= n ; ++ x )
    {
      /*
      cout<<"lx : ";for( i = 1 ; i <= n ; ++ i ) cout<<lx[ i ]<<" "; cout<<"\n";
      cout<<"ly : ";for( i = 1 ; i <= n ; ++ i ) cout<<ly[ i ]<<" ";cout<<"\n";
      cin.get();
      */
      //del = INF ;
      //for( i = 1 ; i <= n ; ++ i ) slack[ i ] = INF ;
      while( 1 )
        {
          del = INF ;
          memset( visx , 0 , sizeof( visx ) );
          memset( visy , 0 , sizeof( visy ) );
          //del = INF ;
          if( find( x ) ) break;
          /*
          for( i = 1 ; i <= n ; ++ i )
            del = slack[ i ] < del ? slack[ i ] : del;
          */
          /*
          for( i = 1 ; i <= n; ++ i )
            if( visy[ i ] )
              {ly[ i ] += del ; lx[ lnky[ i ] ] -= del ;}
          */
          
          for( i = 1 ; i <= n ; ++ i )
            {
              if( visx[ i ] )
                lx[ i ] -= del;
              if( visy[ i ] )
                ly[ i ] += del;
              //else stack[ i ] -= del ;
            }
        }
    }
  return ;
}


void out()
{  int res = 0 ;
  /*
  int res = 0 ;
  for( int i = 1 ;i <= n ; ++ i )
    res += w[ lnky[ i ] ][ i ];
  cout<<res<<"\n";
  res = 0 ;
  */
  for( int i = 1 ; i <= n ; ++ i )
    {
      for( int j = 1 ; j <= n ; ++ j )
        res += w[ i ][ j ];
      res -= w[ lnky[ i ] ][ i ];
    }
  cout<<res<<"\n";
  //for( int i = 1 ; i <= n ; ++ i ) cout<<lnky[ i ]<<" "; cout<<"\n";
  return ;
}

int main()
{
  init();
  
  km();
  
  out();

  return 0;
}
