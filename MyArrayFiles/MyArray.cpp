/*
 *  lab1exe_F.cpp
 *  ENSF 694 Lab 1, exercise F
 *  Completed by: Jaskirat Singh
 *  Submission date: July 3
 */

#include "MyArray.h"

int search(const MyArray* myArray, int obj){
// Students are supposed to complete the implementation of the this function
    for(int i = 0; i < myArray->list_size; i ++) {
        if(myArray->array[i] == obj) {
            return i;
        }
    }
    return -1;
}

void initialize(MyArray* myArray) {
    // Students are supposed to complete the implementation of the this function
    myArray->list_size = 0;
}

int retrieve_at(MyArray* myArray, int pos){
    // Students are supposed to complete the implementation of the this function
    return myArray->array[pos];
    return 0;
}

int count(MyArray* myArray, int obj ){
    // Students are supposed to complete the implementation of the this function
    int counter = 0;
    for(int i = 0; i < myArray->list_size; i ++){
        if(myArray->array[i] == obj) {
            counter ++;
        }
    }
    return counter;
}

void append( MyArray* myArray, int array[], int n ) {
    // Students are supposed to complete the implementation of the this function
    //Append array if condition is true, do nothing if it is false
    if(myArray->list_size + n <= SIZE) {
        //Append new array to existing array
        for(int i = 0; i < n; i ++) {
            myArray->array[myArray->list_size + i] = array[i];
        }
        //Increase array size
        myArray->list_size += n;
    }
}

void insert_at(MyArray* myArray, int pos, int val) {
    // Students are supposed to complete the implementation of the this function
    myArray->list_size ++;
    // Starting from the index of the new list size, move each element after pos to the right
    for(int i = myArray->list_size - 1; i > pos; i --) {
        myArray->array[i] = myArray->array[i - 1];
    }
    // Insert new value into the freshly emptied space
    myArray->array[pos] = val;
}

int remove_at(MyArray* myArray, int pos ) {
    // Students are supposed to complete the implementation of the this function
    int valueRemoved = myArray->array[pos];
    for(int i = pos; i < myArray->list_size - 1; i ++) {
        myArray->array[i] = myArray->array[i+1];
    }
    //Decriment list_size to reflect new value
    myArray->list_size --;
    return valueRemoved;
}

int remove_all(MyArray* myArray, int value ) {
    // Students are supposed to complete the implementation of the this function
    int valueRemoved = -1;
    for(int i = 0; i < myArray->list_size; i ++) {
        if(myArray->array[i] == value) {
            valueRemoved = remove_at(myArray, i);
        }
    }
    return valueRemoved;
}

// You can modify this function however you want:  it will not be tested

void display_all(MyArray* myArray) {
    // Students are supposed to complete the implementation of the this function
    for(int i = 0; i < myArray->list_size; i ++) {
        cout << "Element " << i + 1 << ": " << myArray->array[i] << endl;
    }
}

bool is_full(MyArray* myArray){
    // Students are supposed to complete the implementation of the this function
    return myArray->list_size == SIZE;
}

bool isEmpty(MyArray* myArray){
    // Students are supposed to complete the implementation of the this function
    return myArray->list_size == 0;
}

int size(MyArray* myArray){
    // Students are supposed to complete the implementation of the this function
    return myArray->list_size;
}
