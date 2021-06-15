#include <stdint.h>

#ifndef _BMP_H_
#define _BMP_H_
#define TRUE 1
#define FALSE 0
#define ARGUMENT_ERROR 1
#define FILE_ERROR 2
#define MEMORY_ERROR 3
#define VALID_ERROR 4
#define HEADER_SIZE 54

// Set data alignment to 1 byte boundary
#pragma pack(1)     

/*
 * BMP files are laid out in the following fashion:
 *   --------------------------
 *   |          Header        |   54 bytes
 *   |-------------------------
 *   |    Palette (optional)  |   0 bytes (for 24-bit RGB images)
 *   |-------------------------
 *   |       Image Data       |   file size - 54 (for 24-bit images)
 *   --------------------------
 */

/** 
 * BMP header (54 bytes).
 */

typedef struct __attribute__((packed)) BMP_Header {
    uint16_t type;           // Magic identifier
    uint32_t size;           // File size in bytes
    uint16_t reserved1;      // Not used
    uint16_t reserved2;      // Not used
    uint32_t offset;         // Offset to image data in bytes
    uint32_t header_size;    // Header size in bytes
    int32_t  width_px;       // Width of the image
    int32_t  height_px;      // Height of image
    uint16_t planes;                    // Number of color planes
    uint16_t bits_per_pixel;            // Bits per pixel
    uint32_t compression;               // Compression type
    uint32_t imagesize;                 // Image size in bytes
    int32_t  xresolution;               // Pixels per meter
    int32_t  yresolution;               // Pixels per meter
    uint32_t ncolours;                  // Number of colors  
    uint32_t importantcolours;          // Important colors
} BMP_Header;

typedef struct __attribute__((packed)) Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t alpha;
} Pixel;

typedef struct BMP_Image {
    BMP_Header header;
    int norm_height; //normalized height
    Pixel ** pixels;
} BMP_Image;

void PrintError(int error);
int CheckArgCount(int argc);
FILE* OpenFile(char* filename, char* opt);
BMP_Image* CreateBMPImage();
char* AllocateImageData(int dataSize);
void ReadImageData(FILE* fptr, char* data, int dataSize);
void InvertImageData(char* data, int dataSize);
void WriteImage(FILE* fptr, BMP_Header* header, char* data, int dataSize);
void FreeImage(BMP_Image* image);
void CloseFile(FILE* fptr);
int CheckBMPValid(BMP_Header* header);
void PrintBMPHeader(BMP_Header* header);
void PrintBMPImage(BMP_Image* image);

#endif /* bmp.h */
