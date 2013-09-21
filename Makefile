BUILDDIR    = bin/
INCLUDEDIR  = include/
SOURCEDIR   = src/

DIRS        = $(wildcard $(SOURCEDIR)*/)
VPATH       = $(SOURCEDIR):$(DIRS):$(foreach dir, $(DIRS), $(wildcard $(dir)*/))

IFILES     := $(shell find $(SOURCEDIR) -name '*.cpp')
OFILES     := $(subst $(SOURCEDIR), $(BUILDDIR), $(addsuffix .o, $(notdir $(shell find $(SOURCEDIR) -name '*.cpp'))))

CC          = clang
CCFLAGS     = -c -Wall -O3 -std=c++0x -I$(INCLUDEDIR)
LINKFLAGS   = -lGL -lGLU -lglfw3 -lXrandr -lXi -lGLC
DYNLINK     = /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXxf86vm.so

EXEC = Divide-and-Conquer

all: $(EXEC)

$(EXEC): $(OFILES)
	$(CC) $(foreach file, $^, $(BUILDDIR)$(file)) $(LINKFLAGS) -o $@ $(DYNLINK)

%.cpp.o: %.cpp
	$(CC) $(CCFLAGS) $< -o $(BUILDDIR)$@

.PHONY: clean
clean:
	rm $(BUILDDIR)*
	rm $(EXEC)
