#include <stack>
#include <iostream>

using namespace std;

struct Node{
    Node(int d) : d(d), left(0), right(0) {}
    Node* left;
    Node* right;
    int     d;
};

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->d << " ";
    inorder(root->right);
}

void inorderloop(Node* root) {
    if(!root) return;
    std::stack<Node*> s;
    s.push(root);        
    bool hasRight=true;
    while(!s.empty()) {
        Node* nd = s.top();
        if(hasRight && nd->left) {
            s.push(nd->left);
            continue;
        }
        cout << nd->d << " ";
        s.pop();
        if(nd->right) {
            s.push(nd->right);
            hasRight = true;
        }
        else
            hasRight = false;
    }
}

void inorderloop2(Node* root) {
    stack<Node*> s;
    while(root || !s.empty()) {
        if(root) {
            s.push(root);
            root=root->left;
            continue;
        }

        root = s.top();
        s.pop();
        cout << root->d << " ";
        root=root->right;
    }
}

int main()
{
    Node* root = new Node(0);
    Node* left1 = root->left = new Node(1);
    Node* right1 = root->right = new Node(8);

    Node* left2 = left1->left = new Node(2);
    Node* right2 = left1->right = new Node(7);

    Node* left3 = left2->left = new Node(3);
    Node* right3 = left2->right = new Node(4);

    right3->left = new Node(5);
    right3->right = new Node(6);

    right1->left = new Node(9);
    right1->left->right = new Node(10);

    inorder(root);
    cout << endl;
    inorderloop(root);
    cout << endl;
    inorderloop2(root);
    cout << endl;

   return(0);
}
