````md
# `const` With Pointers in C — Short Notes

## 1. Example from the tutor

```c
unsigned int strlen(const char *str)
{
    unsigned int n;
    const char *p;

    for (p = str, n = 0; *p; p++, n++)
        ;
    return (n);
}
````

Here:

```c
const char *str;
const char *p;
```

means:

> The characters are protected, but the pointer can move.

---

## 2. `const char *p`

```c
const char *p;
```

Read it as:

> `p` points to constant characters.

### Allowed

```c
p = str;          // OK: assign pointer
p++;             // OK: move pointer
p = another_str; // OK: point somewhere else
```

### Not allowed

```c
*p = 'A';        // ERROR: cannot change the character
```

### Analogy

> My finger can move, but I cannot edit what I touch.

| Operation  | Meaning              | Allowed? |
| ---------- | -------------------- | -------- |
| `p++`      | Move my finger       | Yes      |
| `p = str`  | Point somewhere else | Yes      |
| `*p = 'A'` | Change what I touch  | No       |

---

## 3. `char *const p`

```c
char *const p = str;
```

Read it as:

> `p` is a constant pointer to changeable characters.

The pointer itself cannot move, but the characters can be changed.

### Allowed

```c
*p = 'A';     // OK: change first character
p[1] = 'B';   // OK: change second character
p[2] = 'C';   // OK: change third character
```

### Not allowed

```c
p++;          // ERROR: pointer itself cannot move
p = other;    // ERROR: cannot assign pointer again
```

### Important point

Even if `p` cannot move, this is allowed:

```c
p[2] = 'C';
```

Because:

```c
p[2]
```

means:

```c
*(p + 2)
```

`p + 2` is only a temporary address calculation. It does **not** change `p` itself.

### Analogy

> My finger is glued in one place, but I can still reach nearby boxes by calculating positions from it.

| Operation    | Meaning                     | Allowed? |
| ------------ | --------------------------- | -------- |
| `p++`        | Move the finger itself      | No       |
| `p = other`  | Glue finger somewhere else  | No       |
| `*p = 'A'`   | Change first character      | Yes      |
| `p[2] = 'C'` | Change character at index 2 | Yes      |

---

## 4. `const char *const p`

```c
const char *const p = str;
```

Read it as:

> Constant pointer to constant characters.

The pointer cannot move, and the characters cannot be changed.

### Not allowed

```c
p++;          // ERROR
p = other;    // ERROR
*p = 'A';     // ERROR
p[1] = 'B';   // ERROR
```

### Analogy

> My finger is glued, and I am not allowed to edit what I touch.

---

## 5. Quick memory rule

Look at what `const` is protecting.

```c
const char *p;
```

`const` protects the `char`.

> Characters cannot change, pointer can move.

```c
char *const p;
```

`const` protects the pointer `p`.

> Pointer cannot move, characters can change.

```c
const char *const p;
```

`const` protects both.

> Pointer cannot move, characters cannot change.

---

## 6. Summary table

| Type                  | Can move pointer? | Can change characters? | Meaning                            |
| --------------------- | ----------------: | ---------------------: | ---------------------------------- |
| `char *p`             |               Yes |                    Yes | Normal pointer                     |
| `const char *p`       |               Yes |                     No | Pointer to constant chars          |
| `char *const p`       |                No |                    Yes | Constant pointer to chars          |
| `const char *const p` |                No |                     No | Constant pointer to constant chars |

---

## 7. Unforgettable sentence

> `const char *p` = movable finger, locked text.
> `char *const p` = glued finger, editable text.
> `const char *const p` = glued finger, locked text.

```
```

