#include        "rectangle.h"
#include        "line.h"
#include        "pixel.h"

/*
** @function    draw_rectangle  draw a full rectangle on a framebuffer.
** @params      buffer          The framebuffer being drawn onto
** @params      start           The start position of the rectangle
** @params      end             The end position of the rectangle
** @params      color           the color of the rectangle
** @returns     void
*/
void            draw_rectangle(framebuffer_t *buffer, sfVector2i start, sfVector2i end, sfColor color)
{
    sfVector2i  a;
    sfVector2i  b;

    a.x = start.x;
    b.x = end.x;
    a.y = start.y;
    b.y = start.y;
    while (a.y <= end.y)
    {
        draw_line(buffer, a, b, color);
        a.y++;
        b.y++;
    }
}

/*
** @function    draw_reectangle_custom  draw a rectangle with custumized properties
** @params      buffer          the framebuffer being drawn onto 
** @params      rectangle       the customized rectangle
** @returns     void
*/
void            draw_rectangle_custom(framebuffer_t *buffer, rectangle_t rectangle)
{
    sfVector2i  start_x_end_y = { rectangle.start.x, rectangle.end.y };
    sfVector2i  start_y_end_x = { rectangle.end.x, rectangle.start.y };
    line_t      line;

    if (rectangle.fill == 0)
        return draw_rectangle(buffer, rectangle.start, rectangle.end, rectangle.color);
    line.thickness = rectangle.thickness;
    line.color = rectangle.color;
    line.start = rectangle.start;
    line.end = start_y_end_x;
    draw_thick_line(buffer, line);
    line.end = start_x_end_y;
    draw_thick_line(buffer, line);
    line.start = start_x_end_y;
    line.end = rectangle.end;
    draw_thick_line(buffer, line);
    line.start = start_y_end_x;
    draw_thick_line(buffer, line);
}
