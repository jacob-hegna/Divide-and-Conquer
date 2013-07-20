#include "image.h"

#include <cstdio>

ImageError Image::init(std::string path) {
	png_byte header[8];

	FILE *file = fopen(path.c_str(), "rb");
	if(file == NULL) {
		return FILE_NOT_FOUND;
	}

	fread(header, 1, 8, file);

	if(png_sig_cmp(header, 0, 8)) {
		fclose(file);
		return FILE_NOT_PNG;
	}

	png_structp pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!pngPtr) {
		fclose(file);
		return CANNOT_READ_FILE;
	}

	png_infop infoPtr = png_create_info_struct(pngPtr);
	if(!infoPtr) {
		fclose(file);
		png_destroy_read_struct(&pngPtr, (png_infopp)NULL, (png_infopp)NULL);
		return CANNOT_GET_INFO;
	}

	png_infop endPtr = png_create_info_struct(pngPtr);
	if(!endPtr) {
		fclose(file);
		png_destroy_read_struct(&pngPtr, &infoPtr, (png_infopp)NULL);
		return CANNOT_GET_INFO;
	}

	if (setjmp(png_jmpbuf(pngPtr))) {
		png_destroy_read_struct(&pngPtr, &infoPtr, &endPtr);
        fclose(file);
		return LIBPNG_FAILED;
    }

	png_init_io(pngPtr, file);
	png_set_sig_bytes(pngPtr, 8);
	png_read_info(pngPtr, infoPtr);

	int bitDepth, colorType;
	png_uint_32 tempWidth, tempHeight;

	png_get_IHDR(pngPtr, infoPtr, &tempWidth, &tempHeight, &bitDepth, &colorType, NULL, NULL, NULL);
	

}