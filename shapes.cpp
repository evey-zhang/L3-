#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) 
{
   for(int i=top; i < height + top; i++)  //for two vertical sides of rect
   {
     if ((i > 0) && (left > 0) && (i < SIZE))
     {
      image[i][left] = 0;
       
     }
     if (i>0 && ((left + width) >0) && (left + width) < SIZE )
     {
      image[i][left + width] = 0;
     }
   }

   for(int i=left; i < left + width; i++)// for two horizontal sides of rect
   {
     if ((i > 0) && (top > 0) && (i < SIZE))
     {
      image[top][i] = 0;
      
     }
     if ((i>0)&& (i < SIZE) && (top +height) > 0) 
     {
      image[top + height][i] = 0;
     }
   }
  
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) 
{
  double rx = width / 2; // 
  double ry = height / 2;
   for (double theta=0.0; theta < 2*M_PI; theta += .01) 
   {
      double x = cx + rx*cos(theta);
      double y = cy + ry*sin(theta);
      if (!(x < 0 || y < 0 || x>SIZE || y > SIZE))
      {
        image[int(y)][int(x)] = 0;
      }
      
   }
}


int main() 
{
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) 
   {
      for (int j=0; j < SIZE; j++) 
      {
         image[i][j] = 255;
      }
   }
   // Main program loop here
   int type; 
   while (type != 2)
   {
     cout<< "To draw a rectangle, enter: 0 top left height width" << "\n";
     cout << "To draw an ellipse, enter: 1 cy cx height width"<< "\n";
     cout <<"To save your drawing as \"output.bmp\" and quit, enter: 2: "<< "\n";
     
     //first check the type of shape to be drawn
     cin >> type;
     
     if (type == 0)//if rectangle
     {
       int top, left, width, height;
       cin >> top >> left >> width >> height;
       
       draw_rectangle(top, left, width, height);
       // Write the resulting image to the .bmp file
       writeGSBMP("output.bmp", image);
     }
     
     else if (type == 1)//if ellipse
     {
       
       int cy, cx, height, width;
       cin >> cy >> cx >> height >> width;
       //check for negatives
       
       draw_ellipse(cy, cx, height, width);
       // Write the resulting image to the .bmp file
       writeGSBMP("output.bmp", image);
     }
   }
   
   return 0;
}
