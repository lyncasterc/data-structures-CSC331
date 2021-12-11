#include <iostream>
#include "Graph.h"


int main()
{
    Graph<char> g(3), sg(3), g2(7);

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

    // bool result1 = g.isSymmetric();
    // bool result2 = sg.isSymmetric();
    // std::cout << result1 << std::endl;
    // std::cout << result2 << std::endl;


    // bfs
    g2.addVertex('A');
    g2.addVertex('B');
    g2.addVertex('C');
    g2.addVertex('D');
    g2.addVertex('E');
    g2.addVertex('F');
    g2.addVertex('G');

    g2.addEdge('A', 'B');
    g2.addEdge('A', 'C');
    g2.addEdge('A', 'G');

    g2.addEdge('B', 'D');

    g2.addEdge('D', 'E');
    g2.addEdge('D', 'A');

    g2.addEdge('E', 'B');

    g2.addEdge('F', 'C');
    g2.addEdge('F', 'D');

    g2.addEdge('G', 'E');
    g2.addEdge('G', 'F');

    g2.bfs();






}
