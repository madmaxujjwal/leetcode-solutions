<h2><a href="https://leetcode.com/problems/magic-squares-in-grid/">840. Magic Squares In Grid</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">A <code style="user-select: auto;">3 x 3</code> magic square is a <code style="user-select: auto;">3 x 3</code> grid filled with distinct numbers <strong style="user-select: auto;">from </strong><code style="user-select: auto;">1</code><strong style="user-select: auto;"> to </strong><code style="user-select: auto;">9</code> such that each row, column, and both diagonals all have the same sum.</p>

<p style="user-select: auto;">Given a <code style="user-select: auto;">row x col</code>&nbsp;<code style="user-select: auto;">grid</code>&nbsp;of integers, how many <code style="user-select: auto;">3 x 3</code> "magic square" subgrids are there?&nbsp; (Each subgrid is contiguous).</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/11/magic_main.jpg" style="width: 322px; height: 242px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
<strong style="user-select: auto;">Output:</strong> 1
<strong style="user-select: auto;">Explanation: </strong>
The following subgrid is a 3 x 3 magic square:
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/11/magic_valid.jpg" style="width: 242px; height: 242px; user-select: auto;">
while this one is not:
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/11/magic_invalid.jpg" style="width: 242px; height: 242px; user-select: auto;">
In total, there is only one magic square inside the given grid.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> grid = [[8]]
<strong style="user-select: auto;">Output:</strong> 0
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">row == grid.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">col == grid[i].length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= row, col &lt;= 10</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= grid[i][j] &lt;= 15</code></li>
</ul>
</div>