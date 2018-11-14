#ifndef         LINE_H_
# define        LINE_H_

# include       <SFML/Graphics.h>
# include       "framebuffer.h"

// Thickness of 0 does a line of 1 pixel of thickness.
// Thickness of 1 == 2 pixels of thickness.OB
typedef struct  s_line
{
    sfVector2i  start;
    sfVector2i  end;
    sfColor     color;
    unsigned int    thickness;
}               line_t;

// Draw a line
void            draw_line(framebuffer_t *buffer, sfVector2i start, sfVector2i end, sfColor color);
// Draw a line with a set thickness
void            draw_thick_line(framebuffer_t *buffer, line_t line);

#endif          /* LINE_H_ */
