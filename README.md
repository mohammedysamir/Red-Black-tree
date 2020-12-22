# Red-Black-tree
implement Red-Black Tree 
### Documentation to Red-Black Tree code
##### Rules of Red-Black Tree
>    1. each node either be red or black , root is always black.
>    2. each internal node has 2 children[nil , leaves].
>    3. no 2 adjecent red nodes.
>    4. for any node Q , any path from Q to its descendants must have same # of black nodes.
### 1. Insertion :always insert as Red-leaf node
1. Tree is empty
    *  insert node as root and make its color 'black'.
    >![Insertion-case-1](/images/Insertion-case-1.jpeg)
2. Tree isn't empty
    1. Parent is black
        *  just insert it.
        >![Insertion-case-2](/images/Insertion-case-2.jpeg)
    1. Parent is Red
        1. Uncle Red 
            * Switch color of Uncle and Parent to 'black'.
            * Switch color of GrandParent to 'red'.
            >![Insertion-case-3](/images/Insertion-case-3.jpeg)
        1. Uncle is Black or nil
            * Uncle and Node in **Same Direction**
                * Do Left-Right rotation | Right-Left rotation.
                * Swap colors of Node and GrandParent.
                >![Insertion-case-4](/images/Insertion-case-4.jpeg)
            * Uncle and Node in **oppisite Direction**
                * Do Right-Right|Left-Left rotation.
                * Swap colors of Parent and GrandParent
                >![Insertion-case-5](/images/Insertion-case-5.jpeg)


