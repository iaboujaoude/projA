/*
 *  CharLinkedList.h
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  FILE PURPOSE HERE
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

#include <iostream>
#include <string>

class CharLinkedList {
    public:
        CharLinkedList();
        CharLinkedList(char c);
        CharLinkedList(char arr[], int size);
        CharLinkedList(const CharLinkedList &other);
        CharLinkedList &operator=(const CharLinkedList &other);
        int size() const;
        ~CharLinkedList();
        bool isEmpty() const;
        void clear();
        char first() const;
        char last() const;
        char elementAt(int index) const;
        std::string toString() const;
        std::string toReverseString() const;
        void pushAtBack(char c);
        void pushAtFront(char c);
        void insertAt(char c, int index);
        void insertInOrder(char c);
        void popFromFront();
        void popFromBack();
        void removeAt(int index);
        void replaceAt(char c, int index);
        void concatenate(CharLinkedList *other);


    private:
        int listSize;
        struct Node {
            char data_c;
            Node *next;
            Node *previous;
        };
        Node *front;
        Node *back;
        void destructorHelper(Node *curr);
        void copyListValues(const char arr[], int size);
        Node* elementAtHelper(int index, int count, Node *current) const;
        void throwRangeError(int index) const;
        void constructorHelper();
        void setNode(char c, Node *previous_in, Node *next_in, Node *input);
        Node* replaceAtHelper(Node *curr, int index, int count);
};

#endif
