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

sturct node* delete_node(struct node* root,int val){
    if(root == NULL) return NULL;
    else if(val> root->val){
        root->right = delete_node(root->right,val);
    }else if(val< root->val){
        root->left = delete_node(root->left,val);
    }else if (val == root->val){

        //if the node has no children
        if(root->left == NULL && root->right== NULL){
            free(root);
            root = NULL;
        }



        //if the node has one children
        //left child
        else if(root->left != NULL && root->right== NULL){
            struct node* temp = root->left;
            *root = *temp;
            free(temp);
        }
        //right child
         else if(root->left == NULL && root->right!= NULL){
            struct node* temp = root->right;
            *root = *temp;
            free(temp);
        }

        //if the node has two children
        else if(root->left != NULL && root->right!= NULL){
            struct node* temp;
            temp = root->left;
            while(temp->right !=NULL)
                temp = temp->right;
            root->val = temp->val;
            root->left = delete_node(root->left, temp->val);
        }

        return root;

    }
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

    delete_node(root,2);
*/

}
