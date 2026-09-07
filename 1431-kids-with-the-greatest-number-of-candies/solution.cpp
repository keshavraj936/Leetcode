// 0 ms | 12.4 MB
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //max element
        int max = 0;
        for(int i = 0; i < candies.size(); i++){
            if(max < candies[i]){
                max = candies[i];
            }
        }
        //add extra candy to child array
        vector <bool> arr;
        for(int i = 0; i < candies.size(); i++){
            int x = candies[i] + extraCandies;
            if(x >= max){
                arr.push_back(true);
            }else{
                arr.push_back(false);
            }
        }

        return arr;


       

    }
};