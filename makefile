#      makefile
#      
#      Copyright 2011 Bernhard Posselt <bernhard.posselt@gmx.at>
#     				  Mohamed Auf <mohamed.auf@technikum-wien.at> 
#      This program is free software; you can redistribute it and/or modify
#      it under the terms of the GNU General Public License as published by
#      the Free Software Foundation; either version 2 of the License, or
#      (at your option) any later version.
#      
#      This program is distributed in the hope that it will be useful,
#      but WITHOUT ANY WARRANTY; without even the implied warranty of
#      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#      GNU General Public License for more details.
#      
#      You should have received a copy of the GNU General Public License
#      along with this program; if not, write to the Free Software
#      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#      MA 02110-1301, USA.

#PARAMS
VERSION = 1.0
PROGRAM = dijkstra
FOLDER = $(PROGRAM)-$(VERSION)
CXXFLAGS = -g -Wall -O2
LDFLAGS = 

# list all source cpp files here
SOURCES = src/main.cpp \
		  src/class/edge.cpp \
		  src/class/node.cpp

OBJECTS = $(SOURCES:.cpp=.o)


all: $(PROGRAM) $(SOURCES)

# link all object files
$(PROGRAM): $(OBJECTS)
	$(CXX) $(LDFLAGS) $< -o $@

.PHONY:
clean:
	find . -name *.o -exec $(RM) {} \;
	$(RM) $(PROGRAM)

$(FOLDER).tar.gz:
.PHONY:
dist: $(FOLDER).tar.gz src/ test/ doc/
	mkdir -p $(FOLDER)
	cp -r src $(FOLDER)/
	cp -r test $(FOLDER)/
	cp -r doc $(FOLDER)/
	cp makefile $(FOLDER)/
	tar cfvz $(FOLDER).tar.gz $(FOLDER)/
	rm -r $(FOLDER)

.PHONY:
distclean: clean
	rm *.tar.gz

