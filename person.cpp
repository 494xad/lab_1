#include "person.h"


Person::Person()
{
    firstName_ = "";
    lastName_ = "";
}

Person::Person(const Person &person)
{
    firstName_ = person.firstName_;
    lastName_ = person.lastName_;
}

void Person::setLastName(const std::string &lastName)
{
    lastName_ = lastName;
}

void Person::setFirstName(const std::string &firstName)
{
    firstName_ = firstName;
}
