#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
//frequency of different characters 
        unordered_map<char,int> mp;
       
        for(auto it: tasks)  
            mp[it]++;
 //Priority queue to get the task with max frequency
        priority_queue<int> pq;
        for(auto it: mp)
            pq.push(it.second);
//
        int result = 0 ,time;
      
        while(pq.empty()==false)
        {    time=0;
             vector<int> temp;
         
           for(int i=0;i<=n;i++)
           {
               if(!pq.empty())
               {
                   temp.push_back(pq.top()-1);
                   pq.pop();
                   time++;
               }
            }
         
           for(auto it: temp)
            {
              if(it) 
              pq.push(it);
            }
//for the remaning A          
          result+= pq.empty() ? time : n+1;
             
        }
        return result;
    }
};