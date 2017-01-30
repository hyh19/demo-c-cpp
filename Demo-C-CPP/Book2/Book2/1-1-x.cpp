//
//  1-1-x.cpp
//  Demo-Data-Structure-Algorithm-CPP
//
//  Created by Yuhui Huang on 12/01/2017.
//  Copyright © 2017 Yuhui Huang. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

template <typename DataType>
class SeqList {
public:
    SeqList(int size=defaultSize) {
        if (size > 0) {
            maxSize = size;
            length = 0;
            elements = new DataType[maxSize];
            for (int i=0; i<maxSize; i++) {
                elements[i] = NULL;
            }
        }
    }
    
    ~SeqList() {
        delete [] elements;
    }
    
    bool insertElement(DataType data);
    
    bool deleteElement(int location);
    
    DataType getElement(int location);
    
    bool changeElement(int location, DataType newData);
    
private:
    static const int defaultSize = 10;
    DataType *elements;
    int maxSize;
    int length;
};

template <typename DataType>
bool SeqList<DataType>::insertElement(DataType data) {
    int currentIndex = length;
    if (length >= maxSize) {
        return false;
    } else {
        elements[currentIndex] = data;
        length++;
        return true;
    }
}

template <typename DataType>
DataType SeqList<DataType>::getElement(int location) {
    if (location<0 || location>length) {
        cout << "invalid param" << endl;
        return 0;
    } else {
        return elements[location];
    }
}

template <typename DataType>
bool SeqList<DataType>::deleteElement(int location) {
    if (location>=length || location<0) {
        return false;
    } else {
        for (int i=location; i<length; i++) {
            elements[i] = elements[i+1];
        }
        length--;
        return true;
    }
}

template <typename DataType>
bool SeqList<DataType>::changeElement(int location, DataType newData) {
    if (location<0 || location>=length) {
        return false;
    } else {
        elements[location] = newData;
        return true;
    }
}

int main(int argc, const char * argv[]) {
    SeqList<int> list(10);
    for (int i=0; i<10; i++) {
        list.insertElement(i*10);
    }
    for (int i=0; i<10; i++) {
        cout << list.getElement(i) << " ";
    }
    cout << endl;
    return 0;
}
