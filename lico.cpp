//===============《赎金信》===========================================================================
// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/ransom-note
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//方案一：
// ## 暴力解法
//这道题目和242.有效的字母异位词很像，242.有效的字母异位词相当于求 字符串a 和 字符串b 是否可以相互组成 ，而这道题目是求 字符串a能否组成字符串b，而不用管字符串b 能不能组成字符串a。
// 本题判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成，但是这里需要注意两点。
// ---第一点“为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思”  这里*说明杂志里面的字母不可重复使用。*
// ---第二点 “你可以假设两个字符串均只含有小写字母。” *说明只有小写字母*，这一点很重要
// 代码如下：
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        string::iterator raniter, magiter;
        int count=0;
        for(raniter=ransomNote.begin(); raniter!=ransomNote.end(); raniter++)
        {
            for(magiter=magazine.begin(); magiter!=magazine.end(); magiter++)
            {
                if(*raniter == *magiter)
                {
                    magazine.erase(magiter);
                    count++;
                    break;
                } 
            }
        }

        if(count == ransomNote.length())
            return true;
        else
            return false;

    }
};

//方案二
// ## 哈希解法
// 因为题目所只有小写字母，那可以采用空间换取时间的哈希策略， 用一个长度为26的数组还记录magazine里字母出现的次数。
// 然后再用ransomNote去验证这个数组是否包含了ransomNote所需要的所有字母。
// 依然是数组在哈希法中的应用。
// 一些同学可能想，用数组干啥，都用map完事了，其实在本题的情况下，使用map的空间消耗要比数组大一些的，因为map要维护红黑树或者哈希表，而且还要做哈希函数，是费时的！数据量大的话就能体现出来差别了。 所以数组更加简单直接有效！
// 代码如下：
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};

        for(int i=0; i<magazine.lenth(); i++)
            record[magazine[i]-'a']++;

        for(i=0; i<ransomNote.lenth(); i++)
        {
            record[ransomNote[i]-'a']--;

            if(record[ransomNote[i]-'a'] < 0)
                return false;
        }

        return true;
    }
};

//===================《Fizz Buzz》=======================================================================
// 给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：

// answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
// answer[i] == "Fizz" 如果 i 是 3 的倍数。
// answer[i] == "Buzz" 如果 i 是 5 的倍数。
// answer[i] == i （以字符串形式）如果上述条件全不满足。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/fizz-buzz
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> str;

        for(int i=1; i<=n; i++)
        {
            if(i%15 == 0)
                str.push_back("FizzBuzz");
            else if(i%3 == 0)
                str.push_back("Fizz");
            else if(i%5 == 0)
                str.push_back("Buzz");
            else
                str.push_back(to_string(i));
        }
        return str;   
    }
};

//===================《链表中间节点》=======================================================================
// 给定一个头结点为 head 的非空单链表，返回链表的中间结点。
// 如果有两个中间结点，则返回第二个中间结点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 方法一：数组
// 思路和算法
// 链表的缺点在于不能通过下标访问对应的元素。因此我们可以考虑对链表进行遍历，
//同时将遍历到的元素依次放入数组 A 中。如果我们遍历到了 N 个元素，那么链表以及数组的长度也为 N，
//对应的中间节点即为 A[N/2]。

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/middle-of-the-linked-list/solution/lian-biao-de-zhong-jian-jie-dian-by-leetcode-solut/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> list = {head};
        while(head->next != nullptr)
        {
            list.push_back(head->next);
            head = head->next;
        }
        return list[list.size() / 2];
    }
};

// 方法二：单指针法
// 我们可以对方法一进行空间优化，省去数组 A。
// 我们可以对链表进行两次遍历。第一次遍历时，我们统计链表中的元素个数 N；第二次遍历时，我们遍历到第 N/2 个元素（链表的首节点为第 0 个元素）时，将该元素返回即可。

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/middle-of-the-linked-list/solution/lian-biao-de-zhong-jian-jie-dian-by-leetcode-solut/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            ++n;
            cur = cur->next;
        }
        int k = 0;
        cur = head;
        while (k < n / 2) {
            ++k;
            cur = cur->next;
        }
        return cur;
    }
};

// 方法三：快慢指针法
// 思路和算法
// 我们可以继续优化方法二，用两个指针 slow 与 fast 一起遍历链表。slow 一次走一步，fast 一次走两步。那么当 fast 到达链表的末尾时，slow 必然位于中间。

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/middle-of-the-linked-list/solution/lian-biao-de-zhong-jian-jie-dian-by-leetcode-solut/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
1 2 3 4 5 6 7 8 9 10 11 12 13 14
1 2 3 4 5 6 7 8
1   3   5   7   9    11    13    xx
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while((slow!=nullptr)&&(slow->next!=nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

//=================《将数字变成 0 的操作次数》============================================================================
//给你一个非负整数 num ，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。
class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;

        while(num != 0)
        {
            if(num%2 == 0)
            {
                num = num / 2;
            }
            else
            {
                num--;
            }

            count++;
        }
        return count;
    }
};

// 方法一：模拟
// 思路与算法

// 将 num 与 1进行位运算来判断 num 的奇偶性。
// 记录操作次数时：
// ---如果 num 是奇数，我们需要加上一次减 1 的操作。
// ---如果 num > 1，我们需要加上一次除以 2 的操作。
// 然后使 num 的值变成 num/2, 重复以上操作直到 num=0 时结束操作。

class Solution {
public:
    int numberOfSteps(int num) {
        int ret = 0;
        while (num) {
            ret += (num > 1 ? 1 : 0) + (num & 0x01);
            num >>= 1;
        }
        return ret;
    }
};

//================《基于排列构建数组》======================================================================
// 给你一个 从 0 开始的排列 nums（下标也从 0 开始）。请你构建一个 同样长度 的数组 ans ，其中，对于每个 i（0 <= i < nums.length），都满足 ans[i] = nums[nums[i]] 。返回构建好的数组 ans 。
// 从 0 开始的排列 nums 是一个由 0 到 nums.length - 1（0 和 nums.length - 1 也包含在内）的不同整数组成的数组。
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> array;
        vector<int>::iterator iter;

        for(iter = nums.begin(); iter!=nums.end(); iter++)
            array.push_back(nums[*iter]);
            //array.push_back(nums.at(*iter));
        return array;
    }
};

//===============8.31-剑指offer 03-《找出数组中重复的数字》=============================================================
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
//也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

//方法1：直接使用hash表存储是否出现过 复杂度O(N) 空间O(N)
//了解map 和 unordered_map的用法和区别
int findRepeatNumber(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        if(mp.find(nums[i]) != mp.end()) 
            return nums[i];
        else 
            mp[nums[i]] ++;
    }
    return -1;
}
