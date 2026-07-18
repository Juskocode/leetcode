class Solution {
public:
    int parseTimeFormat_2(char d1, char d2) {
        return (d1 - '0') * 10 + (d2 - '0');
    }
    
    int parseTimeToSec(string time_) {
        int h = parseTimeFormat_2(time_[0], time_[1]);
        int m = parseTimeFormat_2(time_[3], time_[4]);
        int s = parseTimeFormat_2(time_[6], time_[7]);
        return (h * 3600) + (m * 60) + s;
    }
    
    int secondsBetweenTimes(string startTime, string endTime) {
        return parseTimeToSec(endTime) - parseTimeToSec(startTime);
    }
};