#include<bits\stdc++.h>
using namespace std ;
class Node {
public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int counter=0;
vector<int> arr;
int times_called = 0;
int chance_of_end=0;
vector<int> all_num ;
vector<int> recursionTrav, stackTrav;
int getNumber(){
    
    if(times_called>50){
        chance_of_end=1;
    }
    if(times_called>200){
        chance_of_end=3;
    }
    if(times_called>500){
        chance_of_end=5;
    }
    if(times_called>1000){
        chance_of_end=7;
    }
    if(times_called>1200){
        chance_of_end= 2;
    }
    if(times_called>2500){
        chance_of_end= 4;
    }
    if(times_called>5000){
        chance_of_end= 3;
    }
    if(times_called>10000){
        chance_of_end= 5;
    }
    if(times_called>20000){
        chance_of_end= 6;
    }
    if(times_called>30000){
        chance_of_end= 3;
    }
    if(times_called>70000){
        chance_of_end= 9;
    }
    if(times_called>100000){
        chance_of_end= 10;
    }

    times_called++;
    
    int chance = rand()%10+1;
    int num;
    if (chance<=chance_of_end){
        num=-1;
    }
    else{
        num = rand()%50;
    }
    all_num.push_back(num);
    //cout<< "num -> "<< num <<"..   ";
    return num;
}



/*vector<int> arr2 = {17, 0, 24, 8, 14, 45, 27, 41, 42, 36, 4, 3, 32, 16, 45, 26, 38, 12, 49, 44, 11, 33, 14, 11, 18, 44, 7, 9, 41, 28, 35, -1, 38, 40, 14, 46, 40, 20, -1, 1, 48, 23, 4, 40, 26, 8, 39, 23, 38, 32, 41, 15, 8, 30, 6, 36, 45, 22, -1, 27, 47, 36, -1, 36, 17, 24, 2, -1, -1, 24, 30, 41, 37, 37, 33, 9, 8, 38, 46, 
30, 18, -1, 12, 10, 24, 48, 45, 2, -1, 36, 20, 21, 49, 34, 34, 49, 38, -1, 27, 28, 48, 7, -1, -1, 13, 9, 35, -1, -1, 19, 48, 24, 44, 39, -1, 35, 43, 37, 3, 0, 18, -1, 48, -1, 48, 7, -1, -1, 42, 29, -1, 8, -1, 38, 11, -1, 22, 28, 12, 25, 19, -1, 16, -1, 22, -1, -1, 7, 42, 25, -1, -1, -1, 19, -1, 1, 5, 
2, 32, 38, 17, 32, -1, 4, -1, 26, 18, -1, 5, 49, -1, -1, 10, 3, 23, 46, 29, 37, 49, 45, 16, 5, 32, 34, 1, 21, 13, 5, 3, -1, 32, 13, 21, 46, -1, -1, 46, -1, 11, 0, 16, -1, 42, 3, -1, -1, -1, 49, 13, -1, -1, 18, 5, 41, -1, 27, -1, -1, -1, -1, -1, -1, 33, -1, 47, 27, -1, -1, -1, 42, 2, -1, -1, 2, 27, 43, -1, -1, -1, -1, -1, -1, -1, 43, 31, -1, -1, -1, 14, -1, 10, -1, -1, -1, -1, 33, -1, -1, 17, 0, -1, -1, 24, 25, 44, 2, -1, 28, -1, -1, -1, 14, 2, -1, 10, 10, 20, 26, 43, 14, 32, 15, 27, -1, 27, 28, -1, -1, -1, -1, -1, 37, -1, 25, -1, -1, -1, 30, 11, -1, -1, 3, -1, -1, -1, 13, -1, -1, -1, 0, -1, 28, 7, 0, 39, -1, -1, 24, 8, -1, 1, -1, -1, 43, -1, 40, -1, -1, 6, -1, -1, -1, 6, 26, 26, 37, -1, 11, 22, 12, 46, 41, -1, 29, 9, -1, 5, -1, -1, -1, -1, -1, -1, 19, -1, -1, 33, -1, 17, 25, 23, -1, -1, -1, -1, 9, 21, -1, 34, 33, -1, 29, -1, -1, -1, 34, 43, 5, -1, 31, -1, -1, -1, 5, -1, -1, -1, 24, 2, -1, 23, 
-1, -1, 22, 10, 32, -1, 19, -1, -1, 35, -1, 39, -1, 3, -1, -1, -1, -1, 35, 42, 14, -1, -1, 25, 42, 49, 11, 17, -1, 40, -1, -1, -1, 15, -1, -1, -1, -1, 
-1, -1, 20, 27, -1, 36, 20, 47, -1, -1, -1, -1, 13, -1, -1, 40, -1, -1, 13, -1, -1, 32, -1, 25, 3, -1, 47, -1, 21, -1, -1, 45, -1, 28, 12, 35, 44, 40, 
8, 20, -1, -1, -1, -1, -1, 20, -1, -1, -1, -1, 0, 15, 28, -1, 38, -1, 9, -1, 31, 42, 10, -1, 4, 46, -1, 43, -1, -1, 17, 33, 26, 38, -1, 24, 23, 7, 44, 
18, 11, 5, -1, 46, -1, 14, -1, 13, -1, 48, -1, 6, -1, 4, 26, -1, 43, 36, 41, -1, -1, 2, 38, -1, 15, -1, -1, -1, 11, 36, -1, -1, -1, -1, -1, -1, 2, 12, 
-1, -1, -1, -1, -1, 48, -1, 13, 28, -1, -1, 8, -1, 11, -1, -1, 43, 2, -1, 48, -1, -1, -1, -1, -1, -1, -1, 28, 8, 21, -1, 31, -1, -1, 13, 39, -1, 37, -1, -1, -1, 11, 43, 19, 19, 0, -1, -1, 15, 15, -1, 12, 32, -1, 10, -1, -1, -1, 1, -1, 29, -1, 23, 27, -1, 39, -1, 41, -1, -1, -1, 34, 0, -1, 24, -1, -1, 
3, 18, 26, 0, 9, -1, 30, 49, 28, 14, -1, 26, 16, 16, 31, -1, -1, 21, -1, -1, -1, 15, -1, -1, -1, -1, 12, -1, -1, 18, 2, 7, -1, -1, 30, -1, 34, 40, -1, 
2, -1, 8, 41, -1, -1, -1, 8, -1, -1, 2, 29, 23, 16, 48, 46, -1, -1, 22, 42, 25, 8, -1, 48, -1, -1, -1, 49, -1, 32, -1, 25, -1, 36, 18, 28, -1, 30, 25, 
29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 46, -1, -1, 19, 13, -1, -1, -1, -1, -1, 34, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, 43, -1, -1, -1, -1, 35, -1, -1, -1, -1, -1, -1, -1, 18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 40, -1, 43, -1, -1, 19, -1, -1, -1, -1, -1, -1, 14, -1, -1, -1, 0, -1, -1, 11, -1, 8, -1, 26, -1, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, -1, 
-1, -1, 28, -1, -1, -1, 15, 23, 34, -1, -1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 23, -1, 26, -1, -1, -1, -1, -1, -1, 
-1, -1, -1, 43, -1, -1, 18, -1, -1, -1, 27, -1, -1, -1, -1, -1, -1, 45, 35, 37, -1, -1, -1, -1, 11, -1, 42, -1, 31, -1, -1, -1, -1, -1, -1};
*/
// creation of tree via stack
Node * creationOfTreeViaDfs(){
    stack<Node*> Stack;
    Node * root = new Node (arr[0]);
    Stack.push(root);
    Node * temp = root;
    int iter =1;
    while ( Stack.empty() ==0 and iter<arr.size()){
        //cout<<"h ";
        if (iter<arr.size()){
            if(arr[iter]==-1){
                if(Stack.top() == NULL){
                    Stack.pop();
                    Stack.pop();
                    Stack.push(NULL);
                }
                else{
                    Stack.push(NULL);
                }   
            }
            else{
                temp = new Node(arr[iter]);
                if(Stack.top()==NULL){
                    Stack.pop();
                    Stack.top()->right= temp;
                    Stack.pop();
                    Stack.push(temp);
                }
                else{
                    Stack.top()->left = temp;
                    Stack.push(temp);

                }
            }

            iter++;
        }
        // if (Stack.top() == NULL){
        //     Stack.pop();
        //     if(Stack.empty()){
        //         break;
        //     }
        //     Stack.push(NULL);
        // }
        
    }

   
    
    return root;
}

Node * treeCreation(){
    int d;
    //cin>>d;
    d= arr[counter++];
    if (d==-1) return NULL;
    Node * new_Node = new Node(d);
    new_Node ->left = treeCreation();
    new_Node ->right = treeCreation();
    return new_Node;
}
Node * treeCreationRandomly(){
    int d;
    //cin>>d;
    d= getNumber();
    if (d==-1) return NULL;
    Node * new_Node = new Node(d);
    new_Node ->left = treeCreationRandomly();
    new_Node ->right = treeCreationRandomly();
    return new_Node;
}
void inorderTraversal (Node * root,vector<int> &arr){
    // Base case
    if (root == 0){
        return;
    }
    //cout<<root->data<<" ";
    arr.push_back(root->data);
    inorderTraversal(root-> left, arr);
    inorderTraversal(root->right, arr);
}
int main(){
    cout<<"before all\n";

    // generating the input by creating the input tree
    Node * ipRoot = treeCreationRandomly();
    cout<< "after ip tree \n";
    arr = all_num;


    auto start_stack = std::chrono::high_resolution_clock::now();
    Node * root_sta = creationOfTreeViaDfs();
    auto finish_stack = std::chrono::high_resolution_clock::now();
    cout<<"after stack creation\n";
    std::chrono::duration<double> elapsed_seconds_stack = finish_stack- start_stack;
    cout<<"Time elapsed with stack "<<elapsed_seconds_stack.count()<<endl;
    inorderTraversal(root_sta,stackTrav);

    auto start_recur = std::chrono::high_resolution_clock::now();
    Node * root_rec  = treeCreation();
    auto finish_recur = std::chrono::high_resolution_clock::now();
    cout<<"after recur creation\n";
    std::chrono::duration<double> elapsed_seconds_recur = finish_recur - start_recur;
    cout<<"Time in recursion "<<elapsed_seconds_recur.count()<<endl<<endl;
    inorderTraversal(root_rec,recursionTrav);

    
      
    cout<< "sizes equal?:  "<<(stackTrav.size() == recursionTrav.size())  <<endl;

    

    int equal = true;
    for(int i=0;i< stackTrav.size(); i++){
        //cout<< stackTrav[i]<< " ";
        if (stackTrav[i] != recursionTrav[i]){
            equal = false;
            break;
        }
        
    }
    cout<<"\n";
    cout<<"is equal: "<<equal<<endl;
    cout<<"\n times called: "<<times_called<<endl;

    // for (auto x: all_num){
    //     cout<< x<<", ";
    // }
    cout<<endl;




    

    
    
    
}