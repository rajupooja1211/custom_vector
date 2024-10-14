#include <iostream>
#include <cassert>
template <typename T>
class Vector {
private:
    T* elements;
    size_t max_capacity;
    size_t current_size;

   // Resize the array when more capacity is needed(expand)
    void expandCapacity() {
        max_capacity = max_capacity > 0 ? max_capacity * 2 : 1;
        T* newElements = new T[max_capacity];
        for (size_t i = 0; i < current_size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

public:
    // Default constructor(Constructor initializes an empty vector)
    Vector() : elements(nullptr), max_capacity(0), current_size(0) {}

    // Parameterized constructor(Constructor with initial capacity)
    Vector(size_t initialCapacity) : max_capacity(initialCapacity), current_size(0), elements(new T[initialCapacity]) {}

    // Copy constructor
    Vector(const Vector& source) : elements(new T[source.max_capacity]), max_capacity(source.max_capacity), current_size(source.current_size) {
        for (size_t i = 0; i < current_size; ++i) {
            elements[i] = source.elements[i];
        }
    }

    // Destructor(to free allocated memory)
    ~Vector() {
        delete[] elements;
    }

    // Append an element to the end of the vector(add)
    void append(const T& value) {
        if (current_size == max_capacity) {
            expandCapacity();
        }
        elements[current_size++] = value;
    }

    // Remove the last element of the vector
    void removeLast() {
        if (current_size > 0) {
            current_size--;
        }
    }

    // Get the number of elements in the vector(current_size)
    size_t getSize() const {
        return current_size;
    }

    //Operator[] to access elements in the array-style
    T& operator[](size_t index) {
        assert(index < current_size && "Index out of bounds");
        return elements[index];
    }

    const T& operator[](size_t index) const {
        assert(index < current_size && "Index out of bounds");
        return elements[index];
    }

    // Access an element with bounds checking
    T& at(size_t index) {
        if (index >= current_size) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }
};

// Main function to demonstrate vector usage(example)
int main() {
    Vector<int> vector;
    vector.append(84);
    vector.append(27);
    vector.append(30);

    std::cout << "Vector elements added: ";
    for (size_t i = 0; i < vector.getSize(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    vector.removeLast(); // Remove the last element

    std::cout << "Vector elements after removal: ";
    for (size_t i = 0; i < vector.getSize(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
