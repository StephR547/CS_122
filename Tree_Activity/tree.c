#include "tree.h"
void create_root(tree **root, int element){    
    if (*root != NULL){        
        printf("Root has already been created, preventing operation\n");
    }else{        
        *root = malloc(sizeof(tree));        
        (*root)->element = element;        
        (*root)->parent = NULL;        
        (*root)->left = NULL;        
        (*root)->right = NULL;    
    }
}
void set_left(tree *node, int element){    
    if (node == NULL){        
        printf("Node is NULL, operation prevented\n");    
    }else{        
        if (node->left != NULL){            
            // Element already exists, overwriting            
            node->left->element = element;        
        }else{            
            tree *new_node = NULL;            
            // Quick way to set up a node            
            create_root(&new_node, element);            
            new_node->parent = node;            
            node->left = new_node;        
        }    
    }

}
void set_right(tree *node, int element){    
    if (node == NULL){        
        printf("Node is NULL, operation prevented\n");    
    }else{        
        if (node->right != NULL){            
            node->right->element = element;        
        }else{            
            tree *new_node = NULL;            
            create_root(&new_node, element);            
            new_node->parent = node;            
            node->right = new_node;        
        }    
    }
}
void set_left_tree(tree *parent_node, tree *child_node){    
    if (parent_node == NULL){        
        printf("Parent is NULL, operation not performed\n");    
    }else if (parent_node->left != NULL){        
        printf("Parent already has a left subtree, operation prevented\n");    
    }else if (child_node == NULL){        
        printf("Child node is NULL, operation not performed\n");    
    }else{        
        parent_node->left = child_node;        
        child_node->parent = parent_node;    
    }
}
void set_right_tree(tree *parent_node, tree *child_node){    
    if (parent_node == NULL){        
        printf("Parent is NULL, operation not performed\n");    
    }else if(parent_node->right != NULL){        
        printf("Parent already has a right subtree, operation not performed\n");    
    }else if (child_node == NULL){        
        printf("Child node is NULL, operation not performed\n");    
    }else{        
        parent_node->right = child_node;        
        child_node->parent = parent_node;    
    }
}
tree *go_up(tree *node){    
    if (node == NULL){        
        printf("Node is NULL, prevented\n");    
    }    
    if (node->parent == NULL){        
        printf("Node has no parent, operation prevented\n");    
    }else{        
        return node->parent;    
    }  
    return node;
}
tree *go_left(tree *node){    
    if (node == NULL){        
        printf("Node is NULL, prevented\n");    
    }else if (node->left == NULL){        
        printf("Node has no left, operation prevented\n");    
    }else{        
        return node->left;    
    }    
    return node;
}
tree *go_right(tree *node){    
    if (node == NULL){        
        printf("Node is NULL, prevented\n");    
    }else if (node->right == NULL){        
        printf("Node has no right, prevented\n");    
    }else{        
        return node->right;    
    }    
    return node;
}

void preorder(tree *node){    
    if (node != NULL){        
        printf("%d\n", node->element);        
        preorder(node->left);        
        preorder(node->right);    
    }
}
void inorder(tree *node){    
    if (node != NULL){        
        inorder(node->left);        
        printf("%d\n", node->element);        
        inorder(node->right);    
    }
}
void postorder(tree *node){    
    if (node != NULL){        
        postorder(node->left);        
        postorder(node->right);        
        printf("%d\n", node->element);    
    }
}
void delete_sub_tree(tree **node){    
    if (*node == NULL){        
        return;    
    }else if ((*node)->left != NULL){        
        delete_sub_tree(&((*node)->left));     
    }else if ((*node)->right != NULL){        
        delete_sub_tree(&((*node)->right));    
    }    
    free(*node);    
    *node = NULL; 
}