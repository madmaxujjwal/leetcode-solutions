<h2><a href="https://leetcode.com/problems/flip-string-to-monotone-increasing/">926. Flip String to Monotone Increasing</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">A binary string is monotone increasing if it consists of some number of <code style="user-select: auto;">0</code>'s (possibly none), followed by some number of <code style="user-select: auto;">1</code>'s (also possibly none).</p>

<p style="user-select: auto;">You are given a binary string <code style="user-select: auto;">s</code>. You can flip <code style="user-select: auto;">s[i]</code> changing it from <code style="user-select: auto;">0</code> to <code style="user-select: auto;">1</code> or from <code style="user-select: auto;">1</code> to <code style="user-select: auto;">0</code>.</p>

<p style="user-select: auto;">Return <em style="user-select: auto;">the minimum number of flips to make </em><code style="user-select: auto;">s</code><em style="user-select: auto;"> monotone increasing</em>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "00110"
<strong style="user-select: auto;">Output:</strong> 1
<strong style="user-select: auto;">Explanation:</strong> We flip the last digit to get 00111.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "010110"
<strong style="user-select: auto;">Output:</strong> 2
<strong style="user-select: auto;">Explanation:</strong> We flip to get 011111, or alternatively 000111.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "00011000"
<strong style="user-select: auto;">Output:</strong> 2
<strong style="user-select: auto;">Explanation:</strong> We flip to get 00000000.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= s.length &lt;= 10<sup style="user-select: auto;">5</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">s[i]</code> is either <code style="user-select: auto;">'0'</code> or <code style="user-select: auto;">'1'</code>.</li>
</ul>
</div>