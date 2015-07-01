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
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(10);

    tree.print_in_order();

	std::cout << "Removing  5 " << std::endl;
	tree.remove(5);
	std::cout << "should be removed and destroyed 5 in this point" << std::endl;
	tree.remove(4);
	std::cout << "root was 4 and is removed now " << std::endl;
	std::cout << "printing pre order Root->Left->Right" << std::endl;
	tree.print_pre_order();

	



}

int main() {
    test_one();
	
	
   
	std::cin.get();

    return 0;

}