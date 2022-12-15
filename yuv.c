// program for creating rgb to yuv with user defined colours

#include <stdio.h>

#define RED	0.299
#define GREEN	0.587
#define BLUE	0.114
#define UMAX	0.436
#define VMAX	0.615
void convertFromRGB ();
float redValue;
float greenValue;
float blueValue;
float y;
float u;
float v;

int main () 
{

  printf("Please input RED Value:");
  scanf("%f", &redValue);
  printf("Please input GREEN Value:");
  scanf("%f", &greenValue);
  printf("Please input BLUE Value:");
  scanf("%f", &blueValue);

  convertFromRGB(); // calling the Conversion function

  printf("\nFor the RGB input (%.2f, %.2f, %.2f),\n",redValue, greenValue, blueValue);
  printf("The YUV values are (%.2f, %.2f, %.2f)",y, u, v);
  return 0;
}
void convertFromRGB () // conversion of RGB TO YUV
{  

  y = (RED * redValue) + (GREEN * greenValue) + (BLUE * blueValue);

  u = UMAX * ((blueValue - y)/ (1 - WEIGHTEDBLUE));

  v = VMAX * ((redValue - y)/ (1 - WEIGHTEDRED)); 
}
