// 4 ms | 25.1 MB
class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++){
            int element =  a[i];
            int element_position = a[i] - 1;

            if(a[i] <= n && element != a[element_position]){
                swap(a[i], a[element_position]);
                i--;
            }
        }

        for(int i = 0; i < n; i++){
            if(a[i] != i + 1){
                return {a[i], i + 1};
            }
        }
        return{};
    }
};