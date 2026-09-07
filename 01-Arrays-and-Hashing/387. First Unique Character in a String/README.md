<h2><a href="https://leetcode.com/problems/first-unique-character-in-a-string">387. First Unique Character in a String</a></h2>

<p>Given a string <code>s</code>, find the <strong>first</strong> non-repeating character in it and return its index. If it <strong>does not</strong> exist, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "leetcode"</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The character <code>'l'</code> at index 0 is the first character that does not occur at any other index.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "loveleetcode"</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "aabb"</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>


---

# 🛍️ First-Unique-Character-in-a-String | Explained

## Approach 1: Two-Pass Fixed-Size Frequency Array
### Intuition
Imagine you are a security guard checking tickets at a theater entrance. You have a list of attendees, and some people share the same access badge while others have completely unique badges. If you want to know who the very first person in line is holding an exclusive, one-of-a-kind badge, you cannot decide just by looking at each person as they arrive—because a badge that looks unique at index 0 might show up again at the very end of the line.

Instead, you need a two-phase process:
1. **The Headcount (Tallying):** Keep a small ledger with 26 slots (one for each letter 'a' through 'z'). Go through the line from start to finish and put a tally mark next to each letter seen.
2. **The Queue Inspection:** Walk the queue again from front to back. For each person, look up their letter's tally on your ledger. The very first person you encounter whose letter has a tally count of exactly `1` is your answer. If you reach the end without finding any, everyone is duplicated.

### Algorithm Visualized
```mermaid
flowchart TD
    Start([Input String: s]) --> Init[Initialize freq array of size 26 to 0]
    
    subgraph Pass1 [Pass 1: Build Frequency Map]
        Init --> Loop1{For each char c in s}
        Loop1 -- Next Char --> Incr["freq[c - 'a']++"]
        Incr --> Loop1
    end

    Loop1 -- Finished String --> Pass2
    
    subgraph Pass2 [Pass 2: Locate First Unique Character]
        Pass2[Start index i = 0] --> Loop2{i < s.size?}
        Loop2 -- Yes --> Cond{"freq[s[i] - 'a'] == 1?"}
        Cond -- True --> Found([Return index i])
        Cond -- False --> NextI[i++]
        NextI --> Loop2
    end

    Loop2 -- No --> NotFound([Return -1])
```

### Approach
1. **Instantiate a Fixed Frequency Array:** Since the problem guarantees that the input consists solely of lowercase English letters, allocate a fixed-size array of 26 integers initialized to `0`. This bypasses the memory and hashing overhead of dynamic hash tables (like `std::unordered_map`).
2. **First Pass (Frequency Collection):** Traverse the string $s$ character by character using a range-based loop. Map each character `c` to its zero-based alphabet index (`c - 'a'`) and increment its corresponding bucket in the array.
3. **Second Pass (Order Preservation):** Iterate through the string a second time using an index-based loop (`0` to `s.size() - 1`). Check the precomputed count of the character at `s[i]`. Because we are iterating from left to right, the first character that evaluates to `freq[s[i] - 'a'] == 1` is guaranteed to be the first non-repeating character.
4. **Fallback:** If the second loop terminates without finding a frequency of `1`, return `-1`.

### Detailed Code Analysis
- **Line 4:** `int freq[26] = {0};`
  - Allocates an array of 26 integers on the call stack and zero-initializes all elements. This acts as a direct-address table where index `0` represents `'a'`, index `1` represents `'b'`, and so on up to index `25` for `'z'`.
- **Lines 6–8:** 
  ```cpp
  for(char c : s){
      freq[c - 'a']++;
  }
  ```
  - A fast, range-based `for` loop that iterates over each character in the string.
  - `c - 'a'` computes the 0-indexed offset using ASCII values (e.g., `'a' - 'a' = 0`, `'b' - 'a' = 1`).
  - `freq[c - 'a']++` increments the frequency count for that specific letter.
- **Lines 10–14:**
  ```cpp
  for(int i = 0; i < s.size(); i++){
      if(freq[s[i] - 'a'] == 1){
          return i;
      }
  }
  ```
  - An index-based traversal of the original string to preserve input order.
  - For each index `i`, we inspect the value stored in `freq[s[i] - 'a']`.
  - The first time we hit a count of `1`, we immediately return `i`, short-circuiting any remaining work.
- **Line 15:** `return -1;`
  - If the loop finishes without executing the `return i;` statement, it implies every character in the string has a frequency $\ge 2$. Thus, `-1` is returned.

### Code
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        for(char c : s){
            freq[c - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            if(freq[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};
```

### Complexity
- **Time:** $\mathcal{O}(N)$, where $N$ is the length of the string $s$.
  - **Pass 1:** Iterates through all $N$ characters of the string: $\mathcal{O}(N)$.
  - **Pass 2:** Iterates through at most $N$ characters: $\mathcal{O}(N)$.
  - Array lookups and increments are $\mathcal{O}(1)$ operations.
  - Total time complexity is $\mathcal{O}(N + N) = \mathcal{O}(N)$.
- **Space:** $\mathcal{O}(1)$ auxiliary space.
  - The array `freq` has a strictly constant size of 26 integers regardless of the size of the input string $N$.

---

## 🕵️‍♂️ Follow-up Questions

### 1. What if the input contains arbitrary Unicode characters or the full ASCII set instead of just lowercase English letters?
A fixed array of size 26 (`c - 'a'`) will no longer work and will cause an out-of-bounds memory access. 
- For the full ASCII set (0–127 or 0–255), we can expand the array to `int freq[256] = {0};` while retaining $\mathcal{O}(1)$ space.
- For arbitrary UTF-8/Unicode characters, replace the array with a dynamic hash map like `std::unordered_map<char32_t, int>`. Space complexity becomes $\mathcal{O}(U)$, where $U$ is the number of distinct unique characters in the string.

### 2. How would you solve this if the data was presented as an infinite stream rather than an in-memory string?
In a data streaming scenario, you cannot make a second pass over the input. You can maintain a hash map of counts along with a `std::queue<pair<char, int>>` (or a doubly-linked list / `std::list`) storing character candidate pairs `(character, first_index)`:
1. For each incoming character, increment its count in the hash map and push `(c, index)` to the queue if it's the first time seeing it.
2. When queried for the first unique character, peek at the front of the queue. If the front character's count in the map is $> 1$, pop it from the queue (lazy deletion).
3. Repeat step 2 until the front character has a count of `1` (which is returned) or the queue becomes empty (return `-1`).