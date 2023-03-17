#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value)
    {
        this->value = value;
    }
};
class BinarySearchTree
{
public:
    void insert(int num)
    {
        if (root == nullptr)
            root = new Node(num);
        else
            insert(&root, num);
    }

    void delete_K(int k)
    {
        Node* max_K = maxNode(root, k);
        deleteNode(root, max_K->value);
    }

    void print()
    {
        if (!root)
            return;

        cout << root->value << ' ';

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            if (current->left)
            {
                cout << current->left->value << ' ';
                q.push(current->left);
            }

            if (current->right)
            {
                cout << current->right->value << ' ';
                q.push(current->right);
            }
        }
    }
private:
    Node* root = nullptr;

    void insert(Node** parent, int num)
    {
        if (*parent == nullptr)
            *parent = new Node(num);
        else if (num < (*parent)->value)
            insert(&(*parent)->left, num);
        else
            insert(&(*parent)->right, num);
    }

    Node* minNode(Node* node)
    {
        Node* current = node;
        while (current && current->left)
        {
            current = current->left;
        }
        return current;
    }

    Node* maxNode(Node* node, int& count)
    {
        if (!node)
            return node;

        Node* current = nullptr;
        if (node->right)
        {
            current = maxNode(node->right, count);
            if (current)
                return current;
        }

        --count;

        if (count == 0)
            return node;

        if (node->left)
        {
            current = maxNode(node->left, count);
            if (current)
                return current;
        }

        return nullptr;
    }

    Node* deleteNode(Node* node, int num)
    {
        if (!node)
            return node;

        if (num == node->value)
        {
            if (node->left && node->right)
            {
                Node* min = minNode(node->right);
                node->value = min->value;
                node->right = deleteNode(node->right, min->value);
            }
            else if (!node->left && node->right)
            {
                Node* current = node->right;
                delete node;
                node = current;
            }
            else if (node->left && !node->right)
            {
                Node* current = node->left;
                delete node;
                node = current;
            }
            else
            {
                delete node;
                node = nullptr;
            }

            return node;
        }

        if (num < node->value)
            node->left = deleteNode(node->left, num);
        else
            node->right = deleteNode(node->right, num);

        return node;
    }
};
int main()
{
    BinarySearchTree tree;
    int n;
    int k;
    cin >> n >> k;

    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        tree.insert(num);
    }

    tree.delete_K(k);

    tree.print();


    return 0;
}
