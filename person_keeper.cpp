#include "person_keeper.h"

#include <fstream>
#include <sstream>
#include <vector>

PersonKeeper &PersonKeeper::getInstance()
{
    static PersonKeeper instance;
    return instance;
}

CustomStack<Person> PersonKeeper::readPersons(const std::string &path)
{
    std::fstream fileToRead(path);
    if (!fileToRead.is_open())
    {
        throw std::runtime_error("Failed to open file " + path);
    }

    CustomStack<Person> personsStack;

    std::string lineWithData;
    while (std::getline(fileToRead, lineWithData)) {
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
                throw std::runtime_error("invalid format in file + " + path);
            }
            counter++;
        }
        if (partsOfName.size() == PartsCount)
        {
            Person p{ partsOfName[0], partsOfName[1], partsOfName[2] };
            personsStack.push(p);
        }
    }
    fileToRead.close();

    return personsStack;
}

void PersonKeeper::writePersons(const CustomStack<Person> &persons)
{

}
