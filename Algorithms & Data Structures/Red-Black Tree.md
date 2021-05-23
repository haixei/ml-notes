# Red-black Tree

The Red-black Tree is our normal binary search tree with one extra attribute for each node: the colour.  It helps us make sure that the tree remains balanced during insertions and deletions. When we modify the tree, it gets rearranged and recoloured to "restore the colouring properties that constrain how unbalanced the tree can become in the worst case"[[1]](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree). It's also worth keeping in mind that although not perfect, the rebalancing guarantees searching, tree rearrangement and recolouring are performed in ![{\mathcal {O}}(\log n)](https://wikimedia.org/api/rest_v1/media/math/render/svg/74a9dfea91c47d1c6563e89bbcd891771b91acfa)time.



![Red-black Tree Graph](https://i.imgur.com/ahL97NX.png)





## Properties of the tree

- Each node is either red or black
- The root of the tree is **always** black
- A red node cannot have a red parent or red child
- Every path from a node (including the root) to any of its descendants NULL nodes has  **the same number of black nodes**



## When it's used?

It's a fairly popular self-balancing search tree and widely use in different areas of computer science. Most of the self-balancing BST library functions like map and set in C++ use Red**-**Black Tree. It is is also used by Linux for a CPU Scheduling. Red-black tree is similar to AVL trees, but provide faster real-time bounded worst case performance for insertion and deletion with just a slightly slower lookup time.



## Rotation and creating a new node

To-do.



## The code

- Basic implementation (build a tree, add/remove a new node)



_Find the code in [this directory.]()_