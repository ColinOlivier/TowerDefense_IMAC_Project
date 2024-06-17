#include "graph/NodeGraph.hpp"

namespace Graph
{
    // NodeGraph(std::vector<std::pair<NodeGraph&, double>>& edgesVect) {
    //     for (size_t i = 0; i < edges.size(); i++)
    //     {
    //         edges.push_back(EdgeGraph(edgesVect[i].first, edgesVect[i].second));
    //     }

    // }

    // NodeGraph::NodeGraph() {
    //     NodeGraph(std::vector<std::pair<NodeGraph&, double>>{});
    // }

    EdgeGraph& NodeGraph::createEdge(NodeGraph* nodeTo_ptr, double lengthTo) {
        edges.push_back(EdgeGraph(nodeTo_ptr, lengthTo));
        return edges.back();
    }

}
