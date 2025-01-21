#include<iostream>
#include<string>
#include<vector>
using namespace std;

class bird{
    public:
    int age, weight;
    int nol;
    string color;

    void eat(){
        cout<<"Bird is Eating"<<endl;
    }
    void fly(){
        cout<<"Bird is flying"<<endl;
    }
};


class sparrow: public bird
{
    public:
    sparrow(int age, int weight, string color, int nol){
        this->age = age;
        this->weight = weight;
        this->color = color;
        this->nol = nol;
    }

    void grassing(){
        cout<<"Sparrow is grassing"<<endl;
    }    
};


class piegon: public bird
{
public:
    void guttering(){
        cout<<"Piegon is guttering"<<endl;
    }
};


int main(){
    sparrow s(1, 1, "blue", 2);
    cout<<s.color<<endl;
    s.eat();
    s.grassing();

    piegon p;
    p.eat();
    p.guttering();


}