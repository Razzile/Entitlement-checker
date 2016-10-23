# Entitlement-checker
Checks if the current process has a specified entitlement at runtime on darwin systems.

Usage:

```c
bool has_tfp = has_entitlement("task_for_pid-allow");
// do something with has_tfp
```

Currently, this code relies on functions in Security.framework but I intend to replace that code with 
code to dynamically check entitlements from the mach-o file in memory at runtime
