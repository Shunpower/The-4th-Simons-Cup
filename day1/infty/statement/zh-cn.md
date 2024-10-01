{{ self.title() }}

{{ s('background') }}

{{ img('background.jpg', size = 0.3, align = 'middle', inline = False, caption='“未选择正面标签”') }}

{{ s('description') }}

**本题包含多组测试数据**。

为了补偿自己的负面评价，Simons 决定更加努力地练习。他首先打算为接下来的 $n$ 天制定放假安排。

在这 $n$ 天时间里，有 $m$ 天是法定节假日，分别是第 $p_1,p_2,\cdots p_m$ 天。除此之外，为了避免自己过于劳累，Simons 可能还需要给自己放假。具体来说，最终的放假安排需要满足：

- 不能连续练习超过 $x$ 天。
- 任何一个假期之前和之后连续练习的天数不能超过 $y$ 天。

为了保证最好的效果，Simons 希望给自己放假的天数最少。你需要求出这个最小值。

{{ s('input format') }}

{{ self.input_file() }}

第一行一个正整数 $T$，表示包含的数据组数。

对于每组数据：

第一行四个正整数 $n,m,x,y$，分别表示计划天数，法定节假日天数，对连续练习的限制常数 $x,y$。

接下来一行 $m$ 个整数表示 $\{p_m\}$。

{{ s('output format') }}

{{ self.output_file() }}

对于每组数据，输出一个整数表示 Simons 最少给自己放假的天数。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

这组样例描述了 $2024$ 年 $6$ 月的假期情况。

{{ s('sample', 2) }}

{{ self.sample_file() }}

上面是只提示存在第二组样例，但不渲染到题面中。

{{ s('subtasks') }}

不要使用markdown原生的表格，使用下列方式渲染一个表格，其中表格存放在试题目录的 `tables` 子目录下。

原理上用一个二维的 json 表格或 python 表格存储。会自动纵向合并相同的格子，如果添加了 `merge = False` 则不会合并。不支持横向合并。建议用 python 的格式写，如例子中的 `data.pyinc`，这样可以根据数据生成；跟数据无关的表格则可以像 `table.json` 那样存储。`titled` 表示在要合并的前提下，第一行是否参与合并。

如果自己手动造表格，可以用 `null` 表示和上一行合并，可以用 `no_merge` 函数表示强制不合并特定的格子。

{{ s('scoring') }}

这是评分方法，如果有必要的话。

{{ s('hint') }}

这里是一个非常温馨的提示。