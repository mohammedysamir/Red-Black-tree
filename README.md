# Red-Black-tree
implement Red-Black Tree 
### Documentation to Red-Black Tree code
##### Rules of Red-Black Tree
    * each node either be red or black , root is always black.
    * each internal node has 2 children[nil , leaves].
    * no 2 adjecent red nodes.
    * for any node Q , any path from Q to its descendants must have same # of black nodes.
### 1. Insertion :always insert as Red-leaf node
    1. Tree is empty
        * insert node as root and make its color 'black'.
    1. Tree isn't empty
        1. Parent is black
            * just insert it.
        1. Parent is Red
            1.Uncle Red 
                1. Switch color of Uncle and Parent to 'black'.
                1. Switch color of GrandParent to 'red'.
            1.Uncle is Black or nil
                1.Uncle and Node in **Same Direction**
                    1.Do Left-Right rotation | Right-Left rotation.
                    1.Swap colors of Node and GrandParent.
                1.Uncle and Node in **oppisite Direction**
                    1.Do Right-Right|Left-Left rotation.
                    2.Swap colors of Parent and GrandParent

