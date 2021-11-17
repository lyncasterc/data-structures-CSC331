#ifndef BSTree_H
#define BSTree_H
#include <iostream>


template<typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template<typename T>
class BSTree
{
    private:
        Node<T> *root;
        void destroy(Node<T> *&);
        void preOrder(Node<T> *) const;
        void postOrder(Node<T> *) const;
        void inOrder(Node<T> *) const;
    public:
        BSTree();
        void copy (Node<T> *&, Node<T> *);
        BSTree(const BSTree<T> &);
        const BSTree<T> & operator= (const BSTree<T> &);
        bool isEmpty() const;
        void insertItem (const T &item);  
        void deleteItem (const T &item);
        void deleteItem (Node<T> *&, const T &item);
        void deleteNode (Node<T> *&);
        bool searchItem (const T &item) const;
        void preOrder () const;
        void inOrder() const;
        void postOrder() const;
        void destroy();
        ~BSTree();
};


template<typename T>
BSTree<T>::BSTree()
{
    root = NULL;
}

template<typename T>
void BSTree<T>::copy(Node<T> *&this_root, Node<T> *other_root)
{
    if(!other_root)
    {
        this_root = NULL;
    }

    else
    {
        this_root = new Node<T>;
        this_root->data = other_root->data;
        copy(this_root->left, other_root->left);
        copy(this_root->right, other_root->right);
    }
}

template <typename T>
BSTree<T>::BSTree(const BSTree<T> &other)
{
    copy(root, other.root);
}

template <typename T>
const BSTree<T> & BSTree<T>::operator= (const BSTree<T> & other)
{
    if(this != &other)
    {
        if(root)
        {
            destroy(root);
        }

        if(!other.root)
        {
            root = NULL;
        }

        else
        {
            copy(root, other.root);
        }
    }

    return *this;
}


template<typename T>
void BSTree<T>::postOrder() const
{
    postOrder(root);
}

template<typename T>
void BSTree<T>::inOrder() const
{
    inOrder(root);
}

template<typename T>
void BSTree<T>::preOrder() const
{
    preOrder(root);
}


template<typename T>
void BSTree<T>::postOrder(Node<T> *node) const
{

    if(node)
    {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }
}

template<typename T>
void BSTree<T>::inOrder(Node<T> *node) const
{

    if(node)
    {
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
}

template<typename T>
void BSTree<T>::preOrder(Node<T> *node) const
{

    if(node)
    {
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

template<typename T>
bool BSTree<T>::isEmpty() const
{
    return root == NULL;
}

template<typename T>
bool BSTree<T>::searchItem(const T &item) const
{
    Node<T> *node;
    node = root;

    while(node)
    {
        if(node->data == item)
        {
            return true;
        }

        else if(item < node->data)
        {
            node = node->left;
        }

        else
        {
            node = node->right;
        }
    }

    return false;
}

template<typename T>
void BSTree<T>::insertItem(const T &item)
{
    Node<T> *node;
    Node<T> *prev_node;
    Node<T> *temp;
    
    temp = new Node<T>;
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    if(!root)
    {
        root = temp;
    }
    else
    {
        node = root;

        while(node)
        {
            prev_node = node;

            if(node->data == item)
            {
                std::cout << "ERROR: Duplicates not allowed\n";
                delete temp;
                return;
            }

            else if(item < node->data)
            {
                node = node->left;
            }

            else
            {
                node = node->right;
            }
        }

        if(item < prev_node->data)
        {
            prev_node->left = temp;
        }

        else
        {
            prev_node->right = temp;
        }
    }
}


template<typename T>
void BSTree<T>::deleteNode(Node<T> *&node)
{
    Node<T> *q;

    q = node;

    if (node->left == NULL )
    {
        node = node->right;
        delete q;

    }
    else if (node->right == NULL )
    {
        node = node->left;
        delete q;
    }
    else 
    {
        q = node->left;
        Node<T> *trail = NULL;

        while (q->right != NULL)
        {
            trail = q;
            q = q->right;
        }

        node->data = q->data;

        if (trail == NULL )
            node->left = q->left;
        else
            trail->right = q->left;

        delete q;      
    }
}

template<typename T>
void BSTree<T>::deleteItem(Node<T> *&node, const T &item)
{
    if(!node)
    {
        std::cout << "ERROR: Item does not exist";
    }
    
    else if(item > node->data)
    {
        deleteItem(node->right, item);
    }

    else if(item < node->data)
    {
        deleteItem(node->left, item);
    }

    else
    {
        deleteNode(node);
    }
}

template<typename T>
void BSTree<T>::deleteItem(const T &item)
{
    deleteItem(root, item);
}


template<typename T>
void BSTree<T>::destroy(Node<T> *& node)
{
    if(node)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
        node = NULL;
    }
}

template<typename T>
void BSTree<T>::destroy()
{
    destroy(root);
}

template<typename T>
BSTree<T>::~BSTree()
{
    destroy(root);
}

#endif