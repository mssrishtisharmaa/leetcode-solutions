class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int l = 0;
        int r = 0;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for( int i = 0; i < s1.size() ;i++){
            freq1[s1[i] - 'a']++;
        }

        while( r < s2.size()){
            freq2[s2[r] - 'a']++;

            if( (r-l +1) > s1.size()){
            freq2[s2[l] - 'a']--;
            l++;

            }

            if(freq1 == freq2) return true;


            r++;
        }
        return false;
    }
};

// fiexed window of lengh size of s1

// love that iwnodw in s2

// we need to match 

// we can make match array of size s1 and then as we find the same char in winodw and s1 we update that match array to one if the window makes all viss arry to one then we return true and exit else return false 

// space complxity = o(s1)

// tc o( n * N * N) WORST 



// OPTIMAL ( 0 (N ))

// COMAPRE USING FREQUENCY 

// MAINTIAN FREQ OF S1 AND COMPARE IT WITH S2 

// AS I ENETR WINDOW ( UPDATE FREQ OF RIGHT CHARTER )
// IF NOT VALID : reduce fre of left element , left ++ 


// VALID CONDITION : IF ( FREQ == FREQ2  )( RETURN TURE ; BREAK;)