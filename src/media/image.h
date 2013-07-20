#ifndef _IMAGE_H
#define _IMAGE_H

#include <string>

#include <libpng12\png.h>
#include <GLFW\glfw3.h>

enum ImageError {
	FILE_NOT_FOUND,
	FILE_NOT_PNG,
	CANNOT_READ_FILE,
	CANNOT_GET_INFO,
	LIBPNG_FAILED
};

class Image {
public:
	Image(void) {
		// Nothing to do here
	}

	Image(std::string path) {
		init(path);
	}

	~Image(void) {
		free();
	}

	ImageError init(std::string path);

	void free(void) {
		glDeleteTextures(1, &_tex);
	}

private:
	GLuint _tex;
};

#endif