#ifndef         PIXEL_H_
# define        PIXEL_H_

# include       <SFML/Graphics.h>

// Pixel structure that allow to draw pixel with a defined thickness.
// WARNING :    A thickness of 0 means that the pixel will do 1x1 px.
//              A thickness of 1 will do a 2x2 pixel.
//              the pos is the center of the pixel.
//              On odd thickness the thickness will be x+1 y+1
//
//              pos = X. thickness = 3
//              _________
//              | | | | |
//              ---------
//              | |X| | |
//              ---------
//              | | | | |
//              ---------
//              | | | | |
//              ---------
typedef struct  s_pixel
{
    sfVector2i  pos;
    sfColor     color;
    int         thickness;
}               pixel_t;

// Draw a pixel a X-Y pos.
void            put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color);

// Draw a pixel with a certain thickness
void            put_thickness_pixel(framebuffer_t *buffer, pixel_t pixel);

#endif          /* PIXEL_H_ */
