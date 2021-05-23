# Linked Lists

A linked list is nothing else than a sequence of nodes, where a node contains the data and a pointer to another node. The most common example are singly linked list, where nodes have a link to only the next node in the list. There's also double linked lists that aside of the pointer to the next node, they also have one for the node before.



![Linked Lists Graph](https://i.imgur.com/DUywOVE.png)



## When to use?

One of the important ways linked lists can help you in is the insertion of new data. Let's imagine a scenario like the following: you have an array of numbers [1, 2, 3, 4, 6] and you want to insert a new value between 4 and 6. When using an array we do not only have to inert our new value but also change the index of all the other values. We can do that by moving each number one to the right and insert the value, or splice the array based on the index and do all that stuff but there's an easier way. If we replace our array with a linked list we only have to create a new node and update the pointer from the number 4 to point to the new node 5 instead of the 6 from before.

**In general** linked lists are really good when you want to insert and remove a lot of data but not really need to look it up often. Splitting and joining bidirectionally-linked lists is very efficient. We have to keep in mind that there's also no memory allocation needed before creating a structure, which can be both good and bad depending on what you want to achieve.



## The code

- Basic implementation (Create, remove node)
- Add two numbers



_Find the code in [this directory.]()_