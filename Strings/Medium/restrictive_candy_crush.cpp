#include <bits/stdc++.h>
using namespace std;

// string Reduced_String(int k, string s)
// {
//     string ans = "";
//     stack<char> s1;
//     stack<int> s2;
//     int n = s.length();
//     for (int i = 0; i < n; i++)
//     {
//         if (s1.empty() or s1.top() != s[i])
//         {
//             s1.push(s[i]);
//             s2.push(1);
            
//             // cout << "s1.top : " << s1.top() << "\n";
//             // cout << "s2.top : " << s2.top() << "\n";
//         }
//         else
//         {
//             if (s2.top() < k-1)
//             {
//                 s1.push(s[i]);
//                 s2.top()++;

//                 // cout << "s1.top : " << s1.top() << "\n";
//                 // cout << "s2.top : " << s2.top() << "\n";
//             }
//             else
//             {
//                 for (int i = 0; i < k-1; i++)
//                 {
//                     s1.pop();

//                     // cout << "s1.top : " << s1.top() << "\n";
//                     // cout << "s2.top : " << s2.top() << "\n";
//                 }
//                 s2.pop();

//                 // cout << "s1.top : " << s1.top() << "\n";
//                 // cout << "s2.top : " << s2.top() << "\n";
//             }
//         }
//     }

//     while (!s1.empty())
//     {
//         ans = s1.top() + ans;
//         s1.pop();
//     }
//     return ans;
// }

string Reduced_String(int k, string s) {

    string ans = "";
    stack<char> s1;
    stack<int> s2;
    int n = s.length();
    if (k <= 1){
        return ans;
    }
    else{
        for (int i = 0; i < n; i++)
        {
            if (s1.empty() or s1.top() != s[i])
            {
                s1.push(s[i]);
                s2.push(1);
            }
            else
            {
                if (s2.top() < k-1)
                {
                    s1.push(s[i]);
                    s2.top()++;
                }
                else
                {
                    for (int i = 0; i < k-1; i++)
                    {
                        s1.pop();
                    }
                    s2.pop();
                }
            }
        }

        while (!s1.empty())
        {
            ans += s1.top();
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
}

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    cout << Reduced_String(k, s);

    return 0;
}

/*

o b i w j r u f c e j z u v i o j k t i y h i a x u l n q o l p f c v k a i y w h r x e z r y b g y e t m p u l s p m j z m c g b u h f h d v u c u y d t o l f p a k o y s c f y l w j a s
o b i w j j r u u f c e j z u v v i o j k t i y h i a x u l n q o l p f c v k a i y w h r r x e z r y b g y e t m p u l s p m j z m c g b u h f h d v u c c u y d t o l f p a k o y s c f y l w j a s s

*/