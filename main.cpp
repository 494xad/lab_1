#include <iostream>

template<typename T>
class CustomStack
{
public:

    CustomStack() {
        itemsCount = 0;
        lastItemPtr = nullptr;
    }

    ~CustomStack() {

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
    CustomStack<int> myStack;
    myStack.push(1);
    myStack.push(2);

    std::cout << myStack.getSize() << "\n";
    std::cout << myStack.pop() << "\n";
    std::cout << myStack.getSize() << "\n";
}

