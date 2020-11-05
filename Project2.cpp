#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h> 

using namespace std; 

int problem1(string) 
{ 
    ifstream input_file;
    input_file.open("data.txt"); 
      
    int sum = 0, n = 0; 

    string line; 
    while (input_file >> line) { 
        for (int i = 0; line[i] != '\0'; i++) { 
            if (isdigit(line[i])){
                 n = 10 * n + (line[i] - '0');   
            } else { 
                sum += n; 
                n = 0; 
            } 
        }
    }
    cout << "The sum of all the integers is: " << sum << endl;
}

int problem2(string){
    ifstream inputFile;
    char num;
    int X[100] = {};

   inputFile.open("data.txt");
   while (inputFile >> num)
{
      X[static_cast<int>(num)]++;
}

   for (int i = 0; i <= 100; i++)
   {
      if ( X[i] > 0 )
      {
            cout << static_cast<char>(i) << " " << X[i] << endl;
      }
   }

   return 0;
}

string problem3(vector<string> s) { 
	unordered_map<string, int> mp; 
	for (int i = 0; i < s.size(); i++){
        mp[s[i]]++; 
    } 
		

	int ffreq,sfreq = INT_MIN; 
	for (auto lol = mp.begin(); lol != mp.end(); lol++) { 
		if (lol->second > ffreq) { 
			ffreq = ffreq; 
			sfreq = lol->second; 
		} 

		else if (lol->second > sfreq){
            sfreq = lol->second; 
        }
	} 
   
	for (auto lol = mp.begin(); lol != mp.end(); lol++) 
		if (lol->second == sfreq) 
			return lol->first; 
}

int main() 
{ 
    string s = "data.txt";
    problem1(s); 
    problem2(s);
    //problem3(s);
    return 0; 
} 