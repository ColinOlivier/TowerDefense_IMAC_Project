#pragma once 
#include <vector>
#include <array>

#include "graph/NodeGraph.hpp"
#include "map/tile/TileData.hpp"

namespace Graph {
    struct Graph
    {
        std::vector<NodeGraph> nodes;

        NodeGraph& createNode();
        // NodeGraph createNode(std::vector<std::pair<NodeGraph&, double>> edges);
    };


    Graph getGraphFromMapTileTypeArray(std::array<TileType, 10 * 10>& mapTileTypeArray);
}

