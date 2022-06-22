#include<bits/stdc++.h>
using namespace std;
#define ll long long
char pt[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char ct[26]={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
string p="",c="",r="";

void encryption(){
        for(ll i=0;i<p.size();i++)
            {
                for(j=0;j<26;j++)
                    {
                        if(pt[j]==p[i])
                        {
                                    c+=ct[j];
                        }
                        }
            }
            cout << "cipher text is: " << c << '\n';
}
int main()
{
            
            
            int i,j;
            
            cout << "\n enter the plain text: ";
            cin >> p;
            

            //converting cipher text into plain text (decryption)
            for(i=0;i<strlen(c);i++)
            {
                        for(j=0;j<26;j++)
                        {
                        if(ct[j]==c[i])
                        {
                                    r[i]=pt[j];
                        }
                        }
            }
            printf("\n \n plain text is: %s",r);
           
}
