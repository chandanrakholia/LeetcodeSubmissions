// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    // int n;
    // int arr[]={6,2,5,4,5,1,6};
    // n=sizeof(arr)/sizeof(arr[0]);

    //FOR NSL

    vector<int>v1;
    stack<pair<int,int>>s1;
    for (int i =0; i<heights.size(); i++)
    {
        if (s1.size()==0)
        {
            v1.push_back(-1);
            // cout<<-1<<endl;
        }
        else if (s1.size()>0 && heights[i]>s1.top().first)
        {
            v1.push_back(s1.top().second);
            // cout<<s.top()<<endl;
        }
        else if (s1.size()>0 && heights[i]<=s1.top().first)
        {
            while (s1.size()>0 and s1.top().first>=heights[i])
            {
                s1.pop();
            }
            if (s1.size()==0)
            {
                v1.push_back(-1);
                // cout<<-1<<endl;
            }
            else
            {
                v1.push_back(s1.top().second);
                // cout<<s.top()<<endl;
            }
            
        }
        
        s1.push({heights[i],i});
        
    }

    //FOR NSR
    vector<int>v2;
    stack<pair<int,int>>s2;
        for (int i =heights.size()-1; i>=0; i--)
    {
        if (s2.size()==0)
        {
            v2.push_back(heights.size());
            // cout<<-1<<endl;
        }
        else if (s2.size()>0 && heights[i]>s2.top().first)
        {
            v2.push_back(s2.top().second);
            // cout<<s.top()<<endl;
        }
        else if (s2.size()>0 && heights[i]<=s2.top().first)
        {
            while (s2.size()>0 and s2.top().first>=heights[i])
            {
                s2.pop();
            }
            if (s2.size()==0)
            {
                v2.push_back(heights.size());
                // cout<<-1<<endl;
            }
            else
            {
                v2.push_back(s2.top().second);
                // cout<<s.top()<<endl;
            }
            
        }
        
        s2.push({heights[i],i});
        
    }
    reverse(v2.begin(),v2.end());

    int area[heights.size()];
    int width[heights.size()];
    for (int i = 0; i < heights.size(); i++)
    {
        width[i]=v2[i]-v1[i]-1;
    }
    
    for (int i = 0; i < heights.size(); i++)
    {
        area[i]=heights[i]*width[i];
        // cout<<area[i]<<endl;
    }

    return *max_element(area,area+heights.size());       
    }
};