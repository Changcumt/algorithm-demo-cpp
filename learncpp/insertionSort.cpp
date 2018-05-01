//
//  insertionSort.cpp
//  learncpp
//
//  Created by 常庆林 on 2018/5/1.
//  Copyright © 2018年 常庆林. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

void print(int A[],int size){
    for (int i = 0; i<size; i++) {
        cout<<A[i]<<endl;
    }
//    cout<<"the size of array:" << size <<endl;
}
//插入排序
//知识点：从第二个元素开始 循环的与之前的元素比较，如果比之前的元素小 则置换位置。 每次循环到第i个元素，则第i 个元素之前的均是已经拍好顺序的
// 时间复杂度为O(n2)
void exec(int A[],int size){
    for(int j = 1;j<size;j++){
        int key = A[j];
        int i = j - 1;
        
        while (A[i]>key && i>-1) {
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
    print(A, size);
}

void insertionSort(){
    int aaa[] = {1,2,9,4,5,6};
    int arrSize = sizeof(aaa)/(sizeof(aaa[0]));
    exec(aaa,arrSize);
}

