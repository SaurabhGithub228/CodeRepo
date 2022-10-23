class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> alphabet(256,0);
        vector<int> al(256,0);
        int l=t.length();
        int n=s.length();
        for(int i=0;i<l;i++) alphabet[t[i]-'A']++;
        int start=0;
        int front=-1;
        int len=INT_MAX;
        int count=0;
        for(int i=0;i<n;i++){
            al[s[i]-'A']++;
            if(alphabet[s[i]-'A'] >0 && alphabet[s[i]-'A'] >= al[s[i]-'A']) count++;
            
            if(count==l){
                while(alphabet[s[start]-'A']==0 || (alphabet[s[start]-'A']<al[s[start]-'A'])){
                    if(al[s[start]-'A']>alphabet[s[start]-'A']) al[s[start]-'A']--;
                    start++;
                }
                int lt=i-start+1;
                if(lt<len){
                    len=lt;
                    front=start;
                }
            }
            
        }
        return front==-1? "" : s.substr(front,len);
    }
};
