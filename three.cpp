// program for creating a raw file with 3 different colors

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#define SIZE 640*480*3         // total size of the file
#define N SIZE*2/3		// size to be printed for one colour	

using namespace std;
int main()
{
  FILE * file;
  int i;
  file = fopen("filename.raw","wb");    //opening file for writing binary data
  char* ptr = NULL;
  ptr = (char*)malloc(SIZE);  
  
  if (ptr!=NULL)
  { 
  for(i=0;i<SIZE/3;i=i+3)
   {
      ptr[i] = 255;   // printing first color till SIZE/3
   }
  for(i=SIZE/3;i<N;i=i+3)
   {
      ptr[i+1] = 255;  // printing second color till N
   }
  for(i=N;i<SIZE;i=i+3)  
   {
      ptr[i+2] = 255;   // printing third colour for the last part
   }
   
  }
  
  fwrite(ptr,SIZE,1,file);
  if(ptr!=NULL)
  {
    free(ptr);
  }
  fclose(file);  
  return 0;
}
