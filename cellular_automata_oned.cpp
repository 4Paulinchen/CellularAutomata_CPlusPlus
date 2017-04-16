/* One Dimensional Cellular Automata"
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "boost/multi_array.hpp"
#include <fstream>
#include <cstdio>

using namespace std;

int comparison(std::array<int, 3> comparison_vektor){
  // Function for present row
  // Rule 30 (I think)
  std::array<int, 3> c={1,0,0};
  std::array<int, 3> c2={0,1,1};
  std::array<int, 3> c3={0,1,0};
  std::array<int, 3> c4={0,0,1};

  if      (comparison_vektor==c)
           {return 1;}

  else if (comparison_vektor==c2)
            {return 1;}
  else if (comparison_vektor==c3)
            {return 1;}
  else if (comparison_vektor==c4)
            {return 1;}
  else
            {return 0;}


  }

int main()
{
   remove ( "output.txt" );
  // Length first array
  int n;
  cout << "Length array 1: ";
  cin >> n;
  // initialize Matrix A(n*n) output
  typedef boost::multi_array<double, 2> array_type;
  typedef array_type::index index;
  array_type A(boost::extents[n][n]);
  //
  // initialize initial condition in first row
  // here: 1 in middle rest zero
  for (int i=0;i<n;i++)
  {
      A[0][i]=0;
  }
  if ( n % 2 == 0 )
  {

    A[0][(n)/2]=1;
  }
  else
  {
      A[0][(n-1)/2]=1;
  }


  // checking previous row to determine present row
  for (int i=1;i<n;i++)
  {

     for (int j=1;j<n-1;j++)
        {
            std::array<int, 3> comparison_vektor;
            comparison_vektor[0]=A[i-1][j-1];
            comparison_vektor[1]=A[i-1][j];
            comparison_vektor[2]=A[i-1][j+1];
            A[i][j]= comparison(comparison_vektor);
        }
     A[i][0]=0;
     A[i][n-1]=0;
  }
 // Writing output to text file
  cout << "displaying matrix" << endl;
    freopen("output.txt","a+",stdout);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        freopen("output.txt","a+",stdout);
        cout << endl;
    }


  return 0;
}
