class MyCalendar
{
public:
    map<int, int> m;
    vector<pair<int, int>> v;

    MyCalendar()
    {
    }

    //     bool book(int start, int end) {

    //         m[start]++;
    //         m[end]--;
    //         int sum = 0;
    //         for(auto it = m.begin();it!=m.end();it++)
    //         {

    //             sum+=it->second;

    //             if(sum > 1)
    //             {
    //                 m[start]--;
    //                 m[end]++;
    //                 return false;
    //             }

    //         }

    //         return true;

    //     }
    bool book(int start, int end)
    {

        for (auto it : v)
        {

            if (it.second > start && it.first < end)
                return false;
        }
        v.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */