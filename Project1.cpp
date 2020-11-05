/*
*Problem 1
*
*
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double seconds, H, M, D;
    char input;

    cout<< "Input seconds: "<< endl;
    cin >> seconds;

    cout<<"\nMenu options:";
    cout<<"\n(M)inutes";
    cout<<"\n(H)ours";
    cout<<"\n(D)ays";
    cout<<"\nSelect the conversion format M/H/D and enter it here: ";
    cin>>input;

    H = (seconds / 3600.0); 
	
	M = (seconds / 60.0);
	
	D = (seconds / 86400.0);

     switch (input) 
    { 
        case 'M':  
            cout << "The number of seconds entered is: " << M << " minutes"; 
            break; 
        case 'H':  
            cout << "The number of seconds entered is: " << H << " hours"; 
            break; 
        case 'D':  
            cout << "The number of seconds entered is: " << D << " days"; 
            break;
        default:  
            cout << "Input invalid"; 
            break;   
    } 
return 0;
}
*
*
*Problem 2
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<string> names){
	for(int i = 0; i < names.size(); i++){
        cout << names[i] << endl;
        }
	cout << "\n" << endl;
}

bool cp(string one, string two){
	return one<two;
}

vector<string> alphabaticalSort(vector<string> one){
	sort(one.begin(),one.end(),cp);
	return one;
}

int main() {
	vector<string> names(4);
	string name;
	cout << "Enter four names: " << endl;
	for(int i = 0; i < 4; i++) {
		cin >> name;
		names.push_back(name); 
	}
	
    names = alphabaticalSort(names);

    cout << "In Alphabatical Order:" << endl;
    print(names);
    return 0;
}
