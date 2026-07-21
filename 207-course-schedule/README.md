<h2><a href="https://leetcode.com/problems/course-schedule">Course Schedule</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>. You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you <strong>must</strong> take course <code>b<sub>i</sub></code> first if you want to take course <code>a<sub>i</sub></code>.</p>

<ul>
	<li>For example, the pair <code>[0, 1]</code>, indicates that to take course <code>0</code> you have to first take course <code>1</code>.</li>
</ul>

<p>Return <code>true</code> if you can finish all courses. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> numCourses = 2, prerequisites = [[1,0],[0,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= numCourses &lt;= 2000</code></li>
	<li><code>0 &lt;= prerequisites.length &lt;= 5000</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
	<li>All the pairs prerequisites[i] are <strong>unique</strong>.</li>
</ul>
<h3>⚙️ Approach 1: Kahn's Algorithm (BFS / Topological Sort)</h3>

<ol>
<li>Create an adjacency list where an edge <code>b → a</code> means course <code>b</code> must be completed before course <code>a</code>.</li>

<li>Compute the <strong>indegree</strong> of every course (number of prerequisites).</li>

<li>Push all courses having <code>indegree = 0</code> into a queue since they can be taken immediately.</li>

<li>Perform BFS:
<ul>
<li>Remove a course from the queue.</li>
<li>Increase the count of completed courses.</li>
<li>For every dependent course, decrease its indegree by 1.</li>
<li>If a course's indegree becomes 0, push it into the queue.</li>
</ul>
</li>

<li>After BFS finishes:
<ul>
<li>If the number of processed courses equals <code>numCourses</code>, return <code>true</code>.</li>
<li>Otherwise, some courses were never processed because they are part of a cycle, so return <code>false</code>.</li>
</ul>
</li>
</ol>

<hr>

<h3>⚙️ Approach 2: DFS (Cycle Detection)</h3>

<ol>
<li>Create an adjacency list where an edge <code>b → a</code> represents a prerequisite relationship.</li>

<li>Maintain two arrays:
<ul>
<li><code>vis[]</code> → Tracks whether a node has been visited.</li>
<li><code>pathVis[]</code> → Tracks whether a node is currently in the DFS recursion stack.</li>
</ul>
</li>

<li>Run DFS from every unvisited course.</li>

<li>During DFS:
<ul>
<li>Mark the current course as visited.</li>
<li>Mark it as part of the current DFS path.</li>
<li>Visit all neighboring courses.</li>
</ul>
</li>

<li>For each neighbor:
<ul>
<li>If it is unvisited, recursively perform DFS.</li>
<li>If it is already present in the current recursion path (<code>pathVis[neighbor] == 1</code>), a cycle is found.</li>
</ul>
</li>

<li>After exploring all neighbors, remove the current node from the recursion path by setting <code>pathVis[node] = 0</code>.</li>

<li>If any DFS call detects a cycle, return <code>false</code>.</li>

<li>If every DFS completes without finding a cycle, return <code>true</code>.</li>
</ol>

