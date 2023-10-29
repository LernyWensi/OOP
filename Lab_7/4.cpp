#include <iostream>

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class Queue {
    private:
        Node* head;
        Node* tail;

    public:
        Queue() : head(nullptr), tail(nullptr) {}

        void enqueue(int value) {
            Node* newNode = new Node(value);

            if (tail == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void dequeue() {
            if (head == nullptr) {
                std::cout << "Queue is empty"
                          << "\n";
            } else {
                Node* temp = head;
                head = head->next;

                if (head != nullptr) {
                    head->prev = nullptr;
                } else {
                    tail = nullptr;
                }

                delete temp;
            }
        }

        int getFront() {
            if (isEmpty()) {
                return -1;
            }

            return head->data;
        }

        void printQueue() {
            if (isEmpty()) {
                std::cout << "Queue is empty"
                          << "\n";
            }

            std::cout << "Queue: ";

            Node* current = head;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }

            std::cout << "\n";
        }

        bool isEmpty() { return head == nullptr; }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(5);
    queue.enqueue(7);
    queue.enqueue(9);
    queue.enqueue(14);

    queue.printQueue();

    std::cout << "Front element: " << queue.getFront() << "\n";

    queue.dequeue();

    std::cout << "Front element after dequeue: " << queue.getFront() << "\n";

    queue.printQueue();

    queue.dequeue();
    queue.dequeue();

    std::cout << "After two more dequeues"
              << "\n";

    queue.printQueue();

    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
