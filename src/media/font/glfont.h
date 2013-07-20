#ifndef _glfonth_
#define _glfonth_

//*********************************************************
//GLFONT.H -- Header for GLFONT.CPP
//Copyright (c) 1998 Brad Fish
//Copyright (c) 2002 Henri Kyrki
//See glFont.txt for terms of use
//10.5 2002
//*********************************************************

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif

#include <string>
#include <sstream>
#include <Windows.h>
#include <GL/gl.h>

using namespace std;

namespace GLFontError {
	struct InvalidFile{};
	struct InvalidFont{};
}

class GLFontBase {
public:
	GLFontBase();
	void Begin();
	virtual ~GLFontBase();
	void FreeResources();
protected:

	void CreateImpl(const string &FileName, GLuint Tex, bool PixelPerfect = FALSE);

	typedef struct
	{
	union {
		float dx;
		int width;
	};
	union {
		float dy;
		int height;
	};
	float tx1, ty1;
	float tx2, ty2;
	} GLFONTCHAR;

	typedef struct
	{
	int Tex;
	int TexWidth, TexHeight;
	int IntStart, IntEnd;
	GLFONTCHAR *Char;
	} GLFONT;

	GLFONT Font;
	bool ok;
private:
};

class GLFont : public GLFontBase {
public:
	GLFont();
	void Create(const string &FileName, GLuint Tex);
	void TextOut (string String, float x, float y, float z);
};

class PixelPerfectGLFont : public GLFontBase {
public:
	PixelPerfectGLFont();
	void Create(const string &FileName, GLuint Tex);
	void TextOut (string String, int x, int y, int z);
};

template <class T>
void glPrintf(T data, std::string path, int x, int y)
{
	GLuint textureName;
	glGenTextures(1, &textureName);
	PixelPerfectGLFont font;
	font.Create(path, textureName);

	std::stringstream ss;
	std::string s;

	ss << data;
	ss >> s;

	glColor3f(0.f, 0.f, 0.f);
	font.Begin();
	font.TextOutA(s, x, y, 0);

	glDeleteTextures(1, &textureName);
}

#endif
//End of file


