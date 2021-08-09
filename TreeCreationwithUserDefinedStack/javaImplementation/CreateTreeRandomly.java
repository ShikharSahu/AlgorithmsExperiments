package com.shik;

public class CreateTreeRandomly {
    public static TreeNode treeCreation(){
        int data;
        data = GetRandomNumbers.getRandomNumber();
        if (data == -1) {
            return null;
        }
        TreeNode newNode = new TreeNode(data);
        newNode.left = treeCreation();
        newNode.right = treeCreation();
        return newNode;
    }

    public static void dfsTraversal(TreeNode root){
        if(root == null){
            return;
        }
        System.out.println(root.data);
        dfsTraversal(root.left);
        dfsTraversal(root.right);
    }
}
