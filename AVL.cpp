#include<bits/stdc++.h>
using namespace std; 


class Node{
    public : 
    int height,key;
    Node* right, *left;
    Node(int val){
        key = val;
        this->right = NULL; 
        this->left = NULL;
        this->height = 1; 
    } 

};


int height(Node* root){
    if(root == NULL){
        return 0;
    }

    return root->height;
}



int balance(Node* root){
    return height(root->left) - height(root->right);
}



void rightRotate(Node* &root){
    Node* y = root->left; 
    Node* T2 = y->right; 
    y->right = root; 
    root->left = T2; 
    root = y; 
    root->height = height(root); 
    y->height = height(y); 
}

void leftRotate(Node* &root){
    Node* y = root->right; 
    Node* T2 = y->left; 
    y->left = root; 
    root->right = T2; 
    root = y; 
    root->height = height(root); 
    y->height = height(y);  
}


void preorder(Node* root){
    if(root == NULL){
        return; 
    }
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right); 
   
}




void insert(int key, Node* &root){
    if(root == NULL){
        root = new Node(key);
        return;
    }

    else if(key < root->key){
        insert(key,root->left); 
    }

    else if(key > root->key){
        insert(key,root->right);
    }

    root->height= max(height(root->left),height(root->right)) + 1;

    int bal = balance(root);
    if(bal>1 && key<root->left->key){
        rightRotate(root); 
    }
    else if(bal<-1 && key>root->right->key){
        leftRotate(root); 
    }

    else if(bal>1 && key>root->left->key){
        leftRotate(root->left); 
        rightRotate(root); 
    }

    else if(bal<-1 && key<root->right->key){
        rightRotate(root->right); 
        leftRotate(root);
    }



}

int main(){
    Node* root = NULL; 
    insert(10,root); 
    insert(20,root); 
    insert(30,root); 
    insert(40,root); 
    insert(50,root); 
    insert(25,root); 
    preorder(root);

}
