# Red-Black-tree
implement Red-Black Tree 
### Documentation to Red-Black Tree code
##### Rules of Red-Black Tree
    -each node either be red or black , root is always black.
    -each internal node has 2 children[nil , leaves].
    -no 2 adjecent red nodes.
    -for any node Q , any path from Q to its descendants must have same # of black nodes.
### 1. Insertion :always insert as Red-leaf node
    1. Tree is empty
        -insert node as root and make its color 'black'.
    2. Tree isn't empty
        2.1. Parent is black
            -just insert it.
        2.2. Parent is Red
            2.2.1.Uncle Red 
                -Switch color of Uncle and Parent to 'black'.
                -Switch color of GrandParent to 'red'.
            2.2.2.Uncle is Black or nil
                2.2.2.1.Uncle and Node in **Same Direction**
                    -Do Left-Right rotation | Right-Left rotation.
                    -Swap colors of Node and GrandParent.
                2.2.2.2.Uncle and Node in **oppisite Direction**
                    -Do Right-Right|Left-Left rotation.
                    -Swap colors of Parent and GrandParent

