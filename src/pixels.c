#include        "framebuffer.h"
#include        "pixel.h"
#include        "c_graph_prog.h"

/*
** @function    put_pixel           Set a pixel at pos width x height at color
** @params      buffer              The framebuffer being set with the new pixel
** @params      x                   position x of pixel 
** @params      y                   position y of pixel
** @params      color               the color of the pixel
** @returns     void
*/
void            put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
    unsigned int    pos;

    if (buffer == NULL || buffer->pixels == NULL ||     \
        buffer->width <= x || buffer->height <= y)
        return ;
    pos = (buffer->width * y + x) * (BPP / 8);
    buffer->pixels[pos] = color.r;
    buffer->pixels[pos + 1] = color.g;
    buffer->pixels[pos + 2] = color.b;
    buffer->pixels[pos + 3] = color.a;
}

/*
** @function    put_thickness_pixel Draw a custon pixel
** @params      buffer              The framebuffer to draw to
** @params      pixel               the pixel to draw
** @returns     void
*/
void            put_thickness_pixel(framebuffer_t *buffer, pixel_t pixel)
{
    sfVector2i  start;
    sfVector2i  end;

    end.x = pixel.pos.x + pixel.thickness / 2 + (pixel.thickness % 2);
    start.y = pixel.pos.y - pixel.thickness / 2;
    end.y = pixel.pos.y + pixel.thickness / 2 + (pixel.thickness % 2);
    while (start.y < end.y)
    {
        start.x = pixel.pos.x - pixel.thickness / 2;
        while (start.x < end.x)
        {
            put_pixel(buffer, start.x, start.y, pixel.color);
            start.x++;
        }
        start.y++;
    }
}
