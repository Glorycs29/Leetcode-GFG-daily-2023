long long distinctNames(vector<string>& ideas) {
        unordered_set<string> map[26]; 
        for (string& name : ideas){
            map[name[0]-'a'].insert(name.substr(1)); 
        }
        long long res = 0;
        for (int i = 0; i < 25; i++){
            for (int j = i+1; j < 26; j++){
                int total1 = 0, total2 = 0;
                for (auto& substring : map[i]){
                    if (map[j].find(substring) == map[j].end()){
                        total1++;
                    }
                }
                for (auto& substring : map[j]){
                    if (map[i].find(substring) == map[i].end()){
                        total2++;
                    }
                }
                res += total1*total2;
            }
        }
        return res*2;
    }
