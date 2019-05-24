#include <iostream>
#include <vector>
#include <fstream>

#include "game_manager.h"

/// Main
int main(int argc, char *argv[])
{
    Game_manager game( argc, argv );
    game.start();


    // //NOTE: this sample will overwrite the file or test.png without warning!
    // const char* filename = argc > 1 ? argv[1] : "test.png";

    // //generate some image
    // unsigned width = 20, height = 15;
    // short block_size = 40;

    // life::Canvas image( width, height, block_size );
    // for ( auto x{0u} ; x < width ; x++ )
    //     for ( auto y{0u} ; y < height ; y++ )
    //     {
    //         if ( y % 2 )
    //             if ( ! (x % 2) )
    //                 image.pixel( life::Point2(x,y) , life::DEEP_SKY_BLUE );
    //             else
    //                 image.pixel( life::Point2(x,y) , life::RED );
    //         else
    //             if ( ! (x % 2) )
    //                 image.pixel( life::Point2(x,y) , life::RED );
    //             else
    //                 image.pixel( life::Point2(x,y) , life::DEEP_SKY_BLUE );
    //     }

    // encode_png(filename, image.pixels(), image.width(), image.height() );
    // save_ppm3( image.pixels(), image.width(), image.height(), 4, "test.ppm");
}
