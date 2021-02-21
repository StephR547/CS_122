#include <stdio.h>
#include <stdlib.h>

typedef struct tree{    
    struct tree *parent;    
    int element;    
    struct tree *left;    
    struct tree *right;
}tree;

void create_root(tree **root, int element);
void set_left(tree *node, int element);
void set_right(tree *node, int element);
void set_left_tree(tree *parent_node, tree *child_node);
void set_right_tree(tree *parent_node, tree *child_node);

tree *go_up(tree *node);
tree *go_left(tree *node);
tree *go_right(tree *node);

void preorder(tree *node);
void inorder(tree *node);
void postorder(tree *node);

void delete_sub_tree(tree **node);