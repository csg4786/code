#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    
    int n = s1.length(), m = s2.length();
    if (n > m){
        return false;
    } else {
        vector<int> present(26);
        for (int i = 0; i < n; i++) {
            present[s1[i]-'a']++;
        }
        for (auto i : present)
        {
            cout << i << " ";
        }
        cout << endl << endl;
        
        vector<int> temp(26);
        for (int j = 0; j < n; j++) {
            temp[s2[j]-'a']++;
        }

        for (int i = n-1; i < m; i++) {

            for (auto i : temp)
            {
                cout << i << " ";
            }
            cout << endl;

            if (temp == present) {
                return true;
            }
            else if (i < m-1){
                temp[s2[i+1]-'a']++;
                temp[s2[i-n+1]-'a']--;
            }
        }
        return false;
    }
}

int main()
{
    string s1,s2;
    cin >> s1;
    cin >> s2;

    cout << checkInclusion(s1, s2) << endl;
    return 0;
}