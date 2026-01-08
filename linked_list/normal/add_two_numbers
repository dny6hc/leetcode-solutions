/**
 * Định nghĩa cho singly-linked list.
 * Mỗi node lưu một chữ số của số cần biểu diễn.
 */
struct ListNode {
    int val;            // Giá trị của node (1 chữ số)
    ListNode *next;     // Con trỏ tới node tiếp theo

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Hàm cộng hai số được biểu diễn bằng linked list.
     *
     * @param l1 Linked list thứ nhất (chữ số lưu ngược)
     * @param l2 Linked list thứ hai (chữ số lưu ngược)
     * @return Linked list kết quả (chữ số lưu ngược)
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node (node giả)
        // Dùng để đơn giản hoá việc xây dựng linked list kết quả
        // Node này KHÔNG chứa dữ liệu kết quả thực
        ListNode dummy(0);

        // Con trỏ curr dùng để xây dựng danh sách kết quả
        ListNode* curr = &dummy;

        // Biến nhớ (carry) dùng cho phép cộng
        int carry = 0;

        // Lặp khi còn chữ số để cộng hoặc còn carry
        while (l1 || l2 || carry) {

            // Lấy giá trị hiện tại của mỗi list
            // Nếu list đã hết thì coi như giá trị là 0
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Tổng của hai chữ số và carry
            int sum = x + y + carry;

            // Cập nhật carry cho vòng lặp tiếp theo
            carry = sum / 10;

            // Tạo node mới chứa chữ số hiện tại (sum % 10)
            curr->next = new ListNode(sum % 10);

            // Di chuyển curr sang node vừa tạo
            curr = curr->next;

            // Di chuyển con trỏ của hai list đầu vào (nếu còn)
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // Trả về node đầu tiên của kết quả (bỏ qua dummy)
        return dummy.next;
    }
};
