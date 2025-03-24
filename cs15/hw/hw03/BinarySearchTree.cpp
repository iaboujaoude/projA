/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 * Ian Abou-Jaoude
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
        root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}

void BinarySearchTree::post_order_delete(Node *node)
{
        if (node == nullptr) {
                return;
        }
        else {
                post_order_delete(node->left);
                post_order_delete(node->right);
                delete node;
        }
}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

// assignment overload
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // if copying the same do nothing
        if (this == &source) {
                return *this;
        }
        else {
                post_order_delete(root);
                root = pre_order_copy(source.root);
        }

        return *this;
}

BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        if (node == nullptr) {
                return node;
        }
        Node *newRoot = new Node;   
                
        newRoot->data = node->data;
        newRoot->count = node->count;

        newRoot->left = pre_order_copy(node->left);
        newRoot->right = pre_order_copy(node->right);

        return newRoot;
}

int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}

BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        //Traverses to the bottom left and returns node
        if ((node->left == nullptr) or (node == nullptr)) {
                return node;
        }
        else {
                return find_min(node->left);
        }
}

int BinarySearchTree::find_max() const
{
        if (root == nullptr)
                return numeric_limits<int>::min(); // INT_MIN

        return find_max(root)->data;
}

BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        //Traverses to the bottom right and returns node
        if ((node->right == nullptr) or (node == nullptr)) {
                return node;
        }
        else {
                return find_max(node->right);
        }
}

bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) const
{
        bool isThere = false;

        if (isEmpty()) {
                return false;
        }

        if (node == nullptr) {
                return false;
        }
        else if (node->data == value) {
                return true;
        }
        isThere = (contains(node->right, value) or contains(node->left, value));

        return isThere;
}
 
void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}

void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        if (isEmpty()) {
                root = create_node(value);
                return;
        }
        else if (node == nullptr) {
                if (parent->data <= value) {
                        parent->right = create_node(value);
                }
                else {
                        parent->left = create_node(value);
                }
        }
        else if (node->data == value) {
                node->count = node->count + 1;
                return;
        }
        else if (node->data > value) {
                insert(node->left, node, value);
        }
        else if (node->data < value) {
                insert(node->right, node, value);
        }
}

bool BinarySearchTree::remove(int value)
{
        return remove(root, nullptr, value);
}


bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        if (isEmpty()) {
                return false;
        }
        if (node->data == value) {
                if (node->count > 1) {
                        node->count--;
                }
                else if (node->count == 1) {
                        node->count--;
                        if (root->data == value) {
                                deleteRoot();
                        }
                        else if (node->right == nullptr) {
                                if (parent->data > node->data) {
                                        parent->left = node->left;
                                }
                                else if (parent->data < node->data) {
                                        parent->right = node->left;
                                }
                        }
                        else if (node->left == nullptr) {
                                if (parent->data > node->data) {
                                        parent->left = node->right;
                                }
                                else if (parent->data < node->data) {
                                        parent->right = node->right;
                                }
                        }
                        else {
                                removeWithTwo(node, parent);
                        }
                        delete node;
                }

                return true;
        }
        if (node->data < value) {
                return remove(node->right, node, value);
        }
        else {
                return remove(node->left, node, value);
        }
        return false;
}

int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

int BinarySearchTree::tree_height(Node *node) const
{
        if (node == nullptr) {
                return -1;
        }

        return (max(tree_height(node->left), tree_height(node->right)) + 1);

}

// returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

int BinarySearchTree::node_count(Node *node) const
{
        if (isEmpty()) {
                return 0;
        }
        if (node == nullptr) {
                return 0;
        }
        else {
                return (node_count(node->right) + node_count(node->left) + 1);
        }
}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

int BinarySearchTree::count_total(Node *node) const
{
        if (isEmpty()) {
                return 0;
        }
        if (node == nullptr) {
                return 0;
        }
        else {
                return (count_total(node->right) + count_total(node->left) + 
                        (node->count * node->data));
        }
}

BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}

// Helper Funcitons:

// Takes no parameters and simply returns if the tree is empty
bool BinarySearchTree::isEmpty() const {
        return (root == nullptr);
}

//Creates and returns a node on the heap only filling in it's value
BinarySearchTree::Node *BinarySearchTree::create_node(int data) const {
        Node *newN = new Node;
        newN->left = nullptr;
        newN->right = nullptr;
        newN->data = data;
        newN->count = 1;

        return newN;
}

//Called if root needs to be deleted/removed
void BinarySearchTree::deleteRoot() {
        if ((root->right == nullptr) and (root->left == nullptr)) {
                root = nullptr;
                return;
        }

        if (root->right == nullptr) {
                root = root->right;
                return;
        }
        if (root->left == nullptr) {
                root = root->left;
                return;
        }

        removeWithTwo(root, nullptr);
}

// Removes the node given, only called when the given node has two children
// node
void BinarySearchTree::removeWithTwo(Node *node, Node *previous) {
        Node *min = find_min(node->right);
        Node *minPar = get_par(node, min);

        if (previous == nullptr) {
                root = min;
        }
        else {
                if (previous->data > node->data) {
                        previous->left = min;
                }
                else if (previous->data < node->data) {
                        previous->right = min;
                }
        }

        if (minPar != node) {
                if (min->right == nullptr) {
                        minPar->left = nullptr;
                }
                else {
                        minPar->left = min->right;
                }
        }

        min->left = node->left;
}

// Returns the parent node when input given is a child node
BinarySearchTree::Node *BinarySearchTree::get_par(Node *parent, Node *child) {
        if (parent == nullptr) {
                return nullptr;
        }

        if (parent->right == child) {
                return parent;
        }

        if (parent->left == child) {
                return parent;
        }

        if (child->data < parent->data) {
                return find_parent(parent->left, child);
        }
        else if (child->data > parent->data) {
                return find_parent(parent->right, child);
        }
        return nullptr;
}

// void BinarySearchTree::print_info() const{
//         print_info(root);
// }

// void BinarySearchTree::print_info(Node *node) const{
//         if (isEmpty()) {
//                 cout << "nothing in tree." << endl;
//         }
//         if (node == nullptr) {
//                 return;
//         }
//         else {
//                 cout << "Data: " << node->data << "; Count associated: " <<
//                 node->count << endl;
                
//                 print_info(node->right);
//                 print_info(node->left);
//         }
// }