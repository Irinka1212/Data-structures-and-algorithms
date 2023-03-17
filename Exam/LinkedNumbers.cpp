#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node* next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    Node* getHead()
    {
        return head;
    }

private:
    Node* head, * tail;
};

void solve(LinkedList& num1, LinkedList& num2) {

    stack<int> digits;
    int sum = 0;
    Node* curr1 = num1.getHead();
    Node* curr2 = num2.getHead();
    while (curr1 != nullptr && curr2 != nullptr)
    {
        sum += curr1->data + curr2->data;
        digits.push(sum % 10);
        sum /= 10;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while (curr1 != nullptr)
    {
        sum += curr1->data;
        digits.push(sum % 10);
        sum /= 10;
        curr1 = curr1->next;
    }

    while (curr2 != nullptr)
    {
        sum += curr2->data;
        digits.push(sum % 10);
        sum /= 10;
        curr2 = curr2->next;
    }
    if (sum > 0)
    {
        digits.push(sum);
    }
    while (!digits.empty())
    {
        cout << digits.top();
        digits.pop();
    }
}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}