#include "graph/Graph.hpp"

namespace Graph {

    // NodeGraph& Graph::createNode(std::vector<std::pair<NodeGraph&, double>>& edges) {
    //     nodes.push_back(NodeGraph(edges));
    //     return nodes[nodes.size() - 1];
    // }

    NodeGraph& Graph::createNode() {
        nodes.push_back(NodeGraph());
        return nodes.back();
    }

    size_t findInIndexFromMapTileTypeArray(std::array<TileType, 10 * 10>& mapTileTypeArray) {
        std::array<TileType, 10 * 10>::iterator inIt = std::find(mapTileTypeArray.begin(), mapTileTypeArray.end(), TileType::IN);
        return std::distance(mapTileTypeArray.begin(), inIt);
    }

    Graph getGraphFromMapTileTypeArray(std::array<TileType, 10 * 10>& mapTileTypeArray) {

        Graph graph;

        // Find In : TODO better
        size_t inIndex = findInIndexFromMapTileTypeArray(mapTileTypeArray);

        size_t visitIndex{ inIndex };
        while (mapTileTypeArray[visitIndex] != TileType::OUT)
        {

        }



        return Graph();
    }
}