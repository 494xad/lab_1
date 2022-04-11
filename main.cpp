#include <iostream>

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
            return T(0);
        }

        Item* temp = lastItemPtr;

        T retval = temp->data;
        lastItemPtr = temp->prevItem;
        delete(temp);
        itemsCount--;
        return retval;
    }

    // Получение количества элементов в стеке
    size_t getSize() {
        return itemsCount;
    }

private:

    // Переменная, хранящая количество элементов
    size_t		itemsCount;

    // Структрура, описывающая элементы в стеке, стек выполнен на основе связного списка
    struct Item {

        // Указатель на предыдущий элемент в стеке
        Item* prevItem;

        // Данные в элементе стека
        T data;

    };

    // Указатель на вершину стека (первый с конца)
    Item*		lastItemPtr;
};

int main()
{
    CustomStack<int> *myStack = new CustomStack<int>();
    myStack->push(1);
    myStack->push(2);

    delete myStack;
}
