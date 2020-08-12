# uprobe, uretprobe

用户层动态函数(返回)探查:

```
uprobe:binary_path:function_name
uprobe:library_path:function_name
uretprobe:binary_path:function_name
uretprobe:library_path:function_name

// 参数arg0, arg1, ..., argN
// 返回值retval
```
