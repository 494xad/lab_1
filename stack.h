#ifndef STACK_H
#define STACK_H

#include <cstring>

// Класс исключения
class EStackException
{
public:

    // Конструктор
    EStackException(const char* messageText) {
        exceptionText = new char[strlen(messageText) + 1];
        strcpy(exceptionText, messageText);
    }

    // Деструктор
    ~EStackException() {
        delete exceptionText;
    }

    // Выдать сообщение об ошибке
    const char* what() {
        return exceptionText;
    }

protected:

    // Указатель на строку
    char* exceptionText;

};

// Класс исключения, генерируемого при извлечении элемента из пустого стека
class EStackEmpty: public EStackException
{
public:

    // Конструктор
    EStackEmpty(const char* messageText) : EStackException(messageText)
    {

    }

};


// Класс стека на основе связного списка
template<typename T>
class CustomStack
{
public:

    // Конструктор
    CustomStack() {
        itemsCount = 0;
        lastItemPtr = nullptr;
    }

    // Деструктор
    ~CustomStack() {
        Item* temp;
        for (size_t i = 0; i < itemsCount; i++) {
            temp = lastItemPtr;
            lastItemPtr = temp->prevItem;
            delete(temp);
        }
    }

    // Добавление нового элемента
    void push(const T item) {
        // последний элемент в стеке становится предпоследним
        lastItemPtr = new Item{ lastItemPtr, item };

        itemsCount++;
    }

    // Извлечение элемента
    T pop() {

        if (itemsCount == 0) {
            throw EStackEmpty("Stack is Empty!");
        }

        Item* temp = lastItemPtr;

        T retval = temp->data;
        lastItemPtr = temp->prevItem;
        delete temp;
        itemsCount--;
        return retval;
    }

    // Получение количества элементов в стеке
    size_t getSize() {
        return itemsCount;
    }

private:

    // Количетсво элементов в стеке
    size_t itemsCount;

    // Структрура, описывающая элементы в стеке, стек выполнен на основе связного списка
    struct Item {

        // Указатель на предыдущий элемент в стеке
        Item* prevItem;

        // Данные в элементе стека
        T data;
    };

    // Указатель на вершину стека (первый с конца)
    Item* lastItemPtr;
};


#endif // STACK_H
