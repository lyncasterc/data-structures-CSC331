#ifndef Graph_H
#define Graph_H
#include <iostream>

template<typename T>
class Graph
{
    private:
        int num_of_vertices;
        int max_vertices;
        T *vertices;
        int **edges;
        bool *visited;

    public:
        Graph (int m);
        ~Graph();
        void addVertex (T vertex);
        void addEdge (T from_vertex, T to_vertex);
        void deleteVertex (T);
        void deleteEdge (T, T);
        int getIndex (T vertex);
        // void setVisited();
        // void setVertexVisited (T);
        // bool isVertexVisited (T);
        void printOutgoingEdges();
        void printIngoingEdges();
        // void printVertices();
        bool isSymmetric();
};

template<typename T>
Graph<T>::Graph(int m)
{
    num_of_vertices = 0;
    max_vertices = m;
    vertices = new T[m];
    visited = new bool[m];
    edges = new int*[m];

    // initialzing the matrix of m*m with all 0's
    for (size_t i = 0; i < m; i++)
    {
        edges[i] = new int[m];

        for (size_t j = 0; j < m; j++)
        {
            edges[i][j] = 0; 
        } 
    }
    
};

//adds a label/value/weight to the actual vertex
template<typename T>
void Graph<T>::addVertex(T vertex)
{
    if ( num_of_vertices < max_vertices) 
    {
        vertices[num_of_vertices++] = vertex;
    }
    
    else
    {
        std::cout << "\nERROR: GRAPH IS FULL";
    }
}

template<typename T>
void Graph<T>::addEdge(T from_vertex, T to_vertex)
{
    int row, col;
    row = getIndex(from_vertex);
    col = getIndex(to_vertex);
    edges[row][col] = 1;
}

template<typename T>
int Graph<T>::getIndex(T vertex)
{
    int index = 0;

    while(index < num_of_vertices)
    {
        if(vertices[index] == vertex)
        {
            return index;
        }

        else
        {
            index++;
        }
    }

    return -1;
}


template<typename T>
Graph<T>::~Graph()
{
    delete [] vertices;
    delete [] visited;

    for ( int i = 0; i < max_vertices; i++ )
    {
        delete [] edges[i] ;
    }

    delete [] edges;   
}

template <class T>
void Graph<T> :: printOutgoingEdges()
{
    std::cout<<"\nOut-going Edges: \n";

    for ( int i = 0; i < num_of_vertices; i++ )
    {
        for ( int j = 0; j < num_of_vertices; j++ )
        {
            if ( edges[i][j] == 1 )
            {
                std::cout << vertices[i] << " -> " << vertices[j] << "   ";
            }
        }     

        std::cout<<"\n";
    }   
}

template <class T>
void Graph<T> :: printIngoingEdges()
{
    std::cout<<"\nIn-going Edges: \n";

    for ( int i = 0; i < num_of_vertices; i++ )
    {
        for ( int j = 0; j < num_of_vertices; j++ )
        {
            if ( edges[j][i] == 1 )
            {
                std::cout << vertices[i] << " <- " << vertices[j] << "   ";
            }
        }     

        std::cout<<"\n";
    }   
}

template<typename T>
bool Graph<T>::isSymmetric()
{
    for (size_t i = 0; i < num_of_vertices; i++)
    {
        for (size_t j = 0; j < num_of_vertices; j++)
        {
            if(edges[i][j] == 1)
            {
                if(edges[j][i] != 1)
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}



#endif