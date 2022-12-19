// program for coverting rgb raw file to bitmap bmp file.

#include<iostream>
#include <cstdlib>
#include <stdio.h>
int main()
{
typedef struct                       // This block of bytes is at the start of the file and is used to identify the file
    {
    unsigned int   bfSize;           // Size of file 
    unsigned short bfReserved1;      
    unsigned short bfReserved2;      
    unsigned int   bfOffBits;        // Offset to bitmap data (starting address of the byte where the bitmap image data can be found)
    } BITMAPFILEHEADER;

typedef struct                       // detailed information of the image which will be used to display on the screen   
    {
    unsigned int   biSize;           // Size of info header 
    int            biWidth;          // Width of image 
    int            biHeight;         // Height of image 
    unsigned short biPlanes;         // Number of color planes 
    unsigned short biBitCount;       // Number of bits per pixel 
    unsigned int   biCompression;    // Type of compression to use 
    unsigned int   biSizeImage;      // Size of image data 
    int            biXPelsPerMeter;  // X pixels per meter 
    int            biYPelsPerMeter;  // Y pixels per meter 
    unsigned int   biClrUsed;        // Number of colors used 
    unsigned int   biClrImportant;   // Number of important colors 
    } BITMAPINFOHEADER;   

BITMAPFILEHEADER bfh;
BITMAPINFOHEADER bih;

unsigned short bfType=0x4d42;           
bfh.bfSize = 2 + 		// The first 2 bytes of the BMP file format are the character "B" then the character "M" in ASCII encoding
	     sizeof(BITMAPFILEHEADER) + 
	     sizeof(BITMAPINFOHEADER) +
	     640*480*3; 
	     
bfh.bfOffBits = 0x36;  // 54

bih.biSize = sizeof(BITMAPINFOHEADER);
bih.biWidth = 640;
bih.biHeight = 480;
bih.biPlanes = 1;
bih.biBitCount = 24;
bih.biSizeImage = 0;
bih.biXPelsPerMeter = 5000;
bih.biYPelsPerMeter = 5000;
bih.biClrUsed = 1;

// read from file and store in buffer

char buffer[640*480*3]; 
FILE * fr = fopen("yuv1.raw", "rb");
int count = fread(&buffer,640*480*3, 1, fr);
fclose(fr);

// write to a file 
FILE *file = fopen("c.bmp", "wb");

fwrite(&bfType,1,sizeof(bfType),file);
fwrite(&bfh, 1, sizeof(bfh), file);
fwrite(&bih, 1, sizeof(bih), file);
fwrite(&buffer, 640*480*3, 1, file);

fclose(file);
}
