// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

//int v[15][15];
int cnt=0;

void printboard(vector<vector<char>> v)
{
    cout<<endl;
    for( int i=0 ; i<v.size()-1 ; i++)
   {   for( int j=0 ; j<v[0].size()-1 ; j++)
          cout<<v[i][j]<<" ";
        cout<<endl;
   }
   cout<<endl;
}

/*bool is safe(int a[][15] , int n ,int row , int col)
{
    
}*/

bool isSafe(vector<vector<char>> v ,int row , int col)
{
    for(int j=0 ; j<v.size()-1 ; j++)   // checking row
      if(v[row][j] == 'Q')
         return false;
    
    for(int i=0 ; i<v.size()-1 ; i++)   // checking col
      if( v[i][col] == 'Q')
         return false;
    
    int r , c ;

    r=row ; c=col;
    while(r>=0 && c>=0)   // check left up diagonal
    {
        if(v[r][c] == 'Q')
          return false ;
        r-- ; c--;
    }
    
    r=row ; c=col;
    while(r>=0 && c<=v.size()-2)   // check right up diagonal
    {
        if(v[r][c] == 'Q')
          return false ;
        r-- ; c++;
    }
    
    r=row ; c=col;
    while(r<=v.size()-2 && c>=0)   // check left down diagonal
    {
        if(v[r][c] == 'Q')
          return false ;
        r++ ; c--;
    }
    
    r=row ; c=col;
    while(r<=v.size()-2 && c<=v.size()-2 )  // check right down diagonal
    {
        if(v[r][c] == 'Q')
          return false ;
        r++ ; c++;
    }
 
   return true ;
}

void reset(vector<vector<char>> v , int row)
{
    for(int i=0 ; i<v.size()-1; i++)
     // for(int j=0 ; j<n ; j++)
          if(i=row)
          {
              v[0][i+1] = 'Q';
              v[0][i] = '0';
          }
    
    for(int i=0 ; i<v.size()-1 ; i++)
       for(int j=0 ; j<v[0].size()-1 ; j++)
          if(v[i][j]!='X')
             v[i][j] = '0';
     
}

int solutions(vector<vector<char>> v , int row)
{
    if(row>=v.size()-1)
    {
       printboard(v);
       cnt++;
       reset(v,row);
       //return 1;
    }
    for(int j=0 ;j<v[0].size()-1 ; j++)
    {
        if( isSafe(v,row,j) )
      {     v[row][j] = 'Q';
        
        if(solutions(v,row+1))  // reccur other queens
           return 1;
      
        v[row][j] = '0' ;  // else backtrack
      }
    }
    return 0;
}

int main() 
{
    int i , j , n ;
    cout << "Enter n : ";
    cin>>n ;
    vector<vector<char>> v(n+1,vector<char>(n+1,'0'));
    /*for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<n ; j++)
           v[i][j] = 0;*/
    
     if(solutions(v,0))
        cout<<" yay";
     if(cnt!=0)
       cout<<"Number of solutions : "<<cnt;
     else
       cout<<"No solution exists";
         
     
  
   
    return 0;
}