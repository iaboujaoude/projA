/*
 *  CharArrayList.h
 *  Ian Abou-Jaoude
 *  January 31
 *
 *  COMP 15 HW 1 ArrayLists
 *
 *  The header file for CharArrayList
 *
 */
#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H

#include <string>

class CharArrayList 
{
public:

    CharArrayList();
    CharArrayList(char c);
    CharArrayList(char arr[], int size);
    CharArrayList(const CharArrayList &other);
    CharArrayList &operator=(const CharArrayList &other);
    int size() const;
    ~CharArrayList();
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
    void concatenate(CharArrayList *other);
    void shrink();


    
private: 

    int arrSize;
    int capacity;
    char *data;

    void copyArrayValues(const char arr[], int size);
    void expand();
    void throwRangeError(int index);

};

#endif
