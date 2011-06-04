//      main.cpp
//      
//      Copyright 2011 Bernhard Posselt <bernhard.posselt@gmx.at>
//                     Mohamed Auf <mohamed.auf@technikum-wien.at>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
//  

// standard includes
#include <vector>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
// project includes
#include "edge.h"
#include "node.h"


int main(int argc, char **argv) {
  
  std::ifstream _inFile(argv[1]);
  std::string str;
  std::map<std::string, Node> table;
  while (!_inFile.eof())
  {
    std::string str;
    std::getline(_inFile, str);
    char* input = strtok((char*)str.c_str()," ");
    while ((input = strtok((char*)str.c_str()," ")))
    {
      std::cout<<input<<std::endl;
    }
  }
    return EXIT_SUCCESS;
}
