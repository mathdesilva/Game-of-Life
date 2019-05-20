#include <iostream>
#include <vector>
#include <fstream>

#include "../include/lodepng.h"
#include "../include/canvas.h"

/// Saves an image as a **ascii** PPM file.
bool save_ppm3( const unsigned char * data, size_t w, size_t h, size_t d,  const std::string & file_name_ )
{
    std::ofstream ofs_file( file_name_, std::ios::out  );
    if ( not ofs_file.is_open() )
        return false;

    ofs_file << "P3\n"
        << w << " " << h << "\n"
        << "255\n";

    size_t i{0};
    while ( i < (w*h*d) )
    {
        // depth traversal, usually 3.
        for( auto id{0u} ; id < 3 ; id++ )
            ofs_file << (int) *(data + i++ ) << " ";
        ofs_file << std::endl;
        i++; // to skip alpha channel.
    }

    // Did it not fail?
    auto result = not ofs_file.fail();

    ofs_file.close();

    return result;
}

/// Encode from raw pixels to disk with a single function call
void encode_png(const char* filename, const unsigned char * image, unsigned width, unsigned height)
{
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

/// Main
int main(int argc, char *argv[])
{
    //NOTE: this sample will overwrite the file or test.png without warning!
    const char* filename = argc > 1 ? argv[1] : "test.png";

    //generate some image
    unsigned width = 20, height = 15;
    short block_size = 40;

    life::Canvas image( width, height, block_size );
    for ( auto x{0u} ; x < width ; x++ )
        for ( auto y{0u} ; y < height ; y++ )
        {
            if ( y % 2 )
                if ( ! (x % 2) )
                    image.pixel( life::Point2(x,y) , life::DEEP_SKY_BLUE );
                else
                    image.pixel( life::Point2(x,y) , life::RED );
            else
                if ( ! (x % 2) )
                    image.pixel( life::Point2(x,y) , life::RED );
                else
                    image.pixel( life::Point2(x,y) , life::DEEP_SKY_BLUE );
        }

    encode_png(filename, image.pixels(), image.width(), image.height() );
    save_ppm3( image.pixels(), image.width(), image.height(), 4, "test.ppm");
}
