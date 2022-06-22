#include<bits/stdc++.h>
using namespace std;
#define ll long long
string k="", s;
char table[26][26];

void create_table()
{
    for(ll i=0;i<26;i++)
    {
        for(ll j=0;j<26;j++)
            table[i][j]=((i+j)%26)+'a';
    }
}

void encryption(string s)
{   
    cout << "Cipher Text: \n";
    
    for(ll i=0; i<s.size(); i++)
    {
        k+= (table[(s[i]-'a')][i%3]);
       // cout << k[i];
    }
    cout << k;
    cout << '\n';
    
}

void decryption()
{       
    
    cout << "Plain Text: \n";
    string tmp="";
    for(ll i=0; i<k.size();i++){
        for(ll j=0;j<26;j++)
        {
            if(table[j][i%3]==k[i]) {tmp+= ('a'+j);}
        }
    }
    cout << tmp;
}

int main()
{
    create_table();
    cout <<"Enter text: \n";
    cin >> s;
    encryption (s);
    
    decryption ();       
}
