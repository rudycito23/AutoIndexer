//
// Created by rrluc on 2/17/2022.
//

#ifndef INC_21F_PA02_DSVECTOR_H
#define INC_21F_PA02_DSVECTOR_H

#include "DSString.h"

template<typename theType>

class DSVector {
private:
   theType* data{nullptr};
   int size{0};
   int capacity{10};

private:
    void resize() {
        theType* newMemory = new theType[capacity * 2];    // allocate new memory * 2
        for (int i = 0; i < size; ++i) {                   // move everything from old memory to new memory block
            newMemory[i] = data[i];                        // copy old data into new memory block
        }
        delete[] data;                                     // delete the old memory block data
        data = newMemory;                                  // data = the new memory block
        capacity = capacity * 2;                           // capacity = the new capacity * 2
    }

public:
    DSVector() {                                           // constructor to allocate memory * 2.
        data = new theType[capacity];
    }
    DSVector(const DSVector &vector) {                     // copy constructor
        size = vector.size;
        capacity = vector.capacity;
        data = new theType[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = vector.data[i];
        }
    }
    ~DSVector() {                                          // destructor
        delete[] data;
    }

    DSVector& operator = (const DSVector &vector) {
        size = vector.size;
        capacity = vector.capacity;
        data = new theType[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = vector.data[i];
        }
        return *this;
    }
    theType operator [] (const int index) {                // overload insertion [] operator
        if (index >= size) {                                // if index >= size, then invalid entry
            throw std::out_of_range("Vector index is out of bounds");
        }
        else {
            return data[index];                             // else, return the data within the index
        }
    }
    void pushBack(const theType& info) {                    // push back data into vector
        if (size >= capacity) {                             // if size >= capacity, then resize vector
            resize();
        }
        data[size] = info;                                  // else, place info into data
        size++;
    }
    int findIndex(const theType& info) {                    // find a specific element and be able to remove it
        for (int index = 0; index < size; ++index) {        // iterate through the entire vector
            if (data[index] == info) {                      // if data in the index == what is being searched (info)
                return index;                               // return the index
            }
        }
        return -1;                                          // return -1, if nothing was found
    }
    int removeDataFromIndex(int indexToRemove) {
        // if the indexToRemove is greater than the vector size OR less than zero
        if ((indexToRemove >= size) || (indexToRemove < 0)) {
            return -1;
        }
        else {
            for (int index = indexToRemove; index < size - 1; ++index) {
                // data in the index is now the rest of the data in the vector
                data[index] = data[index + 1];
            }
            size = size - 1;        // the size of the vector is one less size
        }
    }
    int getVectorSize() {
        return size;                                        // return the size of the vector
    }
    theType& atIndex(const int index) {                     // overload insertion [] operator
        if (index >= size) {                                // if index >= size, then invalid entry
            cout << "Invalid entry - you are out of bounds." << endl;
        }
        else {
            return data[index];                             // else, return the data within the index
        }
    }
};
// remove an element from the vector - DONE
// create a find function that will return the index where the element is within the vector. If it doesn't exist
// return -1 - DONE
// get the size of the vector and be able to iterate through the vector - DONE
// implement a bounds checker .at function - DONE
// create a class for words and sentences and page numbers
// to read in files, do not hard-code; use argv to read in files. **argv1 = file (1); argv2 = (2); argv3 = output file**

// line 1 = first letter of the keyword
// line 2 = keywords: list of all the pages the word is located

// ***read in the second file first to know keywords and multiple worded keywords -> compare to file 1
// main should have < 50 lines.

#endif //INC_21F_PA02_DSVECTOR_H