# C++ Q&A


- 预处理

``` C++
// sql/mysqld.cc
#ifdef _WIN32
#else
#endif

#ifndef _WIN32
#ifdef WITH_PERFSCHEMA_STORAGE_ENGINE
#endif
#endif

#if defined(_WIN32)
#endif
```


宏:


``` C++
// sql/rpl_handler.h
#define RUN_HOOK(group, hook, args) \
  (group##_delegate->is_empty() ? 0 : group##_delegate->hook args)

// sql/mysqld.cc
(void)RUN_HOOK(server_state, before_server_shutdown, (NULL));  
```
