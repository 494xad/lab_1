#ifndef PERSON_H
#define PERSON_H

#include <string>

/// Класс, описывающий человека
class Person
{
public:
    Person();
    Person(const std::string& firstName, const std::string& lastName, const std::string& patronymic);
    Person(const Person& person);

    ///Получить фамилию
    const std::string& getLastName() const { return lastName_; }

    ///Получить имя
    const std::string& getFirstName() const { return firstName_; }

    // Получить фамилию
    const std::string& getPatronymic() const { return patronymic_; }

    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setPatronymic(const std::string& patronymic);

private:
    std::string lastName_;
    std::string firstName_;
    std::string patronymic_;
};


#endif // PERSON_H
