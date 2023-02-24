#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int item)
{
    struct TreeNode* temp = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

struct TreeNode* insert(struct TreeNode* node, int val)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(val);
 
    // Otherwise, recur down the tree
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
 
    // Return the (unchanged) node pointer
    return node;
}

void inorder(struct TreeNode *root, int *array, int *i)
{
    if(root!=NULL)
    {
        inorder(root->left, array, i);
        array[*i] = root->val;
        (*i)++;
        inorder(root->right, array, i);
    }
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int returnSize)
{
    int temp;
    int i=0;
    int* array = (int*)malloc(sizeof(int)*(returnSize));
    inorder(root1, array, &i);
    inorder(root2, array, &i);
    for(int i=0; i<returnSize-1; i++)
    {
        for(int k=0; k<returnSize-j-1; k++)
        {
            if(array[i]<array[k])
            {
                temp = array[i];
                array[i] = array[k];
                array[k] = temp;
            }
        }
    }
    for(int j=0; j<returnSize; j++)
    {
        printf("%d ", array[j]);
    }
    printf("%d", array[j]);
}

int main(){
    struct TreeNode* arr1= NULL;
    struct TreeNode* arr2= NULL;
    int* ret;

    int n1=0;
    int n2=0;
    
    scanf("%d",&n1);
    int temp = 0;
    for(int i=0;i<n1;i++){
        scanf("%d",&temp);
        if(temp==-1)
        {
             arr1 = insert(arr1,NULL);
        }
        else
        {
             arr1 = insert(arr1,temp);
        }
    }
    scanf("%d",&n2);
    temp = 0;
    for(int i=0;i<n2;i++){
        scanf("%d",&temp);
      if(temp==-1)
        {
             arr2 = insert(arr2,NULL);
        }
        else
        {
             arr2 = insert(arr2,temp);
        }
    }
    getAllElements(arr1,arr2,n1+n2);
}