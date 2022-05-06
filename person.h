#ifndef PERSON_H
#define PERSON_H

#include <string>

/// Класс, описывающий человека
class Person
{
public:
    Person();
    Person(const Person& person);

    ///Получить фамилию
    const std::string& getLastName() const { return lastName_; }

    ///Получить имя
    const std::string& getFirstName() const { return firstName_; }

    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);

private:
    long key_;
    std::string lastName_;
    std::string firstName_;
};


#endif // PERSON_H
