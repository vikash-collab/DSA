#include<iostream>
#include<unordered_map>
// #include<map>   // ordered map  declare as => map<type, type> name
using namespace std;

void countCharacters(unordered_map<char, int> &mapping, string str){
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        mapping[ch]++;
    }
} 

int main(){

    string str = "hare-krishna";
    unordered_map<char, int> mapping;
    countCharacters(mapping, str);

    for(auto i: mapping){
        cout<<i.first<<"->"<<i.second<<endl;
    }


    
    // // creation
    // unordered_map<string, int>mapping;

    // /// insertion
    // pair<string, int> p = make_pair("love", 25);

    // pair<string, int> q("raman", 24);

    // pair<string, int> r;
    // r.first = "Ansh";
    // r.second = 22;

    // pair<string, int> pr = {"geeks", 3};

    // // insertion
    // mapping.insert(p);
    // mapping.insert(q);
    // mapping.insert(r);
    // mapping.insert(pr);
    // // insert
    // mapping["order"] = 35;

    // cout<<"Size of map: "<< mapping.size()<<endl;
    // // Access
    // cout<< mapping.at("love")<<endl;
    // cout<<mapping["love"]<<endl;
    
    // cout<< mapping.count("lover")<<endl;    // key present h to 1 print hota h, nhi to 0 print
    // cout<<"Size of map: "<< mapping.size()<<endl;


    // if(mapping.find("order") != mapping.end()){
    //     cout<<"Found"<<endl;
    // }
    // else{
    //     cout<<"Not Found"<<endl;
    // }

    // cout<<"Size of map: "<< mapping.size()<<endl;  // size 5
    // cout<<mapping["Kumar"]<<endl;                 // agar es name ki entry nhi h to ye entry create karta h 0 se
    // cout<<"Size of map: "<< mapping.size()<<endl;  // size 6 
    

   return 0; 
}