#include <iostream>
#include <memory>

template<typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> left;
    std::unique_ptr<Node<T>> right;

    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    std::unique_ptr<Node<T>> root;

public:
    void insert(const T& value) {
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);

        if (!root) {
            root = std::move(newNode);
            return;
        }

        Node<T>* current = root.get();
        while (current) {
            if (value < current->data) {
                if (current->left) {
                    current = current->left.get();
                } else {
                    current->left = std::move(newNode);
                    return;
                }
            } else {
                if (current->right) {
                    current = current->right.get();
                } else {
                    current->right = std::move(newNode);
                    return;
                }
            }
        }
    }

    void treeMoving(Node<T>* node) {
        if (node) {
            treeMoving(node->left.get());
            std::cout << node->data << " ";
            treeMoving(node->right.get());
        }
    }

    void printInOrder() {
        treeMoving(root.get());
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree<int> tree;
    tree.insert(50);
    tree.insert(32);
    tree.insert(82);
    tree.insert(16);
    tree.insert(47);

    tree.printInOrder(); 

    return 0;
}