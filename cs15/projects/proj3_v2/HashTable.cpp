#include "HashTable.h"
#include "WordList.h"
#include "WordInstance.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*












    CHANGE NUM ITEMS TO TRACK THE NUMBER OF BUCKETS ONLY? we end up expading when we maybe dont need to
























*/


/*    Name: Default constructor
 *    Purpose: create instance of empty list and set its name
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
HashTable::HashTable() {
    currentTableSize = INITIAL_TABLE_SIZE;
    numItems = 0;

    hashTable = new hNode[currentTableSize];
}

/*
 * destructor
 */
HashTable::~HashTable()
{
    for (int i = 0; i < currentTableSize; i++) {
        delete_buckets(i);
    }

    delete [] hashTable;
}

/*    Name: insert node
 *    Purpose: add a new hNode to the word List
 *    Parameters: a new hNode to add to the word List
 *    Returns: None
 *    Effects: Adds new hNode to the array
 */
void HashTable::insert(string key, Datum new_datum) {
    cout << "lowercase key is: " << get_lowercase(key) << endl;
    cout << "contains is: " << containsBucket(get_lowercase(key)) << endl;
    cout << "numitems is: " << numItems << endl;

    if (containsBucket(get_lowercase(key))) {
        cout << "in insert datum\n";
        insert_datum(key, new_datum);
    } else {
        //cout << "in make bucket\n";
        make_bucket(key, new_datum);
    }
}

/*    Name: make node
 *    Purpose: add a new hNode to the word List given the key and datum if the
 *    word instance doesn't already exist
 *    Parameters: a new hNode to add to the word List
 *    Returns: None
 *    Effects: Adds new hNode to the array
 */
void HashTable::make_bucket(string key, Datum new_datum) {

    if (numItems == currentTableSize) {
        expand();
    }
    
    int index = get_index(get_lowercase(key));

    hNode new_node;

    WordList new_list;
    new_list.insert(key, new_datum);
    new_list.set_name(get_lowercase(key));

    if (collisions(key)) {
        hashTable[index].bucket_vector.push_back(new_list);
        return;
    }

    new_node.bucket_vector.push_back(new_list);

    hashTable[index] = new_node;
    numItems++;    
}

/*    Name: insert datum
 *    Purpose: add a datum to an existing word instance within the word list
 *    Parameters: a key to access the particular word instance to add to and
 *                a datum to add
 *    Returns: None
 *    Effects: Adds new datum to a word instance within the word list
 */
void HashTable::insert_datum(string key, Datum new_datum) {
    
    int index = get_index(get_lowercase(key));
    
    for (unsigned int i = 0; i < hashTable[index].bucket_vector.size(); i++) {
        if (hashTable[index].bucket_vector.at(i).return_name() == get_lowercase(key)) {
            cout << "inserting in datum, key: " << key << " to wordList: " << hashTable[index].bucket_vector.at(i).return_name() << endl;
            hashTable[index].bucket_vector.at(i).insert(key, new_datum);
        }
    }
}

/*    Name: Expand
 *    Purpose: expand the capacity of the hashTable array
 *    Parameters: a string to be the name of the list
 *    Returns: None
 *    Effects: Makes new instance of a WordLst
 */
void HashTable::expand() {
    hNode *data_temp = new hNode[(currentTableSize * 2) + 2];
    int tableSize_copy = currentTableSize;

    

    for (int i = 0; i < tableSize_copy; i++) {

        for (unsigned int j = 0; j < hashTable[i].bucket_vector.size(); j++) {
            //cout << "in expand 1\n";
            currentTableSize = (currentTableSize * 2) + 2;
            int index = get_index(hashTable[i].bucket_vector.at(j).return_name());
            currentTableSize = tableSize_copy;
            // cout << "in expand 2\n";
            // cout << "num items:" << numItems << endl;
            // cout << "currentTableSize:" << currentTableSize << endl;
            // cout << "i:" << i << endl;
            // cout << "j:" << j << endl;
            // cout << "index: " << index << endl;
    
            if (collisions(hashTable[i].bucket_vector.at(j).return_name())) {
                //cout << "in expand 3\n";
                data_temp[index].bucket_vector.push_back(hashTable[i].bucket_vector.at(j));
                //cout << "in expand 4\n";
            }
            else {
                //cout << "in expand 5\n";
                data_temp[index] = hashTable[i];
            }
        }
    }

    if (currentTableSize == tableSize_copy) {
        currentTableSize = (currentTableSize * 2) + 2;
    }

    delete [] hashTable;

    hashTable = data_temp;
}

// /*    Name: isEmpty
//  *    Purpose: find out if there are any elem
//  *    Parameters: a string to be the name of the list
//  *    Returns: None
//  *    Effects: Makes new instance of a WordLst
//  */
// bool HashTable::isEmpty() {
//     return (numItems == 0);
// }

/*    Name: element at
 *    Purpose: access the word Instance at a specific index in the Word List
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */
WordList HashTable::element_at(string key) {
    int index = get_index(get_lowercase(key));

    WordList null("");
    
    if (not containsBucket(key)) {
        return null;
    }
    
    for (unsigned int i = 0; i < hashTable[index].bucket_vector.size(); i++) {
        if (hashTable[index].bucket_vector.at(i).return_name() == 
            get_lowercase(key)) {
            return hashTable[index].bucket_vector.at(i);
        }
    }
    
    return null; 
}

/*    Name: print at caseInSen
 *    Purpose: To print the list of words in a wordlist
 *    Parameters: The key that wants to be printed, the outstream where it is
 *                printed
 *    Returns: if it successfully printed
 *    Effects: None
 */
void HashTable::print_at_caseInSen(string key, ostream &out) {
    //cout << "here\n";
    if (not containsBucket(key)) {
        return;
    }

    element_at(get_lowercase(key)).print_list(out);
}

/*    Name: print at caseSen
 *    Purpose: To print the instance to be printed in a sensitive search
 *    Parameters: The key that wants to be printed, the outstream where it is
 *                printed
 *    Returns: if it successfully printed
 *    Effects: None
 */
void HashTable::print_at_caseSen(string key, ostream &out) {
    if (not containsInstance(key)) {
        return;
    }
    
    element_at(get_lowercase(key)).print_at(key, out);
}

/*    Name: containsInstance
 *    Purpose: assertain whether or not the instance of the word exists
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */

bool HashTable::containsInstance(string key) { 
    if (not containsBucket(key)) {
        return false;
    }
    
    int index = get_index(get_lowercase(key));
    

    for (unsigned int i = 0; i < hashTable[index].bucket_vector.size(); i++) {
        if (hashTable[index].bucket_vector.at(i).return_name() == 
            get_lowercase(key)) {
                if (hashTable[index].bucket_vector.at(i).contains(key)) {
                    return true;
                }
        }
    }

    if (not hashTable[index].bucket_vector.empty()) {
        return true;
    }

    return false;
}

/*    Name: containsBucket
 *    Purpose: assertain whether or not 
 *    Parameters: a string which serves as the key associated with the word
 *                instance being accessed.
 *    Returns: A word instance 
 *    Effects: None
 */

bool HashTable::containsBucket(string key) {
    
    int index = get_index(get_lowercase(key));
    
    for (unsigned int i = 0; i < hashTable[index].bucket_vector.size(); i++) {
        if (hashTable[index].bucket_vector.at(i).return_name() == 
            get_lowercase(key)) {
            return true;
        }
    }

    return false;
}

/*    Name: get index
 *    Purpose: return the hashed value of a string 
 *    Parameters: a string which serves as the key of the hash value
 *    Returns: a interger hash value 
 *    Effects: None
 */
int HashTable::get_index(string word) {
    return hash<string>{}(word) % currentTableSize;
}

// /*    Name: list size
//  *    Purpose: return the number of nodes in the word list
//  *    Parameters: none
//  *    Returns: a interger serving as the number of nodes in the word list
//  *    Effects: None
//  */
// int HashTable::listSize() {
//     return numItems;
// }

string HashTable::get_lowercase(string word) {
    string to_return = "";
    
    for (unsigned int i = 0; i < word.length(); i++) {
        char c = tolower(word[i]);

        to_return = to_return + c;
    }

    return to_return;
}

/*    Name: delete_buckets
 *    Purpose: Deletes the elements on the heap in a certain bucket
 *    Parameters: the index where it must be deleted
 *    Returns: none
 *    Effects: None
 */
void HashTable::delete_buckets(int index) {
    hashTable[index].bucket_vector.clear();
}

void HashTable::print_keys() {
    for (int i = 0; i < currentTableSize; i++) {
        for (unsigned int j = 0; j < hashTable[i].bucket_vector.size(); j++) {
            cout << "Key is: " << hashTable[i].bucket_vector.at(j).return_name() << endl;
            for (int k = 0; k < hashTable[i].bucket_vector.at(j).get_size(); k++) {
                cout << "Key instance: " << hashTable[i].bucket_vector.at(j).word_list[k].key << endl;
            }
        }
    }
}

bool HashTable::collisions(string word) {
    //cout << "in collision 1\n";
    return ((not hashTable[get_index(get_lowercase(word))].bucket_vector.empty())
            and (not containsBucket(get_lowercase(word))));
}