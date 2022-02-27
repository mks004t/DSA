#include<bits/stdc++.h>
using namespace std;

//Anagram: a word that is made by arranging the letters of another word in a different order.
//Step1: Count array of length 256 with all elements 0.
//Step2: increase the count of the letter from S1 string.
//         and decrease from S2 string.
//Step3: check if all the elements of count array is 0 or not.
//       if not O print false (Not An Anagram) else true. 

const int CHAR= 256;
bool isAnagram(string &s1,string &s2)
{
	if(s1.length()!=s2.length())
	    return false;

	int count[CHAR]={0};     //count array of 256 length
	for(int i=0; i < s1.length(); i++) 
	{   
		count[s1[i]]++;
		count[s2[i]]--;
	}
	
	for(int i=0; i<CHAR ;i++)
		if(count[i]!=0)
			return false;

	return true;
}

int main()
{
	string str1,str2;
	getline(cin,str1);
    getline(cin,str2);
    
   
    cout<<isAnagram(str1,str2);
	return 0;
}