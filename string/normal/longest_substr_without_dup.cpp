class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // lastoccur[c] lưu vị trí xuất hiện GẦN NHẤT của ký tự c
        // Khởi tạo 256 phần tử (ASCII), tất cả = -1 (chưa xuất hiện)
        vector<int> lastoccur(256, -1);

        int left = 0;     // Con trỏ trái của cửa sổ trượt
        int maxlen = 0;   // Độ dài lớn nhất của substring hợp lệ

        // Con trỏ phải mở rộng cửa sổ trượt
        for (int right = 0; right < s.size(); right++) {

            // Nếu ký tự hiện tại đã xuất hiện trong cửa sổ [left, right - 1]
            // thì dời left đến sau vị trí xuất hiện trước đó
            if (lastoccur[s[right]] >= left) {
                left = lastoccur[s[right]] + 1;
            }

            // Cập nhật vị trí xuất hiện gần nhất của ký tự hiện tại
            lastoccur[s[right]] = right;

            // Cập nhật độ dài substring lớn nhất
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
