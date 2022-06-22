#include<bits/stdc++.h>
using namespace std;
#define ll long long
string k="", s;
char table1[26][26], table2[26][26];

void create_table()
{
    for(ll i=0;i<26;i++)
    {
        for(ll j=0;j<26;j++)
        {  
            table1[i][j]=((i+j)%26)+'a';
            table2[i][j]=((i+j)%26)+'A';
    }}
}

void encryption(string s)
{   
    cout << "Cipher Text: \n";
    
    for(ll i=0; i<s.size(); i++)
    {   
        if(s[i]>='a' && s[i]<='z')
        k+= (table1[(s[i]-'a')][i%26]);
        else
        k+= (table2[(s[i]-'A')][i%26]);
        
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
        if(k[i]>='a' && k[i]<='z'){
        for(ll j=0;j<26;j++)
        {
            if(table1[j][i%26]==k[i]) {tmp+= ('a'+j);}
        }}
        else
        {
          for(ll j=0;j<26;j++)
        {
            if(table2[j][i%26]==k[i]) {tmp+= ('A'+j);}
        }  
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
