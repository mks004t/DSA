#include<bits/stdc++.h>
using namespace std;

int booleanParenth(string s1,string s2,int n )
{

	int dpt[n][n];
	int dpf[n][n];

	for(int gap=0; gap<n; gap++)
	{
		for(int i=0,j=gap; j<n; i++,j++)
		{
			if(gap==0)
			{
				char ch= s1[i];

				if(ch =='T')
				{
					dpt[i][j]=1;
					dpf[i][j]=0;
				}
				else
				{
					dpt[i][j]=0;
					dpf[i][j]=1;
				}
			}

			else
			{
				for(int k=i; k<j; k++)
				{
					char oprtr=s2[k];
					int LT = dpt[i][k];
					int LF = dpf[i][k];
					int RT = dpt[k+1][j]; 
					int RF = dpf[k+1][j];

					if(oprtr=='&')
					{
						dpt[i][j] += LT*RT;
						dpf[i][j] += LT*RF + LF*RT + LF*RF;
					}
					else if( oprtr=='|')
					{
						dpt[i][j] += LT*RF + LF*RT + LT*RT;
						dpf[i][j] += LF*RF;
					}
					else //( oprtr=='^')
					{
						dpt[i][j] += LT*RF + LF*RT;
						dpf[i][j] += LT*RT + LF*RF;
					}
				}
			}

		}
	}

	return dpt[0][n-1];
}

int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    
    int n=symbols.length();
    
    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
    // (T|((T&F)^T))
    cout<<booleanParenth(symbols, operators,n);
    return 0;
}