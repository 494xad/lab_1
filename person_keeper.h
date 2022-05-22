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
    PersonKeeper(const PersonKeeper& person) = delete;

    // Метод получения экземпляра синглтона
    static PersonKeeper& getInstance();

    // Считать информацию о людях из файла
    // stream Поток для чтения
    CustomStack<Person> readPersons(std::istream& stream);

    // Записать в файл информацию людях
    // persons Стек содержащий информацию о людях
    // stream Поток для записи
    void writePersons(const CustomStack<Person>& persons, std::ostream& stream);

protected:
    // Добавляем конструктор в private часть
    PersonKeeper() {}

    ~PersonKeeper() {}

private:
    CustomStack<Person> persons_;
};


#endif // PERSON_KEEPER_H
