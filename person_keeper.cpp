#include "person_keeper.h"

#include <sstream>
#include <vector>

PersonKeeper& PersonKeeper::getInstance()
{
    static PersonKeeper instance;
    return instance;
}

CustomStack<Person> PersonKeeper::readPersons(std::istream& stream)
{
    CustomStack<Person> personsStack;

    std::string lineWithData;
    while (std::getline(stream, lineWithData)) {
        // Добавляем считанную строчку из файла в поток чтения
        std::istringstream iss(lineWithData);
        std::string firstName, lastName, patronymic;
        if (iss >> firstName >> lastName >> patronymic)
        {
            Person p{firstName, lastName, patronymic};
            personsStack.push(p);
        }
        else {
            throw std::runtime_error("Wrong format in file.\n");
        }
    }
    return personsStack;
}

void PersonKeeper::writePersons(const CustomStack<Person> &persons, std::ostream &stream)
{
    if (!persons.getSize())
    {
        return;
    }
    for (int i = 0; i < persons.getSize(); i++)
    {
        const Person& p = persons.getByIndex(i);
        stream << p.getFirstName() << " " << p.getLastName() << " " << p.getPatronymic() << '\n';
    }
}

