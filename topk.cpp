class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(string word : words)
        {
            mp[word]++;
        }
        vector<pair<string, int>> v;
        for(auto i:mp)
        {
            v.push_back(make_pair(i.first,i.second));
        }
        sort(v.begin(),v.end(),[](pair<string,int> &x, pair<string,int> &y){
            if(x.second==y.second) return x.first<y.first;
            return x.second>y.second;
        });
        vector<string> answer;
        for(int i=0;i<k;i++)
        {
            answer.push_back(v[i].first);
        }
        return answer;
    }
};
