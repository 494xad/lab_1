#include "person.h"


Person::Person()
{
    firstName_ = "";
    lastName_ = "";
}

Person::Person(const std::string &firstName, const std::string &lastName, const std::string &patronymic)
{
    firstName_ = firstName;
    lastName_ = lastName;
    patronymic_ = patronymic;
}

Person::Person(const Person &person)
{
    firstName_ = person.firstName_;
    lastName_ = person.lastName_;
    patronymic_ = person.patronymic_;
}

void Person::setLastName(const std::string &lastName)
{
    lastName_ = lastName;
}

void Person::setFirstName(const std::string &firstName)
{
    firstName_ = firstName;
}
