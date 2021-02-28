
08 - 中等，按中序遍历，在二叉树中寻找给定节点的下一个节点

13 - 中等，回溯法，建立visited，记得置位后是否需要复位

14 - 中等，DP，贪婪算法，剪绳子使得各段乘积达最大

**:star2:[15](./Chapter_2/Sword_15_NumberOf1InBinary.cpp) - 中等，有趣，计算X的二进制表示中1的个数**

**[18.02](./Chapter_3/Sword_18_02_DeleteDuplicatedNode.cpp) - 偏难，恶心，删除链表中的重复元素**

**[19](./Chapter_3/Sword_19_RegularExpressions.cpp) - 偏难，字符串的正则匹配，使用递归**

**[20](./Chapter_3/Sword_20_NumericStrings.cpp) - 中等，恶心，判断某字符串是否表示数字，特殊情况多**

~~21 - E - 简单~~

~~22 - E - 简单~~

**[23](./Chapter_3/Sword_23_EntryNodeInListLoop.cpp) - 中等，快慢指针，寻找链表中环形的入口**

[24](./Chapter_3/Sword_24_ReverseList.cpp) - 简单，翻转链表，记得把原头的next成员置空即可

**[25](./Chapter_3/Sword_25_MergeSortedLists.cpp) - 中等，合并排序的链表，递归（也可以不用递归）**

**[26](./Chapter_3/Sword_26_SubstructureInTree.cpp) - 中等，判断树B是否为树A的子树，递归就行（也可以不用递归，但比较麻烦）**

**[27](./Chapter_4/Sword_27_MirrorOfBinaryTree.cpp) - 简单，二叉树镜像翻转，递归（也可以不用递归）**

**[28](./Chapter_4/Sword_28_SymmetricalBinaryTree.cpp) - 中等，有趣，判断二叉树是否镜像**

~~29 - E -简单~~

30 - 中等，有趣，使用辅助栈构建O(1)最小栈

**[31](./Chapter_4/Sword_31_StackPushPopOrder.cpp) - 中等，判断push栈和pop栈是否合法**

32.03 - 简单，之字形打印二叉树，使用stack即可

**[33](./Chapter_4/Sword_33_SquenceOfBST.cpp) - 中等，判断数组是否是二叉搜索树的后序遍历结果**

**:star2:[35](./Chapter_4/Sword_35_CopyComplexList.cpp) - 困难，恶心，复制复杂链表**

**[36](./Chapter_4/Sword_36_ConvertBinarySearchTree.cpp) - 中等，恶心，把二叉搜索树转换成双向链表**

**[37](./Chapter_4/Sword_37_SerializeBinaryTrees.cpp) - 中等，新奇，序列化、反序列化二叉树**

**[38](./Chapter_4/Sword_38_StringPermutation.cpp) - 中等，字符全排列**

**[39](./Chapter_5/Sword_39_MoreThanHalfNumber.cpp) - 中等，寻找数组中出现次数超过一半的数**

**:star2::star2::star2:[40](./Chapter_5/Sword_40_KLeastNumbers.cpp) - 中等，Partion，multiset容器**

**:star2::star2::star2:[41](./Chapter_5/Sword_41_StreamMedian.cpp) - 中等，用STL函数push_heap、pop_heap和vector实现堆，并使用仿函数less、greater实现最大堆、最小堆**

43 - 中等，求1的个数，找规律，有点麻烦

~~44 - 简单，找规律~~

~~45 - 简单，用了挺多字符串函数~~

**[47](./Chapter_5/Sword_47_MaxValueOfGifts.cpp) - 中等 - 不要用递归，应该用一维DP**

[48](./Chapter_5/Sword_48_LongestSubstringWithoutDup.cpp) - 中等 - 最长的不含重复字符的子字符串，用一个position数组储存每个字母的上一个位置

[49](./Chapter_5/Sword_49_UglyNumber.cpp) - 偏易 - 丑数

~~[50.1](./Chapter_5/Sword_50_01_FirstNotRepeatingChar.cpp) - 简单~~

~~[50.2](./Chapter_5/Sword_50_02_FirstCharacterInStream.cpp) - 简单~~

**:star2::star2::star2:[51](./Chapter_5/Sword_51_InversePairs.cpp) - 困难 - 求逆序对的数目**

[52](./Chapter_5/Sword_52_FirstCommonNodesInLists.cpp) - 简单 - 寻找两个链表的首个公共节点

[53.1](./Chapter_6/Sword_53_1_NumberOfK.cpp) - 简单 - 求数字k出现的次数

~~53.2 - 简单 - 求缺失的数字~~

~~53.3 - 简单 - 求不在位置上的数字~~

**:star2::star2::star2:[54](./Chapter_6/Sword_54_KthNodeInBST.cpp.cpp) - 困难 - 求二叉树的第k个数**

**:star2:[55.2](./Chapter_6/Sword_55_2_BalancedBinaryTree.cpp) - 中等 - 判断是否平衡树**

[56.1](./Chapter_6/Sword_56_1_NumbersAppearOnce.cpp) - 中等 - 寻找数组中两个只出现一次的数字（其余数字均出现两次），利用了x&x=0的性质

[56.2](./Chapter_6/Sword_56_2_NumberAppearingOnce.cpp) - 中等 - 寻找数组中只出现一次的数字（其余数字均出现三次），使用辅助数组进行重建，有一点需要注意：(-1 & (1 << 31)) < 0

58.2 - 中等 - 原地左旋转字符串

**[59.1](./Chapter_6/Sword_59_1_MaxInSlidingWindow.cpp) - 中等 - 有窗口在数组上滑动，求随着窗口的滑动，窗口中的最大值。关键是用index双端队列储存可能的坐标**

[60](./Chapter_6/Sword_60_DicesProbability.cpp) - 中等 - 计算投色子的和的概率

~~[61](./Chapter_6/Sword_61_ContinousCards.cpp) - 简单 - 判断五张扑克是否构成顺子~~

**:star2::star2::star2:[62](./Chapter_6/Sword_62_LastNumberInCircle.cpp) - 困难 - 约瑟夫环问题，圆圈中最后剩下的数字**

**[64](./Chapter_6/Sword_64_Accumulate.cpp) - 新奇 - 模板元编程及各种方法实现连加**

**[65](./Chapter_6/Sword_65_AddTwoNumbers.cpp) - 新奇 - 使用位运算实现加法**

:star2::star2::star2:
基于加减法交换变量值

x = x + y

y = x - y

x = x - y

基于位运算交换变量值

x = x ^ y

y = x ^ y

x = x ^ y

**[67](./Chapter_7/Sword_67_StringToInt.cpp) - 字符串转整数**

**[68](./Chapter_7/Sword_68_CommonParentInTree.cpp) - 求树中两节点的公共父节点，，使用deque保存路径即可，应注意遍历两个节点的父节点路径时，不应该遍历到节点本身**
