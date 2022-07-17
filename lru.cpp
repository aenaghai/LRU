#include<bits/stdc++.h>
#include <map>
using namespace std;

class Node{
    public:
        int key,value;
        Node *prev;
        Node *next;
        Node(int k,int v): key(k), value(v), prev(NULL), next(NULL){}
    /*
        Node(){
        key=0;
        value=0;
        prev=next=NULL;
    }
    */
};

class DoublyLinkedList{
    Node *front;
    Node *rear;
    
    bool isEmpty(){
        return rear==NULL;
    }

    public:
    DoublyLinkedList(): front(NULL), rear(NULL) {}

    Node *AddToHead(int key,int value){
        Node *p=new Node(key,value);
        if(!front&&!rear) front=rear=p;
        else{
            p->next=front;
            front->prev=p;
            front=p;
        }
        return p;
    }

    void pToHead(Node *p){
        if(p==front) return;
        if(p==rear){
            rear=rear->prev;
            rear->next=NULL;
        }
        else{
            p->prev->next=p->next;
            p->next->prev=p->prev;
        }
        p->next=front;
        p->prev=NULL;
        front->prev=p;
        front=p;
    }

    void removeRear(){
        if(isEmpty()) return;
        if(front==rear){
            delete rear;
            front=rear=NULL;
        }
        else{
            Node *temp=rear;
            rear=rear->prev;
            rear->next=NULL;
            delete temp;
        }
    }

    Node *getRear(){
        return rear;
    }

};

class LRUCache{
    int capacity,size;
    DoublyLinkedList *list;
    map<int,Node*> listmap;

    public:
    LRUCache(int capacity){
        this->capacity=capacity;
        size=0;
        list=new DoublyLinkedList();
        listmap=map<int,Node*>();
    }

    int getkey(int key){
        if(listmap.find(key)==listmap.end()) return -1;
        int val=listmap[key]->value;

        //moving the p to front
        list->pToHead(listmap[key]);
        return val;
    }

    void put(int key,int value){
        if(listmap.find(key)!=listmap.end()){
            //if present then just update the value and move it to the front :)
            listmap[key]->value=value;
            list->pToHead(listmap[key]);
            return;
        }

        if(size==capacity){
            //remove the lru i.e. rear element
            int k=list->getRear()->key;
            listmap.erase(k);
            list->removeRear();
            size--;
        }

        //add new to the front to queue
        Node *p=list->AddToHead(key,value);
        size++;
        listmap[key]=p;
    }

    ~LRUCache(){
        map<int,Node*>::iterator i;
        for(i=listmap.begin();i!=listmap.end();i++){
            delete i->second;
        }
        delete list;
    }

};
