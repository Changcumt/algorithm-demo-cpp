//
//  quickSort.cpp
//  learncpp
//
//  Created by 常庆林 on 2018/5/3.
//  Copyright © 2018年 常庆林. All rights reserved.
//

#include <stdio.h>

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
//快速排序
//知识点：找一个主元用来区分两个区域边界，大于主元的是一组 小于等于主元的是一组，每次迭代重排数组
// 时间复杂度为o(n)
int partition(int A[],int p,int r){
    int mainKey = A[r];
    int i = p - 1;
    for(int j = p;j<=r-1;j++){
        if(A[j]<=mainKey){
            i = i+1;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i+1;
}

void qSort(int A[],int p,int r){
    if(p<r){
        int q = partition(A,p,r);
        qSort(A,p,q-1);
        qSort(A,q,r);
    }
}
void exec(int A[],int size){
    qSort(A,0,size-1);
    print(A, size);
}

void quickSort(){
    int aaa[] = {3,222,4,66,7,990,2};
    int arrSize = sizeof(aaa)/(sizeof(aaa[0]));
    exec(aaa,arrSize);
}

