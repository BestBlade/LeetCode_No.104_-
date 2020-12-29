/* ------------------------------------------------------------------|
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	迭代法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了99.25%的用户
*	内存消耗：19 MB, 在所有 C++ 提交中击败了24.15%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int res = 0;
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                q.emplace(curr->left);
            }
            if (curr->right) {
                q.emplace(curr->right);
            }
        }
        res++;
    }
    return res;
}