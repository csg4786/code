#include <bits/stdc++.h>
using namespace std;

bool palindrome_check(string str,int s, int e){
    if (s > e){
        return true;
    }
    if (str[s] == str[e]){
        return palindrome_check(str,s+1,e-1)&true;
    }
    else{
        return false;
    }
}

int main()
{
    string s;
    cin >> s;

    (palindrome_check(s,0,s.length()-1))? cout << "Palindrome" : cout << "Not Palindrome";
    
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
// 	int t;
// 	cin >> t;
// 	while(t--){
// 	    int n;
// 	    cin >> n;
// 	    vector <int> v(n);
// 	    for (int i = 0; i < n; i++){
// 	        cin >> v[i];
// 	    }
// 	    for (int i = n-1; i >= 0; i--){
// 	        cout << v[i] << " ";
// 	    }
// 	}
// 	return 0;
// }