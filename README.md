### **Directory Structure**
To support a new platform, add `src/platform/mu_time_<platform>.c`, 
add `src/platform/mu_time_<platform>.h` and `test/test_mu_time_<platform>.c` as
shown below:

```
mu_time/
├── docs
├── examples
├── LICENSE
├── README.md
├── src
│   ├── mu_time_impl.h
│   ├── mu_time.h
│   └── platform
│       ├── mu_time_posix.c
│       └── mu_time_posix.h
└── test
    ├── fff.h
    ├── Makefile
    ├── test_mu_time_posix.c
    ├── unity_internals.h
    ├── unity.c
    └── unity.h
```

Each platform gets its own **header** (`mu_time_<platform>.h`), **implementation** (`mu_time_<platform>.c`) and **test file**
(`test_mu_time_<platform>.c`).
