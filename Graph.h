#include <iostream>
#include <vector>
#include <queue>

template< typename T >
class Graph
{
private:
    std::vector< T > m_graphValues;
    std::vector< std::vector< bool > > m_adjacencyMatrix;

public:
    void newVertex( const T &object )       //SZABLON
    {
        std::vector< bool > temp( m_graphValues.size(), 0 );
        m_adjacencyMatrix.push_back( temp );                  //Dodajemi wektor do macierzy wypelniony zerami (na razie brak krawêdzi
        m_graphValues.push_back( object );                      //Dodajemy zawartoœæ wierzcho³ka do wektora z zawartoœciami
        for( unsigned int i = 0; i < m_graphValues.size(); i++ )
            m_adjacencyMatrix[ i ].push_back( 0 );            //Dodajemy do ka¿dego wektora 0 na koñcu
        //Mamy macierz powiêkszon¹ o 1 kolumnê i 1 wiersz zer

    }
    void setEdge( int vertex1, int vertex2, bool a )
    {
        m_adjacencyMatrix[ vertex1 ][ vertex2 ] = a;
    }
    bool getEdge( int unsigned i, int unsigned j )
    {
        return m_adjacencyMatrix[ i ][ j ];
    }
    void setValue( const T &object, int i )       //Szablon
    {
        m_graphValues[ i ] = object;
    }
    void createMatrix( int n )
    {
        m_adjacencyMatrix.clear();
        for( int i = 0; i < n; i++ ){
            std::vector< bool > temp( n, 0 );
            m_adjacencyMatrix.push_back( temp );
        }
    }

    void createValues( int n )
    {
        m_graphValues.clear();
        for( int i = 0; i < n; i++ ){
            m_graphValues.push_back( T() );        //SZABLON
        }
    }
    unsigned int getSize()
    {
        return m_graphValues.size();
    }
    void BFS( int startVertex )
    {
        unsigned int n = m_graphValues.size();
        int visitedVertices[ n ];
        for( unsigned int i = 0; i < n; i++ )       //Zerujemy tablicê
            visitedVertices[ i ] = false;
        std::queue< int > verticesQueue;            //kolejka wierzcho³kow do odwiedzenia

        verticesQueue.push( startVertex );
        visitedVertices[ startVertex ] = true;          //Odwiedzamy pierwszy wierzcho³ek i dajemy do kolejki
        while( !verticesQueue.empty() ){
            startVertex = verticesQueue.front();
            verticesQueue.pop();                        //usuwamy z kolejki wierzcho³ek odczytany
            std::cout << m_graphValues[ startVertex ] << std::endl;
            for( unsigned int i = 0; i < n; i++ ){
                if( m_adjacencyMatrix[ startVertex ][ i ] == 1 && visitedVertices[ i ] == false ){     // jeœli sprawdzany wierzcho³ek jest po³¹czony z i-tym wierzcholkiem i i-ty wierzcho³ek nie by³ odwiedzony
                    verticesQueue.push( i );            // Umieszczamy s¹siaduj¹cy wierzcho³ek w kolejce
                    visitedVertices[ i ] = true;
                }
            }
        }
    }
};

