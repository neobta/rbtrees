
//
// Created by neobta on 6/7/15.
//

#ifndef REDBLACKTREESDEMO_REDBLACKTREEITEM_H
#define REDBLACKTREESDEMO_REDBLACKTREEITEM_H

#include <memory>

namespace redBlackTrees {

    template<typename T>



    class redBlackTree {





        enum red_black_tree_color {
            BLACK, RED
        };

    private:

        class redBlackTreeNode {
            red_black_tree_color color;
            T value;


        public:

            //typedef std::shared_ptr<redBlackTrees::redBlackTree<T>::redBlackTreeNode> node_ptr;


            redBlackTreeNode(T i);
            ~redBlackTreeNode();


            void assign_left(std::shared_ptr<redBlackTreeNode> item);
            void assign_right(std::shared_ptr<redBlackTreeNode> item);

            const T& getValue();
            std::shared_ptr<redBlackTreeNode> left;
            std::shared_ptr<redBlackTreeNode> right;
            std::weak_ptr<redBlackTreeNode> parent;

            void print_in_order();
            void print_pre_order();
            void print_post_order();
            void print_node_value();



        };

        std::shared_ptr<redBlackTreeNode> root;
        void left_rotate(std::shared_ptr<redBlackTreeNode> node);

        auto find(std::shared_ptr<redBlackTreeNode> current_node, T item) -> decltype(current_node);

        /*void insert_fix_up(redBlackTree &newItem);*/


    public:

        redBlackTree();

        ~redBlackTree();

        bool is_root_null();
        void insert(T n);
        void print_in_order();
        void print_pre_order();
        void print_post_order();

        void test_rotate(T item);


        /*


        redBlackTree* right_rotate();


        int get_value();






        void assign_node_as_red();
        void assing_node_as_black();
        redBlackTree* get_root();*/
    };
}

/*************************************/
/* Node Methods */
/*************************************/
template<typename T>
redBlackTrees::redBlackTree<T>::redBlackTreeNode::redBlackTreeNode(T i) : value(i), left(), right(), parent(),
                                                                          color(RED) { }

template<typename T>
redBlackTrees::redBlackTree<T>::redBlackTreeNode::~redBlackTreeNode() {
    std::cout << "destroying Node :" << value << std::endl;
}


template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::assign_left(std::shared_ptr<redBlackTreeNode> item) {
    if (left != nullptr) {
        std::cout << "Es diferente de null" << std::endl;
        std::cout << "haciendo left->parent = nulo" << std::endl;
        left->parent = std::shared_ptr<redBlackTreeNode>();

        std::cout << "Clean up done" << std::endl;
    }
    else {
        std::cout << "Left is null ptr" << std::endl;
    }
    std::cout << "escribiendo left = item " << std::endl;
    left = item;
    std::cout << "asignacion left terminada" << std::endl;
}


template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::assign_right(std::shared_ptr<redBlackTreeNode> item) {
    if (right != nullptr) {
        std::cout << "already had a value on right" << std::endl;
        std::cout << "asigning left->parent = nullptr" << std::endl;
        right->parent = std::shared_ptr<redBlackTreeNode>();

        std::cout << "Clean up done" << std::endl;
    }
    else {
        std::cout << "right is null ptr" << std::endl;
    }
    std::cout << "assigning right = item " << std::endl;
    right = item;
    std::cout << "assign right done" << std::endl;
}

template<typename T>
const T&  redBlackTrees::redBlackTree<T>::redBlackTreeNode::getValue()
{
    return value;
}


template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::print_in_order()
{
    if (this->left!= nullptr)
        left->print_in_order();

    this->print_node_value();

    if (this->right!= nullptr)
        right->print_node_value();
}


template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::print_pre_order()
{

    this->print_node_value();
    if (this->left!= nullptr)
        left->print_in_order();

    if (this->right!= nullptr)
        right->print_node_value();
}


template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::print_post_order()
{

    this->print_node_value();
    if (this->left!= nullptr)
        left->print_in_order();

    if (this->right!= nullptr)
        right->print_node_value();
}

template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::print_node_value()
{
    std::cout << value << std::endl;
}




/*************************************/
/* Tree Implementation */
/*************************************/

template<typename T>
redBlackTrees::redBlackTree<T>::redBlackTree(){

    root = std::shared_ptr<redBlackTreeNode>();
}

template<typename T>
redBlackTrees::redBlackTree<T>::~redBlackTree() {

    root = std::shared_ptr<redBlackTreeNode>();

    std::cout << "destroying tree " << std::endl;
}

template<typename T>
bool redBlackTrees::redBlackTree<T>::is_root_null() {
    return root == nullptr;
}


template<typename  T>
void redBlackTrees::redBlackTree<T>::insert(T n) {
    if (is_root_null())
    {
        root= std::make_shared<redBlackTreeNode>(n);
    }
    else
    {
        bool assigned=false;
        auto currentNode = root;
        while (!assigned)
        {
            if (currentNode->getValue()>n)
            {
                if (currentNode->left == nullptr)
                {
                    std::cout << "current node : "<<  currentNode->getValue() << " -> left is null ptr " << std::endl;
                    currentNode->assign_left(std::make_shared<redBlackTreeNode>(n));
                    std::cout << "assign node left " << std::endl;
                    assigned = true;
                }
                else
                {
                    currentNode = currentNode->left;
                }
            }
            else if (currentNode->getValue()==n)
            {
                std::cout << "key already in the tree" <<std::endl;
                assigned=true;
            }
            else
            {
                if (currentNode->right== nullptr)
                {
                    std::cout << "current node : " << currentNode->getValue()<< " right is nullprt" <<std::endl;
                    currentNode->assign_right(std::make_shared<redBlackTreeNode>(n));
                    std::cout << "assign node right" <<std::endl;
                    assigned=true;
                }
                else
                {
                    currentNode = currentNode->right;
                }

            }


        }

    }
}

template<typename  T>
void redBlackTrees::redBlackTree<T>::print_in_order()
{
    root->print_in_order();
}

template<typename  T>
void redBlackTrees::redBlackTree<T>::print_pre_order()
{
    root->print_pre_order();
}

template<typename  T>
void redBlackTrees::redBlackTree<T>::print_post_order()
{
    root->print_post_order();
}

template<typename T>
void redBlackTrees::redBlackTree<T>::left_rotate(std::shared_ptr<redBlackTreeNode> node){
    if (node->right== nullptr)
    {
        std::cout <<"cannot be rotate nothing in the right to be transplanted" << std::endl;
        return;
    }
    std::shared_ptr<redBlackTreeNode> p = node->parent.lock();
    std::shared_ptr<redBlackTreeNode> r = node->right;
    std::shared_ptr<redBlackTreeNode> rl = r->left;


    if (p== nullptr) {
        std::cout << "Parent is null we are rotating root, so we need to change the root with the node on the right"<<std::endl;
        this->root = r;
    }
    else
    {


        if (p->left == node)
        {
            p->assign_left(r);
        }
        else
        {
            p->assign_right(r);
        }
    }


    r->assign_left(node);
    node->assign_right((rl));


}




template<typename T>
auto
redBlackTrees::redBlackTree<T>::find(std::shared_ptr<redBlackTrees::redBlackTree<T>::redBlackTreeNode> current_node, T item)
-> decltype(current_node)
{


    //return root;
   if (current_node->getValue()==item)
        return current_node;
    else
    {
        if (current_node->getValue()>item) {

            if (current_node->left == nullptr)
                return std::shared_ptr<redBlackTrees::redBlackTree<T>::redBlackTreeNode>(); //not found

            return find(current_node->left, item);
        }
        else {
            if (current_node->right== nullptr)
                return std::shared_ptr<redBlackTrees::redBlackTree<T>::redBlackTreeNode>(); //not found
            return find(current_node->right, item);
        }
    }
}

template<typename T>
void redBlackTrees::redBlackTree<T>::test_rotate(T item)
{
     std::shared_ptr<redBlackTrees::redBlackTree<T>::redBlackTreeNode> node =find(root, item);


    std::cout << "se encontrol el node" << std::endl;

    if (node== nullptr)
        std::cout << "el node es nulo" <<std::endl;

    else
    {
        std::cout << "node value : " << node->getValue() << std::endl;
    }
}

#endif //REDBLACKTREESDEMO_REDBLACKTREEITEM_H


