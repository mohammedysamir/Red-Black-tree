#include <iostream>
#include"RedBlackTree.cpp"
int main() {
RedBlackTree *rb=new RedBlackTree();
rb->insert(13);
rb->insert(8);
rb->insert(1);
rb->insert(11);
rb->insert(6);
rb->insert(17);
rb->insert(15);
rb->insert(25);
rb->insert(22);
rb->insert(27);
rb->Print();
rb->Delete(15);
rb->Delete(11);
rb->Print();

}








/*

              5
            /   \
           4     6
          /       \
         1         8
          \       /
           3     7   
*/