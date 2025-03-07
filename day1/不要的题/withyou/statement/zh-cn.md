{{ self.title() }}

{{ s('background') }}

{{ img('background.jpg', size = 0.18, align = 'middle', inline = False, caption='生来便是高山，向前亦是坦途') }}

{{ s('description') }}

**本题包含多组测试数据。**

Simons 偷偷潜入 z!moo 的录音室超前点播了 z!moo 还未完成的的最新创作。这首歌由 $n$ 个音符组成，第 $i$ 个音符是 $a_i$。其中的每个音符都在 $1$ 到 $10^9-1$ 之间。

由于创作还没有完成，里面还存在一些乱写的用于占位的桥段。Simons 认为，如果存在一个区间 $[l,r]$ 使得 $\forall i\in[l,r),a_i\le a_{i+1}$ 或者 $\forall i\in[l,r),a_i\ge a_{i+1}$，则 $[l,r]$ 是**用于占位的**。

对于区间 $[l,r]$，若 $r-l+1=k$，则它是一个**桥段**。

也会写歌的 Simons 想要帮助 z!moo 清理掉这些没用的音符。你需要帮他求出，为了使得这首歌不存在**用于占位的桥段**，至少需要修改多少个位置的音符，并尝试给出一个方案 $\{a'_n\}$。如果无解，也需要报告。

特别地，由于听歌的 Simons 只需要听就行了，所以 Simons 修改可以用的音符的音域限制在上界和下界上都比 z!moo 更宽。形式化地说，修改后的音符可以在 $0$ 到 $10^9$ 之间。

{{ s('input format') }}

{{ self.input_file() }}

第一行一个正整数 $T,id$，表示数据组数和测试点编号。样例中均按照其满足的测试点范围给出 $id$。

对于每组测试数据：

第一行两个正整数 $n,k$，含义如题面所述。

接下来一行 $n$ 个正整数表示 $\{a_n\}$，描述这首歌。

{{ s('output format') }}

{{ self.output_file() }}

对于每组测试数据，第一行一个正整数表示需要修改的音符数量的最小值。无解输出 $-1$。

如果有解，在第二行输出 $n$ 个正整数，描述 Simons 修改出的 $\{a'_n\}$，需要保证里面不存在**用于占位的桥段**，且使用的音符不超过值域限制，且修改的音符数量和答案一致。如有多种方案，你只需要输出其中一种。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

对于第一组数据，任意长度为 $3$ 的区间都是一个桥段。当这首歌改为 $\{1,2,1,7,5\}$ 时：

- 对于桥段 $[1,3]$，由于存在 $a_1<a_2$ 和 $a_2>a_3$，所以这不是一个用于占位的桥段。
- 对于桥段 $[2,4]$，由于存在 $a_2>a_3$ 和 $a_3<a_4$，所以这不是一个用于占位的桥段。
- 对于桥段 $[3,5]$，由于存在 $a_3<a_4$ 和 $a_4>a_5$，所以这不是一个用于占位的桥段。

综上，Simons 改出来的这首歌中不存在任何用于占位的的桥段，满足条件。可以证明，$2$ 是最少的修改次数。

对于第四组数据，任意长度为 $5$ 的区间都是一个桥段。当这首歌不变时：

- 对于桥段 $[1,5]$，由于存在 $a_3>a_4$ 和 $a_4<a_5$，所以这不是一个用于占位的桥段。
- 对于桥段 $[2,6]$，由于存在 $a_3>a_4$ 和 $a_4<a_5$，所以这不是一个用于占位的桥段。
- 对于桥段 $[3,7]$，由于存在 $a_3>a_4$ 和 $a_4<a_5$，所以这不是一个用于占位的桥段。

综上，z!moo 写出来的这首歌中本就不存在任何用于占位的的桥段，满足条件。所以不需要作出任何修改，$0$ 显然也是最少的修改次数。

{{ s('sample', 2) }}

{{ self.sample_file() }}

这组样例满足测试点 $1$ 的数据范围。

{{ s('sample', 3) }}

{{ self.sample_file() }}

这组样例满足测试点 $2,3$ 的数据范围。本样例不包含方案。

{{ s('sample', 4) }}

{{ self.sample_file() }}

这组样例满足测试点 $4,5$ 的数据范围。本样例不包含方案。

{{ s('sample', 5) }}

{{ self.sample_file() }}

这组样例满足测试点 $8,9$ 的数据范围。本样例不包含方案。

{{ s('sample', 6) }}

{{ self.sample_file() }}

这组样例满足测试点 $10,11$ 的数据范围。本样例不包含方案。

{{ s('sample', 7) }}

{{ self.sample_file() }}

这组样例满足测试点 $15$ 的数据范围。本样例不包含方案。

{{ s('sample', 8) }}

{{ self.sample_file() }}

这组样例满足测试点 $18,19$ 的数据范围。本样例不包含方案。

{{ s('sample', 9) }}

{{ self.sample_file() }}

这组样例满足测试点 $20,21$ 的数据范围。本样例不包含方案。

{{ s('sample', 10) }}

{{ self.sample_file() }}

这组样例满足测试点 $24,25$ 的数据范围。本样例不包含方案。

{{ s('部分分设置') }}

对于 $100\%$ 的数据，$1\le id\le 25$，$1\le T\le 10^6$，$\sum n\le 3\times 10^6$，$1\le k\le n\le 10^6$，$0< a_i< 10^9$。

本题包含**自定义校验器**。在答案正确的情况下，任何正确且能够取到答案的方案都可以获得分数。再次提醒，你的方案需要保证 $0\le a'_i\le 10^9$。

{{tbl('data')}}

特殊性质 A：$\{a_n\}$ 要么单调不升要么单调不降。

特殊性质 B：$\{a_n\}$ 中任意两个音符都不相同。

特殊性质 C：$\{a_n\}$ 中有且仅有恰好一种音符。

特殊性质 D：$\{a_n\}$ 中有且仅有恰好两种音符。

特殊性质 E：$\{a_n\}$ 中有且仅有恰好三种音符。

{{s('hint')}}

为了方便选手调试，我们在本题文件夹中下发了本题的自定义校验器 `checker.cpp` 和编译其需要使用的库文件 `testlib.h`。该校验器不会检查是否有解或检查你输出的答案，只会检查你输出的内容是否合法（例如方案是否与答案相符）。**不保证该校验器和实际测试使用的校验器完全相同。**

选手可以在 `testlib.h` 的同一目录下自行编译并运行。运行方式为：`checker <input-file> <output-file> <answer-file>`，其中 `<input-file>` 表示输入文件，`<output-file>` 表示你的输出文件，`<answer-file>` 可以是任意文件。