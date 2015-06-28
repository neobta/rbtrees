//
// Created by neobta on 6/7/15.
//

#include <iostream>
#include "redBlackTree.hh"


using namespace std;
using namespace redBlackTrees;

//redBlackTree::redBlackTree(int i): value(i), left(nullptr), right(nullptr), parent(nullptr), color(RED) { }
/*

void redBlackTree::assign_left(redBlackTree &l) {

    if (left != nullptr) {


        left->parent = nullptr;

    }

    if (&l == nullptr)
        left = nullptr;
    else {
        //remove old parent

        if (l.parent != nullptr) {
            if (l.parent->left == &l) {
                l.parent->left = nullptr;
            } else {
                l.parent->right = nullptr;
            }
        }

        left = &l;
        l.parent = this;
    }
}



void redBlackTree::assign_right(redBlackTree &r) {

    if (right != nullptr) {
        right->parent = nullptr;
    }

    if (&r == nullptr)
        right = nullptr;
    else
    {
        //remove old parent


        if (r.parent != nullptr)
        {

            if(r.parent->left == &r)
            {
                r.parent->left= nullptr;
            }else
            {
                r.parent->right= nullptr;
            }
        }

        right = &r;
        r.parent=this;
    }
}


redBlackTree *redBlackTree::left_rotate() {

    if (right== nullptr)
    {
        cout << "No se puede rotar ya que no hay nada a la derecha" << endl;
        return this;
    }

    redBlackTree *p = (*this).parent;
    redBlackTree *r = (*this).right;
    redBlackTree *rl = r->left;


    if (p==nullptr)
    {
        cout << "es nulo el parent" <<endl;
        p = r;
    }
    else{
        if (p->left == this)
        {
            p->assign_left(*r);
        }
        else
        {
            p->assign_right(*r);
        }
    }

    if (r != nullptr)
        r->assign_left(*this);
    this->assign_right(*rl);


    return p;
}

redBlackTree *redBlackTree::right_rotate() {

    if (left== nullptr)
    {
        cout << "No se puede rotar ya que no hay nada a la izquierda" << endl;
        return this;
    }

    redBlackTree *p = (*this).parent;
    redBlackTree &l = *(*this).left;
    redBlackTree &lr= *l.right;



    if (p==nullptr)
    {
        cout << "es nulo el parent, la rotaci�n es en el root" <<endl;
        p = &l;
    }
    else{
        if (p->left == this)
        {
            p->assign_left(l);
        }
        else
        {
            p->assign_right(l);
        }
    }

    l.assign_right(*this);
    this->assign_left(lr);



    return p;

}


redBlackTree* redBlackTree::insert(redBlackTree &newItem) {
    redBlackTree *y = nullptr;
    if (newItem.value < this->value )
    {
        if (this->left != nullptr) {
            //insert into the left node
            return this->left->insert(newItem);
        }
        else{
            assign_left(newItem);
            newItem.left = nullptr;
            newItem.right = nullptr;
            newItem.color=RED;
            insert_fix_up(newItem);
            return this->get_root();

        }
    }
    else
    {
        if (this->right != nullptr) {
            return this->right-> insert(newItem);
        }
        else
        {
            assign_right(newItem);
            newItem.left = nullptr;
            newItem.right = nullptr;
            newItem.color=RED;
            insert_fix_up(newItem);
            return this->get_root();
        }
    }


}

redBlackTree* redBlackTree::get_root(){
    if (this->parent== nullptr)
        return this;
    else
        return this->parent->get_root();

}

void redBlackTree::insert_fix_up(redBlackTree &newItem) {
    redBlackTree* z = &newItem;
    redBlackTree* y = nullptr;
    while (z->parent != nullptr && z->parent->color==RED)
    {
        if (z->parent->parent == nullptr) //two levels left, there is nothing more to do
            break;

        if (z->parent== z->parent->parent->left )
        {

            y = z->parent->parent->right;

            if (y != nullptr && y->color == RED) //RED uncle
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z= z->parent->parent;
            }
            else {
                if(z==z->parent->right) {
                    z=z->parent;
                    z->left_rotate();
                }
                z->parent->color = BLACK;
                if (z->parent->parent != nullptr)
                {
                    z->parent->parent->color = RED;
                    z->parent->parent->right_rotate();
                }
            }
        }

        else
        {

            y = z->parent->parent->left;

            if (y != nullptr && y->color == RED) //RED uncle
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z= z->parent->parent;
            }
            else {
                if(z==z->parent->left) {
                    z=z->parent;
                    z->right_rotate();
                }
                z->parent->color = BLACK;
                if (z->parent->parent != nullptr)
                {
                    z->parent->parent->color = RED;
                    z->parent->parent->left_rotate();
                }
            }

        }



    }

    //set root color
    this->get_root()->color=BLACK;
}

void redBlackTree::print_in_order() {
    if (left != nullptr)
        this->left->print_in_order();
    cout << "Value : " << this->value << " Color :" << this->color<< endl;
    if (right!= nullptr)
        this->right->print_in_order();

}

void redBlackTree::print_pre_order() {
    cout << "Value : " << this ->value << " color : " << this->color<< endl;
    if (left != nullptr) {
        cout << "left of " << this->value << endl;
        this->left->print_pre_order();
    }

    if (right!= nullptr) {
        cout << "right of " << this->value << endl;
        right->print_pre_order();
    }


}

void redBlackTree::print_post_order() {



    if (left != nullptr)
        left->print_post_order();

    if (right != nullptr)
        right->print_post_order();

    cout << "Value : " << this->value << " Color : " << this->color<< endl;

}


int redBlackTree::get_value() {
    return value;
}


void redBlackTree::assign_node_as_red() {
color=RED;
}

void redBlackTree::assing_node_as_black() {
color =BLACK;
}
*/
