/*
 * main.c
 *
 *  Created on: Aug 8, 2018
 *      Author: karl
 */
#include "stdio.h"

// https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem


struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
int max = 0;
void count(struct node* root, int level) {
    if (max < level) max = level;
    if (root->left != NULL)
        count(root->left, level+1);
    if (root->right != NULL)
        count(root->right, level+1);
}
int getHeight(struct node* root) {
    count(root, 0);
    return max;
    // Write your code here
}
