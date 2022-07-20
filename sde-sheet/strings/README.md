1. [Short encoding of words](https://leetcode.com/problems/short-encoding-of-words/)

   - Store all the words in the map
   - sort the words from longest to shortest length
   - loop through the array and for each word find the substr till ith index to end
   - if the substring matches the already present string in the array(checking by m.find(s)!=m.end()), erase that string from the map.
   - increament the final ans by the length of the ith index string + 1

2. [Number of matching subsequences](https://leetcode.com/problems/number-of-matching-subsequences/submissions/)

   - Creating vector map for all letters in the string s
   - iterating over all the words and finding the upper_bound of the letter in the vector.
   - if the letter is present after a particular "last" index, then assign do last = idx (idx is the index of the letter in the vector map).
   - if letter is not present then it means that particular word is not a subseq of the string s.
