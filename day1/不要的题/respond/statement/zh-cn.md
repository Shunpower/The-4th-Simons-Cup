{{ self.title() }}

{{ s('background') }}

{{ img('background.jpg', size = 0.14, align = 'middle', inline = False, caption='“缔造属于你我的璀璨”') }}

{{ s('description') }}

Simons 为了 solo 舞台准备了一个有 $n$ 个段落的舞蹈，其中第 $i$ 个段落的美观程度是 $a_i$。

对于一个练习计划 $(s,t)$，Simons 需要从第 $s$ 个段落开始练习 $t+1$ 天。为了保证整体的连贯性，Simons 每天都只能练习与前一天练习的段落相邻的段落，也可以继续练习前一天练习过的段落。特别地，Simons 第一天**必须**练习段落 $s$。

最终舞台的表现效果值是他曾经练习过的所有段落的 $a_i$ 的和。特别注意，由于舞台上肯定不能把相同的段落一直跳，所以**同一段落只能计入一次**。

Simons 希望你求出，对于任意练习计划 $(s,t)$ 满足 $1\le s\le n,1\le t\le 2n$，求出最终舞台的表现效果值的最大值 $f(s,t)$。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含一个正整数 $n$，表示这个舞蹈的段落数量。

输入的第二行包含 $n$ 个整数 $a_i$，表示每个段落的美观程度。

{{ s('output format') }}

{{ self.output_file() }}

为了减小输出量，你只需要输出 $\sum\limits_{s=1}^n(2^s\cdot\bigoplus\limits_{t=1}^{2n}t\cdot f(s,t))$ 对 $2007072007$ 取模的值。

**标准程序不依赖于输出方式**。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

对于这组数据，所有 $f(i,j)$ 的值为：

$$
f=\begin{bmatrix} 3 & 6 & 6 & 6 & 6 & 6 \\ 5 & 5 & 6 & 6 & 6 & 6 \\ 5 & 6 & 6 & 6 & 6 & 6 \\ \end{bmatrix}
$$

对于 $f(2,2)$，Simons 将练习 $2+1=3$ 天。

- 第一天，Simons 必须练习段落 $2$。
- 第二天，Simons 选择练习与段落 $2$ 相邻的段落 $3$。
- 第三天，Simons 选择继续练习段落 $3$。

此时 Simons 练习了段落 $2,3$，这些段落的美观程度和是 $2+3=5$，可以证明没有比它更大的答案，所以 $f(2,2)=5$。

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', 3) }}

{{ self.sample_file() }}

这组样例满足测试点 $3,4$ 的限制。

{{ s('sample', 4) }}

{{ self.sample_file() }}

这组样例满足测试点 $8\sim 10$ 的限制。

{{ s('sample', 5) }}

{{ self.sample_file() }}

这组样例满足测试点 $11\sim 14$ 的限制。

{{ s('sample', 6) }}

{{ self.sample_file() }}

这组样例满足测试点 $15\sim 20$ 的限制。

{{ s('部分分设置') }}

**请注意本题不同寻常的空间限制。**

对于 $100\%$ 的数据，保证 $1\le n\le {{args['n'].hn()}}$，$0\le a_i\le 10^9$。

{{ tbl('data') }}

特殊性质 A：美观程度序列 $\{a_n\}$ 中至多只有 $10$ 个元素不为 $0$。

特殊性质 B：美观程度序列 $\{a_n\}$ 中至多只有 $10$ 个 $i\in[1,n)$ 使得 $a_i>a_{i+1}$。