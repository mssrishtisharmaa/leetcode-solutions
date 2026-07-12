class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        // str hours_s , min_s, sec_s;
        // str hours_e , min_e, sec_e;
        // for ( inti i = 0 ; i < 8; i++){
        //     hours_s 
        // } 
        string hours_s = startTime.substr(0,2);
         string min_s = startTime.substr(3,2);
         string sec_s = startTime.substr(6,2);
         string hours_e = endTime.substr(0,2);
         string min_e = endTime.substr(3,2);
         string sec_e = endTime.substr(6,2);

        int h_s = stoi(hours_s);
        int m_s = stoi(min_s);
        int s_s = stoi(sec_s);
        int h_e = stoi(hours_e);
        int m_e = stoi(min_e);
        int s_e = stoi(sec_e);

        

        int total_sec_start =( h_s * 3600) + (m_s * 60) + s_s;
        int total_sec_end = ( h_e * 3600) + (m_e * 60 ) + s_e;
        int ans = total_sec_end - total_sec_start;
        if (ans < 0)
    ans += 24 * 3600;
        return ans;
        


        // int num = stoi(str);
    }
};