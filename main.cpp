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
  
  std::ifstream _inFile("ubahn.txt");
  std::map<std::string, Node*> table;
  while (!_inFile.eof())
  {
    std::string str;
    std::getline(_inFile, str);
    char* input = strtok((char*)str.c_str(),"\"");
    char* ubahn = input;
    Node*lastnode = NULL;
    Edge*lastedge = NULL;
    input = strtok(NULL,"\"");
    while (input)
    {
      if(!table.count(input))
      {
	  std::string name(input);
	  Node current(name);
	  table.insert(std::pair<std::string, Node*>(name, &current));
	  if(lastnode!=NULL)
	  {
	    Edge e(lastnode);
	    e.duration = lastedge->duration;
	    e.subwayLine=ubahn;
	    current.addEdge(&e);
	  }
	  if((input = strtok(NULL,"\"\r")))
	  {
	    Node * next;
	    Edge f(next);
	    f.duration = atoi(input);
	    f.subwayLine=ubahn;
	    input = strtok(NULL,"\"");
	    std::string name(input);
	    next = new Node(name);	    
	    current.addEdge(&f);
	    lastedge = &f;
	  }
	  lastnode = &current;

      }
      else
      {
	std::string name(input);
	Node * x = new Node(input);
	Edge * current = new Edge(x);
	current->duration = atoi(strtok(NULL,"\""));
	table[name]->addEdge(current);
	
	if(lastnode!=NULL)
	{
	  Edge * before = new Edge(lastnode);
	  before->duration = lastedge->duration;
	  table[name]->addEdge(before);
	}
	
	if((input = strtok(NULL,"\"\r")))
	{
	  Node * nxt = new Node(input);
	  Edge * next = new Edge(nxt);
	  next->duration = lastedge->duration;
	  next->subwayLine=ubahn;
	  table[name]->addEdge(next);
	 }
	  std::cout<<"dd:"<<name<<std::endl;
	  lastedge = current;
      }
    }
  }
   //std::cout<<table["Spittelau"]->name<<std::endl;
    return EXIT_SUCCESS;
}
