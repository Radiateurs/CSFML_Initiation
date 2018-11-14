#include        "my_math.h"
#include        "line.h"
#include        "pixel.h"

/*
** @function    draw_line       draw a line on a framebuffer
** @params      buffer          the framebuffer to draw on
** @params      start           the x-y start position of the line
** @params      end             the x-y end position of the line
** @params      color           the color of the line
** @returns     void
*/
void            draw_line(framebuffer_t *buffer, sfVector2i start, sfVector2i end, sfColor color)
{
    double      delta_x = end.x - start.x;
    double      delta_y = end.y - start.y;
    double      delta = ABS(delta_x) + ABS(delta_y);
    double      delta_it = delta;
    sfVector2i  point;

    while (delta_it >= 0)
    {
        point.x = start.x + delta_x * (delta_it / delta);
        point.y = start.y + delta_y * (delta_it / delta);
        put_pixel(buffer, point.x, point.y, color);
        delta_it--;
    }
}

/*
** @function    draw_thick_line draw a line on a framebuffer from a structure line_t
** @params      buffer          the framebuffer to draw on
** @params      line            the line structure
** @returns     void
*/
void            draw_thick_line(framebuffer_t *buffer, line_t line)
{
    double      delta_x = line.end.x - line.start.x;
    double      delta_y = line.end.y - line.start.y;
    double      delta = ABS(delta_x) + ABS(delta_y);
    double      delta_it = delta;
    pixel_t     point;

    point.color = line.color;
    point.thickness = line.thickness;
    while (delta_it >= 0)
    {
        point.pos.x = line.start.x + delta_x * (delta_it / delta);
        point.pos.y = line.start.y + delta_y * (delta_it / delta);
        put_thickness_pixel(buffer, point);
        delta_it--;
    }
}
