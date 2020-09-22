class Solution {
public:
    struct account {
        string name;
        set<string>email;
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<account> v;
        account acc;
        acc.name = accounts[0][0];
        for (int i = 1; i < accounts[0].size(); i++)
            acc.email.insert(accounts[0][i]);
        v.push_back(acc);
        vector<bool>merged(accounts.size());
        merged[0] = true;
        for (int m = 1; m < accounts.size(); m++) {
            for (auto p = v.begin(); p != v.end(); p++) {
                for (int i = 1; i < accounts.size(); i++) {
                    if (merged[i])continue;
                    if (accounts[i][0] == p->name && !merged[i]) {
                        for (int j = 1; j < accounts[i].size(); j++)
                            if (p->email.find(accounts[i][j]) != p->email.end()) {
                                merged[i] = true;
                                for (int k = 1; k < accounts[i].size(); k++)
                                    p->email.insert(accounts[i][k]);
                                m--;
                                if (m < 0)m = 0;
                            }
                    }
                }
            }
            if (!merged[m]) {
                account tmp;
                tmp.name = accounts[m][0];
                for (int i = 1; i < accounts[m].size(); i++)
                    tmp.email.insert(accounts[m][i]);
                v.push_back(tmp);
            }
        }

        vector<vector<string>>ans;
        for (auto p = v.begin(); p != v.end(); p++) {
            vector<string>temp;
            temp.push_back(p->name);
            for (auto i = p->email.begin(); i != p->email.end(); i++)
                temp.push_back(*i);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;

    }
};