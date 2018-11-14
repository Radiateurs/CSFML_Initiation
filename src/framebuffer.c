#include            <stdlib.h>
#include            "framebuffer.h"
#include            "c_graph_prog.h"

/*
** @function    framebuffer_create  Create a framebuffer
** @params      width               The width of the framebuffer
** @params      height              The height of the framebuffer
** @returns     framebuffer_t       A perfectly allocated framebuffer. NULL if malloc fails
*/
framebuffer_t       *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t   *buffer;
    unsigned int    i;
    unsigned int    size;

    i = 0;
    size = (width * height) * (BPP / 4);
    if ((buffer = malloc(sizeof(*buffer))) == NULL)
        return (NULL);
    buffer->width = width;
    buffer->height = height;
    buffer->pixels = malloc(sizeof(*(buffer->pixels)) * size);
    if (buffer->pixels == NULL)
        return (buffer);
    while (i < size)
    {
        buffer->pixels[i] = 0;
        i++;
    }
    return (buffer);
}

/*
** @function    framebuffer_destroy Destroy a framebuffer. Cleans everything that needs to be cleaned.
** @params      buffer              The framebuffer to clean
** @returns     void
*/
void                framebuffer_destroy(framebuffer_t *buffer)
{
    if (buffer == NULL)
        return ;
    if (buffer->pixels != NULL)
        free(buffer->pixels);
    free(buffer);
}

/*
** @function    frambuffer_to_texture   Display theframebuffer to a window at pos x y
** @params      buffer                  The framebuffer to convert
** @returns     sfTexture*              Returns a pointer to the new texture
*/
sfTexture           *framebuffer_to_texture(framebuffer_t *buffer)
{
    sfTexture       *texture;

    if (buffer == NULL || buffer->pixels == NULL)
        return (NULL);
    if ((texture = sfTexture_create(buffer->width, buffer->height)) == NULL)
        return (NULL);
    sfTexture_updateFromPixels(texture, buffer->pixels, buffer->width, buffer->height, 0, 0);
    return (texture);
}
