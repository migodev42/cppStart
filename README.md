# cppStart

### Start
* Install complier

``` 
sudo apt install g++;
```

* Create a cpp file

``` 
#include <iostream>

int main(){
    using namespace std;
    cout << "Hello Wolrd\n";
    return 0;
}

```

* Compile and debug

press `F5` to compile and debug. (config files are in `/.vscode/` )

### Complie single source file and multi single files

Edit `.vscode/tasks.json`

``` js
 {
     ...

     "args": [

         "-Wall",
         "-g",
         // "${file}",      // 单个源文件编译
         "${fileDirname}/*.cpp", // 当前路径下所有源文件编译
         "-o",
         // "${fileDirname}/${fileBasenameNoExtension}.out",  // 单个源文件编译输出: 文件名.out
         "${fileDirname}/main.out" // 多个源文件编译输出: main.out
     ],

     ...
 }
```

- 初级算法
    - [ ] 数组
      - [ ] 买股票的最佳时机-2    
- [代码随想录](https://github.com/youngyangyang04/leetcode-master)
    - 数组 二分法、双指针法、滑动窗口、模拟行为 https://mp.weixin.qq.com/s/LIfQFRJBH5ENTZpvixHEmg
      - [x] 35 搜索插入位置 二分搜索 注意数组区间
      - [x] 27 移除元素 双指针
      - [x] 209 长度最小的子数组 双指针滑窗法
      - [x] 59 螺旋矩阵II 模拟顺时针画矩阵、循环不变式、注意数组区间
    - 链表 
      - [x] 203 移除链表元素 使用虚拟头节点（在单链表中移除头结点 和 移除其他节点的操作方式是不一样）
      - [x] 707 设计链表 使用虚拟头节点 size struct
      - [x] 206 反转链表 双指针/重新创建/递归
      - [x] 141 环形链表 快慢双指针 
      - [x] 142 环形链表2 找环形链表入口 双指针、解方程、归纳
    - 哈希表/散列表 hash table（数组 集合set 映射map） 底层实现：哈希表O(1)/红黑树O(logn)
      https://mp.weixin.qq.com/s/g8N6WmoQmsCUw3_BaWxHZA
      - [x] 242 有效的字母异位词 排序比较/数组哈希表/哈希表
      - [x] 349 两个数组的交集 unordered_set
      - [x] 202 快乐数 不停计算，结果存到unordered_set，有重复即是快乐数
      - [x] 1 两数之和 unordered_map 存储每一次的数字，target-curr查是否存在与map中。O(n)        
      - [ ] 454 四数相加II 
  - 练习
    - 数组
      - [x] 三数之和
      - [ ] 四数之和
    - 树 
      - [x] 129 求根到叶子节点数字之和 DFS 带参prev递归，非尾调用和尾调用版本
    