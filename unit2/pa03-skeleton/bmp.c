#include <stdlib.h>
#include <stdio.h>

#include "bmp.h"
/* USE THIS FUNCTION TO PRINT ERROR MESSAGES
   DO NOT MODIFY THIS FUNCTION
*/
void PrintError(int error){
  switch(error){
  case ARGUMENT_ERROR:
    printf("Usage:ex5 <source> <destination>\n");
    break;
  case FILE_ERROR:
    printf("Unable to open file!\n");
    break;
  case MEMORY_ERROR:
    printf("Unable to allocate memory!\n");
    break;
  case VALID_ERROR:
    printf("BMP file not valid!\n");
    break;
  default:
    break;
  }
}

/* The input argument is the number of command line arguments given when executing the file.
 * It checks to see if there are at least 3 commandline arguments.
 * If yes , the function returns TRUE. if not, the function prints error message and returns FALSE.
*/
int CheckArgCount(int argc) {
}

/* The input arguments are a string as the name of a file and the option on how the function will manipulate the file.
 * This function opens the file and returns the FILE pointer.
 * If it fails to open the file, the function prints error message returns NULL.
*/
FILE* OpenFile(char* filename, char* opt) {
}


/* The input argument is the source file pointer. The function will first construct a BMP_Image image by allocating memory to it.
 * Then the function read the header from source image to the image's header.
 * Compute data size, width, height, and bytes_per_pixel of the image and stores them as image's attributes.
 * Finally, allocate menory for image's data according to the image size.
 * Return image;
*/
BMP_Image* CreateBMPImage(FILE* fptr) {

  //Allocate memory for BMP_Image*;

  //Read the first 54 bytes of the source into the header

  //Compute data size, width, height, and bytes per pixel;

  //Allocate memory for image data
}


/* The input argument is the size of image data. The function allocates memory for storing the image data and returns image data pointer.
 * If memory allocation fails, the function prints error message.
*/
char* AllocateImageData(int dataSize) {
}

/* The input arguments are the source file pointer, the image data pointer, and the size of image data.
 * The functions reads data from the source into the image data.
*/
void ReadImageData(FILE* fptr, char* data, int dataSize) {
}

/* The input arguments are image data pointer and the size of image data.
 * The function inverts every byte of the image data.
*/
void InvertImageData(char* data, int dataSize) {
}

/* The input arguments are the destination file pointer, BMP_Header pointer, and the image data pointer, and the size of image data.
 * The function write the header and image data into the destination file.
*/
void WriteImage(FILE* fptr, BMP_Header* header, char* data, int dataSize) {
}

/* The input argument is the BMP_Image pointer. The function frees memory of the BMP_Image.
*/
void FreeImage(BMP_Image* image) {
}

/* The input argument is file pointer. The function closes the file.
*/
void CloseFile(FILE* fptr) {
}

/* The functions checks if the source image has a valid format.
 * It returns TRUE if the image is valid, and returns FASLE if the image is not valid.
 * DO NOT MODIFY THIS FUNCTION
*/
int CheckBMPValid(BMP_Header* header) {
  // Make sure this is a BMP file
  if (header->type != 0x4d42) {
    return FALSE;
  }
  // Make sure we are getting 24 bits per pixel
  if (header->bits_per_pixel != 24) {
    return FALSE;
  }
  // Make sure there is only one image plane
  if (header->planes != 1) {
    return FALSE;
  }
  // Make sure there is no compression
  if (header->compression != 0) {
    return FALSE;
  }
  return TRUE;
}

/* The function prints all information of the BMP_Header.
   DO NOT MODIFY THIS FUNCTION
*/
void PrintBMPHeader(BMP_Header* header) {
  printf("file type (should be 0x4d42): %x\n", header->type);
  printf("file size: %d\n", header->size);
  printf("offset to image data: %d\n", header->offset);
  printf("header size: %d\n", header->header_size);
  printf("width_px: %d\n", header->width_px);
  printf("height_px: %d\n", header->height_px);
  printf("planes: %d\n", header->planes);
  printf("bits: %d\n", header->bits_per_pixel);
}

/* The function prints information of the BMP_Image.
   DO NOT MODIFY THIS FUNCTION
*/
void PrintBMPImage(BMP_Image* image) {
  printf("data size is %d\n", image->data_size);
  printf("width_px is %d\n", image->width_px);
  printf("height_px size is %d\n", image->height);
  printf("bytes per pixel is %d\n", image->bytes_per_pixel);
}
