#pragma once 
#include <vector>
#include <utility>

#include "graph/EdgeGraph.hpp"

namespace Graph {

    struct NodeGraph
    {
        std::vector<EdgeGraph> edges;

        // NodeGraph();
        // NodeGraph(std::vector<std::pair<NodeGraph&, double>>& edgesVect);

        EdgeGraph& createEdge(NodeGraph* nodeTo_ptr, double lengthTo);
    };
}