/*
  AC-automate
  write by gestapolur
  2011-10-14
  2011-10-23
  hint: we suppose all input are lowercase letters 
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXA 27
using namespace std;

class node
{
public:
  bool endsign;
  node *fail;
  node *pre ;
  char c;
  node *next[ MAXA ] ;
};

node *root = { NULL };
int n , m; 
int node

/*
  traceback & construct fail point
*/
void fail( node x , node y , char fd )
{
  for( int i = 0 ; i < 26 ; ++ i )
    if( x->next[ i ] not_eq NULL and i == x )
  return ; 
}

void add( string k )// construct tries
{
  int len , tmp ;
  node *p = NULL , *pre;
  len = k.size();
  tmp = 0;
  pre = root ;
  p = root->next[ k[ tmp ] - 'a' ] ;
  do{

    if( p == NULL )
      {
        p = new node;
        //cout<<k[ tmp ]<<"\n";
        pre->next[ k[ tmp ] - 'a' ] = p;
        p->endsign = false;
        p->pre = pre ;
        p->next[ MAXA ] = NULL;
        p->c = k[ tmp ];
      }
    ++ tmp;
    if( tmp == len ) {p->endsign = true;}
    else { pre = p ; p = p->next[ k[ tmp ] - 'a' ]; }
  }while( tmp < len );
  return ;
}

void disp( node *p )
{
  if( p not_eq NULL )
    {
      cout<<p->c<<": ";
      for( int i = 0 ; i < 26 ; ++ i )
        if( p->next[ i ] not_eq NULL )
          cout<<char( i + 'a' )<<" ";
      cout<<"\n";
      for( int i = 0 ; i < 26 ; ++ i )
        if( p->next[ i ] not_eq NULL )
          disp( p->next[ i ] );
    }
  return ;
}

void contree()
{
  
  return ;
}

void init()
{
  int i;
  string word;
  cin>>n>>m;
  //init root
  root = new node ;
  root->next[ MAXA ] = NULL;
  root->c = ' ';
  //input n dic word
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>word;
      add( word );
    }
  disp( root );
  
  contree();
  /*
  //input m word to find
  for( i = 1 ; i <= m ; ++ i )
    {
      cin>>word;
      find( );
    }
  */
  return ;
}

int main()
{
  init();
  
  
  return 0;
}
