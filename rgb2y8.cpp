// program for converting RGB to Y8 (grayscale )

#include<iostream>
#include<fstream>
#define Height 480
#define Width 640 
#define SIZE Height*Width*3
#define N Height*Width
int main()
{
 int row,col; // column represented as col
 int gray=0; // used for storing grayscale data
 unsigned int stride = Width * 3;  // width * bytes per pixel
 uint8_t* bufferIn = NULL;
 bufferIn = (uint8_t*)malloc(SIZE);
 uint8_t* bufferOut = NULL;
 bufferIn = (uint8_t*)malloc(N);

 FILE * fileIn = fopen("filename.raw", "rb");  
 fread(bufferIn,640*480*3, 1, fileIn);
 fclose(fileIn);
     gray = 0;
     for( row=0;row<Height;row++)   // looping through each and every pixel of the RGB data
      {
       for( col=0;col<stride;col+=3) 
        {  
           bufferOut[gray] = ( *(bufferIn + (row*stride+col))+ 
           		     *(bufferIn + (row*stride+col+1))+ 
           		     *(bufferIn + (row*stride+col+2)) ) / 3;		// finding the average of R G B and storing it in buffer
           gray++;     
        }
      }           
 FILE *fileOut = fopen("filename.raw", "wb"); 
 fwrite(bufferOut,640*480, 1, fileOut);
 if( bufferIn !== NULL && bufferOut != NULL)
 {
 free(bufferIn);
 free(bufferOut);
 }
 fclose(fw);
}
