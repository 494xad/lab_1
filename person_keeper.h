#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H

#include "person.h"
#include "stack.h"

#include <fstream>


/// Класс синглетон, позволяющий считывать
/// и записывать информацию о людях
class PersonKeeper
{
public:
    PersonKeeper() = delete;
    PersonKeeper(const PersonKeeper& person) = delete;

    PersonKeeper& getInstance();

    // Считать информацию о людях из файла
    // path Путь к файлу
    const CustomStack<Person>& readPersons(const std::string& path);

    // Записать в файл информацию людях
    // persons Стек содержащий информацию о людях
    void writePersons(const CustomStack<Person>& persons);

protected:
    ~PersonKeeper() {}

private:
    CustomStack<Person> persons_;
};


#endif // PERSON_KEEPER_H
