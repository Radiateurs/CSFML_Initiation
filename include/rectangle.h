#ifndef         RECTANGLE_H_
# define        RECTANGLE_H_

# include       "framebuffer.h"
# include       "line.h"

// Structure for rectangle.
// start is the pos start of the rectangle.
// end is the endpos of the rectangle.
// color is the rgba color of the rectangle.
// fill defines is the rectangle is filled or not.
// (0 = NOT FILLED | >= 1 = FILLED)
// thickness is only used if the rectangle is not filled.
// it defines the thickness of the border of the rectangle
typedef struct  s_rectangle
{
    sfVector2i  start;
    sfVector2i  end;
    sfColor     color;
    int         fill;
    unsigned int    thickness;
}               rectangle_t;

// Draw a rectangle starting at start and finishing at end of a set color
void            draw_rectangle(framebuffer_t *buffer, sfVector2i start, sfVector2i end, sfColor color);

// Draw rectangle from the structure rectangle_t
void            draw_rectangle_custom(framebuffer_t *buffer, rectangle_t rectangle);

#endif          /* RECTANGLE_H_ */
