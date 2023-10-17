#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node<T>* next;

        Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Stack {
    private:
        Node<T>* top;

    public:
        Stack() : top(nullptr) {}

        void Add(T data) {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = top;
            top = newNode;
        }

        void Delete() {
            if (top == nullptr) {
                std::cout << "Stack is empty. Cannot delete element."
                          << "\n";
                return;
            }

            Node<T>* current = top;
            top = top->next;
            delete current;
        }

        T Top() {
            if (top == nullptr) {
                std::cout << "Stack is empty. No top element."
                          << "\n";
                return T();
            }

            return top->data;
        }

        void printStack() {
            if (top == nullptr) {
                std::cout << "Stack is empty. Cannot delete element."
                          << "\n";
                return;
            }

            Node<T>* current = top;

            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }

            std::cout << "\n";
        }
};

int main() {
    Stack<int> stack;

    stack.Add(1);
    stack.Add(2);
    stack.Add(3);
    stack.Add(4);
    stack.Add(5);
    stack.Add(6);

    std::cout << "Initial stack: ";
    stack.printStack();

    std::cout << "Top element: " << stack.Top() << "\n";

    std::cout << "Stack after deletion: ";
    stack.printStack();

    stack.Delete();
    std::cout << "Top element after deletion: " << stack.Top() << "\n";

    return 0;
}
