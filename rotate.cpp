// program for rotating an image by 90 degrees 

#include<iostream>
#include<fstream>
#include <stdint.h>
#define Width 640
#define Height 480
using namespace std;
int main()
{
  const int BFHS = 14; // bitmap file header size
  const int BIHS = 40; // bitmap info header size
  unsigned int SIZE = BFHS + BIHS;   
  FILE* fileIn = fopen("b.bmp", "rb");
  FILE* fileOut = fopen("rotated1.bmp", "wb");
  char* head = (char*)malloc(SIZE);   
  char* bufferIn = (char*)malloc(Height*Width*3);
  char* bufferOut = (char*) malloc(3);
  
  fread(head,SIZE,1,fileIn); // read the header of the the input bmp file  
  fread(bufferIn, 3*Width*Height , 1 , fileIn); // read RGB values

  // swap width with height  
  uint32_t temp = *(uint32_t*)&head[BFHS+4];                // uint32_t means unsigned int
 *(uint32_t*)&head[BFHS+4] = *(uint32_t*)&head[BFHS+8];
 *(uint32_t*)&head[BFHS+8]= temp;

  fwrite(head,SIZE, 1, fileOut);  // writing header to the output file  
  for (int y=0; y<Width; y++)
   {
    for (int x=0; x<Height; x++)
     {
       fwrite(&bufferIn[(Height-x-1)*Width*3+y*3],3,1,fileOut);  
     }
    fwrite(bufferOut,0.5,1,fileOut);
  }
}
