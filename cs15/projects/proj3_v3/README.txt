/**********************************************************
* Project 3: Gerp
* CS 15
* README
* Ian Abou-Jaoude & Elijah Weston
*********************************************************/



/************** WEEK ONE **************/

Compile/run:

g++ -o stringProcessingCompile -Wall -Wextra -Werror stringProcessing.h 
stringProcessing.cpp stringProcessingTest.cpp

g++ -o WordInstanceTest -Wall -Wextra -Werror WordInstance.h WordInstance.cpp
WordInstanceTest.cpp

To compile the FSTreeTraversal executable, type "make" into the terminal.

Testing was done through the program stringProcessingTest.cpp that has a main
which is commented out. No bugs were found in the first phase of our testing.
The way to compile and run the test is given above. 


/************** WEEK TWO **************/

1. Purpose:
    "gerp" is a program which gets every line the a given word appears in,
    within a given file, for its client. Working in a two step process, 
    "gerp" indexes a given set of files from a certain directory, then
    prompts the user for a query which is matched within the index. The
    program then prints every line the query appears on in a given output file.
    Furthermore, the program distiguishes between a case-sensitive and
    case-insensitive search. A case-sensitive search will find only the
    lines where the given word appears in the exact capitalization as given,
    whereas a case-insensitive search finds every line in which the word
    occurs in any capitalization variation.

2. Acknowledgements:
    Ian and I recieved help from various TAs in office hours. We also used
    the lecture slides to help gain a better understanding of HashTables, 
    the STL standard library for vectors, and C++'s hash function.

3. Files:
    DirNode.h:
        Provided for us by the reference, this file is the interface for
        the nodes which make up the FSTree.

    FSTree.h:
        Provided by the reference. This file conatins the interface for
        the n-ary tree which contains DirNodes which serve as a
        representation of each file within a directory.

    gerp.cpp:
        This file contains the main function for our implementation
        of the "gerp" program. It creates a hashTable instance, 
        prompts users for their query, creates arrays of the lines and
        paths within a directory, and sends results of a user query to
        a given output file.

    HashTable.cpp:
        This file contains the implementation of the HashTable class
        which indexes every word in a given directory within an
        array of WordLists.

    HashTable.h:
        This file provides the interface for the HashTable class. 

    HashTableTest.cpp:
        This is a testing file for the HashTable class which creates
        a new instance, data upon which to test it, and calls upon 
        the HashTable member functions to ensure their functionality.

    stringProcessing.h:
        The interface for the stringProcessing class which strips
        a given string of all of the non alphanumeric characters
        within it and returns the result of this modification. 

    stringProcessing.cpp:
        Implementation for the stringProcessing class.

    stringProcessingTest.cpp
        This is a testing file for the stringProcessing class which functions
        by creating an instance of the stringProcessing class, providing
        an array of strings to process via its functions, and observing the
        output to ensure correct functionality.

    WordList.h
        This file contains the interface for the WordList class which
        contains a vector of WordInstances of the same word with
        different variations in capitalization.

    WordList.cpp
        This file contains the implementation of the WorList class.

    testWordList.cpp
        This is a testing file for the WordList class. It tests the
        class by creating datum on which to test it, creating an
        instance, and calling various functions to varify that their output
        matches the desired.

    WordInstance.h
        This file contains the interface for the WordInstance class which
        contains a vector of datums. Datums contains the the line, line number
        , and filepath for a location of a given word within a directory.

    WordInstance.cpp

    WordInstanceTest.cpp

    unit_tests.h: 

    Makefile:

4. Compilation:
    To compile our implementation of "gerp," type "make" in the terminal.
    To run our program, execute "gerp" with command "./gerp" followed by
    the full path of the directory you wish to index and an output file
    to which to send the results of your queries.

    Usage: ./ gerp inputDirectory outputFile

5. Architectural Overview:
    This implementation of "gerp" uses a HashTable to create an index of
    a given directory. The buckets are comprised of WordLists whose
    purpose is to store WordInstances in a vector that have within 
    them a vector of Datum that contain the line, line number, and filePath
    of an instance at which a given word appears. There are also two arrays
    that contain every line and every filePath within a given directory.
    
6. Data Structures and Algorithms 
    The index built by "gerp" is implemented using a HashTable. This allows
    the client of the index to access any element within the table in constant
    time. Each bucket in the table corresponds to a word obtained from a file
    which is first converted to lowercase, then hashed to get the numerical
    index at which the word will be stored in the array.

    The words to hash are from files within a directory provided by the user.
    Using a n-ary tree which was provided to us by the reference, we 
    implemented a function which obtained from a directory the file
    path for every single file within that directory and all of its
    subdirectories. These filepaths were stored in an array called "paths."
    By traversing through "paths," opening the corresponding file, reading
    the line, then getting every word in each, we access every word in a
    given directory.

    This HashTable is implemented using an array of "hNodes," each that 
    contain a vector of WordLists. The reason for keeping vectors within each
    bucket (hNode) is for collisions. Collisions occur when two different keys
    , in this case words, are mapped to the same bucket (index) by the C++ hash
    function. If and when collisions occur, the element mapped to an 
    already-filled index will simply be added to the vector within the bucket.
    This process is known as chaining. Because each wordList holds a "name"
    variable which can be accessed via the get_name() function within its class,
    one can access a certain wordList by traversing the vector of
    wordLists at the index of the array matching a hashed query then matching
    that query with the result of the get_name() function.

    As mentioned previously, the vectors within the buckets of the overall 
    HashTable are of wordLists. WordLists have two private variables: a vector
    and a name. The name is a lowercase word serving as the overall 
    categorization of the word list. The vectors in the wordList are 
    comprised of "tNodes". These tNodes contain a key and a WordInstance.
    Each element contained within the list
    is an instance of the same word as the name, though with different 
    capitalization. The key is the specific variation in capitalization 
    of a word, whereas the WordInstance is a
    vector containing datum what hold the line, line number, and file path
    of every occurance of the key within the given directory.

6. Testing:

