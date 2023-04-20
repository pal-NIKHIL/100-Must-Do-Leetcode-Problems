// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. Given an array of integers nums, find the next permutation of nums. The replacement must be in place and use only constant extra memory.

//leetcode link-https://leetcode.com/problems/next-permutation/description/

#include<bits/stdc++.h>
using namespace std;

void permuatation(int start,int end,vector<int>&nums,vector<vector<int>> &all){
    if(start==end){
        all.push_back(nums);
        return;
    }
    for(int i=start;i<=end;i++){
    swap(nums[start],nums[i]);
    permuatation(start+1,end,nums,all);
    swap(nums[start],nums[i]);
    }
}

int main()
{
    vector<int> nums= {1,2,3};
    
    // Approach 1 (Brute Force) 
    // Time Complexity O(n!) because of all permutation .
     vector<vector<int>> all;
        permuatation(0,nums.size()-1,nums,all);
        sort(all.begin(),all.end());
        for(auto i:all){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<all.size();i++){
            if(all[i]==nums){
                if(i==all.size()-1){ nums= all[0];break;}
                else if(i<all.size()-1 && all[i]!=all[i+1]){ nums= all[i+1];break;}
            }
        }
    
    //Approach 2(using stl)

    next_permutation(nums.begin(),nums.end());

    //Approah 3(optimize)
 for (int i = 1; i <=5; i++)
 {
    int j;
   for (j = 1; j <=5-i; j++)
   {
    cout<<" ";
   }
   int k=i;
   for(;j<=5;j++){
    cout<<k--;
   }
   k=2;
   for(;j<=5+i-1;j++){
    cout<<k++;
   }
    cout<<endl;
 }
 
        
}