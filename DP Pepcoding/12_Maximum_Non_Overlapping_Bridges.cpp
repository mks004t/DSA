#include<bits/stdc++.h>
using namespace std;

//Application of LIS 
struct CityPairs
{
    int north, south;
};

bool mycomp(struct CityPairs a,struct CityPairs b)
{
	if(a.north==b.north)
		return a.south <b.south;

	return a.north<b.north;
}

int maxBridges(struct CityPairs values[],int n)
{
	int LIS[n];
	LIS[0]=1;

	sort(values,values+n,mycomp);

	for(int i=1;i<n;i++)
	{
		LIS[i]=1;
		for(int j=0;j<i;j++)
		{
			if(values[i].south>=values[j].south)
				LIS[i]=max(LIS[i],1+LIS[j]);
		}
	}
    
    int ans=INT_MIN;
	for(int i=0;i<n;i++)
		ans=max(ans,LIS[i]);

	return ans;
};

int main()
{
    struct CityPairs values[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};
    int n = 4;
    cout << maxBridges(values, n);   
    return 0;
}
