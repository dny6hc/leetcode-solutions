class Solution {
public:
    bool isPalindrome(int x) {
        // Loại các trường hợp không hợp lệ
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int revNum = 0;
        // Đảo nửa sau của số
        while (x > revNum) {
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }
        // So sánh nửa đầu và nửa sau
        return (x == revNum || x == revNum / 10);
    }
};
