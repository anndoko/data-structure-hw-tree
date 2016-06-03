//
//  main.cpp
//  Tree
//
//  Created by Yu-An Ko on 2016/6/1.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//
#include "oopTree.hpp"
#include <iostream>

int main() {
    
    int i;
    
    //  30% credit
    CompleteBinaryTree cbt(8);  // build a new tree cbt
    for(i = 0; i < 8; i++){     // insert numbers 0~7
        cbt.Insert(i);
    }
    cbt.inorder();  // do inorder traversal
    
    // 30% credit
    int d[8] = {3, 7, 11, 6, 37, 28, 1, 4};    // an input array
    BST bst;
    for(i = 0; i < 8; i++){
        bst.Insert(d[i]);   // insert the input array
    }
    bst.inorder();  // do inorder traversal

    
    // 40% credit
    MaxHeap mh(8); int x;       // build a new max heap mh
    for(i = 0; i < 8; i++){    // insert numbers 0~7
        mh.Insert(i);
    }
    mh.inorder();   // do inorder traversal
    
    cout << "MaxHeap DeleteMax" <<endl;
    for(i = 0; i < 8; i++){
        cout<< *mh.DeleteMax(x) <<" "; // print the deleted keys
    }
    
    //  10%

    return 0;
}
