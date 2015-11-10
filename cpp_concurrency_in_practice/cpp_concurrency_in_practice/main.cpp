//
//  main.cpp
//  cpp_concurrency_in_practice
//
//  Created by 武文骁 on 15/11/10.
//  Copyright © 2015年 武文骁. All rights reserved.
//

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

struct Node{int value;Node* next;};
std::atomic<Node*> list_head(nullptr);

void append(int val)
{
    Node* newNode = new Node{val,list_head};
    
    while(!list_head.compare_exchange_weak(newNode->next,newNode)){}
}

int main()
{
    std::vector<std::thread> threads;
    for(int i = 0;i<10;++i)
    {
        threads.push_back(std::thread(append,i));
    }
    for(auto& th:threads)
    {
        th.join();
    }
    for(Node* it = list_head;it != nullptr; it = it->next)
    {
        std::cout << ' ' <<it->value;
    }
    std::cout << '\n';
    
    Node* it;
    while(it = list_head)
    {
        list_head = it->next;
        delete it;
    }
}