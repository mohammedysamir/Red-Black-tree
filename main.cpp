#include <iostream>
#include"RedBlackTree.cpp"
int main() {
 RedBlackTree *rb=new RedBlackTree();
rb->insert(5);
rb->insert(6);
rb->insert(4);
rb->insert(8);
rb->insert(1);
rb->insert(3);
rb->insert(7);
rb->Print();
rb->Clear();
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