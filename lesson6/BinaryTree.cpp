#include <iostream>
#include <cstring>

struct node_t{
    node_t *left;
    node_t *right;
    node_t *parent;
};

struct binary_tree_t{
    node_t *root;
    size_t dataSize;
    size_t length;
    int (*compare)(void *, void *);
};

void TreeInit( binary_tree_t **tree, size_t dataSize, int (*compare)(void *, void *) ){
    (*tree) = static_cast<binary_tree_t*>(malloc( sizeof( binary_tree_t ) ) ) ;
    (*tree)->root = NULL;
    (*tree)->dataSize = dataSize;
    (*tree)->length = 0;
    (*tree)->compare = compare;
}

node_t *newNode( binary_tree_t **tree, void *data ){
    node_t *node = static_cast<node_t*>( malloc( sizeof(node_t) + (*tree)->dataSize ));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    memcpy( reinterpret_cast<void*>(node + 1), data, (*tree)->dataSize );
    return node;
}

void TreeAdd( binary_tree_t **tree, void *data ){
    node_t *node = newNode( tree, data );

    if( (*tree)->root == NULL ){
        (*tree)->root = node;
    }else{

        node_t *currentNode = (*tree)->root;
        while(1){
            int cmp = (*tree)->compare( reinterpret_cast<void*>(currentNode+1), data );

            if( cmp > 0 ){

                if( currentNode->right != NULL ){
                    currentNode = currentNode->right;
                    continue;
                }else{
                    currentNode->right = node;
                    node->parent = currentNode;
                    break;
                }

            }else if( cmp < 0 ){
                
                if( currentNode->left != NULL ){
                    currentNode = currentNode->left;
                    continue;
                }else{
                    currentNode->left = node;
                    node->parent = currentNode;
                    break;
                }
            }else{
                return;        
            }
        }
    }
    (*tree)->length++;
}

node_t *TreeFind( binary_tree_t **tree, void *data ){  //Поиск в дереве значения data, если такого нет, выводит NULL
    if( (*tree)->root == NULL ){
        return NULL;
    }
    node_t *currentNode = (*tree)->root;
    
    while(1){
        int cmp = (*tree)->compare( reinterpret_cast<void*>(currentNode+1), data );
        if ( cmp<0 ){
            if ( currentNode->left != NULL ){
            currentNode = currentNode->left;
            continue;   
            } 
            else return NULL;
        }else if ( cmp>0 ){
            if (currentNode->right != NULL){
            currentNode = currentNode->right;  
            continue;  
            } 
            else return NULL;
        }
        else{
            std::cout << "node is found" << std::endl;
            return currentNode;  
        }
    }
}

bool TreeNodeDelete( binary_tree_t **tree, void *data ){ //Удаление ноды,если такая существует и возвращение true(1), иначе false(0)
    if( (*tree)->root == NULL ){
        return false;
    }
    
    node_t *currentNode = TreeFind( tree, data );
    if ( currentNode == NULL ) return false;

    if ( currentNode->right == NULL && currentNode->left == NULL ){
        node_t *prev = currentNode->parent;
        delete currentNode;
        int cmp = (*tree)->compare( reinterpret_cast<void*>(prev+1), data );
        if ( cmp<0 ){
            prev->left = NULL;
            return true;
        }else{
            prev->right = NULL;
            return true;
        }   
    }   

    if ( currentNode->right != NULL && currentNode->left == NULL){
        node_t *prev = currentNode->parent;
        node_t *next = currentNode->right;
        delete currentNode;
        int cmp = (*tree)->compare( reinterpret_cast<void*>(prev+1), data );
        if ( cmp<0 ){
            prev->left = next;
            return true;
        }else{
            prev->right = next;
            return true;
        }   
    }  

    if ( currentNode->right == NULL && currentNode->left != NULL){
        node_t *prev = currentNode->parent;
        node_t *next = currentNode->left;
        delete currentNode;
        int cmp = (*tree)->compare( reinterpret_cast<void*>(prev+1), data );
        if ( cmp<0 ){
            prev->left = next;
            return true;
        }else{
            prev->right = next;
            return true;
        }   
    }
}


void integerPreOrder( node_t *root ){
    if( root == NULL )
        return;

    std::cout << *reinterpret_cast<int*>( root + 1 ) << std::endl;
    integerPreOrder( root->left );
    integerPreOrder( root->right );
}

int integerCompare( void* first, void* second ){
    return *static_cast<int*>(second) - *static_cast<int*>(first);
}

int main(){
    binary_tree_t *bin_tree;

    TreeInit( &bin_tree, sizeof(int), integerCompare );

    int value = 7;
    TreeAdd( &bin_tree, &value );
    
    value = 5;
    TreeAdd( &bin_tree, &value );

    value = 6;
    TreeAdd( &bin_tree, &value );

    value = 8;
    TreeAdd( &bin_tree, &value );

    value = 9;
    TreeAdd( &bin_tree, &value );

    integerPreOrder( bin_tree->root );

    int val = 9;
    TreeFind( &bin_tree, &val);

    int data = 3;
    bool check_if_deleted = TreeNodeDelete( &bin_tree, &data );

    integerPreOrder( bin_tree->root );
    std::cout << check_if_deleted;
}