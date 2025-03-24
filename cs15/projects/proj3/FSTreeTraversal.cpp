/*
 *  FSTreeTraversal.cpp
 *  Ian Abou-Jaoude & Elijah Weston-Capulong
 *  April 10, 2022
 *
 *  COMP 15 - Proj 3
 *
 *  Program to create and print all file paths in a given directory.
 *
 */

#include "FSTree.h"
#include <iostream>
#include <vector>

using namespace std;

void makePath(DirNode *node, string initialDirectory, vector<string>& paths);
void printPaths(vector<string> paths);

int main(int argc, char *argv[]) {

    //Ensure correct command line call
    if (argc != 2) {
        return -1;
    }

    //Initialize necessary objects
    string directory = argv[1];
    FSTree tree(directory);

    vector<string> paths;

    //Create and print new file paths
    makePath(tree.getRoot(), directory, paths);
    printPaths(paths);

    return 0;

}

/* make path
 *    Purpose: create a string containing the pathway for each 
 *             file in a given directory
 * Parameters: A node serving as the root of an FSTree, a string 
 *             with the initial file path, and a vector in which 
 *             to store the new path
 *    Returns: None
 *    Effects: None
 */
void makePath(DirNode *node, string initialDirectory, vector<string>& paths) {
    //If the current directory has a subdirectory, add its name 
    //to the file path and continue to traverse the tree
    if (node->hasSubDir()) {

        for (int i = 0; i < node->numSubDirs(); i++) {
            makePath(node->getSubDir(i), 
                        initialDirectory + "/" + 
                        node->getSubDir(i)->getName(), paths);
        }

    }

    //Add the files' names to the file path and add that string to the vector
    if (node->hasFiles()) {
        for (int i = 0; i < node->numFiles(); i++) {
            string newFullPath = initialDirectory + "/" + node->getFile(i);
            paths.push_back(newFullPath);
        }
    }

}

/* print paths
 *    Purpose: print out all of the file paths in a given directory
 * Parameters: a vector from which to print
 *    Returns: None
 *    Effects: None
 */
void printPaths(vector<string> paths) {
    //Traverse vector, printing every element
    for (unsigned int i = 0; i < paths.size(); i++) {
        cout << paths[i] << endl;
    }
}