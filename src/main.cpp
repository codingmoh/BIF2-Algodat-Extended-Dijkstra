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
#include <set>
// project includes
#include "edge.h"
#include "node.h"


int main(int argc, char **argv) {
  
  std::ifstream _inFile("ubahn2.txt");
  std::map<std::string, Node*> table;
  std::map<std::string, Node>::iterator it;
  while (!_inFile.eof())
  {
    std::string str;
    std::getline(_inFile, str);
    char* input = strtok((char*)str.c_str(),"\"");
    char* ubahn = input;
    Node*lastnode = NULL;
    Edge*lastedge = NULL;
    int lastduration = 0;
    input = strtok(NULL,"\"");
    while (input)
    {
      if(!table.count(input))
      {
	  Node * current = new Node(input);
	  table[input] = current;
	  if(lastnode!=NULL)
	  {
	    Edge * last_to_current = new Edge(current);
	    Edge * current_to_last = new Edge(lastnode);
	    last_to_current->duration = lastduration;
	    last_to_current->subwayLine = ubahn;
	    current_to_last->duration = lastduration;
	    current_to_last->subwayLine = ubahn;
	    current->addEdge(current_to_last);
	    lastnode->addEdge(last_to_current);
	  }
	  if((input = strtok(NULL,"\"\r")))
	  {
	    lastduration =  atoi(input);
	    input = strtok(NULL,"\"");
	  }
	  lastnode = current;
      }
      else
      {
	Node * current = table[input];
	Edge * last_to_current = new Edge(current);
	Edge * current_to_last = new Edge(lastnode);
	current_to_last->subwayLine=ubahn;
	current_to_last->duration = lastduration;
	current->addEdge(current_to_last);
	
	if(lastnode!=NULL)
	{
	  last_to_current->subwayLine = ubahn;
	  last_to_current->duration = lastduration;
	  lastnode->addEdge(last_to_current);
	}
	lastnode = current;
	if((input = strtok(NULL,"\"\r")))
	{
	    lastduration =  atoi(input);
	    input = strtok(NULL,"\"");
	}
      }
    }
  }
   
   std::vector<Edge*> x =  table["Schwedenplatz"]->getEdges();
   for(int i = 0;i< x.size();i++)
   {
     Node* n = x[i]->getNextNode();
     std::cout<< n->name<<x[i]->subwayLine<<x[i]->duration<<std::endl;
     
  }
    return EXIT_SUCCESS;
}
