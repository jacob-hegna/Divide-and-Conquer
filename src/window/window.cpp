#include "window.h"

using namespace rapidxml;

Window::Window(std::string path)
{
	init(path);
}

Window::~Window(void) {
	free();
}

void Window::free(void) {
	print("Freeing GLFW window and OpenGL context...\n");
	glfwDestroyWindow(_window);
	fclose(_outputFile);
}

int Window::init(std::string path)
{
	// Input
	struct stat buffer;
	if(stat(path.c_str(), &buffer) == 0) {
		file<> xmlFile(path.c_str());
		xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		xml_node<> *root = doc.first_node("window");

		xml_attribute<> *rootAddr = root->first_attribute("title");
		_title = rootAddr->value();
		rootAddr = rootAddr->next_attribute("aa");
		_aa = atof(rootAddr->value());


		xml_node<> *node = root->first_node("pos");
		xml_attribute<> *attr = node->first_attribute("x");
		_x = atoi(attr->value());
		attr = attr->next_attribute("y");
		_y = atoi(attr->value());

		node = node->next_sibling("size");
		attr = node->first_attribute("w");
		_w = atoi(attr->value());
		attr = attr->next_attribute("h");
		_h = atoi(attr->value());
		attr = attr->next_attribute("fullscreen");
		_fc = (atoi(attr->value()) == 1) ? true : false;

		node = node->next_sibling("color");
		attr = node->first_attribute("r");
		_clearColor.r = atof(attr->value());
		attr = attr->next_attribute("g");
		_clearColor.g = atof(attr->value());
		attr = attr->next_attribute("b");
		_clearColor.b = atof(attr->value());

		root = root->next_sibling("output");
		rootAddr = root->first_attribute("path");
		_outputFile = fopen(rootAddr->value(), "w");

	} else {
		std::ofstream ofile(path);
		ofile << "<window title=\"Divide and Conquer\" aa=\"16\">"                          << std::endl
			  << "     <pos  x=\"15\" y=\"15\"/>"                                           << std::endl
			  << "     <size w=\"800\" h=\"600\" fullscreen=\"0\"/>"                        << std::endl
			  << "     <color r=\"1\" g=\"1\" b=\"1\"/>"                                    << std::endl
		      << "</window>"                                                                << std::endl
		      << "<output path=\"stdio.txt\"/>"                                             << std::endl;
		ofile.close();
		_outputFile = fopen("stdio.txt", "w");
		_clearColor.r = 1.f;
		_clearColor.g = 1.f;
		_clearColor.b = 1.f;
		_x = 50;
		_y = 50;
		_w = 800;
		_h = 600;
		_title = "Divide and Conquer";
		_aa = 16;
		_fc = false;
	}

	// Output
	print("+------------------------------------+\n");
	print("| Output file for Divide-and-Conquer |\n");
	print("+------------------------------------+\n");

	glfwWindowHint(GLFW_SAMPLES, _aa);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	print("Opening window...");
	_window = glfwCreateWindow(_w, _h, _title.c_str(), (_fc) ? glfwGetPrimaryMonitor() : nullptr, nullptr);

	if(!_window) {
		glfwDestroyWindow(_window);
		print("failed!\n");
		return -1;
	}
	print("done!\n");

	glfwSetWindowPos(_window, _x, _y);

	print("Setting up OpenGL...\n");

	glfwMakeContextCurrent(_window);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, _w, _h, 0);
	glClearColor(_clearColor.r,
				 _clearColor.g,
				 _clearColor.b,
				 1.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return 0;
}

void Window::clear(void) {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
}
