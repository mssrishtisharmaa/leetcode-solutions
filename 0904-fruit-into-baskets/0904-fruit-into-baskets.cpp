class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //sliding window 

        int l = 0;
        int r = 0;
        int maxlen = 0;
        unordered_map<int , int> basket;

        while(r < fruits.size()){
            // update 
           basket[fruits[r]]++;


            //invalid//shriink
            if(basket.size() > 2){
                basket[fruits[l]]--;

                if(basket[fruits[l]] == 0) 
                basket.erase(fruits[l]);

                l++;
            }

            if(basket.size() <= 2) maxlen = max(maxlen , r-l+1);


            //valid

            r++;
        }
        return maxlen;
        
    }
};