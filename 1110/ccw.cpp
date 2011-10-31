//det test
#include<iostream>
#include<cmath>
using namespace std;

class point
{
public:
  double x , y;
};

double det( double x1 , double y1 , double x2 , double y2 )
{ return x1 * y2 - x2 * y1 ; }

double cross( point a , point b , point c )
{ return det( b.x - a.x , b.y - a.y , c.x - a.x , c.y - a.y ) ;}

int main()
{
  point a , b , c ;
  cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
  cout<<cross( a , b , c )<<"\n";
  return 0;
}