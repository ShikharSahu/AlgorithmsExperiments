package com.shik;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        GetRandomNumbers getRandomNumbers = new GetRandomNumbers();
        GetInput getInput = new GetInput(1);
        //time start
        System.out.println(GetInput.dfsTreeInput.length);
        long startTimeRecursive = System.nanoTime();
        TreeNode root = RecursiveDFSCreation.treeCreation();
        long estimatedTimeRecursive = System.nanoTime() - startTimeRecursive;
        //time end

        //System.out.println("traversal");
        //RecursiveDFSCreation.dfsTraversal(root);


        long startTimeIterative = System.nanoTime();
        TreeNode iterativeRoot = IterativeDFSCreation.treeCreation();
        long estimatedTimeIterative = System.nanoTime() - startTimeIterative;
        //time end

        System.out.println("Recursive " + estimatedTimeRecursive/1000_000.0);
        System.out.println("iterative " + estimatedTimeIterative/1000_000.0);

//        System.out.println("iterative");
//        RecursiveDFSCreation.dfsTraversal(iterativeRoot);

    }
}
