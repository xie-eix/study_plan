# WordCount

统计英文文本中的词频，按出现次数降序输出前 20 名。

## 编译

需要 Visual Studio 2022（MSVC）。

```bat
build.bat
```

或者手动：

```bat
cl /nologo /utf-8 /EHsc /W4 /std:c++17 /Iinclude src\main.cpp src\word_counter.cpp /Fe:wordcount.exe
```

## 使用

```powershell
.\wordcount.exe data\sample.txt
```

不传参数时从标准输入读：

```powershell
Get-Content data\sample.txt -Raw | .\wordcount.exe
```

## 设计

程序分三步：

1. `countWords`：读入并归一化（去标点、转小写），用 `unordered_map` 计数
2. `sortedByCount`：转成 `vector`，按次数降序、次数相同按字母序排序
3. `printCounts`：输出前 N 名

## 复杂度

设总词数为 n、不同词数为 m：

- 计数：平均 O(n)
- 排序：O(m log m)
- 总计：O(n + m log m)

## 已知限制

- 只处理 ASCII 字母数字，中文会被当作分隔符
- 连字符会被直接删除（`world-world` → `worldworld`）

## 后续计划

- [ ] 支持 `--top N` 参数
- [ ] 支持停用词表
- [ ] 按连字符切分词语