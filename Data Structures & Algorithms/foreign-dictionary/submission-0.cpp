class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> inDegree;
        for(auto word:words){
            for(char c:word){
                inDegree[c]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i],w2 = words[i+1];
            int len = min(w1.size(),w2.size());
            bool found = false;
            for(int j=0;j<len;j++){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    found = true;
                    break;
                }
            }
            if (!found && w1.size() > w2.size()) return "";
        }
        queue<char> q;
        for(auto inDeg:inDegree){
            char ch = inDeg.first;
            int num = inDeg.second;
            if(num==0) q.push(ch);
        }
        string result;
        while(!q.empty()){
            char c = q.front();
            q.pop();
            result+=c;
            for(char nei:adj[c]){
                inDegree[nei]--;
                if(inDegree[nei]==0) q.push(nei);
            }
        }
        return result.size()==inDegree.size()?result:"";
    }
};
