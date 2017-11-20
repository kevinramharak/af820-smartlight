## Author: Kevin Ramharak

# Project settings
PROJECTNAME := af820-smartlight# project name here #

# Directory structure
SRCDIR := src
BUILDDIR := build
TARGET := bin/$(PROJECTNAME)

# Inlude paths
#INCLUDE := $(shell find $(SRCDIR) -type d | sed -e 's/\(src.*\)/-I\1/')

# Compiler settings
CXX := g++
CXXFLAGS := -g -std=c++11 -Wall
SRCEXT := cpp

# Files
SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPENDS := $(OBJECTS:%.o=%.d)

# default
$(TARGET) : $(OBJECTS)
	@echo " $(CXX) $^ -o $(TARGET)"; $(CXX) $^ -o $(TARGET)

-include $(DEPENDS)

# object files
$(BUILDDIR)/%.o : $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	@echo " $(CXX) $(CXXFLAGS) -MMD -o $@ -c $<"; $(CXX) $(CXXFLAGS) -MMD -o $@ -c $<

# clean
clean :
	@echo " rm -r $(BUILDDIR)/*\n rm $(TARGET)"; rm -r $(BUILDDIR)/*; rm $(TARGET)

.PHONY: clean

