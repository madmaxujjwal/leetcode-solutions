<h2><a href="https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/">562. Longest Line of Consecutive One in Matrix</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">Given an <code style="user-select: auto;">m x n</code> binary matrix <code style="user-select: auto;">mat</code>, return <em style="user-select: auto;">the length of the longest line of consecutive one in the matrix</em>.</p>

<p style="user-select: auto;">The line could be horizontal, vertical, diagonal, or anti-diagonal.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/long1-grid.jpg" style="width: 333px; height: 253px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
<strong style="user-select: auto;">Output:</strong> 3
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/long2-grid.jpg" style="width: 333px; height: 253px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> mat = [[1,1,1,1],[0,1,1,0],[0,0,0,1]]
<strong style="user-select: auto;">Output:</strong> 4
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">m == mat.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">n == mat[i].length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= m, n &lt;= 10<sup style="user-select: auto;">4</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= m * n &lt;= 10<sup style="user-select: auto;">4</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">mat[i][j]</code> is either <code style="user-select: auto;">0</code> or <code style="user-select: auto;">1</code>.</li>
</ul>
</div>