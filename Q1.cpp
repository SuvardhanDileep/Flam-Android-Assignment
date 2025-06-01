#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node*next;
        Node*prev;
        Node(int x,int y){
            key=x;
            val=y;
            next=NULL;
            prev=NULL;
        }
    };

    unordered_map<int,Node*>mp;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int cap;

    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node *node=mp[key];
        deleteNode(node);
        insertNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(mp.size()==cap){
                Node *prevNode=tail->prev;
                deleteNode(prevNode);
                mp.erase(prevNode->key);
            }
            Node* newNode=new Node(key,value);
            mp[key]=newNode;
            insertNode(newNode);
        }
        else{
            Node *node=mp[key];
            node->val=value;
            deleteNode(node);
            insertNode(node);
        }
    }

    void insertNode(Node *node){
        Node* headnext=head->next;
        head->next=node;
        node->prev=head;
        node->next=headnext;
        headnext->prev=node;
    }

    void deleteNode(Node *node){
        Node *nodeprev=node->prev;
        Node *nodenext=node->next;
        nodeprev->next=nodenext;
        nodenext->prev=nodeprev;
    }
};

int main()
{
    LRUCache lru(2);  
    lru.put(1, 1);
    lru.put(2, 2);
    cout<<lru.get(1)<<" ";       
    lru.put(3, 3);    
    cout<<lru.get(2)<<" ";       
    lru.put(4, 4);    
    cout<<lru.get(1)<<" ";       
    cout<<lru.get(3)<<" ";       
    cout<< lru.get(4)<<" ";
    return 0;
}