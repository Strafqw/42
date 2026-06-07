

### Absolute import

Spells out the **full path from the project root** (i.e., from wherever Python starts looking — usually the directory you ran `python3` from, or any directory on `sys.path`).

```python
from alchemy.elements import create_air
from alchemy.transmutation.recipes import lead_to_gold
import elements
```

- Path always starts with a **top-level package or module name** — never with a dot.
- Works the same no matter where the importing file lives in the tree.

### Relative import

Spells out the path **relative to the current module's package**, using dots.

```python
from .recipes import lead_to_gold       # same package
from .elements import create_air        # same package
from ..potions import strength_potion   # parent package
from ...something import x               # grandparent package
```

- `.` = current package
- `..` = parent package
- Each extra dot = one level up
- **Only works inside a package** (a directory with `__init__.py`). You cannot use relative imports in a top-level script run as `python3 myfile.py`.

---

### When to use which

| Situation                                                  | Pick                                                  |
| ---------------------------------------------------------- | ----------------------------------------------------- |
| Importing from inside the same package                     | **Relative** — `from .sibling import x`               |
| Importing from a _different_ package or a top-level module | **Absolute** — `from other_pkg.module import x`       |
| Code that might be moved/renamed often                     | **Relative** — survives package renames               |
| Top-level script files (the ones you `python3` directly)   | **Absolute** — relative imports won't work here       |
| Reaching outside your own package                          | **Absolute** — `..` can only go up _within_ a package |

### Trade-offs

**Absolute**

- ✅ Explicit, unambiguous
- ✅ Easy to read — you see exactly where the import comes from
- ❌ Breaks if the package is renamed
- ❌ Verbose for deeply nested packages

**Relative**

- ✅ Concise inside large packages
- ✅ Survives renaming the top-level package
- ❌ Only valid inside packages (not in scripts)
- ❌ The `..` syntax can get cryptic with many levels

### PEP 8 (the official Python style guide) says

> Absolute imports are recommended… However, explicit relative imports are an acceptable alternative to absolute imports, especially when dealing with complex package layouts where using absolute imports would be unnecessarily verbose.

---

### Concrete example from this project

From `alchemy/transmutation/recipes.py`:

```python
from elements import create_fire           # absolute — elements.py is OUTSIDE alchemy
from ..elements import create_air          # relative — alchemy/elements.py, parent package
from ..potions import strength_potion      # relative — alchemy/potions.py, parent package
```

- `create_fire` lives in `elements.py` at the project root, _outside_ the `alchemy` package — you **cannot** reach it with `..` (relative imports never escape their top-level package). Absolute is the only option.
- `create_air` and `strength_potion` live inside the same `alchemy` package — relative is idiomatic.

### Common gotcha

Relative imports require the file to be **loaded as part of a package**. If you do:

```bash
python3 alchemy/transmutation/recipes.py
```

…you'll get `ImportError: attempted relative import with no known parent package`. That's because Python treats the file as a top-level script, not a package member. To run it as part of a package:

```bash
python3 -m alchemy.transmutation.recipes
```


