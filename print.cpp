// program for creating a raw file with a color

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#define SIZE 640*480*3
using namespace std;
int main()
{
  FILE * fp;
  fp = fopen("filename.raw","wb");  opening a binary file for writing
  char* ptr = NULL;
  ptr = (char*)malloc(SIZE);
  for(int i=0;i<SIZE;i++)
   {
      ptr[i] = 255;   // printing white colour for the file
   }
  fwrite(ptr,SIZE,1,fp);
  cout<< sizeof(ptr) << endl;
  if(ptr!=NULL)
  {
    free(ptr);
  }
  fclose(fp);
  return 0;
}

