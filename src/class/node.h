//      node.h
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

#include <vector>
#include <cstring>
#include <iostream>


/*
########################################################################
Node class
########################################################################
*/

// define to avoid circular includes
class Edge;

#ifndef NODE_H
#define NODE_H

/**
 * This represents a node (station of the subway). A node has a name
 * (station name) and a list with edges which are leading away/to the node
 * 
 */
class Node {
    
    public:
        std::string name;
        // methods
        Node(std::string);
        void addEdge(Edge* edge);
        std::vector<Edge* > getEdges();
    
    protected:
        std::vector<Edge* > edges;

};

#endif // NODE_H




