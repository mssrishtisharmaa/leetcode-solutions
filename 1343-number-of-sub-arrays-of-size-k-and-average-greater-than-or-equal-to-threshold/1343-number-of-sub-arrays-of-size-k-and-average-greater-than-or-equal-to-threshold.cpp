class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int r = k -1;
        int avg = 0;
        //first window avg 
        for (int i = 0; i<= r; i++){
            avg = avg + arr[i] ;

        }
        int count = 0;
        if( avg >= threshold * k) count ++;
        while (r < arr.size() -1){
            //movewindow
            avg = avg - arr[l];
            l++;
            r++;
            avg = avg + arr[r] ;
            if( avg >= threshold * k) count ++;


        }
        return count;
        
    }
};

//const window 

// find running avg 

//comapre avg with count and input in counter