#pragma once

namespace Graph
{

    struct NodeGraph;

    struct EdgeGraph
    {
        NodeGraph* to_ptr;
        double length;

        EdgeGraph(NodeGraph* nodeTo_ptr, double lengthTo);
    };
}
