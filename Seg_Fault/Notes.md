# 🧠 Segmentation Fault (Segfault) in C

## 📌 What is a Segmentation Fault?

A **segmentation fault** (often shown as `Segmentation fault` or `SIGSEGV`) is a runtime error that occurs when a program tries to:

* Access memory it is **not allowed to access**
* Or **modify protected memory**

👉 In simple terms:

> Your program touched memory that doesn’t belong to it.

---

## ⚠️ Important Clarification

❌ There are **NO “compile-time segmentation faults”**

* The compiler **cannot detect segfaults directly**
* Segfaults happen **ONLY at runtime**

✔️ The compiler may give **warnings**, but the crash happens when the program runs

---

## 🧩 Common Causes of Segmentation Faults

Instead of “types”, it’s more correct to think in terms of **causes**:

### 1. Out-of-bounds array access

Accessing memory outside array limits

```c
int data[4] = {1, 2, 3, 4};
int x = data[10]; // ❌ invalid
```

---

### 2. Dereferencing NULL or invalid pointers

```c
int *ptr = NULL;
*ptr = 5; // ❌ crash
```

---

### 3. Using uninitialized pointers

```c
int *ptr;
*ptr = 10; // ❌ undefined memory
```

---

### 4. Use-after-free

```c
int *ptr = malloc(sizeof(int));
free(ptr);
*ptr = 5; // ❌ memory already freed
```

---

### 5. Stack overflow (deep recursion)

```c
void f() { f(); } // ❌ infinite recursion
```

---

### 6. Modifying read-only memory

```c
char *str = "hello";
str[0] = 'H'; // ❌ read-only
```

---

## 🔍 Your Example (Very Important)

### Code:

```c
#include <stdio.h>

int main(void)
{
    int data[4] = {1, 2, 3, 4};
    int index = 0;

    printf("index: ");
    scanf("%d", &index);

    printf("%d\n", data[index]);

    return (0);
}
```

---

### 💥 Why this causes a segfault

* Valid indices: `0, 1, 2, 3`
* If user enters:

  ```txt
  1000000
  ```

👉 Then:

```c
data[1000000]
```

* Accesses memory **far outside the array**
* OS blocks access → 💥 **Segmentation fault**

---

### 🧠 Key Insight

> The compiler cannot detect this because it depends on **user input at runtime**

---

## 🛠️ How to Detect Segmentation Faults

### 1. Compile with debug symbols

```bash
gcc -g program.c -o program
```

👉 `-g` allows the debugger to show line numbers

---

### 2. Run with debugger (`lldb` or `gdb`)

#### Using LLDB (macOS)

```bash
lldb ./program
run
```

---

### 3. When crash happens

You will see something like:

```
EXC_BAD_ACCESS (code=1)
```

👉 This means:

> Invalid memory access → segmentation fault

---

### 4. Debugger shows exact line

From your example:

```c
printf("%d\n", data[index]); // ← crash here
```

---

## 🧪 How to Fix Your Example

Always validate input:

```c
if (index >= 0 && index < 4)
    printf("%d\n", data[index]);
else
    printf("Invalid index!\n");
```

---

## 🧠 Mental Model (Very Important)

Think of memory like:

```
[ data[0] ][ data[1] ][ data[2] ][ data[3] ]
```

If you go outside:

```
data[1000000] ❌ → unknown memory → crash
```

---

## ✅ Summary

* Segfault = **invalid memory access**
* Happens **only at runtime**
* Caused by:

  * Out-of-bounds access
  * Bad pointers
  * Freed memory
* Debug using:

  * `-g`
  * `lldb` / `gdb`

---

## 🚀 Next Step (for your future notes)

Later you can add:

* AddressSanitizer (`-fsanitize=address`)
* Valgrind
* Deep dive: stack vs heap memory

---

