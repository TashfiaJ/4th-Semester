#include<bits/stdc++.h>
using namespace std;
#define ll long long
char pt[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char ct[26]={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
string p="",c="",r="";

void encryption(){
        for(ll i=0;i<p.size();i++)
            {
                for(ll j=0;j<26;j++)
                    {
                        if(pt[j]==p[i])
                        {
                                    c+=ct[j];
                        }
                        }
            }
            cout << "cipher text is: " << c << '\n';
}

void decryption()
{
            
            for(ll i=0;i<c.size();i++)
            {
                        for(ll j=0;j<26;j++)
                        {
                        if(ct[j]==c[i])
                        {
                                    r+=pt[j];
                        }
                        }
            }
            cout << "plain text is: " << r;
}

int main()
{
            
            
            
            
            cout << "\nenter the plain text: ";
            cin >> p;
            encryption();
            decryption(); 
           
}
