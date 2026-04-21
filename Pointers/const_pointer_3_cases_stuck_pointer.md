# 📌 Const with Pointers — The 3 Cases (C)

Understanding `const` with pointers means answering one question:

> 🔥 **What is locked? The value, the pointer, or both?**

---

## 🧠 Core Idea

There are **two things**:

* **Value** → the data in memory
* **Pointer** → the address

`const` can apply to either… or both.

---

# 1️⃣ Pointer to Constant

```c
const char *p;
```

### 📛 Name

👉 **Pointer to constant**

---

### 📖 Meaning

* ❌ Cannot change the **value**
* ✅ Can change the **address**

---

### ✅ Example

```c
char a = 'a';
char b = 'b';

const char *p = &a;

*p = 'z';   // ❌ ERROR
p = &b;     // ✅ OK
```

---

### 🧠 Mental Model

👉 “I can move, but I cannot modify what I point to”

---

# 2️⃣ Constant Pointer (🔥 Stuck Pointer)

```c
char *const p;
```

### 📛 Name

👉 **Constant pointer**
👉 Your name: **“Stuck pointer”** ✅

---

### 📖 Meaning

* ✅ Can change the **value**
* ❌ Cannot change the **address**

---

### ✅ Example

```c
char a = 'a';
char b = 'b';

char *const p = &a;

*p = 'z';   // ✅ OK
p = &b;     // ❌ ERROR
```

---

### ⚠️ Pointer Arithmetic

```c
p++;   // ❌ ERROR (pointer is stuck)
```

---

### 🧠 Mental Model

👉 “I am stuck in one place, but I can modify it”

---

# 3️⃣ Constant Pointer to Constant (🔥 Double Locked)

```c
const char *const p;
```

### 📛 Name

👉 **Constant pointer to constant**
👉 Suggested memory name: **“Fully locked pointer”** 🔒

---

### 📖 Meaning

* ❌ Cannot change the **value**
* ❌ Cannot change the **address**

---

### ✅ Example

```c
char a = 'a';
char b = 'b';

const char *const p = &a;

*p = 'z';   // ❌ ERROR
p = &b;     // ❌ ERROR
```

---

### ⚠️ Pointer Arithmetic

```c
p++;   // ❌ ERROR
```

---

### 🧠 Mental Model

👉 “I cannot move, and I cannot modify”

---

# 🔥 Comparison Table

| Declaration           | Name                 | Value | Address | Movement |
| --------------------- | -------------------- | ----- | ------- | -------- |
| `const char *p`       | Pointer to constant  | ❌     | ✅       | ✅        |
| `char *const p`       | Stuck pointer        | ✅     | ❌       | ❌        |
| `const char *const p` | Fully locked pointer | ❌     | ❌       | ❌        |

---

# 🧩 Analogy (Remote & TV)

👉 Think:

* Pointer = **remote control**
* Value = **TV channel**

---

### 1️⃣ Pointer to constant

* You can switch TVs 📺➡️📺
* But cannot change channel ❌

👉 Remote moves, channel locked

---

### 2️⃣ Stuck pointer

* You are stuck with one TV 📺
* But can change channel ✅

👉 Remote stuck, channel free

---

### 3️⃣ Fully locked pointer

* You are stuck with one TV 📺
* And cannot change channel ❌

👉 Everything locked 🔒

---

# 🔥 Ultimate Rule (Exam Trick)

👉 Read **right to left**:

* `const char *p` → pointer to const char
* `char *const p` → const pointer to char
* `const char *const p` → const pointer to const char

---

# 🎯 Final Summary

* `const char *p` → **value locked**
* `char *const p` → **pointer locked (stuck)**
* `const char *const p` → **everything locked**

---

# 📛 Suggested File Name

```bash
const_pointer_3_cases_stuck_pointer.md
```

---
