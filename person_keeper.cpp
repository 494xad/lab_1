#include "person_keeper.h"

#include <sstream>
#include <vector>

PersonKeeper &PersonKeeper::getInstance()
{
    static PersonKeeper instance;
    return instance;
}

CustomStack<Person> PersonKeeper::readPersons(std::istream& stream)
{
    CustomStack<Person> personsStack;

    std::string lineWithData;
    while (std::getline(stream, lineWithData)) {
        // Добавляем считанную строчку из файла в поток для парсинга
        std::stringstream inputStream(lineWithData);
        // Части полного имени
        std::vector<std::string> partsOfName;
        // Формат Имя Фамилия Отчество, поэтому кол-во = 3
        constexpr int PartsCount = 3;
        int counter = 0;
        std::string temp;
        while( std::getline(inputStream, temp, ' '))
        {
            if (counter < PartsCount)
            {
                partsOfName.push_back( temp );
            }
            else
            {
                throw std::runtime_error("invalid format in file");
            }
            counter++;
        }
        if (partsOfName.size() == PartsCount)
        {
            Person p{ partsOfName[0], partsOfName[1], partsOfName[2] };
            personsStack.push(p);
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

