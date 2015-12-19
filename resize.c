/****************************************************************************
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resize a BMP piece by piece.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // update biSizeImage, biWidth, biHeight;
    bi.biSizeImage = 3*(n*n*bi.biHeight*bi.biWidth);
    bf.bfSize      = 54 + 3*(n*n*bi.biHeight*bi.biWidth);
    bi.biHeight    = n*bi.biHeight;
    bi.biWidth     = n*bi.biWidth;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    bi.biHeight /= n;
    bi.biWidth  /= n;

    // determine padding for scanlines
    int padding =  (4 - (  bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpad  =  (4 - (n*bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    int i = 0;
    int r;
    int j;
    int k;
    int z;
    bi.biHeight = abs(bi.biHeight);
    for (i; i < bi.biHeight; i++)
    {
        // iterate over pixels in scanline
        for (r = 0; r < n; r++)
        {
            fseek(inptr, i*((bi.biWidth*3)+padding)+54, SEEK_SET);
            for (j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for (z = 0; z < n;z++)
                {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
        // then add it back (to demonstrate how)
        if (outpad > 0)
        {
        for (k = 0; k < outpad; k++)
            fputc(0x00, outptr);
        }
            }
        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
