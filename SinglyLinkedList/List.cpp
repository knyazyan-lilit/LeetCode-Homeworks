#include <iostream>
#include "List.h"

template <typename T>
FwdList<T>::FwdList()
    : size(0)
{
    head = nullptr;
}

template <typename T>
void FwdList<T>::insert(int pos, T elem)
{
    if (pos > size || pos < 0)
    {
        return;
    }
    else if (pos == 0)
    {
        push_front(elem);
    }
    else if (pos == size)
    {
        push_back(elem);
    }
    else
    {
        Node<T> *newNode = new Node<T>;
        Node<T> *tmp = new Node<T>;
        while (pos != 1)
        {
            tmp = tmp->next;
            --pos;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
        newNode.info = elem;
    }
    ++size;
}

template <typename T>
void FwdList<T>::remove(int pos)
{
    if (pos > size || pos < 0)
    {
        return;
    }
    else if (pos == 0)
    {
        pop_front();
    }
    else if (pos == size)
    {
        pop_back();
    }
    else
    {
        Node<T> *tmp = new Node<T>;
        while (pos != 1)
        {
            tmp = tmp->next;
            --pos;
        }
        Node<T> *newNode = tmp->next;
        tmp->next = tmp->next->next;
        delete newNode;
    }
    --size;
}

template <typename T>
void FwdList<T>::push_front(T elem)
{
    Node<T> *newNode = new Node<T>;
    newNode->info = elem;
    if (head == nullptr)
    {
        newNode->next = nullptr;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    ++size;
}

template <typename T>
void FwdList<T>::push_back(T elem)
{
    Node<T> *newNode = new Node<T>;
    newNode->info = elem;
    if (head == nullptr)
    {
        newNode->next = nullptr;
        head = newNode;
    }
    else
    {
        Node<T> *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->next = nullptr;
    }
    ++size;
}

template <typename T>
void FwdList<T>::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->next == nullptr)
    {
        delete head;
    }
    else
    {
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
    }
    --size;
}

template <typename T>
void FwdList<T>::pop_back()
{
    Node<T> *tmp = head;
    if (head == nullptr)
    {
        return;
    }
    else if (head->next == nullptr)
    {
        delete head;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        delete tmp;
    }
    --size;
}

template <typename T>
void FwdList<T>::traversal(void (*p)(Node<T> node))
{
    Node<T> tmp = new Node<T>;
    while (tmp->next != nullptr)
    {
        p(tmp);
        tmp = tmp->next;
    }
}

template <typename T>
void FwdList<T>::print(Node<T> node)
{
    std::cout << node->info << " ";
}

template <typename T>
size_t FwdList<T>::get_size(){
    return size;
}
