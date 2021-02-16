/*
** EPITECH PROJECT, 2020
** SafeQueue
** File description:
** SafeQueue
*/

#ifndef __SAFEQUEUE__
#define __SAFEQUEUE__

#include <mutex>
#include <queue>
#include <iostream>

class SafeQueue {
    private:
        std::queue<std::string> q;
        std::mutex m;
    public:
        SafeQueue();
        ~SafeQueue();
        void push(std::string str);
        std::string pop();
};

#endif /**/