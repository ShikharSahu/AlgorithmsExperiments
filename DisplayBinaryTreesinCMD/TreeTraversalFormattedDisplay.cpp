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

// function that creates a tree by bfs
Node * createTreeBfs1(vector<int> arr){
    Node * root = new Node(arr[0]);
    queue<Node *> Queue;
    Queue.push(root);
    int iter=1;
    while (!Queue.empty()){
        Node * focus = Queue.front();
        Queue.pop();
        Node * temp= 0;
        if (arr[iter]!=-1){
            temp = new Node(arr[iter]);
            Queue.push(temp);
        }
        focus->left= temp;
        iter++;
        temp=0;
        if (arr[iter]!=-1){
            temp = new Node(arr[iter]);
            Queue.push(temp);
        }
        focus ->right=temp;
        iter++;
    }
    return root;
}
int height(Node * root){
    if (root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1+max(h1,h2);
}


void traverseAndMake(Node * root, vector<vector<char>> &matrix, int depth, char symbol ,int start, int end){
    if (root == NULL){
        return;
    } 
    int mid = (end+start)/2;

    int num = root ->data;
    string num_str = to_string(num);
    int len = num_str.size();

    int matrix_put_start = mid - len/2;
    for(int i= 0 ; i< len; i++){
        matrix[depth][i+matrix_put_start]= num_str[i];
    }
    if (symbol == 'l'){
        matrix[depth-1][mid] = '/';
    }
    else if (symbol == 'r'){
        matrix[depth-1][mid] = '\\';
    }
    matrix[depth+1][mid] = '|';

    traverseAndMake(root->left,matrix, depth+2, 'l' , start , mid-1);
    traverseAndMake(root->right,matrix, depth+2, 'r' ,mid+1,end);
}

// function that contains the matrix of tree
// it can be used to display small tress in a formatted manner in the cmd
void representByMatrix(Node * root){
    int mHeight = height(root); 
    int mWidth = 3*(pow(2,mHeight)-1);

    char center_c = 'c';
    
    vector< vector<char> > matrix(2*mHeight+10,vector<char> (mWidth+10,' ') );

    traverseAndMake(root, matrix, 0, center_c ,0, mWidth-1 );
    
    for (int i=0; i< 2* mHeight ; i++ ) {
        for (int j=0; j<mWidth; j++){
                cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

void inorderTraversal(Node * root){
    if (root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

// util function to display array
void displayArray(vector<int > arr){
    for(int i= 0 ; i< arr.size() ; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}
int main(){
    cout<<endl;
    vector<int> arr33 ={ 1,2,3,4,5,6,7, 8,9,10,11,12,13,14,15, -1,-1,-1,-1, -1,-1,-1,-1 ,-1,-1,-1,-1 ,-1,-1,-1,-1 };
    Node * root3 = createTreeBfs1(arr33);
    cout<<"for the array \n";
    displayArray(arr33);
    cout<<endl;
    representByMatrix(root3);
    cout<<endl;
    
    vector<int> arr ={ 1,2,3,4,5, -1,6,-1,-1,7, -1,-1,-1,-1,-1 };
    Node * root = createTreeBfs1(arr);
    cout<<"for the array \n";
    displayArray(arr);
    cout<<endl;
    representByMatrix(root);
    
}
