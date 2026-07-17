<h2><a href="https://leetcode.com/problems/rotting-oranges">Rotting Oranges</a></h2>

<img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' />

<hr>

<h3>📌 Problem Description</h3>

<p>
You are given an <code>m x n</code> grid where each cell can contain:
</p>

<ul>
<li><code>0</code> → Empty cell</li>
<li><code>1</code> → Fresh orange</li>
<li><code>2</code> → Rotten orange</li>
</ul>

<p>
Every minute, every fresh orange that is <strong>4-directionally adjacent</strong> (up, right, down, left) to a rotten orange also becomes rotten.
</p>

<p>
Return the <strong>minimum number of minutes</strong> required until there are no fresh oranges left. If it is impossible to rot every fresh orange, return <code>-1</code>.
</p>

<hr>

<h3>🧪 Examples</h3>

<p><strong>Example 1:</strong></p>

<pre>
Input:
grid = [[2,1,1],
        [1,1,0],
        [0,1,1]]

Output:
4
</pre>

<p><strong>Example 2:</strong></p>

<pre>
Input:
grid = [[2,1,1],
        [0,1,1],
        [1,0,1]]

Output:
-1

Explanation:
The orange at (2,0) can never become rotten because it is isolated.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
Input:
grid = [[0,2]]

Output:
0

Explanation:
There are no fresh oranges initially.
</pre>

<hr>

<h3>📎 Constraints</h3>

<ul>
<li><code>1 ≤ m, n ≤ 10</code></li>
<li><code>grid[i][j]</code> is <code>0</code>, <code>1</code>, or <code>2</code>.</li>
</ul>

<hr>

<h3>🧠 Intuition</h3>

<p>
This problem can be modeled as a <strong>multi-source BFS</strong>.
</p>

<ul>
<li>Every cell in the grid is treated as a graph node.</li>
<li>Initially, all rotten oranges are the <strong>starting points</strong> because they begin spreading the rot simultaneously.</li>
<li>Each minute, the infection spreads to all adjacent fresh oranges.</li>
<li>BFS naturally processes nodes <strong>level by level</strong>, where each level represents one minute.</li>
</ul>

<hr>

<h3>⚙️ Approach</h3>

<ol>
<li>Traverse the grid once.
    <ul>
        <li>Add every rotten orange to the queue.</li>
        <li>Count the total number of fresh oranges.</li>
    </ul>
</li>

<li>If there are no fresh oranges, return <code>0</code>.</li>

<li>Perform <strong>Multi-Source BFS</strong> starting from all rotten oranges.</li>

<li>For every rotten orange removed from the queue:
    <ul>
        <li>Check its 4 adjacent cells.</li>
        <li>If an adjacent cell contains a fresh orange:
            <ul>
                <li>Convert it into a rotten orange.</li>
                <li>Decrease the fresh orange count.</li>
                <li>Add it to the queue.</li>
            </ul>
        </li>
    </ul>
</li>

<li>After processing one BFS level, increment the elapsed minutes.</li>

<li>After BFS completes:
    <ul>
        <li>If fresh oranges still remain, return <code>-1</code>.</li>
        <li>Otherwise, return the total minutes.</li>
    </ul>
</li>
</ol>

<hr>

<h3>🔹 Why BFS Works</h3>

<ul>
<li>All rotten oranges start spreading simultaneously, making this a perfect <strong>multi-source BFS</strong> problem.</li>
<li>Each BFS level represents exactly <strong>one minute</strong>.</li>
<li>Every orange is processed at most once, ensuring efficiency.</li>
<li>If any fresh orange remains unvisited after BFS, it means it can never become rotten.</li>
</ul>

<hr>

<h3>⏱️ Complexity</h3>

<ul>
<li><strong>Time Complexity:</strong> O(N × M)<br>
Every cell is visited at most once.</li>

<li><strong>Space Complexity:</strong> O(N × M)<br>
The queue can contain all oranges in the worst case.</li>
</ul>
