//Question 1:- 875. Koko Eating Bananas Leetcode
//Question link:- https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Solution 1 Brute Force Not accepted
        /*int speed = 1;
        while(true){
            int hourSpent = 0;
            for(int i=0;i<piles.size();i++){
                hourSpent += piles[i]/speed+(piles[i]%speed!=0);
                if(hourSpent>h) break;
            }

            if(hourSpent>h) speed++;
            else return speed;
        }*/

        //Solution 2 Binary Search

        int left = 1;
        int right = *max_element(piles.begin(),piles.end());

        while(left<right){
            int mid = (left+right)/2;

            int hourSpent = 0;
            for(auto pile: piles){
                hourSpent +=  pile/mid+(pile%mid!=0);
                if(hourSpent>h) break;
            }
            if(hourSpent>h) left = mid+1;
            else right = mid;
        }
        return right;
    }
};
