# include<iostream>
#include<vector>                                        // https://www.spoj.com/submit/EKO/
#include<algorithm>
using namespace std;

bool isPossibleSolution(vector<long long int>trees, long long int m, long long int mid){
     long long int WoodCollected = 0;
    for(int i=0; i<trees.size(); i++){
        if(trees[i]>mid){
            WoodCollected += trees[i]-mid;
        }
    }
          
    return WoodCollected >= m;
}



long long int maxSawBladeHeight(vector<long long int>trees, long long int m){

    long long int start = 0, end , ans = -1;
    end = *max_element(trees.begin(), trees.end());  
    while(start<=end){
        long long int mid = start + (end - start)/2;
        if(isPossibleSolution(trees, m, mid)){

            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    } 
    return ans;     
}

int main(){
    long long int n, m;
    cin>>n>>m;
    vector<long long int>trees;
    while(n--){
        long long int height;
        cin>>height;
        trees.push_back(height);
    }

    cout<<maxSawBladeHeight(trees, m)<<endl;

    return 0;
}