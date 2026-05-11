// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

 public:
    TPQueue() {
        head = nullptr;
    }
    ~TPQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push(T value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        if (value.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next != nullptr &&
               curr->next->data.prior >= value.prior) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    T pop() {
        Node* temp = head;
        T value = head->data;
        head = head->next;
        delete temp;
        return value;
    }
    bool empty() {
        return head == nullptr;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
