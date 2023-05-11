#include <iostream>
using namespace std;


struct node{
        int data;
        node* left;
        node* right;
        int height;
};

node* root;

    void makeEmpty(node* t){
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node* singleRightRotate(node* &t)
	{
		if (t->left != NULL) {
			node* u = t->left;
			t->left = u->right;
			u->right = t;
			t->height = max(t->left->height, t->right->height) + 1;
			u->height = max(u->left->height, t->height) + 1;
			return u;
		}
		return t;
	}
	node* singleLeftRotate(node* &t)
	{
            if (t->right != NULL) {
		    node* u = t->right;
		    t->right = u->left;
		    u->left = t;
		    t->height = max(t->left->height, t->right->height) + 1;
		    u->height = max(t->right->height, t->height) + 1;
		    return u;
            }
            return t;
	}

    node* doubleLeftRotate(node* &t){
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t){
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* insert(int x, node* t){
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if( t->left->height - t->right->height == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(t->right->height - t->left->height == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }
        else if( x == t->data) return t;

        t->height = max(t->left->height, t->right->height)+1;
        return t;
    }

    node* findMin(node* t){
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t){
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
        node* temp;

        // Элемента нет
        if(t == NULL)
            return NULL;

        // Поиск элемента через рекурсию
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);

        
        // С 2мя листьями
        else if(t->left && t->right){
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }

        // С одним или без
        else{
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = max(t->left->height, t->right->height)+1;

        // Если несбалансировано
        // Правый случай
        if(t->left->height - t->right->height == -2)
        {
            // Право+право
            if(t->left->left->height - t->left->right->height == 1)
                return singleLeftRotate(t);
            // Право+лево
            else
                return doubleLeftRotate(t);
        }
        // Левый случай
        else if(t->right->height - t->left->height == 2)
        {
            // Лево+лево
            if(t->right->right->height - t->right->left->height == 1)
                return singleRightRotate(t);
            // Лево+право
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    void print(node* t)
    {
        /*if(t == NULL)
            return;*/
        print(t->left);
        cout << t->data << " ";
        print(t->right);
    }

    void display()
    {
        print(root);
        cout << endl;
    }

int main(){
    root = NULL;
    root = insert(1, root);
    /*root = insert(2, root);
    root = insert(8, root);
    root = insert(20, root);
    root = insert(14, root);*/
    display();
}