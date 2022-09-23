class Solution {
public:
    bool isRobotBounded(string ins) {
        int x = 0, y = 0, d = 0;
        for (char & chr : ins) {
            if (chr == 'L') {
                d = (d + 3) % 4;
            }
            else if (chr == 'R') {
                d = (d + 1) % 4;
            }
            else {
                if (d == 0) ++y;
                else if (d == 1) --x;
                else if (d == 2) --y;
                else ++x;
            }
        }
        return (x == 0 and y == 0) or d != 0;
    }
};