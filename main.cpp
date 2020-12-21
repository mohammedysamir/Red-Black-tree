#include <iostream>
#include"RedBlackTree.cpp"
int main() {
RedBlackTree *rb=new RedBlackTree();
rb->insert(7);
rb->insert(3);
rb->insert(18);
rb->insert(10);
rb->insert(11);
rb->insert(8);
rb->insert(22);
rb->insert(26);
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