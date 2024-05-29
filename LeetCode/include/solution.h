#include <iostream>
#include <vector>
#include <unordered_map>

#include "node.h"

using namespace std;
namespace leetcode
{

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int mn = m + n;
        int m_i = m - 1;
        int n_i = n - 1;
        for(int i = mn - 1; i >= 0; --i)
        {
            if(m_i >= 0 && n_i >= 0)
            {
                if(nums1[m_i] > nums2[n_i])
                {
                    nums1[i] = nums1[m_i--];
                }
                else 
                {
                    nums1[i] = nums2[n_i--];
                }
            }
            else if(m_i >= 0)
            {
                nums1[i] = nums1[m_i--];
            }
            else if(n_i >= 0)
            {
                nums1[i] = nums2[n_i--];
            }
        }
    }


    int removeElement(vector<int>& nums, int val) {
        int res = nums.size();
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            while (l < r && nums[l] != val)
            {
                l++;
            }
            while (l < r && nums[r] == val)
            {
                r--;
                res--;
            }
            if(l < r )
            {
                std::swap(nums[l], nums[r]);
            }
            
            
        }
        if (nums.size() > 0 && nums[l] == val)
        {
            res--;
        }
        return res;
        

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* p = head;
        while(l1 != nullptr || l2 != nullptr)
        {
            if(l1 && l2)
            {
                int value = (l1->val + l2->val + carry) % 10;
                carry =  (l1->val + l2->val + carry) / 10;
                ListNode* cur = new ListNode(value);
                p->next = cur;
                p = p->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1)
            {
                int value = (l1->val + carry) % 10;
                carry =  (l1->val + carry) / 10;
                ListNode* cur = new ListNode(value);
                p->next = cur;
                p = p->next;
                l1 = l1->next;
            }
            else if (l2)
            {
                int value = (l2->val + carry) % 10;
                carry =  (l2->val + carry) / 10;
                ListNode* cur = new ListNode(value);
                p->next = cur;
                p = p->next;
                l2 = l2->next;
            }
        }
        if (carry > 0)
        {
            ListNode* cur = new ListNode(carry);
            p->next = cur;
        }
        return head->next;
    }
};
}