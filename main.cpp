#include <iostream>
#include <cstring>
#include "person_keeper.h"

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cerr << "Not valid parameters count passed. Usage: inputFile outputFile";
        std::exit(-1);
    }

    PersonKeeper& keeper = PersonKeeper::getInstance();
    keeper.readPersons(argv[1]);

    return 0;
}
