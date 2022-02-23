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
        for (int i = 0; i < size; ++i) {                   // move everything from old memory to new memory blcok
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
    DSVector(const DSVector &) {

    }         // copy constructor
    ~DSVector() {

    }        // destructor

    DSVector& operator = (const DSVector&) {

    }
    theType& operator [] (const int index) {            // overload [] operator
        if (index >= size) {                            // if index >= size, then invalid entry
            cout << "Invalid entry - you are out of bounds." << endl;
        }
        else {
            return data[index];                         // else, return the data within the index
        }
    }
    void pushBack(const theType& info) {                // push back data into vector
        if (size >= capacity) {                         // if size >= capacity, then resize vector
            resize();
        }
        else {                                      // else, place info into data
            data[size] = info;
        }
        size++;
    }
    int getVectorSize() {
        return size;                                // return the size of the vector
    }
};


#endif //INC_21F_PA02_DSVECTOR_H
