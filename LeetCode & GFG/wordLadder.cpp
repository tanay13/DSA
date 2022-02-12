class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        map<string, bool> m;
        map<int, vector<char>> idx;

        map<string, bool> visited;

        for (int i = 0; i < wordList.size(); i++)
            m[wordList[i]] = true;

        if (m.find(endWord) == m.end())
            return 0;

        for (int i = 0; i < beginWord.size(); i++)
        {
            map<char, bool> n;

            for (int j = 0; j < wordList.size(); j++)
            {

                if (n[wordList[j][i]] != true)
                {
                    idx[i].push_back(wordList[j][i]);
                    n[wordList[j][i]] = true;
                }
            }
        }

        queue<pair<string, int>> q;

        q.push(make_pair(beginWord, 1));

        visited[beginWord] = 1;

        int ans = INT_MAX;

        while (q.size() > 0)
        {
            auto st = q.front().first;
            auto ind = q.front().second;

            q.pop();

            if (st == endWord)
            {
                ans = min(ans, ind);
                continue;
            }

            for (int i = 0; i < st.length(); i++)
            {

                for (auto it : idx[i])
                {

                    if (st[i] == it)
                        continue;
                    string t = st;

                    t[i] = it;

                    if (m.find(t) == m.end())
                        continue;

                    if (visited[t] != 1)
                    {
                        q.push(make_pair(t, 1 + ind));
                        visited[t] = 1;
                    }
                }
            }
        }

        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};