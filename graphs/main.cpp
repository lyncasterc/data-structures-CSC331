#include <iostream>
#include "Graph.h"


int main()
{
    Graph<char> g(3), sg(3);
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');

    g.addEdge('A', 'B');
    g.addEdge('B', 'C');
    g.addEdge('C', 'A');


    // Symmetric graph
    sg.addVertex('A');
    sg.addVertex('B');
    sg.addVertex('C');

    sg.addEdge('A', 'B');
    sg.addEdge('B', 'A');

    sg.addEdge('B', 'C');
    sg.addEdge('C', 'B');

    sg.addEdge('C', 'A');
    sg.addEdge('A', 'C');

    // g.printOutgoingEdges();
    // g.printIngoingEdges();

    bool result1 = g.isSymmetric();
    bool result2 = sg.isSymmetric();

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;


}