//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    int sum(int n, struct Node* n1, struct Node* n2, struct Node* ans){
        if(n1->next==NULL){
            ans->next=NULL;
            return n1->data + n2->data;
        }
        struct Node* t=new Node(0);
        ans->next=t;
        int temp=sum(n-1, (n1->next), (n2->next), (ans->next));
        ans->next->data=temp%10;
        return n1->data + n2->data + (temp/10);
    }
    
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        int n=0, m=0;
        struct Node* t=num1;
        
        while(t!=NULL){
            n++;
            t=t->next;
        }
        t=num2;
        while(t!=NULL){
            m++;
            t=t->next;
        }
        
        int c;
        if(n>m){
            c=n-m;
            while(c--){
                t=new Node(0);
                t->next=num2;
                num2=t;
                t=NULL;
            }
            m=n;
        }
        else if(n<m){
            c=m-n;
            while(c--){
                t=new Node(0);
                t->next=num1;
                num1=t;
                t=NULL;
            }
            n=m;
        }
        
        struct Node* ans=new Node(0);
        c=sum(n, num1, num2, ans);
        ans->data=c%10;
        t= new Node(c/10);
        t->next=ans;
        ans=t;
        
        while(ans->next!=NULL && ans->data==0){
            ans=ans->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends