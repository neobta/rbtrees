//
// Created by neobta on 6/7/15.
//

#ifndef REDBLACKTREESDEMO_REDBLACKTREEITEM_H
#define REDBLACKTREESDEMO_REDBLACKTREEITEM_H

#include <memory>

namespace redBlackTrees {

  enum red_black_tree_color {BLACK, RED};

  class redBlackTreeItem {
  private:

    red_black_tree_color color;
    int value;
    redBlackTreeItem *left;
    redBlackTreeItem *right;
    redBlackTreeItem *parent;

    void insert_fix_up(redBlackTreeItem &newItem);


  public:


    redBlackTreeItem(int i);

    void assign_left(redBlackTreeItem &l);

    void assign_right(redBlackTreeItem &r);


    redBlackTreeItem* left_rotate();
    redBlackTreeItem* right_rotate();
    redBlackTreeItem* insert(redBlackTreeItem &newItem);

    int get_value();


    void print_in_order();

    void print_pre_order();

    void print_post_order();

    void assign_node_as_red();
    void assing_node_as_black();
    redBlackTreeItem* get_root();
  };
}

#endif //REDBLACKTREESDEMO_REDBLACKTREEITEM_H
