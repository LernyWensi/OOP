#include <iostream>

class Node {
    public:
        double data;
        Node* prev;
        Node* next;

        Node(double value) {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
};

class Stack {
    private:
        Node* topNode;

    public:
        Stack() { topNode = nullptr; }

        void push(double value) {
            Node* newNode = new Node(value);
            if (topNode != nullptr) {
                newNode->next = topNode;
                topNode->prev = newNode;
            }
            topNode = newNode;
        }

        void pop() {
            if (topNode != nullptr) {
                Node* temp = topNode;
                topNode = topNode->next;
                if (topNode != nullptr) {
                    topNode->prev = nullptr;
                }
                delete temp;
            } else {
                std::cout << "Stack underflow! Cannot pop element."
                          << "\n";
            }
        }

        double top() {
            if (topNode != nullptr) {
                return topNode->data;
            } else {
                std::cout << "Stack is empty."
                          << "\n";
                return 0.0;
            }
        }

        bool isEmpty() { return (topNode == nullptr); }

        void printStack() {
            if (isEmpty()) {
                std::cout << "Stack is empty."
                          << "\n";
            } else {
                std::cout << "Stack elements: ";
                Node* current = topNode;
                while (current != nullptr) {
                    std::cout << current->data << " ";
                    current = current->next;
                }
                std::cout << "\n";
            }
        }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);

    myStack.printStack();

    std::cout << "Top element: " << myStack.top() << "\n";

    myStack.pop();

    std::cout << "Top element after pop: " << myStack.top() << "\n";

    myStack.printStack();

    return 0;
}
