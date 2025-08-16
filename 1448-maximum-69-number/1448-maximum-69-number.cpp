class Solution {
public:
    int maximum69Number (int num) {
        int tmp = num, place = 1, best = 0;
        while (tmp > 0) {
            if (tmp % 10 == 6) best = place;
            tmp /= 10;
            place *= 10;
        }
        return num + 3 * best;
    }
};
