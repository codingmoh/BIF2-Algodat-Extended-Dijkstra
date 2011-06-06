//      edge.h
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


#ifndef EDGE_H
#define EDGE_H

// standard includes
#include <vector>
#include <cstring>
#include <iostream>

// project includes
#include "node.h"


/**
 * Represents an edge. An edge connects 2 nodes (subway stations) but 
 * saves only one pointer to the next node object. Also the name of the 
 * subway and the distance has to be saved
 */
class Edge {
    
    public:
        std::string subwayLine;
        int duration; // in minutes
        // methods
        Node* getNextNode();
        Edge(Node* );
    
    protected:
        Node* nextNode;

};


#endif // EDGE_H
