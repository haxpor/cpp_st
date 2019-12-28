#pragma once

#include <iostream>
#include <cstring>

class TGAImage
{
public:
    static bool writeImage(const char* filename, unsigned int* frameBuffer, int width, int height)
    {
        FILE *out_file = fopen(filename, "wb");
        if (out_file == nullptr)
        {
            std::cerr << "Error attempting to open file for writing";
            return false;
        }

        // check the header format of tga at http://www.paulbourke.net/dataformats/tga/
        unsigned char header[18];
        std::memset(header, 0, 18);
        // now we selectively set only the interested fields
        header[2] = 2;  // data type code, it's uncompressed RGB image
        header[12] = width & 0x00FF;  // low-order bytes for width
        header[13] = (width & 0xFF00) >> 8;  // high-order bytes for width
        header[14] = height & 0x00FF; // low-order bytes for height
        header[15] = (height & 0xFF00) >> 8; // high-order bytes for height
        header[16] = 24;  // number of bits per pixel

        if (fwrite(header, sizeof(header), 1, out_file) != 1)
        {
            std::cerr << "Error writing header section for .tga file";
            fclose(out_file);
            return false;
        }

        const int cvtBufferSize = width * height * 3;
        unsigned char cvtFrameBuffer[cvtBufferSize];
        int cvtI = 0;
        for (int j=0; j<height; ++j)
        {
            for (int i=0; i<width; ++i)
            {
                unsigned int frameTmp = frameBuffer[i + j*width];
                cvtFrameBuffer[cvtI++] = frameTmp & 0xFF;
                cvtFrameBuffer[cvtI++] = (frameTmp >> 8) & 0xFF;
                cvtFrameBuffer[cvtI++] = (frameTmp >> 16) & 0xFF;
            }
        }

        if (fwrite(cvtFrameBuffer, sizeof(cvtFrameBuffer), 1, out_file) != 1)
        {
            std::cerr << "Error writing image data section for .tga file";
            fclose(out_file);
            return false;
        }

        // close file
        fclose(out_file);

        return true;
    }
};
