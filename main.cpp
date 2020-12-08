#include <iostream>
#include"RedBlackTree.cpp"
int main() {
RedBlackTree *rb=new RedBlackTree();
rb->insert(5);
rb->Print();
rb->insert(6);
rb->insert(4);
rb->Print();
rb->insert(8);
/*rb->insert(1);
rb->insert(3);
rb->insert(7);*/
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