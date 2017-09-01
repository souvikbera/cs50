/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }
    int n=atoi(argv[1]);
    if(n<1||n>100)
    {
        printf("enter values 1-100");
        return 1;
    }
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    
    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
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
     
    int oheight=bi.biHeight;
    int owidth=bi.biWidth;
    // determine padding for scanlines
    int opadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biHeight=bi.biHeight*n;
    bi.biWidth=bi.biWidth*n;
    int npadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biSizeImage=((bi.biWidth* sizeof(RGBTRIPLE))+npadding)*abs(bi.biHeight);
    bf.bfSize=bi.biSizeImage+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
    
       fwrite(&bf, sizeof(BITMAPFILEHEADER),1,outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER),1,outptr);
   

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oheight); i < biHeight; i++)
    {
        for(int r=0;r<n;r++)
        {
        // iterate over pixels in scanline
        for (int j = 0; j < owidth; j++)
        {
            for(int c=0;c<n;c++)
            {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            if(c!=(n-1))
            fseek(inptr,-sizeof(RGBTRIPLE),SEEK_CUR);
            }
        }
        // skip over padding, if any
        fseek(inptr, opadding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < npadding; k++)
        {
            fputc(0x00, outptr);
        }
        if(r<n-1)
        fseek(inptr,(-sizeof(RGBTRIPLE)*owidth)-opadding,SEEK_CUR);
    }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
