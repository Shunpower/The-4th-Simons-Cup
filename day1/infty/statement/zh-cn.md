{{ self.title() }}

{{ s('background') }}

{{ img('background.jpg', size = 0.3, align = 'middle', inline = False, caption='“未选择正面标签”') }}

{{ s('description') }}

**本题包含多组测试数据**。

{{ s('input format') }}

{{ self.input_file() }}



{{ s('output format') }}

{{ self.output_file() }}


{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}


{{ s('sample', 2) }}

{{ self.sample_file() }}



{{ s('部分分设置') }}