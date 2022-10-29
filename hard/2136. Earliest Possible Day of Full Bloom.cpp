class Solution {
public:
    
    void zip(const vector<int> &a, const vector<int> &b, vector<pair<int,int>> &zipped) {
        for(size_t i=0; i<a.size(); ++i){
            zipped.push_back(std::make_pair(a[i], b[i]));
        }
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> zipped;
        zip(plantTime, growTime, zipped);

        sort(zipped.begin(), zipped.end(), [&](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        
        int max = zipped[0].first + zipped[0].second;

        for (int i = 1; i < zipped.size(); i++) {
            zipped[i].first += zipped[i-1].first;
            if (zipped[i].first + zipped[i].second > max) max = zipped[i].first + zipped[i].second;
        }
        
        return max;
    }
};