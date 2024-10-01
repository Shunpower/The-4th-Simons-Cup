{{ self.title() }}

{{ s('background') }}

{{ img('background.jpg', size = 0.18, align = 'middle', inline = False, caption='生来便是高山，向前亦是坦途') }}

{{ s('description') }}

**本题强制在线**。

{{ s('input format') }}

{{ self.input_file() }}

{{ s('output format') }}

{{ self.output_file() }}

{{ s('sample', 1) }}

{{ self.sample_text() }}

上面是自动读入样例 `1.in/ans`（存储在 `down` 文件夹内） 然后渲染到题面中；如果只有一组样例，则去掉 `1` 或将其替换成空串，样例仍然保存成 `1.in/ans`。上面的 `1` 可以是字符串。

{{ self.title_sample_description() }}

这是第一组数据的样例说明。

{{ s('sample', 2) }}

{{ self.sample_file() }}

上面是只提示存在第二组样例，但不渲染到题面中。

{{ s('部分分设置') }}

