{{ self.title() }}

{{ s('background') }}

{{ img('background.png', size = 0.37, align = 'middle', inline = False, caption='“想爱我的人给我个肩膀，你的声音治愈我伤”') }}

而且如果有机会的话，请一定感谢我寻找你。

{{ s('description') }}

z!mo 有十六种配色。

z!mo 的人生可以看成 $n$ 个阶段排成一行，每个阶段有一个颜色 $c_i\in[0,v)$。z!mo 常常通过回顾自己的人生寻求灵感。

对于一个人生区间 $[l,r]$，z!mo 认为它是**盛放的**当且仅当：可以选出 $\{i|i\in[l,r]\}$ 的两个**无交非空子集** $S_1,S_2$，使得 $|S_1|+\sum\limits_{u\in S_1} c_u=|S_2|+\sum\limits_{u\in S_2} c_u$。

当 z!mo 回顾一个人生区间 $[l,r]$ 时，区间内的所有人生阶段都会随着回顾改变颜色。具体来说，$i\in[l,r]$ 的所有 $c_i\gets c_i^k\bmod v$，其中 $k$ 是一个固定的常数。

z!mo 想要知道，在反复的回顾和思索之间，哪些区间盛放着，哪些区间又不可避免地黯淡。因此你的任务是维护他的 $q$ 条思绪。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含四个整数 $n,q,k,v$。含义如题目描述中所述。

输入的第二行包含 $n$ 个整数 $c_i$，表示 z!mo 每个人生阶段初始的颜色。

接下来 $q$ 行，每行三个整数 $opt,l,r$：

- 若 $opt=1$，意味着 z!mo 需要你判断人生区间 $[l,r]$ 是否是**盛放的**。如果是输出 `YES`，反之输出 `NO`。
- 若 $opt=2$，意味着 z!mo 回顾了人生区间 $[l,r]$。

{{ s('output format') }}

{{ self.output_file() }}

若干行。对于每条 $opt=1$ 的思绪，输出 `YES` 或 `NO`。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

初始时 $\{c_n\}$ 为 $[4,3,8,2,9]$。

对于第一条思绪，可以判定 $[1,5]$ 是**盛放的**区间。取 $S_1=\{1,2\},S_2=\{3\}$ 即可。

第二条思绪进行回顾后，$\{c_n\}$ 变为 $[6,9,4,2,9]$。

对于第三条思绪，可以证明，此时不存在合法的 $S_1,S_2$。所以可以判定 $[1,3]$ 不是**盛放的**。

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', 3) }}

{{ self.sample_file() }}

这组样例满足测试点 $3\sim 5$ 的限制。

{{ s('sample', 4) }}

{{ self.sample_file() }}

这组样例满足测试点 $6\sim 8$ 的限制。

{{ s('sample', 5) }}

{{ self.sample_file() }}

这组样例满足测试点 $9\sim 12$ 的限制。

{{ s('sample', 6) }}

{{ self.sample_file() }}

这组样例满足测试点 $13,14$ 的限制。

{{ s('sample', 7) }}

{{ self.sample_file() }}

这组样例满足测试点 $18\sim 20$ 的限制。

{{ s('sample', 8) }}

{{ self.sample_file() }}

这组样例满足测试点 $21\sim 23$ 的限制。

{{ s('sample', 9) }}

{{ self.sample_file() }}

这组样例满足测试点 $24,25$ 的限制。

{{ s('部分分设置') }}

对于 $100\%$ 的数据，保证 $1\le n,q\le 10^5$，$1\le k<v\le 1000$，$0\le a_i<v$。

{{ tbl('data') }}

特殊性质 A：$k=1$。

特殊性质 B：$k=2$。

特殊性质 C：询问不超过 $20$ 次。

特殊性质 D：$v$ 是质数。

{{ s('后记') }}

z!mo，盛放那一声呐喊我也还记得。