package com.shik;

import java.util.Stack;

public class IterativeDFSCreation {
    public static TreeNode treeCreation(){
        Stack<TreeNode> stack = new Stack<>();
        int[] inputValues = GetInput.getDfsTreeInput();
        //stack.setSize(inputValues.length);

        TreeNode root = new TreeNode(inputValues[0]);
        stack.push(root);
        TreeNode temp;

        int iter = 1;
        int pop_c =0;
        long startTimeIterative = System.nanoTime();

        while (!stack.empty() && iter < inputValues.length){
                if(inputValues[iter] == -1){
                    if (stack.peek() == null){
                        stack.pop();
                        stack.pop();
                        pop_c+=2;
                    }
                    stack.push(null);
                }
                else {
                    temp = new TreeNode(inputValues[iter]);
                    if(stack.peek() == null){
                        stack.pop();
                        stack.peek().right = temp;
                        stack.pop();
                        pop_c+=2;
                    }
                    else {
                        stack.peek().left = temp;
                    }
                    stack.push(temp);
                }
                iter++;

//            if (stack.peek() == null){
//                stack.pop();
//                if(stack.isEmpty()){
//                    break;
//                }
//                stack.push(null);
//            }
        }

        long estimatedTimeIterative = System.nanoTime() - startTimeIterative;
        //time end

//        System.out.println("iterrrrrrr " + estimatedTimeIterative/1000_000.0);
//        System.out.println("pop c " + pop_c);
        return root;

    }
}
