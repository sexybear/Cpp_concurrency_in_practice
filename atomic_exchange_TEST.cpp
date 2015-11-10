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

std::atomic<bool> ready(false);
std::atomic<bool> winner(false);

void count1m(int id)
{
    while(!ready){}
    
    for(int i = 0;i<100000;++i){}
    if(!winner.exchange(true))
    {
        std::cout << "thread#"<< id << "won!\n";
    }
}

int main()
{
    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 million\n";
    
    for(int i = 1;i<=10;++i)
    {
        threads.push_back(std::thread(count1m,i));
        
    }
    ready = true;
    for(auto &th : threads)
    {
        th.join();
    }

    return 0;
}