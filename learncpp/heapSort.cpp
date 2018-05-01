//
//  heapSort.cpp
//  learncpp
//
//  Created by 常庆林 on 2018/5/2.
//  Copyright © 2018年 常庆林. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "math.h"
using namespace std;

static void exec(int A[],int size);
static void print(int A[],int size);

void print(int A[],int size){
    for (int i = 0; i<size; i++) {
        cout<<A[i]<<endl;
    }
    cout<<"----------"<<endl;
    //    cout<<"the size of array:" << size <<endl;
}
//堆排序（二叉树 最大堆）
//知识点：先创建堆 然后针对维护堆性质 然后循环每次取最大堆的根结点，针对剩下的堆 继续维护堆性质。
// 时间复杂度为o(nlgn)
int parent(int i){
    return floor(i/2);
}
int left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
}
//维护最大堆性质
void maxHeapify(int A[],int i,int arrSize){
    int l = left(i);
    int r = right(i);
    int largest;
    if(l<=arrSize && A[l]>A[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r<=arrSize && A[r]>A[largest]){
        largest = r;
    }
    if(largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A,largest,arrSize);
    }
}
//创建堆
void buildMaxHeap(int A[],int size){
    int forCount = floor((size-1)/2);
  
    for(int i = forCount;i>=0;i--){
        maxHeapify(A,i,size-1);
    }
}
void exec(int A[],int size){
    buildMaxHeap(A,size);
    
    // 输出堆
    int forCount = size-1;
    for(int i = forCount;i>0;i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        maxHeapify(A,0,i-1);
    }
    
    print(A, size);
}

void heapSort(){
    int aaa[] = {3,222,4,66,7};
    int arrSize = sizeof(aaa)/(sizeof(aaa[0]));
    exec(aaa,arrSize);
}

