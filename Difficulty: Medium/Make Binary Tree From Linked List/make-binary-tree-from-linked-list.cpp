//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        Node *prevhead = head;
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) {
            cout << "-1\n";
        } else if (root == NULL && prevhead != NULL) {
            cout << "-1\n";
        } else {
            lvl(root);
            cout << endl;
        }
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends


/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void treeLeft(TreeNode*& root, vector<int>& store, int index);
void treeRight(TreeNode*& root, vector<int>& store, int index);

void treeLeft(TreeNode*&root, vector<int>&store, int index){
    //left
   int leftIndex = 2*index +1;
   if(leftIndex < store.size()){
        root = new TreeNode (store[leftIndex]);
        treeLeft(root->left, store, leftIndex);
        treeRight(root->right, store, leftIndex);
   }
    
}
void treeRight(TreeNode*&root, vector<int>&store, int index){
    //right
  int  rightIndex = 2*index +2;
   if(rightIndex < store.size()){
        root = new TreeNode (store[rightIndex]);
        treeLeft(root->left, store, rightIndex);
        treeRight(root->right, store, rightIndex);
   }
}

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // Your code here
    // first of all convert the linked list to a vector array
    vector<int> store;
    
    
    while(head != nullptr){
        store.push_back(head->data);
        head = head->next;
    }
    
    root = new TreeNode (store[0]);
    treeLeft(root->left, store,0);
    treeRight(root->right, store, 0);

}
