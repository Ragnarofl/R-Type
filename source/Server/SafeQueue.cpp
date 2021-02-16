/*
** EPITECH PROJECT, 2020
** SafeQueue
** File description:
** SafeQueue
*/

#include "SafeQueue.hpp"

SafeQueue::SafeQueue() {}

SafeQueue::~SafeQueue() {}

void SafeQueue::push(std::string str)
{
    std::lock_guard<std::mutex> lock(m);
    if (str.empty())
        return;
    q.push(str);
}

std::string SafeQueue::pop()
{
    std::lock_guard<std::mutex> lock(m);
    if (q.empty()) {
        return {};
    }
    std::string str = q.front();
    q.pop();
    // std::cout << "Data popped" << std::endl;
    return str;
}