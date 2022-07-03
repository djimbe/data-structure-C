#include <stdio.h>
#include <stdlib.h>


struct node{
    int val;
    struct node* left;
    struct node* right;
};

struct node* new_node(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val= val;
    temp->left = NULL;
    temp->right =NULL;
    return temp;
}

struct node* insert(struct node* root,int val){
    if(root == NULL){
        return new_node(val);
    }else if(root<root->val){
        root->left = insert(root->left,val)
    }else if(root> root->val){
        root->right=insert(root->right,val)
    }
}

voide search_node(struct node* root, int val){
    if(root == NULL){
        printf("Not found");
    }
    if(root->val == val){
        printf("Data Found");
    }
    else if(root->val>val){
        search_node(root->left,val)
    }else{
        search_node(root->right,val)
    }
}

struct node* root = NULL;

int main()
{

/* some example codes to insert and search
    root = insert(root,1);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,2);

    search_node(root,5);
    search_node(root,3);
*/

}
