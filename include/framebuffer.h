#ifndef     FRAMEBUFFER_H_
# define    FRAMEBUFFER_H_

# include   <SFML/Graphics.h>

typedef struct      s_framebuffer {
    unsigned int    width;
    unsigned int    height;
    sfUint8         *pixels;
}                   framebuffer_t;

// Create a framebuffer and init the pixel array
framebuffer_t       *framebuffer_create(unsigned int width, unsigned int height);

// Free everything that need to be freed
void                framebuffer_destroy(framebuffer_t *buffer);

// Convert the framebuffer to a Texture
sfTexture           *framebuffer_to_texture(framebuffer_t *buffer);

#endif
