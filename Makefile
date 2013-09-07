SOURCE_FILES = src/main.cpp src/media/font.cpp src/window/window.cpp src/utilities/util.cpp src/utilities/timer.cpp src/modes/modes.cpp src/modes/engine/engine.cpp src/modes/gameLoop/gameLoop.cpp src/modes/menu/pause.cpp src/modes/menu/start.cpp src/actor/actor.cpp src/actor/bullet/bullet.cpp src/actor/enemy/enemy.cpp src/actor/hero/hero.cpp

FLAGS = -w -O3 -std=c++0x

LINKER = -lGL -lGLU -lglfw3 -lXrandr -lXi -lftgl

INCLUDE = -I/usr/include/freetype2

EXEC_NAME = Divide-and-Conquer

all: g++

g++:
	g++ -g $(FLAGS) $(SOURCE_FILES) $(INCLUDE) $(LINKER) -o $(EXEC_NAME) /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXxf86vm.so

clang:
	clang -g $(FLAGS) $(SOURCE_FILES) $(INCLUDE) $(LINKER) -o $(EXEC_NAME) /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXxf86vm.so