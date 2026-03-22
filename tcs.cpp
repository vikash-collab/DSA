# coding 

## Take input when Size is Fixed
#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
    int n;
    cin>>n;
    // int arr[n];  // primitive array
    vector<int>arr;  // dynamic array
    
    for(int i=0; i<n; i++){
        // cin>>arr[i];
        int num;
        cin>>num;
        arr.push_back(num);
    }
  
    for(int a: arr){
        cout<<a<<" ";
    } 
    return 0;
}


## Take Input when Size  don't know (not fixed )
### CASE:1 SPACES
#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
    
string s;    
getline(cin, s);          // "1 2 3 4 5 6 7 8"     when SPACES

stringstream ss(s);      // '1' '2' '3' '4' '5' '6' '7' '8'

vector<int>arr;
string temp;
while(getline(ss, temp, ' ')){    // ek-ek kar temp me character add ho jayega
    int num = stoi(temp);    // string to int
    arr.push_back(num);
}

for(int a: arr){
    cout<<a<<" ";
}   
    return 0;
}

### CASE:2 COMMAS
#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
string s;    
getline(cin, s);          // "1,2,3,4,5,6,7,8"     when COMMAS

stringstream ss(s);      // '1' ',' '2' ',' '3' ',' '4' ',' '5' 

vector<int>arr;
string temp;
while(getline(ss, temp, ',')){    // ek-ek kar temp me character add ho jayega
    int num = stoi(temp);    // string to int
    arr.push_back(num);
}


for(int a: arr){
    cout<<a<<" ";
}
    
    return 0;
}

### CASE3: [ ] OR  { }

#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
    
string s;    
getline(cin, s);          // "[1,2,3,4,5,6,7,8]"     when Bracket && Commas

if(s.front()=='[' && s.back()==']'){
    s = s.substr(1, s.length()-2);
}

stringstream ss(s);      // '1' ',' '2' ',' '3' ',' '4' ',' '5' 

vector<int>arr;
string temp;
while(getline(ss, temp, ',')){    // ek-ek kar temp me character add ho jayega
    int num = stoi(temp);    // string to int
    arr.push_back(num);
}


for(int a: arr){
    cout<<a<<" ";
}
    
    return 0;
}


# How Take Input String

#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
    // how to take string input
    int n;
    cin>>n;
    
    cin.ignore();  // if we don't write then  after interger 
                   // 1    this space take  string s so we need to write  cin.ignore
    string s;
    getline(cin, s);
    
    cout<<n<<" "<<s; 
    return 0;
}


Important Questions TCS NQT- Batch 2025
Basic Maths Questions

Q1. Count digits of a number. Link
    
Q2. Find whether given number is Palindrome or not. Link

Q3. Factorial of a number. Link

Q4. Check whether given number is prime or not. Link

Q5. print all Prime factors of given number. Link

Q6. GCD of two numbers. Link

Q7. Check whether given number is Armstrong number or not. Link

Q8. Fibonacci series. Link

Q9. Check if given number is expressed as sum of 2 prime numbers. Link
Q10. Find Sum of AP Series. Link

Q11. Program to find sum of GP Series. Link

Q12. Check Leap Year or not. Link

Q13. Maximum and Minimum digit in a number. Link

Q14. Check if a number is perfect number, Link

Q15. LCM of two numbers. Link

Q16. Convert Binary to decimal and decimal to binary number system. Link Link

Array Questions

Ql. Largest and smallest element in an array. Link

Q2. Second largest and second smallest element in an array. Link

Q3. Check if the array is sorted. Link

Q3. Left rotate an array by K places. Link

Q4. Right rotate an array by K places. .
Q5. Reverse the array. Link

Q6. Find missing number in an array. Link
Q7. Find number that appears one and other appears twice. Link

Q8. Move all zero to end of the array. Link
Q9. Longest sub array with given sum. Link
Q10. Maximum Sub array sum (Kadane's Algorithm) Link
Q11. 2 sum problem. Link
Q12. Sort an array of O's, 1's and 2's (Dutch National Flag Problem). Link
Q13. Majority Element in an array. Link
Q14. Leader in an array. Link
Q15. Maximum sum sub array of size k (Sliding window technique). Link
Q16. Implement Upper Bound Link
Q17. Implement Lower Bound Link
Q18. 3 sum problem Link
Q19. Find first and last position of element in an sorted array. Link
Q20. Equilibrium Point in an array. Link
Q21. Find pairs in an array divisible by K. Link

Strings Questions
Q1. Check if string is palindrome or not. Link
Q2. Check if strings are anagram or not. Link
Q3. Pangram checking of given string. Link
Q4. Count vowel in a string. Link
Q5. Convert Lower to upper case and upper to lower case in a string. Link
Q6. Longest common prefix. Link
Q7. Count number of sub string. Link
Q8. Remove spaces from a given string. Link
Q9. Encrypt the string. Link
Q10. Check if string is sub string of another. Link
Q11. Conversion of String to Integer Link
Q12. Detect Capital Link
Q13. Leetcode Count and Say Link
Q14. Percentage of letter in string  Link
Q15. Longest Substring without repeating character. Link



PYQ TCS -> Story based
    
Q1. Problem Statement -
Given a string S (input consisting) of '*' and '#'. The length of the string is variable. The task is to find the minimum number of *' or '#' to make it a valid string. The string is considered valid if the number of '*' and '#' are equal. The '*' and '#' can be at any position in the string.
Note: The output will be a positive or negative integer based on number of "*"' and '#' in the
input string.
(*>#): positive integer
(#>*): negative integer
(#=*): 0
Example 1:
Input 1: ###*** -> Value of S
Output: 0 number of and # are equal

Q2. Given an integer array Arr of size N the task is to find the count of elements whose value is greater than all of its prior elements.
Note: 1st element of the array should be considered in the count of the result. For example, Arr[]={7,4,8,2,9) As 7 is the first element, it will consider in the result. 8 and 9 are also the elements that are greater than all of its previous elements. Since total of 3 elements is present in the array that meets the condition.
Hence the output = 3.
Example 1:
Input 5 -> Value of N, represents size of Arr
7-> Value of Arr[0]
4-> Value of Arr[1]
8-> Value of Arr[2]
2-> Value of Arr[3]
9-> Value of Arr[4]
Output: 3
    
Q3. At a fun fair, a street vendor is selling different colours of balloons. He sells N number of different colours of balloons (B[]). The task is to find the colour (odd) of the balloon which is present odd number of times in the bunch of balloons.
Note: If there is more than one colour which is odd in number, then the first colour in the array which is present odd number of times is displayed. The colours of the balloons can all be either upper case or lower case in the array. If all the inputs are even in number, display the message "All are even".
Example 1: 7 -> Value of N [r.g,b,b.g.y,y] -> B[] Elements B[0] to B[N-1], where each input element is separated by new line.
Output: r-> [r.g.b,b.g.y,y] -> "r" colour balloon is present odd number of times in the bunch.
Explanation:
From the input array above: r: 1 balloon g: 2 balloons b: 2 balloons y: 2 balloons Hence, ris only the balloon which is odd in number.
    
Q4. You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside
the array nums1. To
accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be
merged, and the last n elements are set to O and should be ignored. nums2 has a length of n.
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3 nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6)
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Q5. A party has been organized on cruise. The party is organized for a limited time(1). The number of guests
entering (E[i]) and leaving (L[i]) the party at every hour is represented as elements of the array. The task is to
find the maximum number of guests present on the cruise at any given instance within T hours.
Example 1:
Input:
5-> Value of T
[7,0,5,1,3] -> E[], Element of E[O] to E[N-1], where input each element is separated by new line
[1,2,1,3,4] -> L[], Element of L[0] to L[N-1], while input each element is separate by new line.
Output:
8 -> Maximum number of guests on cruise at an instance.

Q6. There are total n number of Monkeys sitting on the branches of a huge Tree. As travelers offer Bananas and Peanuts, the
Monkeys jump down the Tree. If every Monkey can eat k Bananas and j Peanuts. If total m number of Bananas and p number
of Peanuts are offered by travelers, calculate how many Monkeys remain on the Tree after some of them jumped down to eat.
At a time one Monkeys gets down and finishes eating and go to the other side of the road. The Monkey who climbed down
does not climb up again after eating until the other Monkeys finish eating.
Monkey can either eat k Bananas or j Peanuts. If for last Monkey there are less than k Bananas left on the ground or less than j
Peanuts left on the ground, only that Monkey can eat Bananas(<k) along with the Peanuts(<j).
Write code to take inputs as n, m, p, k, j and return the number of Monkeys left on the Tree.
Where, n= Total no of Monkeys
k Number of eatable Bananas by Single Monkey (Monkey that jumped down last may get less than k Bananas)
j = Number of eatable Peanuts by single Monkey (Monkey that jumped down last may get less than į Peanuts)
m = Total number of Bananas
p = Total number of Peanuts
Remember that the Monkeys always eat Bananas and Peanuts, so there is no possibility of k and j having a value zero.


Q7. The Caesar cipher is a type of substitution cipher in which each alphabet in the plaintext or messages is shifted by a number of places down the alphabet.
For example, with a shift of 1, P would be replaced by Q, Q would become R, and so on. To pass an encrypted message from one person to another, it is first necessary that both parties have the 'Key' for the cipher, so that the sender may encrypt and the receiver may decrypt it. Key is the number of OFFSET to shift the cipher alphabet. Key can have basic shifts from 1 to 25 positions as there are 26 total alphabets.
As we are designing custom Caesar Cipher, in addition to alphabets, we are considering numeric digits from 0 to 9. Digits can also be shifted by key places.
For Example, if a given plain text contains any digit with values 5 and key =2, then 5 will be replaced by 7, "-"(minus sign) will remain as it is.
Key value less than 0 should result into "INVALID INPUT"
Example 1: Enter your Plaintext: All the best
Enter the Key: 1
The encrypted Text is: Bmm uif Cftu
    
Q8. Sort one array according to another array You are given two arrays a[] (integer) and b[] (char). The ith value of a[] corresponds to the ith value of b[].
Sort the array b[] with respect to a[].
Note: The output is whitespace and newline character sensitive. After every character print a whitespace character. Also do not print any newline character at any point.
Example 1: Input: a[] = (3. 1. 2) b[] = {'G', 'E', 'K'}
Output: EK G
Explanation: Here 3 corresponds to G, 1 corresponds to 'E', 2 corresponds to 'K'

Q9. There are total n number of Monkeys sitting on the branches of a huge Tree. As travelers
offer Bananas and Peanuts, the
Monkeys jump down the Tree. If every Monkey can eat k Bananas and j Peanuts. If total m number of Bananas and p number
of Peanuts are offered by travelers, calculate how many Monkeys remain on the Tree after some of them jumped down to eat.
At a time one Monkeys gets down and finishes eating and go to the other side of the road. The Monkey who climbed down
does not climb up again after eating until the other Monkeys finish eating.
Monkey can either eat k Bananas or j Peanuts. If for last Monkey there are less than k Bananas left on the ground or less than j
Peanuts left on the ground, only that Monkey can eat Bananas(<k) along with the Peanuts(<j).
Write code to take inputs as n, m, p, k, j and return the number of Monkeys left on the Tree.
Where, n= Total no of Monkeys
k= Number of eatable Bananas by Single Monkey (Monkey that jumped down last may get less than k Bananas)
j = Number of eatable Peanuts by single Monkey(Monkey that jumped down last may get less than j Peanuts)
mTotal number of Bananas
p = Total number of Peanuts
Remember that the Monkeys always eat Bananas and Peanuts, so there is no possibility of k and j having a value zero
Example 1:
Input Values -> 20 2 3 12 12
Output Values-> Number of Monkeys left on the tree:10
Note: Kindly follow the order of inputs as n,k,j,m,p as given
in the above example. And output must include the same format as in above example(Number of Monkeys left on the
Tree:)
For any wrong input display INVALID INPUT


Q10. Airport security officials have confiscated several item of the passengers at the security check point. All the items
have been dumped into a huge box (array). Each item possesses a certain amount of
risk [0,1,2]. Here, the risk severity of
the items represent an array[] of N number of integer values. The task here is to sort the items based on their levels of
risk in the array. The risk values range from 0 to 2.
Example:
Input:
7-> Value of N
[1,0,2,0,1,0,2]-> Element of arr[0] to arr[N-1], while input each element is separated by new
line.
Output:
0001122-> Element after sorting based on risk severity

Q11. You are given an array prices where prices[i] is the price of a given stock on the ith
day.
You want to maximize your profit by choosing a single day to buy one stock and ... so on


