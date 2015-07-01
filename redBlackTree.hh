
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
           
            T value;


        public:

            //typedef std::shared_ptr<redBlackTrees::redBlackTree<T>::redBlackTreeNode> node_ptr;
			red_black_tree_color color;

            redBlackTreeNode(T i);
            ~redBlackTreeNode();


            void assign_left(std::shared_ptr<redBlackTreeNode> item,std::shared_ptr<redBlackTreeNode> parent);
            void assign_right(std::shared_ptr<redBlackTreeNode> item,std::shared_ptr<redBlackTreeNode> parent);

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
        void right_rotate(std::shared_ptr<redBlackTreeNode> node);

		std::shared_ptr<redBlackTreeNode> find(std::shared_ptr<redBlackTreeNode> current_node, T item);// -> decltype(current_node);

		std::shared_ptr<redBlackTreeNode> get_minimum(std::shared_ptr<redBlackTreeNode> node);

        void insert_fix_up(std::shared_ptr<redBlackTreeNode> newItem);

		void delete_node(std::shared_ptr<redBlackTreeNode> deleteItem);
		void transplant(std::shared_ptr<redBlackTreeNode> u, std::shared_ptr<redBlackTreeNode> v);


		void delete_fix_up(std::shared_ptr<redBlackTreeNode> x,  std::shared_ptr<redBlackTreeNode> xparent);

    public:

        redBlackTree();

        ~redBlackTree();

        bool is_root_null();
        void insert(T n);
		void remove(T n);
        void print_in_order();
        void print_pre_order();
        void print_post_order();       
		
		
		
        
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
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::assign_left(std::shared_ptr<redBlackTreeNode> item, std::shared_ptr<redBlackTreeNode> parent) {
    if (left != nullptr) {
        std::cout << "Es diferente de null" << std::endl;
        std::cout << "haciendo left->parent = nulo" << std::endl;
        left->parent = std::shared_ptr<redBlackTreeNode>();

        std::cout << "Clean up done" << std::endl;
    }
    else {
        std::cout << "Left is null ptr" << std::endl;
    }


	if (item==nullptr)
	{
		left = item;
		return;
	}

    //remove old parent
    auto op = item->parent.lock();
    if(op!= nullptr) {

        if (op->left == item) {
            op->left =  std::shared_ptr<redBlackTreeNode>();
        } else {
            op -> right = std::shared_ptr<redBlackTreeNode>();
        }
    }



    std::cout << "escribiendo left = item " << std::endl;
    left = item;
    left->parent= parent;
    std::cout << "asignacion left terminada" << std::endl;
}


template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::assign_right(std::shared_ptr<redBlackTreeNode> item, std::shared_ptr<redBlackTreeNode> parent) {

    //Remove right and parent reference
    if (right != nullptr) {
        std::cout << "already had a value on right" << std::endl;
        std::cout << "asigning left->parent = nullptr" << std::endl;
        right->parent = std::shared_ptr<redBlackTreeNode>();

        std::cout << "Clean up done" << std::endl;
    }
    else {
        std::cout << "right is null ptr" << std::endl;
    }

	if (item == nullptr)
	{
		right = item;
		return;
	}
    //remove old parent
    auto op = item->parent.lock();
    if(op!= nullptr) {

        if (op->left == item) {
            op->left =  std::shared_ptr<redBlackTreeNode>();
        } else {
            op -> right = std::shared_ptr<redBlackTreeNode>();
        }
    }
    std::cout << "assigning right = item " << std::endl;
    right = item;
    right->parent= parent;
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
		right->print_in_order();
}


template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::print_pre_order()
{

    this->print_node_value();
    if (this->left!= nullptr)
		left->print_pre_order();

    if (this->right!= nullptr)
		right->print_pre_order();
}


template<typename T>
void redBlackTrees::redBlackTree<T>::redBlackTreeNode::print_post_order()
{

    this->print_node_value();
    if (this->left!= nullptr)
		left->print_post_order();

    if (this->right!= nullptr)
		right->print_post_order();
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
		root->color = BLACK;
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
					std::shared_ptr<redBlackTreeNode> newnode = std::make_shared<redBlackTreeNode>(n);
                    currentNode->assign_left(newnode,currentNode);
                    std::cout << "assign node left " << std::endl;
                    assigned = true;
					insert_fix_up(newnode);
					newnode->color = RED;
						
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
					std::shared_ptr<redBlackTreeNode> newnode = std::make_shared<redBlackTreeNode>(n);
                    currentNode->assign_right(newnode,currentNode);
                    std::cout << "assign node right" <<std::endl;
                    assigned=true;
					newnode->color = RED;
					insert_fix_up(newnode);
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
void redBlackTrees::redBlackTree<T>::remove(T n) {

	auto  item = find(root, n);
	delete_node(item);
}

template <typename T>
void redBlackTrees::redBlackTree<T>::insert_fix_up(std::shared_ptr<redBlackTreeNode> newItem)
{
	
	while (newItem->parent.lock() != nullptr && newItem->parent.lock()->color == RED)
	{
		std::shared_ptr<redBlackTreeNode> np = newItem->parent.lock();
		std::shared_ptr<redBlackTreeNode> ngp = np->parent.lock(); //has to have a Grand Pa becouse parent is red and root always is black 
		if (np == ngp->left)
		{
			auto y = ngp->right;
			if (y!= nullptr  &&y->color == RED)
			{
				np->color = BLACK;
				y->color = BLACK;
				ngp->color = RED;
				newItem = ngp;
			}
			else
			{
				if (np->right!=nullptr && newItem== np->right)
				{
					newItem = np;
					left_rotate(newItem);
				}
				auto tp = newItem->parent.lock();
				tp->color = BLACK;
				auto tgp = tp->parent.lock();
				tgp->color = RED;
				right_rotate(tgp);
			}
		}
		else
		{

			auto y = ngp->left;
			if (y != nullptr && y->color == RED)
			{
				np->color = BLACK;
				y->color = BLACK;
				ngp->color = RED;
				newItem = ngp;
			}
			else
			{
				if (np->left!=nullptr && newItem == np->left)
				{
					newItem = np;
					right_rotate(newItem);
				}
				auto tp = newItem->parent.lock();
				tp->color = BLACK;
				auto tgp = tp->parent.lock();
				tgp->color = RED;
				left_rotate(tgp);
			}
			
		}
		
	}



	root->color = BLACK;
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
            p->assign_left(r,p);
        }
        else
        {
            p->assign_right(r,p);
        }
    }


    r->assign_left(node,r);
    node->assign_right((rl),node);


}



template<typename T>
void redBlackTrees::redBlackTree<T>::right_rotate(std::shared_ptr<redBlackTreeNode> node){
    if (node->left== nullptr)
    {
        std::cout <<"cannot be rotate nothing in the left  to be transplanted" << std::endl;
        return;
    }
    std::shared_ptr<redBlackTreeNode> p = node->parent.lock();
    std::shared_ptr<redBlackTreeNode> l = node->left;
    std::shared_ptr<redBlackTreeNode> lr = l->right;


    if (p== nullptr) {
        std::cout << "Parent is null we are rotating root, so we need to change the root with the node on the left"<<std::endl;
        this->root = l;
    }
    else
    {


        if (p->left == node)
        {
            p->assign_left(l,p);
        }
        else
        {
            p->assign_right(l,p);
        }
    }


    l->assign_right(node,l);
    node->assign_left((lr),node);


}




template<typename T>
std::shared_ptr<typename redBlackTrees::redBlackTree<T>::redBlackTreeNode> redBlackTrees::redBlackTree<T>::find(std::shared_ptr<typename redBlackTrees::redBlackTree<T>::redBlackTreeNode> current_node, T item) //-> decltype(current_node)
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


template <typename T>
std::shared_ptr<typename redBlackTrees::redBlackTree<T>::redBlackTreeNode> redBlackTrees::redBlackTree<T>::get_minimum(std::shared_ptr<redBlackTreeNode> node)
{
	if (node->left != nullptr)
		return	get_minimum(node->left);
	else
		return node;

	
}



template<typename T>
void redBlackTrees::redBlackTree<T>::transplant(std::shared_ptr<redBlackTreeNode> u, std::shared_ptr<redBlackTreeNode> v)
{
	if (u->parent.lock() == nullptr)
	{
		this->root = v;
		//remove old parent
		v->parent = std::shared_ptr<redBlackTreeNode>();
	}
	else
	{
		auto p = u->parent.lock();
		if (u == p->left)
		{
			p->assign_left(v, p);
		}
		else
		{
			p->assign_right(v,p);
		}
	}
}

template<typename T>
void redBlackTrees::redBlackTree<T>::delete_node(std::shared_ptr<redBlackTreeNode> deleteItem)
{
	auto y = deleteItem;
	auto yoriginalColor=  y->color;
	auto mparent = deleteItem->parent.lock();
	std::shared_ptr<redBlackTreeNode> x= std::shared_ptr<redBlackTreeNode>();
	if (deleteItem->left == nullptr)
	{
		x = deleteItem->right;
		transplant(deleteItem, deleteItem->right);
	}
	else if (deleteItem->right == nullptr)
	{
		x = deleteItem->left;
		transplant(deleteItem, deleteItem->left);
	}
	else
	{
		y = get_minimum(deleteItem->right);
		yoriginalColor = y->color;
		x = y->right;
		if (y->parent.lock() ==deleteItem)
		{
			x->parent = y;
		}
		else
		{
			transplant(y, y->right);
			y->assign_right(deleteItem->right,y);
		}
		transplant(deleteItem, y);
		y->assign_left(deleteItem->left,y);
		y->color = deleteItem->color;				
	}

	if (yoriginalColor== BLACK)
	{
		delete_fix_up(x, mparent);
	}

}

template<typename T>
void redBlackTrees::redBlackTree<T>::delete_fix_up(std::shared_ptr<redBlackTreeNode> x, std::shared_ptr<redBlackTreeNode> xparent)
{
	while (x!=root && (x == nullptr || x->color == BLACK))
	{
		if (x!=nullptr)
		{
			xparent = x->parent.lock();
		}

		if (x == xparent->left)
		{
			auto w = xparent->right;
			if (w->color==RED)
			{
				w->color = BLACK;
				xparent->color = RED;
				left_rotate(xparent);
				w = xparent->right;
			}

			if ((w->left == nullptr || w->left->color == BLACK) && (w->right == nullptr || w->right->color == BLACK))
			{
				w->color = RED;
				x = xparent;
			}
			else
			{
				if (w->right == nullptr || w->right->color == BLACK)
				{
					if (w->left != nullptr)
					{
						w->left->color = BLACK;
					}
					w->color = RED;
					right_rotate(w);
					w = xparent->right;
				}

				w->color = xparent->color;
				xparent->color = BLACK;
				if (w->right != nullptr)
				{
					w->right->color = BLACK;
				}
				left_rotate(xparent);
				x = root;
			}
		}
		else
		{

			auto w = xparent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent.lock()->color = RED;
				right_rotate(xparent);
				w = xparent->left;
			}

			if ((w->right == nullptr || w->right->color == BLACK) && (w->left== nullptr || w->left->color == BLACK))
			{
				w->color = RED;
				x = xparent;
			}
			else
			{
				if (w->left == nullptr || w->left->color == BLACK)
				{
					if (w->right != nullptr)
					{
						w->right->color = BLACK;
					}
					w->color = RED;
					left_rotate(w);
					w = xparent->right;
				}

				w->color = xparent->color;
				xparent->color = BLACK;
				if (w->left!= nullptr)
				{
					w->left->color = BLACK;
				}
				right_rotate(xparent);
				x = root;
			}
			
		}
		
	}


	x->color = BLACK;
}

#endif //REDBLACKTREESDEMO_REDBLACKTREEITEM_H


