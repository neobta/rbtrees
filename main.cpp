#include <iostream>
#include "redBlackTreeItem.hh"

using namespace std;
using namespace redBlackTrees;




void test_one (){
    cout << "creando root" << endl;
    redBlackTreeItem* root  = new redBlackTreeItem(4);
    cout << "root creado" << endl;
    root->assign_left(*(new redBlackTreeItem(3)));
    root->assign_right(*(new redBlackTreeItem(5)));



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




    cout << "Impreso correcto" << endl;

}

int main() {
    cout << "Iniciando insert con fixup " << endl;

    cout <<"Creando root " << endl;

    redBlackTreeItem *root= new redBlackTreeItem(1);


    root->insert(*(new redBlackTreeItem(2)));
    root->insert(*(new redBlackTreeItem(3)));



    cout << "obteniendo nuevo root :" <<endl;
    cout << "Root original " << root->get_value() << endl;
    root =root->get_root();
    cout << "Nuevo Root :" << root->get_value() << endl;

    root->print_pre_order();

    root = root->insert(*(new redBlackTreeItem(7)));
    root = root->insert(*(new redBlackTreeItem(9)));
    root = root->insert(*(new redBlackTreeItem(10)));
    root = root->insert(*(new redBlackTreeItem(11)));
    root = root->insert(*(new redBlackTreeItem(13)));



    cout << "obteniendo nuevo root :" <<endl;
    cout << "Root original " << root->get_value() << endl;
    root =root->get_root();
    cout << "Nuevo Root :" << root->get_value() << endl;

    root->print_pre_order();



/*
    cout << "Test de asignación y reasignación " << endl;

    redBlackTreeItem *three = new redBlackTreeItem(3);
    redBlackTreeItem *two = new redBlackTreeItem(2);
    root->assign_right(*three);
    three->assign_left(*two);

    cout << "rotando " << endl;
    three->right_rotate();
    //root->insert(*(new redBlackTreeItem(3)));
    //root->insert(*(new redBlackTreeItem(2)));
    root->print_pre_order();*/



    return 0;

}