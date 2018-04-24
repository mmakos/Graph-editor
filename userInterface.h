#include "Graph.h"

class UserInterface
{
public:
    Graph< std::string >m_graph;

    void addVertex();
    void addEdge();
    void delEdge();
    void searchGraph();
    void writeMatrix();
    void saveGraph();
    void loadGraph();
    bool userMenu();
};
