//
//  main.cpp
//  cpp_concurrency_in_practice
//
//  Created by 武文骁 on 15/11/10.
//  Copyright © 2015年 武文骁. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class LRUCache
{
public:
    struct Node
    {
        int key;
        int value;
        Node* next;
        Node* pre;
        Node(int k,int v):key(k),value(v),next(NULL),pre(NULL){}
    };
    
    int maxsize;
    int cursize;
    typedef Node* Keynode;
    map<int,Keynode> cachemap;
    
    Keynode head;
    Keynode tail;
    
    LRUCache(int capacity)
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->pre = head;
        maxsize = capacity;
        cursize = 0;
    }
    
    void insertHead(Keynode node)
    {
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
    
    void deleteNode(Keynode node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    int get(int key)
    {
        map<int,Keynode>::iterator iter;
        iter = cachemap.find(key);
        if(iter == cachemap.end())
        {
            return -1;
        }
        else
        {
            Keynode temp = iter->second;
            deleteNode(temp);
            insertHead(temp);
            return temp->value;
        }
        return -1;
    }
    
    void set(int key,int value)
    {
        map<int,Keynode>::iterator iter;
        iter = cachemap.find(key);
        if(iter == cachemap.end())
        {
            if(cursize >= maxsize)
            {
                Keynode freenode = tail->pre;
                cachemap.erase(freenode->key);
                deleteNode(freenode);
                free(freenode);
                Keynode temp = (Keynode)malloc(sizeof(struct Node));
                *temp = Node(key,value);
                insertHead(temp);
                cachemap[key] = temp;
            }
            else
            {
                Keynode temp = (Keynode)malloc(sizeof(struct Node));
                *temp = Node(key,value);
                insertHead(temp);
                cursize++;
                cachemap[key] = temp;
            }
        }
        else
        {
            Keynode temp = iter->second;
            temp->value = value;
            deleteNode(temp);
            insertHead(temp);
        }
    }
};

int main(int argc,const char* argv[])
{
    LRUCache L(2);
    L.set(2,1);
    L.set(2,2);
    int v  = L.get(2);
    L.set(1,1);
    L.set(4,1);
    
    printf("%d\n",v);
    printf("%d\n",L.get(2));
    return 0;
    
}