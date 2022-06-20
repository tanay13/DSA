1. [Short encoding of words](https://leetcode.com/problems/short-encoding-of-words/)

   - Store all the words in the map
   - sort the words from longest to shortest length
   - loop through the array and for each word find the substr till ith index to end
   - if the substring matches the already present string in the array(checking by m.find(s)!=m.end()), erase that string from the map.
   - increament the final ans by the length of the ith index string + 1
