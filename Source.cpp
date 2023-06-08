#include <iostream>
#include "my_vector.h"

class List2D {
private:
    class Node {
    public:
        MyVector data;
        Node* prev;
        Node* next;

        Node(const MyVector& values) : data(values), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    List2D() : head(nullptr), tail(nullptr) {}

    ~List2D() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addList(const MyVector& values) {
        Node* newNode = new Node(values);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    MyVector& operator[](int index) {
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        return current->data;
    }
};

int main() {
    List2D list;

    MyVector v1, v2, v3;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    list.addList(v1);
    list.addList(v2);
    list.addList(v3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << list[i][j] << " ";
        }
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}