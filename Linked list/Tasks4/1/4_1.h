#pragma once
#pragma warning(disable:4996)

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (position < 1)
    {
        newNode->next = llist;
        return newNode;
    }

    SinglyLinkedListNode* previous = llist;
    SinglyLinkedListNode* current = llist->next;
    for (int i = 1; i < position; ++i)
    {
        if (current == nullptr)
        {
            throw out_of_range("Invalid position");
        }
        previous = previous->next;
        current = current->next;
    }

    previous->next = newNode;
    newNode->next = current;

    return llist;
}