#include<bits/stdc++.h>
using namespace std;

//O(n)

int main()
{  string str;
	getline(cin,str);
    int end=str.length()-1;   //Importent
    int start=0;
    int flag =1;
    while(end> start)
    {
    	if(str[start]!=str[end])
    		{flag=0; 
    		  break;
    		}
    	end--;
    	start++;
    }
   (flag==1)? cout<<"Plaindrome" : cout<<"Not A Palindrome";
	cout<<endl<<flag;
	return 0;
}