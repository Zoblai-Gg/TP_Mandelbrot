#ifndef PPM_H
#define PPM_H

/*Structure permettant de récuperer le code couleur d'un pixel*/
struct ppm_pixel {
  unsigned char r;
  unsigned char g;
  unsigned char b;
};
/*Fonction permettant d'initialiser les couleurs dans une variable de type ppm_pixel*/
static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}

/* Structure permettant de récupérer les dimensions d'un pixel */
struct ppm_image {
  unsigned int width;
  unsigned int height;
  struct ppm_pixel *px;
};

/*Cette fonction permet l'initialisation d'une image*/
int ppm_image_init(struct ppm_image *im, int w, int h);

/*Cette fonction permet libérer l'image*/
int ppm_image_release(struct ppm_image *im);

/*Cette fonction permet d'associer la couleur à un pixel*/
static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}

/* Cette fonction écrit les coordonnées de chaque pixel dans un fichier*/
int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */