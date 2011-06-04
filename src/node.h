#ifndef NODE_H
#define NODE_H
// standard includes
#include <vector>
#include <cstring>
#include <iostream>

// project includes
#include "edge.h"


/**
 * This represents a node (station of the subway). A node has a name
 * (station name) and a list with edges which are leading away/to the node
 * 
 */
class Edge;
class Node {
    
    public:
        std::string name;
        // methods
	
        Node(std::string);
        void addEdge(Edge*);
        std::vector<Edge* > getEdges();
    
    private:
        std::vector<Edge* > edges;

};


#endif // NODE_H

