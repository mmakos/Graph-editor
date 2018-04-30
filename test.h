#include "userInterface.h"

class Test
{
public:
    UserInterface uI;

    void bfsTest()
    {
        uI.loadGraph( "test.g" );
        //0 -> 0 1 2 3 4 5
        std::vector< std::string > test = uI.m_graph.BFS( 0 );
        if( test[ 0 ] == "w0" && test [ 1 ] == "w1" && test [ 2 ] == "w2" && test [ 3 ] == "w3" && test [ 4 ] == "w4" && test [ 5 ] == "w5" )
            std::cout << "Wierzcholek startowy: 0 - test pomyslny." << std::endl;
        else
            std::cout << "Wierzcholek startowy: 0 - test negatywny." << std::endl;
        test.clear();
        //1 -> 1 2 3 0 4 5
        test = uI.m_graph.BFS( 1 );
        if( test[ 0 ] == "w1" && test [ 1 ] == "w2" && test [ 2 ] == "w3" && test [ 3 ] == "w0" && test [ 4 ] == "w4" && test [ 5 ] == "w5" )
            std::cout << "Wierzcholek startowy: 1 - test pomyslny." << std::endl;
        else
            std::cout << "Wierzcholek startowy: 1 - test negatywny." << std::endl;
        test.clear();
        //2 -> 2 3 0 4 1 5
        test = uI.m_graph.BFS( 2 );
        if( test[ 0 ] == "w2" && test [ 1 ] == "w3" && test [ 2 ] == "w0" && test [ 3 ] == "w4" && test [ 4 ] == "w1" && test [ 5 ] == "w5" )
            std::cout << "Wierzcholek startowy: 2 - test pomyslny." << std::endl;
        else
            std::cout << "Wierzcholek startowy: 2 - test negatywny." << std::endl;
        test.clear();
        //3 -> 3 0 4 1 5 2
        test = uI.m_graph.BFS( 3 );
        if( test[ 0 ] == "w3" && test [ 1 ] == "w0" && test [ 2 ] == "w4" && test [ 3 ] == "w1" && test [ 4 ] == "w5" && test [ 5 ] == "w2" )
            std::cout << "Wierzcholek startowy: 3 - test pomyslny." << std::endl;
        else
            std::cout << "Wierzcholek startowy: 3 - test negatywny." << std::endl;
        test.clear();
        //4 -> 4 1 5 2 3 0
        test = uI.m_graph.BFS( 4 );
        if( test[ 0 ] == "w4" && test [ 1 ] == "w1" && test [ 2 ] == "w5" && test [ 3 ] == "w2" && test [ 4 ] == "w3" && test [ 5 ] == "w0" )
            std::cout << "Wierzcholek startowy: 4 - test pomyslny." << std::endl;
        else
            std::cout << "Wierzcholek startowy: 4 - test negatywny." << std::endl;
        test.clear();
        //5 -> 5
        test = uI.m_graph.BFS( 5 );
        if( test[ 0 ] == "w5" )
            std::cout << "Wierzcholek startowy: 5 - test pomyslny." << std::endl << std::endl;
        else
            std::cout << "Wierzcholek startowy: 5 - test negatywny." << std::endl << std::endl;
        test.clear();
    }
};
