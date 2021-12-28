#include <iostream>
#include <cmath>

using namespace std;


int main() 
{
  
   // Main program loop here
  

  cout<< "To draw a rectangle, enter: 0 top left height width" <<"\n";
  cout << "To draw an ellipse, enter: 1 cy cx height width"<<"\n";
  cout <<"To save your drawing as \"output.bmp\" and quit, enter: 2:"<<"\n";
  int t; 
  int top;
  cin >> t;
  cin >> top;
  
  cout <<t << ", "<< top;
}
  
