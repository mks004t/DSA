#include<bits/stdc++.h>
using namespace std;

//  O(N) time and O(1) time complexity

      void reverse (vector<int> &v, int i,int j)
      {
      	 while(i<j)
      	 {
      	 	swap(v[i],v[j]);
      	 	i++;
      	 	j--;
      	 }	
      }

void eleftRotete(vector<int>&v ,int k)
{  int n=v.size();
	reverse(v,0,k-1);  // rotate the first k element
	reverse(v,k,n-1);  // rotate the k to n element
	reverse(v,0,n-1);  //now rotate whole array
}

// 0(N+k) time and O(K) Space complexity
void leftRotate(vector<int> &v,int k)
{
	int n = v.size();
	vector<int> temp;
	int i=0;
	while(i<k)
	{
		temp.push_back(v[i]);
		i++;
	}	 
	for(int i=0;i<n;i++)
	{ 
    	v[i]=v[i+k];
	}
	for(int i=0;i<k;i++)
	{
		v[n-k+i]=temp[i];
	}

}

int main()
{
	vector<int> v={1,2,3,4,5,6,7};
	int k = 3;

	//leftRotate(v,k);
	 eleftRotete(v,k);

	for(auto i: v)
	{
		cout<<i<<" ";
	}

	return 0;

}