#include            <SFML/Graphics.h>
#include            <SFML/Window.h>
#include            "framebuffer.h"
#include            "c_graph_prog.h"

int                 main()
{
    sfVideoMode     mode = {WIDTH, HEIGHT, BPP};
    sfRenderWindow  *window = sfRenderWindow_create(mode, "Ma premiere fenetre", sfResize | sfClose, NULL);
    sfEvent         event;
    sfTexture       *texture;
    sfSprite        *sprite;
    framebuffer_t    *buffer;

    buffer = framebuffer_create(10, 10);
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            put_pixel(buffer, x, y, sfRed);
        }
    }
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
