#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& item) : data(item), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    List() : head(nullptr), size(0) {}

    ~List() {
        clear();
    }

    void add(const T& item) {
        Node* newNode = new Node(item);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        size++;
    }

    void remove(const T& item) {
        if (head == nullptr) {
            return;
        }

        if (head->data == item) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == item) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                size--;
                return;
            }
            current = current->next;
        }
    }

    T get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }
};

int main() {
    List<int> myList;
    myList.add(123);
    myList.add(14);
    myList.add(54);
    myList.print();

    myList.remove(14);
    myList.print();

    std::cout << myList.get(1) << std::endl; 

    myList.clear();
    myList.print(); 

    return 0;
}