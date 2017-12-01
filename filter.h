#ifndef INCLUDED_FILTER_H
#define INCLUDED_FILTER_H

/* Type of filtering */
typedef enum { MEAN, MEDIAN } filter;

/* RGB values */
typedef struct { unsigned char r, g, b; } RGB;

/* readPPM reads a PPM image from a file.
   Input: file is a pointer to a character string specifying a file name.
   Output:
     *width stores the width of the image
     *height stores its height
     *max stores the largest RGB value in the image

   readPPM returns a pointer to an array of size (*width)*(*height)
   storing the RGB values of the image.
*/
RGB *readPPM(const char *file, int *width, int *height, int *max);

/* writePPM writes an image into a file.
   Input:
      file   name of the file
      width  width of the image
      height height of the image
      max    largest RGB value
      image  pointer to an array of size width*height with RGB values
*/
void writePPM(const char *file, int width, int height, int max,
              const RGB *image);

/* denoiseImage applies filtering to an image.
   Input:
      width  width of the image
      height height of the image
      max    largest RGB value
      image  pointer to an array of size width*height with RGB values
      n      size of filtering window
      f      type of filtering: MEAN or MEDIAN

   denoiseImage returns a pointer to an arrary of size width*height containing the new image.
*/
RGB *denoiseImage(int width, int height, const RGB *image, int n, filter f);

#endif