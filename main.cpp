#include <iostream>
#include <cstring>
#include "person_keeper.h"

void PrintAllPersons(const CustomStack<Person>& persons)
{
    for (int i = 0; i < persons.getSize(); i++)
    {
        const Person& p = persons.getByIndex(i);
        std::cout << p.getFirstName() << " " << p.getLastName() << " " << p.getPatronymic() << ":\n";
    }
}

int main(int argc, char** argv)
{

    setlocale(LC_ALL, "Russian");

    if (argc < 3)
    {
        std::cerr << "Not valid parameters count passed. Usage: inputFile outputFile";
        std::exit(-1);
    }

    PersonKeeper& keeper = PersonKeeper::getInstance();
    CustomStack<Person> result = keeper.readPersons(argv[1]);
    std::cout << "Receieved data from " << argv[1] << std::endl;
    PrintAllPersons(result);

    return 0;
}
