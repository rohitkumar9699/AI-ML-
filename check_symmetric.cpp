#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

bool isMirror(Node* n1, Node* n2)
{
    if (!n1 && !n2)
        return true;
    if (!n1 || !n2)
        return false;
    if (n1->val != n2->val) 
        return false;
    return isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);  
}

bool check(Node* root)
{
    if (!root)
        return true;  
    return isMirror(root->left, root->right);
}

int main()
{
    int n;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    Node* root = nullptr;
    if (n % 2 == 0)
    {
        cout << "\nMirror Image False";
    }
    else
    {
        cout << "Enter value for root: ";
        int value;
        cin >> value;
        root = new Node();
        root->val = value;

        for (int i = 1; i < n; i++)  
        {
            cout << "Enter value: ";
            cin >> value;
            Node* newNode = new Node();
            newNode->val = value;

            if (i % 2 == 1)
                root->left = newNode;  
            else 
                root->right = newNode;  
        }
    }
    if (check(root))
        cout << "Mirror Image true";
    else    
        cout << "Mirror Image False";

    return 0;  
}
