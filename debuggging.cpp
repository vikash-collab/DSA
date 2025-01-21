#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){

	// char str1[6] = "Hello";
	// char str2[6] = "world";
	// char str3[12] = strcat(str1, str2);
	// cout<<str3<<endl;
	string str1 = "hello";
	string str2 = "world";
	str2 = str2 + 'a';

	// string str3 = strcat(str1, str2);
	// string str3 = str1 + str2;

   cout<<str2<<endl;



	// string str;
	// cin>>str;
	// cout<<str;
	// char str[] = "Hello World";

	// cout<<str[0]<<endl;
}








// bool isPossibleSolution(vector<int>Ranks, int nP, int mid){
// 	int c = 0;

// 	for(int i=0; i<Ranks.size(); i++){
// 	    int timeTaken = 0;
//         int R = Ranks[i];
// 		int j  = 1;
// 		while(true){
// 		    if(timeTaken + (j * R) <= mid){
//                 c++;
// 			    timeTaken +=  j * R;
//                 j++;
// 		    }
// 			else{
//                 break;
// 			}
// 		}	
// 		if(c >= nP){
// 			return true;
// 		}
// 	}
// 	return false;
// }


// int minTimetoCompleteOrder(vector<int>Ranks, int nP){
//     int start = 0;
// 	int heighestRank = *max_element(Ranks.begin(), Ranks.end());
// 	int end = heighestRank * (nP * (nP + 1)/2);
// 	int ans = -1;
// 	while(start<=end){
// 		int mid = start + (end - start)/2;
// 		if(isPossibleSolution(Ranks, nP, mid)){
// 			ans = mid;
// 			end = mid - 1;
// 		}
// 		else{
// 			start = mid + 1;
// 		}
// 	}
// 	return ans;
// }





// int main(){
// 	int T;
// 	cin>>T;

// 	while(T--){
// 		int nP, nC;
// 	    vector<int>Ranks;
// 		cin>>nP>>nC;
// 		while(nC--){
// 			int num;
// 			cin>>num;
// 			Ranks.push_back(num);
// 		}
// 		cout<<minTimetoCompleteOrder(Ranks, nP)<<endl;
        
// 	}

// }














// bool isPossibleSolution(vector<long long int>trees, long long int m,long long int mid){
// 	long long int WoodCollected = 0;
// 	for(int i=0; i<trees.size(); i++){
// 		if(trees[i]>mid){
// 			WoodCollected += trees[i] - mid;
// 		}    
// 	}
// 	return  WoodCollected >= m;
// }



// long long int maxSawBladeHeight(vector<long long int>trees, long long int m){

// 	long long int start = 0, end, ans = -1;
// 	end = *max_element(trees.begin(), trees.end());
// 	while(start<=end){
// 		long long int mid = start + (end - start)/2 ;
// 		if(isPossibleSolution(trees, m, mid)){
//             ans = mid;
// 			start = mid + 1;
// 		}
// 		else{
// 			end = mid - 1;
// 		}
// 	}

// 	return ans;
// }

// int main(){
// 	long long int n , m;
// 	cin>>n>>m;
// 	vector<long long int>trees;
//     while(n--){
//         long long int Height;
// 		cin>>Height;
// 		trees.push_back(Height);
// 	}
// 	cout<<maxSawBladeHeight(trees, m)<<endl;
// 	return 0;
// }













// int search(vector<int>nums, int target){
// 		int l = 0, r = nums.size() - 1;
// 		while(l <= r){
// 			int mid = l + (r-l)/2;
// 			if(nums[mid] == target) return mid;
// 			else if(nums[l]<=nums[mid]){
// 				if(nums[l]<=target && target<nums[mid]) r = mid-1;
// 				else l = mid+1;
// 			}
// 			else{
// 				if(nums[mid]<target && target<=nums[r]) l = mid+1;
// 				else r = mid-1;
// 			}
// 		}
// 		return -1;
// }


// void bubble(vector<int>&v){
//     int n = v.size();
// 	for(int i=0; i<n-1; i++){
// 		for(int j=0; j<n-i-1; j++){
// 			if(v[j]>v[j+1]){
// 				swap(v[j], v[j+1]);
// 			}
// 		}
// 	}

// 	for(auto value: v){
// 		cout<<value<<" ";
// 	}
// }


// void Selection(vector<int>&v){
// 	int n = v.size();

// 	for(int  i=0; i<n-1; i++){
// 		int minIndex = i;
// 		for(int j = i+1; j<n; j++){
// 			if(v[minIndex]>v[j]){
// 				minIndex = j;
// 			}
// 		}
// 		swap(v[minIndex], v[i]);
// 	}

// 	cout<<"After sorting : "<<endl;
// 	for(auto value: v){
// 		cout<<value<<" ";
// 	}
// }

// void Insertion(vector<int>v){
// 	int n = v.size();

// 	for(int i=1; i<n; i++){
// 		int j=i-1;
// 	    int key = v[i];
// 		for( ; j>=0; j--){
// 			if(key<v[j]){
//                 v[j+1] = v[j];

// 			}
// 			else{
// 				break;
// 			}
// 		}
// 		v[j+1] = key;
// 	}
// 	cout<<"After Swapping: "<<endl;
// 	for(auto value: v){
// 		cout<<value<<" ";
// 	}
// }

// int main(){
//     vector<int>nums  = {44,33,55,22,11};

//     Insertion(nums);

// }