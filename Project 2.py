"""
	A ternary tree is a tree with in which every node has at most three edges coming out of it (as opposed to a binary tree in which every node has at most two edges coming out of it). 

Write a Python implementation for a recursive ternary tree. The data for the construction is a list of integers L. In addition,
your code should contain at least one class, for example, TernaryTree(), which must contain the following three methods:
generate_tree(), traverse_LMRW(), leaf_count().

Method description
------------------

generate_tree(L) - First element in L is the root node. 
All other elements in L are placed recursively inside the tree according to the following set of rules: 
smaller than root - left; equal to the root - middle; larger than root - right.

traverse_LMRW() - traverses an instance of the object TernaryTree recursively. 
The recursion rules LMRW stand for go (traverse) Left, go (traverse) Middle, go (traverse) Right, 
Write node value (print to screen). That is, we traverse the tree on the left until we cannot go any further, 
then we go to the middle until we cannot go any further, then we go right until we cannot go any further. 
When these have been exhausted, we print the node value to screen.
  
leaf_count() - returns the number of leaves for an instance of the object TernaryTree. 
As a reminder, a leaf nodes are nodes that have no edges coming out of them. 
In other words, they are at the periphery of the tree. 

Your main function should look like this

def main():
    L = [4,1,2,2,3,1,0,4,6,5,6,4]
    T = TernaryTree()
    T.generate_tree(L)
    T.traverse_LMRW()
    T.leaf_count()
"""
class TernaryTree (object):

    def __init__(self, value = None):
        self.value = value
        self.left = None
        self.right = None
        self.middle = None

    def insert_node(self, new_value):
        if new_value < self.value:
            if self.left == None:
                self.left = TernaryTree(new_value)
            else:
                self.left.insert_node(new_value)
        elif new_value == self.value:
            if self.middle == None:
                self.middle = TernaryTree(new_value)
            else:
                self.middle.insert_node(new_value)
        else:
            if self.right == None:
                self.right = TernaryTree(new_value)
            else:
                self.right.insert_node(new_value)


    def generate_tree(self, L):
        self.value = L[0]
        for e in L[1:]:
            self.insert_node(e)

    def traverse_LMRW(self):
        if self.left != None:
            self.left.traverse_LMRW()
        if self.middle != None:
            self.middle.traverse_LMRW()
        if self.right != None:
            self.right.traverse_LMRW()
        print(self.value)
        

    def leaf_count(self, L = []):
        if self.left == None and self.middle == None and self.right == None:
            L.append(self.value)
        else:
            if self.left != None:
                self.left.leaf_count()
            if self.middle != None:
                self.middle.leaf_count()
            if self.right != None:
                self.right.leaf_count()
        return len(L)
        
        

def main():
    L = [4,1,2,2,3,1,0,4,6,5,6,4]
    T = TernaryTree()
    T.generate_tree(L)
    T.traverse_LMRW()
    print("Leaf count:")
    print(T.leaf_count())

main()