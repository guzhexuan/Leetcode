/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，
     在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，
     在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

示例 2：
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，
     在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3：
输入：prices = [7,6,4,3,1] 
输出：0 
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。

示例 4：
输入：prices = [1]
输出：0
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    dp思路：
        用buy1表示某一天进行第一次股票购买后所拥有的最大利润
        用sell1表示某一天进行第一次股票抛售后所拥有的最大利润
        buy2
        sell2
        分别就是进行第二次，转移思路比较简单，在代码里写出
    */
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        int buy1 = -prices[0], sell1 = 0, buy2 = INT32_MIN, sell2 = 0;
        for(int i = 1 ; i < days ; i ++){
            buy1 = max(buy1, -prices[i]);    // buy1我们始终保持自己用最低的价格进行股票购入
            sell1 = max(sell1, prices[i] + buy1);    // 卖出第一次的话就是和前面买进的价格相加(因为保留的是负数)即可
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, prices[i] + buy2);
        }
        return sell2;
    }
};

int main(){
    return 0;
}