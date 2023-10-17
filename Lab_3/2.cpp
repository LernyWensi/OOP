#include <iostream>

class Node {
    public:
        std::string data;
        Node* prev;
        Node* next;

        Node(std::string value) {
            data = value;
            prev = nullptr;
            next = nullptr;
        }
};

class Queue {
    private:
        Node* frontNode;
        Node* rearNode;

    public:
        Queue() {
            frontNode = nullptr;
            rearNode = nullptr;
        }

        void enqueue(std::string value) {
            Node* newNode = new Node(value);
            if (rearNode != nullptr) {
                newNode->prev = rearNode;
                rearNode->next = newNode;
            } else {
                frontNode = newNode;
            }
            rearNode = newNode;
        }

        void dequeue() {
            if (frontNode != nullptr) {
                Node* temporary = frontNode;
                frontNode = frontNode->next;
                if (frontNode != nullptr) {
                    frontNode->prev = nullptr;
                } else {
                    rearNode = nullptr;
                }
                delete temporary;
            } else {
                std::cout << "Queue underflow! Cannot dequeue element."
                          << "\n";
            }
        }

        std::string front() {
            if (frontNode != nullptr) {
                return frontNode->data;
            } else {
                std::cout << "Queue is empty."
                          << "\n";
                return "";
            }
        }

        bool isEmpty() { return (frontNode == nullptr); }

        void printQueue() {
            if (isEmpty()) {
                std::cout << "Queue is empty."
                          << "\n";
            } else {
                std::cout << "Queue elements: ";
                Node* temporary = frontNode;
                while (temporary != nullptr) {
                    std::cout << temporary->data << " ";
                    temporary = temporary->next;
                }
                std::cout << "\n";
            }
        }
};

int main() {
    Queue myQueue;

    myQueue.enqueue("1");
    myQueue.enqueue("2");
    myQueue.enqueue("3");
    myQueue.enqueue("4");
    myQueue.enqueue("5");
    myQueue.enqueue("6");

    myQueue.printQueue();

    std::cout << "Front element: " << myQueue.front() << "\n";

    myQueue.dequeue();

    std::cout << "Front element after dequeue: " << myQueue.front() << "\n";

    myQueue.printQueue();

    return 0;
}
