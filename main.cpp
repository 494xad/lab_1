#include <iostream>
#include <cstring>
#include "person_keeper.h"

void PrintAllPersons(const CustomStack<Person>& persons)
{
    for (int i = 0; i < persons.getSize(); i++)
    {
        const Person& p = persons.getByIndex(i);
        std::cout << p.getFirstName() << " " << p.getLastName() << " " << p.getPatronymic() << "\n";
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

    std::fstream fileToRead(argv[1]);
    if (!fileToRead.is_open())
    {
        throw std::runtime_error("Failed to open file " + std::string(argv[1]));
    }

    PersonKeeper& keeper = PersonKeeper::getInstance();
    CustomStack<Person> result = keeper.readPersons(fileToRead);
    std::cout << "Receieved data from " << argv[1] << ":\n";
    PrintAllPersons(result);
    fileToRead.close();

    std::fstream fileToWrite(argv[2], std::ios::app);
    if (!fileToWrite.is_open())
    {
        throw std::runtime_error("Failed to open file " + std::string(argv[2]));
    }
    keeper.writePersons(result, fileToWrite);

    fileToWrite.close();

    return 0;
}
