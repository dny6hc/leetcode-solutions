#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode #1 – Two Sum
    Difficulty: Easy
    Pattern: Hash Map

    Ý tưởng:
    - Duyệt mảng từ trái sang phải
    - Với mỗi phần tử nums[i], ta cần tìm một số trước đó sao cho:
          nums[i] + x = target
      => x = target - nums[i]

    - Sử dụng unordered_map để lưu:
          key   = giá trị đã duyệt
          value = index của giá trị đó

    - Trong quá trình duyệt:
        1. Tính số còn thiếu (target - nums[i])
        2. Nếu số này đã tồn tại trong map:
             → ta đã tìm được cặp thỏa mãn
        3. Nếu chưa:
             → lưu nums[i] và index i vào map để dùng cho các bước sau

    Độ phức tạp:
    - Time:  O(n)  (duyệt mảng đúng 1 lần)
    - Space: O(n)  (map lưu tối đa n phần tử)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map lưu: giá trị -> index
        unordered_map<int, int> mp;

        // Duyệt từng phần tử trong mảng
        for (int i = 0; i < nums.size(); i++) {

            // Số còn thiếu để đạt target
            int need = target - nums[i];

            // Kiểm tra xem số còn thiếu đã xuất hiện trước đó chưa
            if (mp.count(need)) {
                // Nếu có:
                // mp[need]  : index của số xuất hiện trước
                // i         : index hiện tại
                return {mp[need], i};
            }

            // Nếu chưa tìm thấy cặp phù hợp,
            // lưu số hiện tại và index của nó vào map
            mp[nums[i]] = i;
        }

        // Theo đề bài, luôn tồn tại đúng 1 nghiệm,
        // dòng này chỉ để tránh warning của compiler
        return {};
    }
};
