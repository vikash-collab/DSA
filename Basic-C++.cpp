#include <iostream>
#include <string>
using namespace std;

int decimaltoBinary(int n){
    int num = 0;
    
    for(int i=0; n > 0; i++){
        int lastbit = n&1;
        num = (pow(10, i)*lastbit) + num;
        n = n>>1;
    }
    return num;
}

int binarytoDecimal(int n){
    int num = 0;
    int i=0;
    while(n>0){
        int lastbit = n%10;
        num = (pow(2, i++)*lastbit) + num;
        n = n/10;
    }
    return num;
}

void compareFunction(string s1, string s2)
{
    // comparing both using inbuilt function
    int x = s1.compare(s2);

    if (x != 0) {
        cout << s1 
             << " is not equal to " 
             << s2 << endl;
        if (x > 0)
            cout << s1 
                 << " is greater than " 
                 << s2 << endl;
        else
            cout << s2 
                 << " is greater than " 
                 << s1 << endl;
    }
    else
        cout << s1 << " is equal to " << s2 << endl;
}

int main()
{
    // cin>>st;   // simple way for all but drawback can'nt read after space
    // getline(cin, st);
    // cin.get(ch);   // read once character only include white space
    // char ch[5];
    // cin.getline(ch, 50);  // read multiple character or word  with space & tab
    // cout<<ch<<endl;
    
    
    // int a=3;
    // if(!(a!=4)){
    //   cout<<"! Not equal to  number, that true";
    // }
    // else{
    //   cout<<"equal to number";
    // }
    
    string s1("Geeks");
    string s2("forGeeks");
    compareFunction(s1, s2);
    
    
    cin >> c;
    // switch case with operation for each operator
    switch (c) {
    case '+':
        cout << x << " + " << y << " = " << x + y << endl;
        break;

    case '-':
        cout << x << " - " << y << " = " << x - y << endl;
        break;

    case '*':
        cout << x << " * " << y << " = " << x * y << endl;
        break;
    case '/':
        cout << x << " / " << y << " = " << x / y << endl;
        break;
    default:
        printf("Exiting\n");
    }
    
    int day = 4;
    // using switch
    switch (day) {
        case 1:
            cout << "Monday";
            break;  
        case 12:
            cout << "Tuesday";
            break;
        default:
            cout << "Invalid day number";
            break;
    }
    
    // cout<<decimaltoBinary(108);
    // cout<<binarytoDecimal(1101100);
    // int arr[5];
    // cout<<sizeof(arr)/sizeof(int);

    return 0;
}
