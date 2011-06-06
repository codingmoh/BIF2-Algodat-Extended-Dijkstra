//      node.cpp
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

// project includes
#include "edge.h"
#include "node.h"
/**
 * Constructor which takes the name of the node/station
 * @param std::string name: The station name
 */
Node::Node(std::string name)
{
    this->name = name;
}

/**
 * Add a new edge to the node
 * @param Edge edge: The edge object
 */
void Node::addEdge(Edge* edge)
{
    this->edges.push_back(edge);
}

/**
 * Returns the edges of a node
 * @return std::vector<Edge* > edges: The list with edges
 */
std::vector<Edge* > Node::getEdges()
{
    return this->edges;
}
