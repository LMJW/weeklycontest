#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

struct myhashvec {
    vector<int> v;
    myhashvec(vector<int> vv) : v(vv) {}

    bool operator==(const myhashvec& other) const {
        if (v.size() == other.v.size()) {
            for (int i = 0; i < v.size(); ++i) {
                if (v.at(i) != other.v.at(i)) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

template <>
struct hash<myhashvec> {
    size_t operator()(const myhashvec& m) const {
        auto res = hash<int>()(13);
        for (auto it = m.v.begin(); it != m.v.end(); ++it) {
            res ^= (hash<int>()(*it) << 1);
        }
        return res;
    }
};

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        vector<pair<int, int>> spair;
        unordered_set<int> hash;
        unordered_set<myhashvec> store;
        for (int i = 0; i < A.size(); ++i) {
            for(int j = i+1; j<A.size();++j){
                int x = A[i]+A[j];
                auto t = sqrt(x);
                if (int(t) * int(t) == x) {
                    spair.push_back(make_pair(A[i], A[j]));
                    hash.insert(A[i]);
                    hash.insert(A[j]);
                }
            }
        }

        for (auto it = hash.begin(); it != hash.end(); ++it) {
            vector<int> tmp = vector<int>{*it};
            _dfs(tmp, store, spair, A.size());
        }

        int res_count = 0;
        /// ugly solution
        unordered_map<int,int> hash_a;
        for(int i =0;i<A.size();++i){
            if(hash_a.find(A[i]) == hash_a.end()){
                hash_a[A[i]]=1;
            }else{
                ++hash_a[A[i]];
            }
        }


        for(auto it = store.begin(); it !=store.end();++it){
            auto tmp = *it;
            if (tmp.v.size()!=A.size()){
                continue;
            }else if(tmp.v.size() == A.size()){
                bool all_same = true;
                unordered_map<int,int> hash_tmp;
                for(int i =0;i<tmp.v.size();++i){
                    if(hash_tmp.find(tmp.v[i]) == hash_tmp.end()){
                        hash_tmp[tmp.v[i]]=1;
                    }else{
                        ++hash_tmp[tmp.v[i]];
                    }
                }

                for(auto it = hash_tmp.begin(); it!=hash_tmp.end();++it){
                    auto key = it->first;
                    auto val = it->second;
                    if (val != hash_a[key]){
                        all_same = false;
                        break;
                    }
                }
                if(all_same){
                    ++res_count;
                }
            }
        }
        return  res_count;
    }
    void _dfs(vector<int> path,
              unordered_set<myhashvec>& st,
              vector<pair<int, int>> ps,
              size_t ts) {
        /// assume path length > 0
        auto y = myhashvec(path);
        if (st.find(y) == st.end()){
            st.insert(y);
        }else{
            return;
        }


        int idx = path.size() - 1;
        for (int i = 0; i < ps.size(); ++i) {
            auto a = ps[i].first;
            auto b = ps[i].second;
            if (a == path[idx]) {
                auto np = vector<int>(path);
                np.push_back(b);
                auto pss = vector<pair<int, int>>(ps);
                pss.erase(pss.begin() + i);
                _dfs(np, st, pss, ts);
            }
            if (b == path[idx] && b != a) {
                auto np = vector<int>(path);
                np.push_back(a);
                auto pss = vector<pair<int, int>>(ps);
                pss.erase(pss.begin() + i);
                _dfs(np, st, pss, ts);
            }
        }
        if (path.size() == ts) {
            st.insert(myhashvec(path));
        }
    }
};

int main() {
    vector<int> a = vector<int>{0,0,0,0,1,1,1,1};
    auto x = Solution().numSquarefulPerms(a);
    cout << x << endl;
}