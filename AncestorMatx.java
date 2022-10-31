// Java Program to construct ancestor matrix for a given tree
import java.util.*;
 
class AncestorMatx
{
    // ancestorMatrix function to populate the matrix of
    public static void ancestorMatrix(Node root ,int matrix[][],int size)
    {
         
        // base case:
        if (root==null)
        return ;
         
        // call recursively for a preorder {left}
        ancestorMatrix(root.left, matrix, size);
         
        // call recursively for preorder {right}
        ancestorMatrix(root.right, matrix, size);
         
        // here we will reach the root node automatically
        // try solving on pen and paper
         
        if (root.left != null)
        {
            // make the current node as parent of its children node
            matrix[root.data][root.left.data] = 1;
             
            // iterate through all the columns of children node
            // all nodes which are children to
            // children of root node will also
            // be children of root node
            for (int i = 0; i < size; i++)
            {
                // if children of root node is a parent
                // of someone (i.e 1) then make that node
                // as children of root also
                if (matrix[root.left.data][i] == 1)
                matrix[root.data][i] = 1;
            }
        }
         
        // same procedure followed for right node as well
        if (root.right != null)
        {
            matrix[root.data][root.right.data] = 1;
             
            for (int i = 0; i < size; i++)
            {
                if (matrix[root.right.data][i]==1)
                matrix[root.data][i] = 1;
            }
        }
             
         
    }
     
    // Driver program to test the program
    public static void main(String[] args)
    {
         
        // construct the binary tree as follows
        Node tree_root = new Node(5);
        tree_root.left = new Node (1);
        tree_root.right = new Node(2);
        tree_root.left.left = new Node(0);
        tree_root.left.right = new Node(4);
        tree_root.right.left = new Node(3);
         
        // size of matrix
        int size = 6;
        int matrix [][] = new int[size][size];
         
        ancestorMatrix(tree_root, matrix, size);
         
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
    }
     
    // node class for tree node
    static class Node
    {
        public int data ;
        public Node left ,right;
        public Node (int data)
        {
            this.data = data;
            this.left = this.right = null;
        }
    }
}