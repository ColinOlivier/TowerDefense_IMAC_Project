#include "graph/EdgeGraph.hpp"


namespace Graph {
    EdgeGraph::EdgeGraph(NodeGraph* nodeTo_ptr, double lengthTo) {
        to_ptr = nodeTo_ptr;
        length = lengthTo;
    }
}