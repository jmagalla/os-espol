#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char **argv) {
  FILE* source;
  FILE* dest;
  BMP_Image* image = NULL;

  if(!CheckArgCount(argc)){
    return EXIT_FAILURE;
  }
  if((source = OpenFile(argv[1], "rb")) == NULL) {
    return EXIT_FAILURE;
  }
  if((dest = OpenFile(argv[2], "wb")) == NULL) {
    return EXIT_FAILURE;
  } 

  image = CreateBMPImage(source);

  if(!CheckBMPValid(&image->header)) {
    PrintError(VALID_ERROR);
    return EXIT_FAILURE;
  }
  if (image->data == NULL) {
    return EXIT_FAILURE;
  }

  PrintBMPHeader(&image->header);
  PrintBMPImage(image);

  ReadImageData(source, image->data, image->data_size);
  InvertImageData(image->data, image->data_size);
  WriteImage(dest, &image->header, image->data, image->data_size);

  FreeImage(image);
  CloseFile(source);
  CloseFile(dest);

  return EXIT_SUCCESS;
}
