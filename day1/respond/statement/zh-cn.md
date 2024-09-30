{{ self.title() }}

{{ s('background') }}

{{ img('background.jpg', size = 0.14, align = 'middle', inline = False, caption='“缔造属于你我的璀璨”') }}

{{ s('description') }}

Simons 为了 solo 舞台准备了一个有 $n$ 个段落的舞蹈，其中第 $i$ 个段落的美观程度是 $a_i$。

Simons 每个练习周期可以从第 $s$ 个段落开始练习 $t$ 天。然而，为了保证整体的连贯性，Simons 每天都只能练习与前一天练习的段落相邻的段落，也可以继续练习前一天练习过的段落。当然，Simons 第一天必须练习段落 $s$。

最终舞台的表现效果值是他曾经练习过的所有段落的 $a_i$ 的和。特别注意，由于舞台上肯定不能把相同的段落一直跳，所以**同一段落只能计入一次**。

Simons 希望你求出，对于任意 $(s,t)$ 满足 $1\le s\le n,1\le t\le 2n$，求出最终舞台的表现效果值的最大值 $f(s,t)$。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含一个正整数 $n$，表示这个舞蹈的段落数量。

输入的第二行包含 $n$ 个整数 $a_i$，表示每个段落的美观程度。

{{ s('output format') }}

{{ self.output_file() }}

为了减小输出量，你只需要输出 $\sum\limits_{s=1}^n(2^s\cdot\bigoplus\limits_{t=1}^{2n}t\times f(s,t))$ 对 $2007072007$ 取模的值。

**std 不依赖于输出方式**。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

这是第一组数据的样例说明。

{{ s('sample', 2) }}

{{ self.sample_file() }}

上面是只提示存在第二组样例，但不渲染到题面中。

{{ s('部分分设置') }}

对于 $100\%$ 的数据，保证 $1\le n\le {{args['n'].hn()}}$，$-10^9\le a_i\le 10^9$。

{{ tbl('data') }}

特殊性质 A：美观程度序列 $\{a_n\}$ 中至多只有 $15$ 个元素不为 $0$。

特殊性质 B：$\forall i\in[1,n],1\le a_i$。