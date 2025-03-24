/*
 *  unit_tests.h
 *  Ian Abou-Jaoude
 *  Apr 1
 *
 *  CS 15 HW3
 *
 *  Testing the implementation of Binary Search Tree using unit test
 *
 */

#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;


//Simply initializes a BST and makes sure no valgrind errors occur
// Also tests post order delete and destructor on empty tree
void constructor_works() {
    BinarySearchTree tree;
}

//Tests empty copy constructor and copying by self
void empty_copyOperator() {
    BinarySearchTree tree;
    BinarySearchTree tree_full;
    int arrInt1[9] = {10, 8, 4, 11, 14, 15, 6, 6, 4};

    for (int i = 0; i < 9; i++) {
        tree_full.insert(arrInt1[i]);
    }

    BinarySearchTree t = tree_full;

    t.print_tree();

    t = t;
    t.print_tree();
    
    t = tree;
    t.print_tree();
}

//Tests height function with multpiple different heights and empty trees
void height_works() {
    BinarySearchTree tree_full;
    BinarySearchTree tree_full2;
    BinarySearchTree tree_one;
    BinarySearchTree tree_empty;

    int arrInt1[9] = {10, 8, 4, 11, 14, 15, 6, 6, 4};
    int arrInt2[6] = {10, 4, 18, 13, 6, 21};
    tree_one.insert(5);

    for (int i = 0; i < 9; i++) {
        tree_full.insert(arrInt1[i]);
    }
    for (int i = 0; i < 6; i++) {
        tree_full2.insert(arrInt2[i]);
    }
    
    assert(tree_full.tree_height() == 3);
    assert(tree_full2.tree_height() == 2);
    assert(tree_one.tree_height() == 0);
    assert(tree_empty.tree_height() == -1);
}


//Tests insertion with duplicates empty trees, full trees, and one element
//trees
void insert_works() {
    BinarySearchTree tree_full;
    BinarySearchTree tree_full2;
    BinarySearchTree tree_one;
    BinarySearchTree tree_empty;

    int arrInt1[9] = {10, 8, 4, 11, 14, 15, 6, 6, 4};
    int arrInt2[6] = {10, 4, 18, 13, 6, 21};
    tree_one.insert(5);

    for (int i = 0; i < 9; i++) {
        tree_full.insert(arrInt1[i]);
    }
    for (int i = 0; i < 6; i++) {
        tree_full2.insert(arrInt2[i]);
    }

    tree_full.print_tree();
    tree_full2.print_tree();
    tree_one.print_tree();
    tree_empty.print_tree();
}

//Tests find max with duplicates (is max) empty trees, full trees, and one element
//trees
void max_works() {
    BinarySearchTree tree_full;
    BinarySearchTree tree_full2;
    BinarySearchTree tree_one;
    BinarySearchTree tree_empty;

    int arrInt1[9] = {10, 8, 4, 11, 14, 15, 6, 15, 4};
    int arrInt2[6] = {10, 4, 18, 13, -6, 21};
    tree_one.insert(5);

    for (int i = 0; i < 9; i++) {
        tree_full.insert(arrInt1[i]);
    }
    for (int i = 0; i < 6; i++) {
        tree_full2.insert(arrInt2[i]);
    }

    cout << "Empty max: " << tree_empty.find_max() << endl;
    assert(tree_one.find_max() == 5);
    assert(tree_full2.find_max() == 21);
    assert(tree_full.find_max() == 15);
}

//Tests find min with duplicates (is min) empty trees, full trees, and one element
//trees, and negative number
void min_works() {
    BinarySearchTree tree_full;
    BinarySearchTree tree_full2;
    BinarySearchTree tree_one;
    BinarySearchTree tree_empty;

    int arrInt1[9] = {10, 8, 4, 11, 14, 15, 6, 15, 4};
    int arrInt2[6] = {10, 4, 18, 13, -6, 21};
    tree_one.insert(5);

    for (int i = 0; i < 9; i++) {
        tree_full.insert(arrInt1[i]);
    }
    for (int i = 0; i < 6; i++) {
        tree_full2.insert(arrInt2[i]);
    }

    cout << "Empty min: " << tree_empty.find_min() << endl;
    assert(tree_one.find_min() == 5);
    assert(tree_full2.find_min() == -6);
    assert(tree_full.find_min() == 4);
}

// Tests to see if the contains function can catch numbers in a full empty and
// one elem list, looking for numbers at the star, back and middle
void contains_works() {
    BinarySearchTree tree_full;
    BinarySearchTree tree_full2;
    BinarySearchTree tree_one;
    BinarySearchTree tree_empty;

    int arrInt1[9] = {10, 8, 4, 11, 14, 15, 6, 15, 4};
    int arrInt2[6] = {10, 4, 18, 13, -6, 21};
    tree_one.insert(5);

    for (int i = 0; i < 9; i++) {
        tree_full.insert(arrInt1[i]);
    }
    for (int i = 0; i < 6; i++) {
        tree_full2.insert(arrInt2[i]);
    }

    assert(!tree_one.contains(0));

    assert(tree_full2.contains(-6));
    assert(tree_full2.contains(10));
    assert(!tree_full2.contains(2));
    assert(tree_full2.contains(21));
    
    assert(!tree_full.contains(99));
    assert(tree_full.contains(11));
    assert(tree_full.contains(15));
    assert(!tree_full.contains(5));
}

// Tests the node counting function on different trees full empty, only one, 
// and repeating numbers
void node_count_works() {
    BinarySearchTree tree_full;
    BinarySearchTree tree_full2;
    BinarySearchTree tree_one;
    BinarySearchTree tree_empty;

    int arrInt1[9] = {10, 8, 4, 11, 14, 15, 6, 15, 4};
    int arrInt2[6] = {10, 4, 18, 13, -6, 21};
    tree_one.insert(5);

    for (int i = 0; i < 9; i++) {
        tree_full.insert(arrInt1[i]);
    }
    for (int i = 0; i < 6; i++) {
        tree_full2.insert(arrInt2[i]);
    }

    assert(tree_full2.node_count() == 6);
    assert(tree_full.node_count() == 7);
    assert(tree_empty.node_count() == 0);
    assert(tree_one.node_count() == 1);

}

// Tests the total counting function on different trees full empty, only one, 
// and repeating numbers that are scattered at different parts of tree
void total_count_works() {
    BinarySearchTree tree_full;
    BinarySearchTree tree_full2;
    BinarySearchTree tree_one;
    BinarySearchTree tree_empty;

    int arrInt1[14] = {10, 8, 4, 11, 14, 15, 6, 15, 4, 11, 14, 13, 12, 8};
    int arrIntSum1 = 0;
    int arrInt2[6] = {10, 4, 18, 13, -6, 21};
    int arrIntSum2 = 0;
    
    tree_one.insert(5);
    tree_one.insert(5);
    tree_one.insert(5);

    for (int i = 0; i < 14; i++) {
        tree_full.insert(arrInt1[i]);
        arrIntSum1 = arrIntSum1 + arrInt1[i];
    }
    for (int i = 0; i < 6; i++) {
        tree_full2.insert(arrInt2[i]);
        arrIntSum2 = arrIntSum2 + arrInt2[i];
    }

    cout << tree_full.count_total() << endl;
    assert(tree_full.count_total() == arrIntSum1);
    assert(tree_full2.count_total() == arrIntSum2);
    assert(tree_empty.count_total() == 0);
    assert(tree_one.count_total() == 15);

}

// Ensuring no valgrind errors and that remove can be done on many different
// parts of the bst like root leaves and middle nodes
void remove_works() {
    BinarySearchTree tree_full;
    BinarySearchTree tree_full2;
    BinarySearchTree tree_one;
    BinarySearchTree tree_empty;

    int arrInt1[14] = {10, 8, 4, 11, 14, 15, 6, 15, 4, 11, 14, 13, 12, 8};
    int arrIntSum1 = 0;
    int arrInt2[6] = {10, 4, 18, 13, -6, 21};
    int arrIntSum2 = 0;
    
    tree_one.insert(5);
    tree_one.insert(5);
    tree_one.insert(5);

    for (int i = 0; i < 14; i++) {
        tree_full.insert(arrInt1[i]);
        arrIntSum1 = arrIntSum1 + arrInt1[i];
    }
    
    assert(tree_full.count_total() == arrIntSum1);
    assert(tree_full2.count_total() == arrIntSum2);
    assert(tree_empty.count_total() == 0);
    assert(tree_one.count_total() == 15);

    tree_full.remove(8);
    assert(tree_full.count_total() == (arrIntSum1 - 8));
    tree_full.remove(8);
    tree_full.print_tree();
    assert(tree_full.count_total() == (arrIntSum1 - 8 - 8));
    tree_full.remove(11);
    assert(tree_full.count_total() == (arrIntSum1 - 8 - 8 - 11));
    tree_full.remove(6);
    assert(tree_full.count_total() == (arrIntSum1 - 8 - 8 - 11 - 6));
    tree_full.remove(10);
    assert(tree_full.count_total() == (arrIntSum1 - 8 - 8 - 11 - 6 - 10));





}

