# usdt


用户级静态定义的跟踪:

```
usdt:binary_path:probe_name
usdt:libraty_path:probe_name
usdt:binary_path:probe_namespace:probe_name
usdt:library_path:probe_namespace:probe_name

bpftrace -l 'usdt:/usr/bin/python3'
```
