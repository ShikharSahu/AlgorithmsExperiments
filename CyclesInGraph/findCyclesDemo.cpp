/*
@author: ShikharSahu
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef long long int ll;
using namespace std;
#define MOD 1e9+7;

set<vector<int>> complete, partial;

void printPath(vector<int> path){
    path.pop_back();
    for (int e : path){
        cout << e << "  ->  ";
    }
    cout << path.front();
    cout << endl ;
}
void helper (int current, vector<int>& allConnected, vector<pair<int,vector<int> > >& graph, int initial, unordered_set<int>& visited, vector<int>& path){
    if (path.size()>=2){
        if( find(allConnected.begin(), allConnected.end(), initial) != allConnected.end() ){
            if( path.size() == graph.size() ){
                path.push_back(initial);
                complete.insert(path);
                path.pop_back();
                // printPath(path);
            // print path
            }
            else {
                path.push_back(initial);
                partial.insert(path);
                // printPath(path);
                path.pop_back();
            }
        // add to set of paths
        }
    }
    for(int element : allConnected){
        if(visited.count(element)==0){
            visited.insert(element);
            path.push_back(element);
            helper(element, graph[element-1].second, graph, initial, visited, path);
            path.pop_back();
            visited.erase(element);
        }
    }
}
void printMatrix(vector<vector<bool> > graph){
    int n = graph.size();
    for (int i =0 ; i< n; i++){
        for (int j = 0 ; j < n ; j ++){
            cout << (int) graph[i][j] << "   ";
        }
        cout << endl;
    }
}
vector<vector<bool> > getMatrix(int n){
    vector<vector<bool> > graph(n,vector<bool>(n,false));
    for (int i =0 ; i< n; i++){
        for (int j = 0 ; j < n ; j ++){
            if(i!=j){
                if(rand()%3 == 0){
                    graph[i][j] = true;
                }
            }
        }
    }
    return graph;
}
vector<pair<int,vector<int> > > getList(vector<vector<bool> > mat){
    vector<pair<int,vector<int> > > graph;
    for (int i = 0 ; i < mat.size(); i++){
        vector<int> temp;
        for(int j = 0; j <mat.size(); j++){
            if(mat[i][j]){
                temp.push_back(j+1);
            }
        }
        graph.push_back(make_pair(i+1,temp));
    }
    return graph;
}

void solve(){
    // vector<pair<int,vector<int> > > graph(4);
    // graph[0] = {1,{2,3}};
    // graph[1] = {2,{1,4}};
    // graph[2] = {3,{2}};
    // graph[3] = {4,{1,3}};
    srand(time(0));
    int size = 5 + rand() % 3;
    auto mat  = getMatrix(size);
    cout << "graph is :\n";
    printMatrix(mat);
    auto graph = getList(mat);

    vector<int> path;
    unordered_set<int> visited;
    for (auto node: graph){

        visited.insert(node.first);
        path.push_back(node.first);
        helper(node.first, node.second, graph, node.first, visited, path);
        path.pop_back();
        visited.erase(node.first);
    }
    
    cout << "Number of complete of complete cycles: " << complete.size() <<endl;
    cout << "complete path\n";
    for (auto path : complete){
        printPath(path);
    }

    cout << endl;
    set<vector<int>> perfectPartials; 
    for (auto path : partial){
        if(path.size()>3){
            perfectPartials.insert(path);
        }
    }
    cout << "Number of complete of partial cycles: " <<  perfectPartials.size() <<endl;
    cout << "partial path\n";
    for (auto path : perfectPartials){
        printPath(path);
    }
    
}



int main(){ 
    ll T=5;
    while(T--){
        solve();
    }
} 
