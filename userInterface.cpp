#include <fstream>
#include <string>
#include "userInterface.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

void UserInterface::addVertex()
{
    std::string name;
    std::cout << "Podaj nazwe: ";
    std::cin >> name;
    m_graph.newVertex( name );
    std::cout << "Dodano wierzcholek" << std::flush;
    Sleep( 1500 );
    system( "clear || cls" );
}

void UserInterface::addEdge()
{
    unsigned int i = 0, j = 0;
    std::cout << "Od ktorego wierzcholka chcesz poprowadzic krawedz: ";
    std::cin >> i;
    if( !std::cin.good() ){
        std::cin.clear();
        std::cin.ignore( 100, '\n' );
    }
    std::cout << "Do którego wierzcholka chcesz poprowadzic krawedz: ";
    std::cin >> j;
    if( !std::cin.good() ){
        std::cin.clear();
        std::cin.ignore( 100, '\n' );
    }
    if( i > m_graph.getSize() || j > m_graph.getSize() ){
        std::cout << "Nie ma takiego wierzcholka!";
        Sleep( 2000 );
        system( "clear || cls" );
        return;
    }
    m_graph.setEdge( i, j, 1 );
    system( "clear || cls" );
}

void UserInterface::delEdge()
{
    unsigned int i = 0, j = 0;
    std::cout << "Od ktorego wierzcholka chcesz usunac krawedz: ";
    std::cin >> i;
    if( !std::cin.good() ){
        std::cin.clear();
        std::cin.ignore( 100, '\n' );
    }
    std::cout << "Do którego wierzcholka chcesz usunac krawedz: ";
    std::cin >> j;
    if( !std::cin.good() ){
        std::cin.clear();
        std::cin.ignore( 100, '\n' );
    }
    if( i > m_graph.getSize() || j > m_graph.getSize() ){
        std::cout << "Nie ma takiego wierzcholka!";
        Sleep( 2000 );
        system( "clear || cls" );
        return;
    }
    m_graph.setEdge( i, j, 0 );
    system( "clear || cls" );
}

void UserInterface::searchGraph()
{
    unsigned int startVertex;
    std::cout << "Od ktorego wierzcholka chcesz przeszukac graf: ";
    std::cin >> startVertex;
    if( !std::cin.good() ){
        std::cin.clear();
        std::cin.ignore( 100, '\n' );
    }
    if( startVertex > m_graph.getSize() ){
        std::cout << "Nie ma takiego wierzcholka!" << std::flush;
        Sleep( 2000 );
        system( "clear || cls" );
        return;
    }
    m_graph.BFS( startVertex );
}

void UserInterface::writeMatrix()
{
    unsigned int n = m_graph.getSize();
    for( unsigned int i = 0; i < n; i++ ){
        for( unsigned int j = 0; j < n; j++ )
            std::cout << m_graph.getEdge( i, j ) << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void UserInterface::saveGraph()
{
    std::fstream save;
    save.open( "graph.g", std::ios::out | std::ios::binary );
    if( !save.good() ){
        std::cout << "Nie udalo sie zapisac!" << std::flush;
        Sleep( 1500 );
        system( "clear || cls" );
        return;
    }
    int n = m_graph.getSize();
    save << n << std::endl;
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            save << m_graph.getEdge( i, j ) << " ";
        }
        save << std::endl;
    }
    for( int i = 0; i < n; i++ ){
        save << m_graph.getValue( i ) << std::endl;
    }
    save.close();
}

void UserInterface::loadGraph()
{
    std::fstream load;
    load.open( "graph.g", std::ios::in | std::ios::binary );
    if( !load.good() ){
        std::cout << "Nie znaleziono zapisanego grafu!" << std::flush;
        Sleep( 1500 );
        system( "clear || cls" );
        return;
    }
    int n = 0;
    load >> n;
    m_graph.createMatrix( n );
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            bool temp = 0;
            load >> temp;
            if( temp )
                m_graph.setEdge( i, j, 1 );
        }
    }
    m_graph.createValues( n );
    std::string temp;
    std::getline( load, temp );
    for( int i = 0; i < n; i++ ){
        std::getline( load, temp );
        m_graph.setValue( temp, i );
    }
    load.close();
}

bool UserInterface::userMenu()
{
    int actionNumber = 0;
    std::cout << "Wybierz czynnosc: " << std::endl << std::endl;
    std::cout << "1. Dodaj wierzcholek" << std::endl;
    std::cout << "2. Dodaj krawedz" << std::endl;
    std::cout << "3. Usun krawedz" << std::endl;
    std::cout << "4. Przeszukaj graf" << std::endl;
    std::cout << "5. Zapisz graf" << std::endl;
    std::cout << "6. Wczytaj graf" << std::endl;
    std::cout << "7. Wypisz macierz sasiedztwa" << std::endl;
    std::cout << "8. Zamknij program" << std::endl;
    std::cin >> actionNumber;
    if( !std::cin.good() ){
        std::cin.clear();
        std::cin.ignore( 100, '\n' );
    }
    if( actionNumber < 1 || actionNumber > 8 ){
        std::cout << "Zly numer!" << std::flush;
        Sleep( 2000 );
        system( "clear || cls" );
        return true;
    }
    system( "clear || cls" );
    switch( actionNumber ){
    case 1:
        addVertex();
        break;
    case 2:
        addEdge();
        break;
    case 3:
        delEdge();
        break;
    case 4:
        searchGraph();
        break;
    case 5:
        saveGraph();
        break;
    case 6:
        loadGraph();
        break;
    case 7:
        writeMatrix();
        break;
    case 8:
        return false;
    }
    return true;
}
