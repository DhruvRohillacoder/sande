#include <iostream>
#include <algorithm> // For std::copy

class IntContainer {
private:
    int* array;
    size_t capacity;
    size_t size;

    void resize() {
        capacity = capacity * 2;
        int* new_array = new int[capacity];
        std::copy(array, array + size, new_array);
        delete[] array;
        array = new_array;
    }

public:
    IntContainer() : array(nullptr), capacity(0), size(0) {}

    ~IntContainer() {
        delete[] array;
    }

    void add(int value) {
        if (size >= capacity) {
            resize();
        }
        array[size++] = value;
    }

    int get(size_t index) const {
        if (index < size) {
            return array[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    IntContainer container;

    container.add(10);
    container.add(20);
    container.add(30);

    for (size_t i = 0; i < container.getSize(); ++i) {
        std::cout << container.get(i) << std::endl;
    }

    return 0;
}