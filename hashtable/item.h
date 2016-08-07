#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <unordered_map>

const int VAZIO = -1;

template<class T> struct Item{
    int key;
    T value;

    Item(int key = VAZIO){
        this->key = key;
    }

    Item(int key, T value){
        this->key = key;
        this->value = value;
    }
};

#endif // ITEM_H
