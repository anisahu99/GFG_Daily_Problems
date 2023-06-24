//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class TrieNode{
    public:
    char data;
    TrieNode* children [26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};



class Solution{   
public:
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string words){

        if(words.length()==0){
            root->isTerminal=true;
            return;
        }

        TrieNode* child;

        int index=words[0]-'a';
        //present
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            child=new TrieNode(words[0]);
            root->children[index]=child;
        }

        insertUtil(child,words.substr(1));
    }
    void insertWord(string words){
        insertUtil(root,words);
    }

    bool searchUtil(TrieNode* root,string words){
        if(words.length()==0){
            return root->isTerminal;
        }

        TrieNode* child;

        int index=words[0]-'a';
        //present
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,words.substr(1));
    }

    bool searchWord(string words){
        return searchUtil(root,words);
    }
};
    int klengthpref(string arr[], int n, int k, string str){
        if(str.length()<k) return 0;
        Trie* t=new Trie();
        t->insertWord(str.substr(0,k));
        int cnt=0;
        
        for(int i=0;i<n;i++){
            string s=arr[i];
            if(s.length()<k){
                continue;
            }
            if(t->searchWord(s.substr(0,k))){
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends