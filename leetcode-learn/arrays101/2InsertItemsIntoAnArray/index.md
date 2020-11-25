### Basic Array Operations
Now that we have a fairly good understanding of what an Array actually is, and how it is stored inside the computer's physical memory, the next important thing to look at is all the operations that Arrays support. An Array is a data structure, which means that it stores data in a specific format and supports certain operations on the data it stores. Consider the DVD inventory management software from the introduction section. Let's look at some operations you might want to perform using this software:

- **Insert** a new DVD into the collection at a specific location.
- **Delete** a DVD from the existing collection if it doesn't make sense to keep it in the inventory anymore.
- **Search** for a particular DVD in the collection. This is one of the most commonly executed operation on our collection, because our inventory management software would be used hundreds of times a day to look for a particular DVD asked for by the user.


In this section, we'll be looking at the three basic operations that are supported by almost every data structure; **insertion**, **deletion**, and **search**


### Array Insertions

Inserting a new element into an Array can take many forms:
1 Inserting a new element at the end of the Array.
2 Inserting a new element at the beginning of the Array.
3 Inserting a new element at any given index inside the Array.

``` cpp
void move(vector<int>& target, int frompos) {
        for (int i = target.size() - 1; i > frompos; --i) {
            target[i] = target[i - 1];
        }
}
```