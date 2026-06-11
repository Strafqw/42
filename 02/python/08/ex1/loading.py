import sys
try:
    import pandas as pd
except ImportError:
    pd = None
try:
    import numpy as np
except ImportError:
    np = None
try:
    import matplotlib
    import matplotlib.pyplot as plt
except ImportError:
    matplotlib = None
    plt = None
deps = [
    (pd, "pandas", "Data manipulation ready"),
    (np, "numpy", "Numerical computation ready"),
    (matplotlib, "matplotlib", "Visualization ready"),
]


def check_dependencies() -> bool:
    all_ok = True
    for module, name, desc in deps:
        if module is None:
            print(f"[MISSING] {name} - not installed")
            all_ok = False
        else:
            print(f"[OK] {name} ({module.__version__}) - {desc}")
    return all_ok


def gen_matrix() -> "np.ndarray":
    return np.random.randn(1000)


def analyze(data: "np.ndarray") -> "pd.DataFrame":
    df = pd.DataFrame({"signal": data})
    print(df.describe())
    return df


def visualize(df: "pd.DataFrame") -> None:
    plt.plot(df["signal"])
    plt.title("Matrix Data Analysis")
    plt.xlabel("Time")
    plt.ylabel("Signal")
    plt.savefig("matrix_analysis.png")


if __name__ == "__main__":
    print("LOADING STATUS: Loading programs...")
    print()
    print("Checking dependencies:")
    if not check_dependencies():
        print()
        print("Install missing dependencies with:")
        print("  pip:    pip install -r requirements.txt")
        print("  Poetry: poetry install")
        sys.exit(1)
    print("Analyzing Matrix data...")
    print("Processing 1000 data points...")
    data = gen_matrix()
    df = analyze(data)
    print("Generating visualization...")
    visualize(df)
    print()
    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")
