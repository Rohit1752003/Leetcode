<h2><a href="https://leetcode.com/problems/flood-fill">Flood Fill</a></h2>

<img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' />

<hr>

<h3>🧠 Intuition</h3>
<p>
The Flood Fill problem can be treated as a <strong>graph traversal problem</strong>.
</p>

<ul>
<li>Each cell in the matrix is a <strong>node</strong>.</li>
<li>Each node connects to its 4 neighbors: <strong>Up, Right, Down, Left</strong>.</li>
<li>Starting from <code>(sr, sc)</code>, we need to recolor all connected nodes having the same original color.</li>
</ul>

<p>
Since we must visit every connected cell exactly once, <strong>BFS (Breadth First Search)</strong> is a natural fit.
</p>

<hr>

<h3>⚙️ Approach</h3>

<ol>
<li>Store the <strong>original color</strong> of the starting pixel.</li>

<li>If the original color is already equal to the new color, return the image immediately.</li>

<li>Create a <strong>visited matrix</strong> to avoid reprocessing cells.</li>

<li>Create a copy of the image (<code>ans</code>) to store results.</li>

<li>Start <strong>BFS</strong> from <code>(sr, sc)</code>.</li>

<li>For each cell:
    <ul>
        <li>Check all 4 directions.</li>
        <li>If neighbor:
            <ul>
                <li>is inside the grid,</li>
                <li>is not visited,</li>
                <li>has the same original color,</li>
            </ul>
        </li>
        <li>Then:
            <ul>
                <li>mark visited,</li>
                <li>recolor it,</li>
                <li>push into queue.</li>
            </ul>
        </li>
    </ul>
</li>

<li>Return the modified image.</li>
</ol>

<hr>

<h3>🔹 Why BFS Works</h3>

<ul>
<li>BFS explores nodes <strong>level by level</strong>, ensuring all connected cells are covered.</li>
<li>We only expand into cells with the same original color → correct component.</li>
<li>Each cell is processed <strong>only once</strong> using the visited matrix.</li>
</ul>

<hr>

<h3>⏱️ Complexity</h3>

<ul>
<li><strong>Time Complexity:</strong> O(N × M)<br>
Every cell is visited at most once.</li>

<li><strong>Space Complexity:</strong> O(N × M)<br>
Visited matrix + queue + result grid.</li>
</ul>

<hr>

<h3>📌 Problem Statement</h3>

<p>
You are given an image represented by an <code>m x n</code> grid of integers <code>image</code>, where <code>image[i][j]</code> represents the pixel value.
</p>

<p>
Given <code>sr</code>, <code>sc</code>, and <code>color</code>, perform a <strong>flood fill</strong>:
</p>

<ol>
<li>Start from the pixel <code>(sr, sc)</code>.</li>
<li>Change its color to <code>color</code>.</li>
<li>Repeat for all <strong>adjacent (4-directional)</strong> pixels with the same original color.</li>
<li>Stop when no more valid adjacent pixels exist.</li>
</ol>

<p>
Return the modified image.
</p>

<hr>

<h3>🧪 Examples</h3>

<p><strong>Example 1:</strong></p>

<pre>
Input:
image = [[1,1,1],
         [1,1,0],
         [1,0,1]],
sr = 1, sc = 1, color = 2

Output:
[[2,2,2],
 [2,2,0],
 [2,0,1]]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
Input:
image = [[0,0,0],
         [0,0,0]],
sr = 0, sc = 0, color = 0

Output:
[[0,0,0],
 [0,0,0]]
</pre>

<hr>

<h3>📎 Constraints</h3>

<ul>
<li><code>1 ≤ m, n ≤ 50</code></li>
<li><code>0 ≤ image[i][j], color &lt; 2<sup>16</sup></code></li>
<li><code>0 ≤ sr &lt; m</code></li>
<li><code>0 ≤ sc &lt; n</code></li>
</ul>
