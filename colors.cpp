// program for creating three RGB raw file.

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#define SIZE 640*480*3
using namespace std;

int main()
{
  FILE * redfile, *greenfile, *bluefile;
  int i;
  char* red = NULL;
  red = (char*)malloc(SIZE);
  char* green = NULL;
  green = (char*)malloc(SIZE);
  char* blue = NULL;
  blue = (char*)malloc(SIZE);
  
  redfile = fopen("red.raw","wb");
  greenfile = fopen("green.raw","wb");
  bluefile = fopen("blue.raw","wb");
  
  
  for(i=0;i<SIZE;i=i+3)
  {
    red[i] = 255; // prints 255,0,0,255,0.........SIZE (red color)
  }
  
    for(i=1;i<SIZE;i=i+3)
  {
    green[i] = 255; // prints 0,255,0,0,255,0,.......SIZE (green color)
  }
  
    for(i=2;i<SIZE;i=i+3)
  {
    blue[i] = 255;  // prints 0,0,255,0,0,255,0,......SIZE (blue color)
  } 
 
  
  fwrite(red,SIZE,1,redfile);
  fwrite(green,SIZE,1,greenfile);
  fwrite(blue,SIZE,1,bluefile);
  
 
 if( red != NULL && green != NULL && blue != NULL)
 {
  free(red);
  free(green);
  free(blue);
 }
  fclose(redfile);
  fclose(greenfile);
  fclose(bluefile);
  return 0;
}
