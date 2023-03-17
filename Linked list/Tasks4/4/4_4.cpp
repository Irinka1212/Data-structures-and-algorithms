#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node
{
    int data = 0;
    Node* next = nullptr;
    Node* previous = nullptr;
};

class DoubleLinkedListNode
{
public:
    void Add(int x)
    {
        ++size;

        Node* newNode = new Node;
        newNode->data = x;
        if (!head)
        {
            head = newNode;
            middle = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            if (size > 2 && size % 2 == 0)
                middle = middle->next;
        }
        tail = newNode;
    }

    void RemoveLast()
    {
        --size;

        Node* previous = tail->previous;
        if (previous == nullptr)
            head = nullptr;
        else
        {
            previous->next = nullptr;
            if (size > 2 && size % 2 != 0)
                middle = middle->previous;
        }

        delete tail;
        tail = previous;
    }

    void Milen()
    {
        if (head == tail)
            return;

        Node* middleNode = middle;

        Node* newHead = middleNode->next;
        newHead->previous = nullptr;
        middleNode->next = nullptr;

        tail->next = head;
        head->previous = tail;
        if (size % 2 == 0)
            middle = tail;
        else
            middle = tail->previous;
        head = newHead;
        tail = middleNode;
    }

    void Print() const
    {
        cout << size << '\n';

        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* middle = nullptr;
    int size = 0;
};

int main()
{
    int n;
    cin >> n;

    DoubleLinkedListNode list;

    cin.ignore();

    string query;
    int number = 0;
    for (int i = 0; i < n; ++i)
    {
        query.erase();
        cin >> query;

        if (query == "gun")
            list.RemoveLast();
        else if (query == "milen")
            list.Milen();
        else
        {
            cin >> number;
            list.Add(number);
        }
    }

    list.Print();

    return 0;
}

