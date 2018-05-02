//
//  countSort.cpp
//  learncpp
//
//  Created by 常庆林 on 2018/5/3.
//  Copyright © 2018年 常庆林. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "math.h"
using namespace std;

static void exec(int A[],int size);
static void print(int A[],int size);
static void qSort(int A[],int size);
static int partition(int A[],int p,int r);

void print(int A[],int size){
    for (int i = 0; i<size; i++) {
        cout<<A[i]<<endl;
    }
    cout<<"----------"<<endl;
    //    cout<<"the size of array:" << size <<endl;
}
//计数排序
//知识点：C[]用来计数
// 时间复杂度为o(n)

void exec(int A[],int size){
    int k = 200;
    int C[k];
    for (int i=0;i<=k;i++){
        C[i] = 0;
    }
    for(int j = 0;j<size;j++){
        C[A[j]] = C[A[j]]+1;
    }
    for (int i=0;i<=k;i++){
        C[i] = C[i] +C[i-1];
    }
    int B[size];
    
    for(int j = size-1;j>=0;j--){
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]]-1;
    }
    
    print(B, size);
}

void countSort(){
    int aaa[] = {3,22,44,55,66,33,44};
    int arrSize = sizeof(aaa)/(sizeof(aaa[0]));
    exec(aaa,arrSize);
}


