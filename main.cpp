#include "test.h"

int main()
{
    Test test;
    test.bfsTest();
    UserInterface uI;

    while( uI.userMenu() );
    return 0;
}
