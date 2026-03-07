#include <bits/stdc++.h>
using namespace std;



class Tries{
public:
    Tries* child[26];
    int cnt;  
    Tries(){
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
        cnt = 0;
    }
};






class Solution {
public:
    int prefixConnected(vector<string>& words, int k){
        Tries *root = new Tries();

        for(string word:words){
            if(word.length()>=k){
                Tries *node= root;
                // k char
                for(int i=0;i<k;i++){
                    int idx = word[i]-'a';
                    if(node->child[idx]==nullptr){
                        node->child[idx] = new Tries();
                    }
                    node = node->child[idx];
                    node->cnt++;
                }
            }
        }



        int g=0;
        queue<pair<Tries* ,int >> q;
        q.push({root,0});
        //bfs
        while(!q.empty()){
            auto n = q.front();
            int d= n.second;
            Tries* t = n.first;
            q.pop();

            for(int i=0;i<26;i++){
                if(t->child[i]!=nullptr){
                    if(d==k-1){
                        if(t->child[i]->cnt>=2){
                            g++;
                        }
                    }else{
                        q.push({t->child[i],d+1});
                    }
                }
            }

        }

        return g;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution sol;
    vector<string> words = {"apple","apply","banana","bandit"};
    int k = 2;
    cout << sol.prefixConnected(words, k) << endl;

    return 0;
}