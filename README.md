# Mean/Median Photo Filter

This program takes a PPM photo as input and applies a mean or median filter and stores the file in an output specified. Both filter types work by taking in a filter size of N, where N is a N x N window that takes a pixel as the center pixel in the frame and the entries neighbouring the center pixel are confined in the frame (to the extent of the frame size). The respective filter calculation is done on all pixel's RGB values and the calculated pixel RGB values are stored in each pixel within the frame. This process repeats for each pixel of the image. Neighbouring pixels in the window that are out of bounds are simply ignored to keep a consistency in the filtering. Where the filter types differentiate is what calculation is done.

For the mean filter calculation, each pixel within the frame has their RGB values summed (for their respective colors), the three summed values are each divided by the number of pixels within the frame, then, the three calculated RGB values are stored in each pixel withing the frame, making all pixels in the frame have the same RGB values.

For the median filter calculation, the median is applied to the pixels in the frame on each of their RGB values, the middle RGB value for all pixels in the frame are taken and applied as the RGB values for the pixels making them all the same.

Execution prototype:
    
    ./denoise input_file output_file N F

input_file: The photo in which the filter is applied to.

output_file: The name of the output PPM file.

N: The frame size of the filter window. An odd number is assumed. Best results are around 3-11.

F: The type of filtering to be applied where M is median filtering and A is mean filtering.

# Sample runs:

Sample run 1 (Improper arguments):

    ./denoise
    Error, Usage: denoise input_file output_file N F
    
Sample run 2 (Mean filter):
    
    ./denoise ein.ppm einnew.ppm 7 A                    //A mean filter using window size 7x7
    *** ein.ppm read 1.4e-01 seconds 
    *** ein.ppm processed in 1.4e-01 seconds 
    *** einnew.ppm written in 1.1e-01 seconds
[Original Input File](https://i.imgur.com/eTJzlOW.png) vs. [New Output File](https://i.imgur.com/ZKsJQvO.jpg)

Sample run 3 (Median filter):

    ./denoise Mediantest.ppm Medianfix.ppm 11 M         //A median filter using window size 11x11
    *** Mediantest.ppm read 2.5e-02 seconds 
    *** Mediantest.ppm processed in 4.0e-01 seconds 
    *** Medianfix.ppm written in 1.7e-02 seconds 
[Original Input File](https://i.imgur.com/fa4Kg0u.png) vs. [New Output File](https://i.imgur.com/QKSpX4o.png)

# How to Run:

To use the program on Linux:
1) Download the "filter.h","main.c" and "makefile" files. Make sure they are in the same directory.
3) Type "make" in the terminal while being in the same directory as the files. The executable "denoise" should now be created.
4) Execute the file with the execution prototype "./denoise input_file output_file N F", inputting your values.

NOTE: Make sure the photo you are using for the program is a PPM file, to convert an image to a PPM file use imagemagick by typing "convert -compress none image_to_convert new_ppm_file.ppm" in the terminal.

NOTE: If you do not have Imagemagick use "sudo apt-get install imagemagick" to install it.

NOTE: Make sure the makefile does not have .txt in the name.
