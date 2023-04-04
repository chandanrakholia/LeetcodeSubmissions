// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
    int n;
    n=students.size();
    queue<int>stu;
    queue<int>sand;
    for (int i = 0; i < n; i++)
    {
        // int x;
        // cin>>x;
        stu.push(students[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // int y;
        // cin>>y;
        sand.push(sandwiches[i]);
    }
    int count=0;
    while (sand.size()>0 and count<stu.size())
    {
        if (sand.front()==stu.front()/* and count<stu.size()*/)
        {
            sand.pop();
            stu.pop();
            count=0;
        }
        else
        {
            stu.push(stu.front());
            stu.pop();
            ++count;
        }
    }
    // if (sand.size()>0)
    // {
    //     cout<<count<<endl;
    // }
    // else
    // {
        // cout<<count<<endl;
    // }
    return count;
    
    
    

    }
};