#include <iostream>
#include "redBlackTree.hh"

using namespace std;
using namespace redBlackTrees;




void test_one (){
    cout << "creando root" << endl;
    redBlackTree<int> tree{};

    cout << "tree created" << endl;

    cout << "Is root null? :" << tree.is_root_null() << std::endl;

    tree.insert(1);
    tree.insert(3);
    tree.insert(2);
    tree.insert(5);
    tree.insert(4);

    tree.print_in_order();

    tree.test_rotate(3);

/*

    root->print_in_order();


    cout << "Antes de rotar  a la izquierda vamos a ver cual es el root : " << root->get_value() <<endl;

    root = root->left_rotate();


    cout << "Rotado a la izquierda Correcto " << endl;
    cout << "El valor de root es : " << root->get_value() << endl;

    cout << "trata de rotar a la izquierda sin nada a la derecha " << endl;
    root = root ->left_rotate();
    cout << "no fallo y debio haber resgresaod el mismo root " << endl;

    root->print_in_order();


    root = root->right_rotate();


    cout << "Rotado a la derecha Correcto " << endl;
    cout << "El valor de root es : " << root->get_value() << endl;



    root = root->right_rotate();


    cout << "Rotado a la derecha Correcto " << endl;
    cout << "El valor de root es : " << root->get_value() << endl;



    root = root->right_rotate();


    cout << "Rotado a la derecha Correcto sin nada a la izquierda " << endl;
    cout << "El valor de root es : " << root->get_value() << endl;




    cout << "Impreso correcto" << endl;*/

}

int main() {
    test_one();
    /*cout << "Iniciando insert con fixup " << endl;

    cout <<"Creando root " << endl;

    redBlackTree *root= new redBlackTree(1);


    root->insert(*(new redBlackTree(2)));
    root->insert(*(new redBlackTree(3)));



    cout << "obteniendo nuevo root :" <<endl;
    cout << "Root original " << root->get_value() << endl;
    root =root->get_root();
    cout << "Nuevo Root :" << root->get_value() << endl;

    root->print_pre_order();

    root = root->insert(*(new redBlackTree(7)));
    root = root->insert(*(new redBlackTree(9)));
    root = root->insert(*(new redBlackTree(10)));
    root = root->insert(*(new redBlackTree(11)));
    root = root->insert(*(new redBlackTree(13)));



    cout << "obteniendo nuevo root :" <<endl;
    cout << "Root original " << root->get_value() << endl;
    root =root->get_root();
    cout << "Nuevo Root :" << root->get_value() << endl;

    root->print_pre_order();

*/

/*
    cout << "Test de asignación y reasignación " << endl;

    redBlackTree *three = new redBlackTree(3);
    redBlackTree *two = new redBlackTree(2);
    root->assign_right(*three);
    three->assign_left(*two);

    cout << "rotando " << endl;
    three->right_rotate();
    //root->insert(*(new redBlackTree(3)));
    //root->insert(*(new redBlackTree(2)));
    root->print_pre_order();*/



    return 0;

}