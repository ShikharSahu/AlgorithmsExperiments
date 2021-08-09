# Explanation of classes:
1. IterativeDFSCreation : Creates the tree using iteration and user defined stack by the input from GetInput class
2. RecursiveDFSCreation : creates the same tree but recursively.
3. TreeCreationRandomly : Creates a tree with randomly generated numbers for the creation of test cases for the use as input for the other tree generation.
4. GetInput: With the help from TreeCreationRandomly, it supplies inputs to the other tree creation functions.
5. TreeNode : This the class used to represent the nodes of the tree.

# Applications :
1. In the recursive method, for the creation of very tall trees. User may face stackOverFLow error. Such error is not faced in the iterative method as user defined stack is used.
