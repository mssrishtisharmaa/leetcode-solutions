class Solution {
public:
    int maxVowels(string s, int k) {
        //constant window 
        int count = 0;
        //forst wondow 
        int l = 0;
        int r = k-1;

        for ( int i = 0 ; i <= r ; i++ ){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            count ++;
        }
        int maxcount = count;

        while(r < s.size()){
            //slide 
             if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
             count --;

             l ++;

             r++;
              if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u')
             count ++;
             maxcount = max(maxcount , count);



            
        }
        return maxcount;

        
    }
};

// keep track of vowels in winow slide the window and update count