#include            <SFML/Graphics.h>
#include            <SFML/Window.h>
#include            "framebuffer.h"
#include            "line.h"
#include            "pixel.h"
#include            "c_graph_prog.h"
#include            "rectangle.h"

line_t              create_line()
{
    line_t          line;
    sfVector2i      start = {0, 0};
    sfVector2i      end = {200, HEIGHT-50};

    line.start = start;
    line.end = end;
    line.thickness = 4;
    line.color = sfGreen;
    return (line);
}

rectangle_t         create_rectangle()
{
    rectangle_t     rect;
    sfVector2i      start = {50, 50};
    sfVector2i      end = {250, 500};

    rect.start = start;
    rect.end = end;
    rect.thickness = 20;
    rect.color = sfBlue;
    return (rect);
}

int                 main()
{
    sfVideoMode     mode = {WIDTH, HEIGHT, BPP};
    sfRenderWindow  *window = sfRenderWindow_create(mode, "Ma premiere fenetre", sfResize | sfClose, NULL);
    sfEvent         event;
    sfTexture       *texture;
    sfSprite        *sprite;
    framebuffer_t   *buffer;
    line_t          line = create_line();
    rectangle_t     rect = create_rectangle();

    buffer = framebuffer_create(WIDTH, HEIGHT);
    draw_thick_line(buffer, line);
    draw_rectangle_custom(buffer, rect);
    texture = framebuffer_to_texture(buffer);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window))
    {  
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
