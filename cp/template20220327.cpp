#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define fe             first
#define se             second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define FOR(i, j, k, in)    for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in)   for (int i=j ; i>=k ; i-=in)
#define REP(i, j)           FOR(i, 0, j, 1)
#define RREP(i, j)          RFOR(i, j, 0, 1)

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#else 
#define bug(...)
#endif

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int log_a_to_base_b(int a, int b)
{
    return log(a) / log(b);
}
bool isPrime(int num){
    if(num<=3){
        return true;
    }
    if(num%2 == 0 or num%3 == 0){
        return false;
    }
    for(int i = 5; i*i < num +1; i+=6 ){
        if(num%i == 0 or num%(i+2) == 0){
            return false;
        }
    }
    return true;
}

vector<bool> sieveBoolArray(int n){
    vector<bool> nums(n+1, true);
    // initially all nums are prime

    for(int i = 0; i < n+1; i+=2){
        nums[i] = false;
    }
    clock_t z = clock();	

    for(int i = 3; i*i <= n+1; i+=2){
        if (nums[i]){
            for(int j = i * i; j <= n; j+=i ){
                nums[j] = false;
            }
        }
    }
    nums[2] = true;
    int c = 0;
    for(int i = 2 ; i < n+1; i++){
        if(nums[i]) {
            // cout << i << endl;
            c++;
        }
    }
	cerr << "Run Time sieve: " << ((double)(clock() - z) / CLOCKS_PER_SEC) <<endl;

    cout << "by sieve : " << c << endl;
    return nums;
}
void merge(vector<int>& arr, int s, int mid, int e){
    
    int i = s, j = mid+1, iter = 0;
    vector<int> temp(e-s+1);

    while(i <= mid and j <= e){
        if(arr[i] < arr[j]){
            temp[iter++] = arr[i++];
        }
        else{
            temp[iter++] = arr[j++];
        }
    }

    while (i<=mid){
        temp[iter++] = arr[i++];
    }
    while (j <= e){
        temp[iter++] = arr[j++];
    }
    for(int i1 = 0; i1 < e-s+1; i1++){
        arr[i1+s] = temp[i1];
    }
}
void mergesort(vector<int>& arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (e-s)/2 +s;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);
    merge(arr, s, mid ,e);
}

void quicksort(vector<int>& arr, int s, int e){
    if(s>=e){
        return;
    }
    int pivot = arr[e];
    int i = s;
    int j = e-1;
    while (i <= j){
        if(arr[i] < pivot){
            i++;
        }
        else{
            swap(arr[i],arr[j]);
            j--;
        }
    }
    swap(arr[i],arr[e]);
    quicksort(arr,s,i-1);
    quicksort(arr,i+1,e);

}

void setIthBit(int &n, int i){
    int mask = ~(1<<(i));
    n = n&mask;
}
bool isPowerOfTwo(int n){
    if(n==0) return false;
    return (n==1 or ((n&(n-1)) == 0));
}






vector<vector<int>> addMatrix( vector<vector<int>>& mat1, vector<vector<int>>& mat2){
    int mat1Row = mat1.size();
    int mat1Column = mat1[0].size();
    vector< vector<int> > answer(mat1Row, vector<int>(mat1Column));
    
    for(int ansMatRow = 0; ansMatRow< mat1Row; ansMatRow++){
        for (int ansMatColumn = 0; ansMatColumn < mat1Column; ansMatColumn++){
           answer[ansMatRow][ansMatColumn] = mat1[ansMatRow][ansMatColumn] + mat2[ansMatRow][ansMatColumn];
        }
    }
    return answer;

}

vector<vector<int>> multiplyMatrix( vector<vector<int>>& mat1, vector<vector<int>>& mat2){
    int mat1Row = mat1.size();
    int mat2Row = mat2.size();
    int mat1Column = mat1[0].size();
    int mat2Column = mat2[0].size();
    vector< vector<int> > answer(mat1Row, vector<int>(mat2Column));

    for(int ansMatRow = 0; ansMatRow< mat1Row; ansMatRow++){
        for (int ansMatColumn = 0; ansMatColumn < mat2Column; ansMatColumn++){
            int localAns = 0;
            for(int dotLoopIter = 0; dotLoopIter < mat1Column; dotLoopIter++){
                localAns += mat1[ansMatRow][dotLoopIter]*mat2[dotLoopIter][ansMatColumn];
            }
            answer[ansMatRow][ansMatColumn] = localAns;
        }
    }
    return answer;
}

int bigMod(string num,int m){
    // xy (mod a) ≡ ((x (mod a) * 10) + (y (mod a))) mod a
    int res = 0;
    for(int i = 0; i < num.size(); i++){
        res = ((res*10) + (num[i] - '0'))%m;
    }
    return res;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
    cout << endl;
#endif

	clock_t z = clock();

	int t = 1;
	// cin >> t;
	for (int testcase = 0; testcase < t; testcase++){
        solve(testcase);
    }

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
	return 0;
}
