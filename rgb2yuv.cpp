// this program will convert RGB to YUV(YUYV)

#include<iostream>
#include<cstdlib>
#include<stdio.h>
#define SIZE 640*480*3
#define N 640*480*2
#define Height 480
#define Width 640
int main()
{
 int j,i; 
 unsigned int r,g,b,Y1,U1,V1,U,V,r1,g1,b1,U2,V2,Y;
 
 uint8_t* bufferIn = (uint8_t*)malloc(SIZE); 
 uint8_t* bufferOut = (uint8_t*)malloc(N);
 
 FILE *fileIn = fopen("abhishek.raw", "rb");  
 fread(bufferIn,1,SIZE, fileIn);
 fclose(fileIn);

  for(i=0,j=0;i<640*480*3;i=i+6,j=j+4) 
    {
         
  //getting RGB values from the Input file  
  											
       r = bufferIn[i+0]; 
       
       g = bufferIn[i+1];  
            
       b = bufferIn[i+2]; 
       
       r1 = bufferIn[i+3]; 
       
       g1 = bufferIn[i+4];  
       
       b1 = bufferIn[i+5];   
        
 // formula for converting RGB to YUV
               
      Y  =  0.257*r+0.504*g+0.098*b+16;
      U1 = -0.148*r-0.291*g+0.439*b+128;
      V1 =  0.439*r-0.368*g-0.071*b+128;

      Y1 =  0.257*r1+0.504*g1+0.098*b1+16;
      U2 = -0.148*r1-0.291*g1+0.439*b1+128;
      V2 =  0.439*r1-0.368*g1-0.071*b1+128; 
       
      U = (U1+U2)/2;
      V = (V1+V2)/2;
  
 // storin YUYV values in the BufferOut to display YUV file
 
        bufferOut[j+0] = Y;    
        bufferOut[j+1] = U;
        bufferOut[j+2] = Y1;
        bufferOut[j+3] = V;           
      }   
 FILE *fileOut = fopen("yuv1.raw","wb"); 
 fwrite(bufferOut,1,N,fileOut);
 fclose(fileOut);
}  
