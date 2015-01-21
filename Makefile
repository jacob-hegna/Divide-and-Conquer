BUILDDIR    = ./bin/
INCLUDEDIR  = ./include/
SOURCEDIR   = ./src/

DEFINES     =

PREFIX      = /usr/local
INSTDIR     = $(PREFIX)
INSTBIN     = $(INSTDIR)/bin

SDIRS       = $(wildcard $(SOURCEDIR)*/)
VPATH       = $(SOURCEDIR):$(SDIRS):$(foreach dir, $(SDIRS), $(wildcard $(dir)*/))

IFILES      = $(shell find $(SOURCEDIR) -name '*.cpp')

OFILES      = $(subst $(SOURCEDIR),  $(BUILDDIR), $(addsuffix .o, $(notdir $(shell find $(SOURCEDIR)  -name '*.cpp'))))

CC          = g++
LINKER      = $(CC)
ARCH        = 64

CCFLAGS     = -c -g -w -O3 -m$(ARCH) -std=c++0x -I$(INCLUDEDIR) -I/usr/local/include -I/opt/X11/include -L/usr/local/lib -I/opt/X11/lib
LINKFLAGS   = -m$(ARCH) -lglfw3 -framework OpenGL -lGLUT


TARGET = divide-and-conquer

.PHONY: all install remove clean

all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	test -d $@ || mkdir -p $@

$(TARGET): $(foreach file, $(OFILES), $(BUILDDIR)$(file))
	$(LINKER) $^ $(LINKFLAGS) -o $(BUILDDIR)$@

$(BUILDDIR)%.cpp.o: %.cpp
	$(CC) $(foreach def, $(DEFINES), -D $(def)) $(CCFLAGS) $< -o $@

install:
	test -d $(INSTDIR) || mkdir -p $(INSTDIR)
	test -d $(INSTBIN) || mkdir -p $(INSTBIN)

	install -m 0755 $(BUILDDIR)$(TARGET) $(INSTBIN)

remove:
	rm $(INSTBIN)/$(TARGET)

clean:
	rm $(BUILDDIR)*