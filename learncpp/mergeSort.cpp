//
//  mergeSort.cpp
//  learncpp
//
//  Created by 常庆林 on 2018/5/1.
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
//归并排序
//知识点：每次把数组分解成两个，递归分解成最小后排序，最后在合并。
// 时间复杂度为o(n)

void merge(int A[],int p,int q,int r){
    int n1 = q-p+1; // 左侧数组元素数量 + 1
    int n2 = r-q; // 右侧数组元素数量 + 1
    int L[n1+1];
    int R[n2+1];
    for (int i = 0; i<n1; i++) {
        L[i] = A[p+i];
    }
    for (int i = 0; i<n2; i++) {
        R[i] = A[q+i+1];
    }
    L[n1] = 999; //∞ 无穷大的值
    R[n2] = 999;
    
    int i = 0;
    int j = 0;
    
    for (int k =p; k<=r; k++) {
        if(L[i]<R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
    
}
void recur(int A[],int p ,int r){
    if(p<r){
        int q =  floor((p+r)/2);
        recur(A,p,q);
        recur(A,q+1,r);
        merge(A,p,q,r);
    }
    
}
void exec(int A[],int size){
    recur(A,0,size-1);
    print(A, size);
}

void mergeSort(){
    int aaa[] = {222};
    int arrSize = sizeof(aaa)/(sizeof(aaa[0]));
    exec(aaa,arrSize);
}


