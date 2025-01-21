#include<iostream>
#include<queue>
#include<vector>
using namespace std;


// KQueue in Array
class KQueue{
  public:
    int n, k, freeSpot;
    int *arr, *front, *rear, *next;

    KQueue(int _n, int _k): n(_n), k(_k), freeSpot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        for(int i=0; i<k; i++)
            front[i] = rear[i] = -1;
        for(int i=0; i<n; i++)
            next[i] = i + 1;
        next[n-1] = -1;           
    }  

    //push x into qith Queue
    bool push(int x, int qi)
    {
        //Overflow
        if(freeSpot==-1){
            return false;
        }

        // find first free index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        //if  first element in qi
        if(front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // link new element to that Q's rearest element
            next[rear[qi]] = index;
        }

        //update next
        next[index] = -1;

        //update next
        next[index] = -1;

        //update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }  


    //Pop element fron qith Queue
    int pop(int qi){
        //underflow
        if(front[qi]==-1){
            return -1;
        }

        //find index to pop
        int index = front[qi];

        //from update
        front[qi] = next[index];

        //update freeSpots
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};


int sumofminmaxofallwindowofsizek(vector<int>& nums, int k) {
        deque<int>dq, dq2;
        int ans = 0;

        /// first window process
        for(int i=0; i<k; i++){
            // chotte element ko remove krado
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
          // badha element remove kardo  
            while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
                dq2.pop_back();
            }

            // now insert elemnt so we can checkout of window element
            dq.push_back(i);

             dq2.push_back(i);
        }

        ans += nums[dq.front()] + nums[dq2.front()];

        // remiaing window ko process
        for(int i=k; i<nums.size(); i++){
            // removal  
            ///1.out of range 
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            if(!dq2.empty() && i-dq2.front()>=k){
                dq2.pop_front();
            }
            
            /// 2.chotte element removal
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back(); 
            }

            while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
                dq2.pop_back(); 
            }

            // inserting index, so we can checkout of window element
            dq.push_back(i);
             dq2.push_back(i);
            
            // current window ka amnswer store karo
            ans  += nums[dq.front()] + nums[dq2.front()];
        }

    return ans;
}




int main(){

    ///sum of min max of all window
    vector<int>v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout<<sumofminmaxofallwindowofsizek(v, k)<<endl;



    // //KQueue in Array
    // KQueue kq(8, 3);
    // cout << kq.push(1,0) <<endl;
    // cout << kq.push(2,0) <<endl;
    // cout << kq.push(5,1) <<endl;
    // cout << kq.push(3,0) <<endl;
    // cout << kq.pop(1) <<endl;
    // cout << kq.pop(1) <<endl;
    // cout << kq.pop(0) <<endl;
    // cout << kq.pop(0) <<endl;
    // cout << kq.pop(0) <<endl;
    // cout << kq.pop(0) <<endl;
    // cout << kq.pop(0) <<endl;
    // cout << kq.pop(0) <<endl;
    // cout << kq.pop(1) <<endl;




    // string str = "ababc";
    // queue<int>q;
    // int freq[26] = {0};

    // for(int i=0; i<str.size(); i++){
    //     char ch = str[i];   //step1  : string character
    //     freq[ch-'a']++;     // step2 : frequency maintain
    //     q.push(ch);        // step3  : current charac. push in queue

    //     //answer find karo  // step4 : chaeck in queue front element is frequency could not be > 1
    //     while(!q.empty()){
    //         char frontCharacter = q.front();
    //         if(freq[frontCharacter-'a'] >1){
    //             // yaani this front character not be the answer
    //             q.pop();
    //         } 
    //         else{
    //             // =1 wala case
    //             // yhi answer
    //             cout<<frontCharacter<<"->";
    //             break;
    //         }
    //     }

    //     if(q.empty()){
    //         //koi answer nhi nikla
    //         cout<<"#"<<"->";
    //     }
    // }

    return 0;
}

