#include <bits/stdc++.h>

using namespace std;

// time complexity is O(N log N)

bool Mycomp(pair<int,int>p1,pair<int,int>p2)
{
	double r1=(double ) p1.first/p1.second;
	double r2= (double) p2.first/p2.second;
	return r1>r2;
}


double fKnapS(pair<int,int>arr[],int n,int w)
{   double result=0.00;
	sort(arr,arr+n,Mycomp);

	for(int i=0;i<n;i++)
    {   if(arr[i].second<=w)
	   {
		     result+=arr[i].first;  // adding the elements in the bag of "price"
		     w-=arr[i].second;      // decreasing the capacity of bag "Weight"
	   }
	  
	   else
	  {
		     result+=arr[i].first*((double) w/arr[i].second);  // adding the remaining part of the bag with fraction of the item
		     break;
	   }
	}

  return result;

}


int main()
{ pair<int ,int>arr[]={{120,30},{100,20},{60,10}};  // fisrt is price and second is weight of item 
  int n=3;
  int w=50;                    // capacity of the bag
  cout<<fKnapS(arr,n,w);
	

	return 0;

}