#include<iostream>
#define MAXN 10
using std::cin;
using std::cout;
int con[MAXN],org[MAXN],n;
bool check(int k)
 {
  int i;
  for(i=1;i<k;i++)
    if(con[i]==con[k])
       return false;
  return true;         
 }
 
void dfspara()
 {
  int i,j,p=1,tot=0,pa=1;
  bool mark=false;
  cin>>n;
  for(i=1;i<=n;i++)
     {
     cin>>org[i];
     con[i]=1;
     pa*=i;              
     }    
 
  while(tot<pa)
   {
   if(p>n)
     {
       /*
     for(i=1;i<=n;i++)
        cout<<org[con[i]]<<" ";
     cout<<"\n";   
     */
     p--;
     tot++;
     mark=true;     
     }             
   else
     {
     if(!mark)
       {
       while(!check(p))
          con[p]++;
       p++;          
       }
     else
       {
       if(con[p]<n)
         {
         while(mark and con[p]<n)
            {          
           con[p]++;              
           if(con[p]<=n and check(p))
              {mark=false;break;}
            }
         if(mark)
           {con[p]=1;p--;}   
         }
       else
         {con[p]=1;p--;}       
       }                             
     }        
   }     
  return ;     
 }
 
int main()
 {
  dfspara();
  //system("pause"); 
  return 0;       
 }
