#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void vectorDemo(){
    
    vector<int> A ={12,2,3,14};

    cout<<A[3]<<endl;

    sort(A.begin(), A.end());

    bool it = binary_search(A.begin(), A.end(), 3);

}

void setDemo(){

    set<int> S;

    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for(int x: S)
        cout<<x<<" ";
    cout<<endl;

    auto it = S.find(-1);

    if(it == S.end()){
        cout<<"not present";
    }
    else{
        cout<<"Its present ";
        cout<< *it <<endl;
    }
    
    auto it2 = S.upper_bound(-1);
    auto it3 = S.upper_bound(0);
    cout << *it2 << " " << *it3 << endl;

    auto it4 = S.upper_bound(2);

    if(it4 == S.end()){
        cout<<"not found"<<endl;
    }
    else{
        cout<< *it4 << endl;
    }
}

int main(){

    setDemo();

}