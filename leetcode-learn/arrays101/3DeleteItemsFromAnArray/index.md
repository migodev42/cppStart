# Array Deletions
Deletion in an Array works in a very similar manner to insertion, and has the same three different cases:
删除数组的元素和插入元素非常相似，同样有三种不同的方式

1.Deleting the last element of the Array. 删除数组尾部的元素
2.Deleting the first element of the Array. 删除数组第一个元素
3.Deletion at any given index. 删除制定index的元素

### Deleting From the End of an Array
### Deleting From the Start of an Array
### Deleting From Anywhere in the Array




``` cpp
void move(vector<int>& target, int frompos) {
        for (int i = frompos+1  - 1; i < target.size(); ++i) {
            target[i-1] = target[i];
        }
}
```