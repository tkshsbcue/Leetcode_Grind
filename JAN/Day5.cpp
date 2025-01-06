class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> sol(boxes.size(),0);
        for(int i = 0; i < boxes.size(); i++){
            int temp = 0;
            for(int j = 0; j < boxes.size(); j++){
                if(boxes[j] == '1'){
                    temp += abs(i - j);
                }
                sol[i] = temp;
            }
        }

        return sol;

    }
};