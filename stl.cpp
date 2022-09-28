// added some comments for my personal understanding

#include <bits/stdc++.h>
using namespace std;

int main() {

    
    // for any container:
    // use x.size() function to get length
    // use x.emplace() to insert, --> doesn't work for pairs


    // for making a comparator, just check which cases are true, and return false for everything else
    bool comp(int el1, int el2) {
        if(el1 <= el2)
            return true;
        else
            return false;
    }

    // pair<int, int> arr[] = {{1, 4}, {5, 2}, {5, 9}}
    // make comparator: check first, if first is equal check second

    bool comp2(pair<int, int> el1, pair<int, int> el2) {
        if(el1.first < el2.first) {
            return true;
        }
        else if(el1.first == el2.first) {
            if(el1.second > el2.second) {
                return true;
            }
        }
        else {
            return false;
        }
    }


    // stores in ascending order, and only contains one occurence of each element
    set<int> st;

    //set that stores element in any order
    unordered_set<int> us;

    // set that can store multiple occurences of the same value
    multiset<int> ms;

    // maps key value pairs in sorted order of KEYS
    map<string, int> mp;

    // maps key value in unsorted order DOES NOT USE PAIRS !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    unordered_map<int, int> ump;

    //sorted order of keys
    multimap<string, int> mmp;
    mp.emplace("apple ", 50);
    mp.emplace("apple ", 60);

    for(auto it:mp) {
        cout << it.first << it.second << endl;
    }


    // each element of all kinds of map shown above is a pair which is also a container
    pair<int, int> pr;
    // use first and second variable names
    pr.first = 4;
    pr.second = 5;

    //cout << pr.first << " " << pr.second << endl;

    //stack
    stack<int> stk; // lifo ds
    // pop
    // top() --> prints ELEMENT at top, NOT the index
    // size
    // empty --> checks empty or not, returns boolean
    // push or emplace

    stk.push(2);
    stk.push(1);
    stk.push(13);
    stk.push(67);

    // cout << stk.top() << endl; // prints 67
    // stk.pop();
    // cout << stk.top() << endl;

    // how to delete the entire stack
    while(!stk.empty()) {
        stk.pop();
    }

    // stack<int> stk2;
    // cout << stk2.top() << endl; // will give error as stack is empty

    // queue
    queue<int> q;
    // push()
    // front()
    // pop(0)
    // size()
    // empty()
    // no rear() is there lol

    q.push(34); q.push(4); q.push(78);

    cout << q.front() << endl;

    // priority queue --> stores all in sorted order, descending in O(lg n)
    // it will insert in max heap --> remember max heap is priority queue
    priority_queue<int> pq;
    // push
    // pop
    // top
    // empty
    // size

    // pq.push(1);
    // pq.push(6);
    // pq.push(2);

    // cout << pq.top() << endl;


    pq.push(-7);
    pq.push(-8);
    pq.push(-9);


    cout << -1*pq.top() << endl;

    // min-priority queue
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(5);
    minpq.push(3);
    minpq.push(4);

    cout << minpq.top() << endl;


    deque<int> dq;
    // push_front
    // push_back
    // pop_front
    // pop_back
    // begin, end, rbegin, rend
    // size
    // clear
    // at

    list<int> l;
    // push_front
    // push_back
    // pop_front
    // pop_back
    // begin, end, rbegin, rend
    // size
    // clear
    // at
    // remove --> any element at O(1) time

    // given N elements, return the elements the occurs the maximum number of times
    // ip
    // 5
    // 1 2 3 3 3

    map<int, int> mpp;
    int n;
    cin >> n;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mpp[x]++;   // mp[key] returns the value
        if(mpp[x] > maxi) {
            maxi = x;
        }
    }

    cout << maxi << endl;

    // given N elements, print all elements in sorted order
    // 6
    // 6 6 3 2 3 5

    // output
    // 2 3 3 5 6 6 

    int n;
    cin >> n;
    multiset<int,int> mst;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mst.insert(x);
    }

    for(auto it: mst) {
        cout << it << endl;
    }

    // Bitset
    // int -> 16 bits --> 2 bytes
    // char -> 8 bits --> 1 byte

    // bitset -> like an array but each place stores 1 bit
    bitset<5> bt;
    // used in a lot of segment tree problems 

    cin >> bt; // 10101

    // all
    bt.all(); // ---> like AND, returns true if all bits are 1 else returns false
    // any
    bt.any(); // ----> like OR
    // count ----> prints number of srt bits
    // flip
    bt.flip(2); // --.> flips the bit on the index number passed as argument
    // none() returns true if none of the bits are set, else returns false
    // set 
    bt.set(); // sets up the ENTIRE bitset
    bt.set(4); // sets up particular index
    bt.set(2, 0); // sets 2nd inex as 0
    // reset ---> similar set, sets it to 0
    // size --> prints 5
    // test
    cout << bt.test(3); // check if bt is set or not for index 1

    // WE CANNOT RESIZE BITSET



    // algorithms.h

    // sorting
    // array, vector
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n;i++) cin >> arr[i];  
    sort(arr, arr+n); // in increasing order      // uses 3 kinds of sort
    // sort(arr+1, arr+4) --> sorts from index 1 to 3    vector<int> v(5,0);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end()); // [) 


    // vec -. 1 6 2 7 4
    // sort it only 1 to 3 index
    // final 1 2 6 7 4

    sort(v.begin()+1, v.begin()+4);

    // If i want to reverse
    // reverse(startIterator, endIterator) -> [)
    reverse(arr, arr+n);
    reverse(v.begin(), v.end());

    // max element between i and j
    // min_element and max_element returns a POINTER
    int el = *max_element(arr, arr+n); // [)
    int en = *min_element(arr, arr+n);

    // sum of i to j
    int sum = 0;
    int i, j;
    for(int k = i; k<=j;k++) {
        sum += arr[k]; 
    }
    
    // accumulate(startIterator, endIterator, initialSum)
    int sum = accumulate(arr, arr+n, 0); 


    // arr = [1 6 7 1 2 1 3]
    // x = 1
    // how many times x occurs?
    int freq = count(v.begin(), v.end(), 1);


    // find the first ocurence of x
    auto it = find(v.begin(), v.end(), 2); // return iterator or pointer pointing to first instance of it, or else it returns pointing to end()

    // it - begin() ---> returns ind
    int ind = it - arr; // not *it, *it will give the element

    auto it = find(v.begin(), v.end(), 4); // suppose 4 doesnt exist
    if(it == v.end()) {
        cout << "element is not present" << endl;
    }


    // binary search
    // this stl works only on sorted arrays, time is O(lg n)


    //syntax
    // binary_search(firstIterator, lastIterator, x)
    // returns a true or false
    bool res = binary_search(arr, arr+n, 5);
    bool res = binary_search(v.begin(), v.end(), 5);

    

    // lower_bound function
    // works on sorted arrays and takes O(n)
    // returns an iterator pointing to an element which is not less than x
    // arr[] --> 1 5 7 8 10 10 10 11 11 12
    // x = 10
    // x = 6, pointer will point to element 7
    // x = 13 --> end()
    // this works in log N

    int x = 8;
    auto it = lower_bound(arr, arr+n, x);
    ind = it - arr;

    auto it = lower_bound(v.begin(), v.end(), x);
    ind = it - v.begin();


    // upper_bound 
    // returnss an iterator which points to an element which
    // is just greater than x
    // arr[] --> 1 5 7 8 10 10 10 11 11 12
    // x = 6 --> points to element 7
    // x = 12 ----> end() iterator
    // x = 15 ---> also end() iterator



    // find me the index where x lies
    // find function can be used but usesO(N)
    int i = lower_bound(v.begin(), v.end(), x) - v.begin();

    if(i != n && arr[ind] == x) {   // i is not pointing to end iterator and the element is there at arr[ind]
        cout << "Found at: " << ind;
    }


    // find the last occurencce of x in an array
    // WILL NOT WORK IF X = 0, ind -= 1 will become -1, throw an error, make sure to check for the edge case
    int ind = upper_bound(arr, arr+x, x) - arr;
    ind -= 1;
    if(arr[ind] == x) {
        cout << "last occurene: " << ind;
    }
    else {
        cout << "does not exist.\n";
    }


    // tell me number of times x occurs in array
    int freq = upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x); // works every time :)




    // Next Permutation
    // string s = "abc"
    // all permutations are as follows;

    // abc
    // acb
    // bac
    // bca
    // cab
    // cba

    // number of permutations = n!


    string s = "bca";
    bool res = next_permutation(s.begin(), s.end());
    // s will become cab automatically
    // if next permutation happens, it will store cab


    s = "cba";
    bool res = next_permutation(s.begin(), s.end());
    // s doesn't change to the next permutation and so res becomes false

    s = "bca";
    // string is also a container so you can sort it :)
    sort(s.begin(), s.end()); // sets "bca" as "abc"
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));


    // same way we also have:
    // prev_permutation 


    // ------------------------------------------------------------------------------
    // COMPARATOR
    sort(arr, arr+n); // ascending
    sort(arr, arr+n, comp); 
    int arr[10];
    sort(arr, arr+n, greater<int>); // only in descending order, it's an inbuilt comparator

    // note: you can't use comparators in queue and stack

    vector<vector<int>> v(n, vector<int>(n, 0));


}
