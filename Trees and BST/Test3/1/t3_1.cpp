#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }


    void leaves(Node* root) {
        long long sum = 0;
        sum = sumOdd(root, sum);
        cout << sum;
    }

    long long sumOdd(Node* node, long long sum)
    {
        if (!node)
            return sum;

        if (node->leftNode)
            sum = sumOdd(node->leftNode, sum);

        if (!node->leftNode && !node->rightNode && node->data % 2 == 1)
            sum += node->data;

        if (node->rightNode)
            sum = sumOdd(node->rightNode, sum);

        return sum;
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}