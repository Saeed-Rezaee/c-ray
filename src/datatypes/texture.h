//
//  texture.h
//  C-ray
//
//  Created by Valtteri on 09/04/2019.
//  Copyright © 2015-2019 Valtteri Koskivuori. All rights reserved.
//

enum fileType {
	bmp,
	png
};

struct dimensions {
	int height;
	int width;
};

enum colorspace {
	linear,
	sRGB
};

struct texture {
	enum fileType fileType;
	enum colorspace colorspace;
	char *filePath;
	char *fileName;
	int count;
	unsigned char *data;
	unsigned int *width;
	unsigned int *height;
};

struct color;

void blit(struct texture *t, struct color c, unsigned int x, unsigned int y);
void blitDouble(double *buf, int width, int height, struct color *c, unsigned int x, unsigned int y);

void textureFromSRGB(struct texture *t);
void textureToSRGB(struct texture *t);

void freeTexture(struct texture *tex);