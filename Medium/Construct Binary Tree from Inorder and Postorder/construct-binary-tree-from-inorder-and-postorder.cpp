//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *solve(int in[], int post[], int is, int ie, int ps, int pe, map<int,int> &mp)
    {
        if(ie < is || pe < ps)
            return NULL;
        int inroot = mp[post[pe]];
        int count  = inroot - is;
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = post[pe];
        new_node->left =  solve(in,post,is,inroot-1,ps,ps+count-1,mp);
        new_node->right = solve(in,post,inroot+1,ie,ps+count,pe-1,mp);
        return new_node;
    }
    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) 
    {
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[in[i]] = i;
        }
        return solve(in,post,0,n-1,0,n-1,mp);
        // Your code here
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends