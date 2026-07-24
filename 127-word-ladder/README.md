<h2><a href="https://leetcode.com/problems/word-ladder">Word Ladder</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>A <strong>transformation sequence</strong> from word <code>beginWord</code> to word <code>endWord</code> using a dictionary <code>wordList</code> is a sequence of words <code>beginWord -&gt; s<sub>1</sub> -&gt; s<sub>2</sub> -&gt; ... -&gt; s<sub>k</sub></code> such that:</p>

<ul>
	<li>Every adjacent pair of words differs by a single letter.</li>
	<li>Every <code>s<sub>i</sub></code> for <code>1 &lt;= i &lt;= k</code> is in <code>wordList</code>. Note that <code>beginWord</code> does not need to be in <code>wordList</code>.</li>
	<li><code>s<sub>k</sub> == endWord</code></li>
</ul>

<p>Given two words, <code>beginWord</code> and <code>endWord</code>, and a dictionary <code>wordList</code>, return <em>the <strong>number of words</strong> in the <strong>shortest transformation sequence</strong> from</em> <code>beginWord</code> <em>to</em> <code>endWord</code><em>, or </em><code>0</code><em> if no such sequence exists.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> beginWord = &quot;hit&quot;, endWord = &quot;cog&quot;, wordList = [&quot;hot&quot;,&quot;dot&quot;,&quot;dog&quot;,&quot;lot&quot;,&quot;log&quot;,&quot;cog&quot;]
<strong>Output:</strong> 5
<strong>Explanation:</strong> One shortest transformation sequence is &quot;hit&quot; -&gt; &quot;hot&quot; -&gt; &quot;dot&quot; -&gt; &quot;dog&quot; -&gt; cog&quot;, which is 5 words long.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> beginWord = &quot;hit&quot;, endWord = &quot;cog&quot;, wordList = [&quot;hot&quot;,&quot;dot&quot;,&quot;dog&quot;,&quot;lot&quot;,&quot;log&quot;]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The endWord &quot;cog&quot; is not in wordList, therefore there is no valid transformation sequence.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= beginWord.length &lt;= 10</code></li>
	<li><code>endWord.length == beginWord.length</code></li>
	<li><code>1 &lt;= wordList.length &lt;= 5000</code></li>
	<li><code>wordList[i].length == beginWord.length</code></li>
	<li><code>beginWord</code>, <code>endWord</code>, and <code>wordList[i]</code> consist of lowercase English letters.</li>
	<li><code>beginWord != endWord</code></li>
	<li>All the words in <code>wordList</code> are <strong>unique</strong>.</li>
</ul>
<hr>
<h3>🧠 Intuition</h3>

<p>
The problem can be viewed as finding the <strong>shortest path in an unweighted graph</strong>.
</p>

<ul>
<li>Each word represents a graph node.</li>
<li>An edge exists between two words if they differ by exactly one character.</li>
<li>Every transformation has the same cost (one step).</li>
</ul>

<p>
Since we need the minimum number of transformations, <strong>Breadth First Search (BFS)</strong> is the ideal choice because it explores all possible transformations level by level. The first time we reach <code>endWord</code>, we are guaranteed to have found the shortest transformation sequence.
</p>

<hr>

<h3>⚙️ Approach</h3>

<ol>

<li>Store all words from <code>wordList</code> in an <code>unordered_set</code> for <strong>O(1)</strong> average lookup.</li>

<li>If <code>endWord</code> is not present in the set, return <code>0</code> since it is impossible to reach.</li>

<li>Create a queue that stores:
<ul>
<li>The current word.</li>
<li>The number of transformations taken to reach it.</li>
</ul>
</li>

<li>Push <code>beginWord</code> into the queue with an initial step count of <code>1</code>.</li>

<li>Remove <code>beginWord</code> from the set (if present) to avoid revisiting it.</li>

<li>Perform BFS until the queue becomes empty.</li>

<li>For every word removed from the queue:
<ul>

<li>If it is equal to <code>endWord</code>, return the current step count.</li>

<li>For every character position in the word:
<ul>
<li>Store the original character.</li>
<li>Replace it with every lowercase letter from <code>'a'</code> to <code>'z'</code>.</li>
<li>Skip the replacement if the character remains unchanged.</li>
</ul>
</li>

<li>If the newly formed word exists in the set:
<ul>
<li>Push it into the queue with <code>steps + 1</code>.</li>
<li>Erase it from the set immediately so it is visited only once.</li>
</ul>
</li>

<li>Restore the original character before moving to the next position.</li>

</ul>
</li>

<li>If BFS finishes without reaching <code>endWord</code>, return <code>0</code>.</li>

</ol>

<hr>

<h3>🔹 Why BFS Works</h3>

<ul>

<li>Each transformation changes exactly one letter, so every edge in the graph has the same weight.</li>

<li>BFS explores all words reachable in one transformation before moving to two transformations, then three, and so on.</li>

<li>Therefore, the first time <code>endWord</code> is reached, the shortest transformation sequence has been found.</li>

<li>Removing words from the set immediately after visiting them prevents revisiting the same word and keeps the algorithm efficient.</li>

</ul>

<hr>

<h3>⏱️ Complexity</h3>

<p>
Let:
</p>

<ul>
<li><strong>N</strong> = Number of words in <code>wordList</code></li>
<li><strong>L</strong> = Length of each word</li>
</ul>

<ul>
<li><strong>Time Complexity:</strong> <code>O(N × L × 26)</code><br>
For every visited word, we try replacing each character with all 26 lowercase letters.</li>

<li><strong>Space Complexity:</strong> <code>O(N)</code><br>
The unordered set and BFS queue together require linear extra space.</li>
</ul>

