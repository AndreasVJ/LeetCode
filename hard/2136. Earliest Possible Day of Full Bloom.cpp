class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> zipped;
        for(size_t i=0; i < plantTime.size(); ++i) {
            zipped.push_back(make_pair(plantTime[i], growTime[i]));
        }

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