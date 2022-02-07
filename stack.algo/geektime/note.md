> [geektime](https://time.geekbang.org/column/article/81835) --  [wangzheng](https://github.com/wangzheng0822/algo): [notes](https://github.com/wangzheng0822/algo/tree/master/notes),  [java](https://github.com/wangzheng0822/algo/tree/master/java), [golang](https://github.com/wangzheng0822/algo/tree/master/go), [cpp](https://github.com/wangzheng0822/algo/tree/master/c-cpp), [rust](https://github.com/wangzheng0822/algo/tree/master/rust), [py](https://github.com/wangzheng0822/algo/tree/master/python)


## 13 | 线性排序: 如何根据年龄给100w用户数据排序
- 线性排序 (linear sort) 指的是时间复杂度是O(n)的排序算法，如桶排序、计数排序、基数排序；非基于比较的排序算法，都不涉及元素之间的比较操作。线性排序算法的时间复杂度、空间复杂度分析相对简单，但是对排序的数据要求比较苛刻。

- 桶排序(Bucket Sort): n个数据划分到m个桶里，每个桶使用快排，时间复杂度 O(n/m\*log(n/m)), 桶排序总共的时间复杂度即O(n\*log(n/m)), 当m趋近于n, log(n/m)是非常小的量，桶排序的复杂度趋于O(n)。要求待排序数据在桶之间有着天然的大小顺序，其次要求各个桶之间的分布是均匀的。桶排序比较适合用在外部排序。


- 计数排序(Counting Sort) 桶排序的特例，适用于数据范围m远小于n的场景，并且数据范围是非负整数范围，所以在使用计数排序之前需要先进行数据范围的压缩或者变化。


- 基数排序(Radix Sort) 需要待排序数据可以分割出独立的位来比较，而且位之间有递进关系；除此之外，要求每一位的数据范围不能太大，这样可以用线性排序算法来排序。如果要排序的数据有k位，需要进行k次桶排序或者基数排序，总的时间复杂度是O(kn)，考虑到k如果不大，则近似位O(n)。


