# 🔢 Root-Finding Methods: Secant & Modified False Position

This project demonstrates and compares **two numerical methods** for solving nonlinear equations:  
**Secant Method** and **Modified False Position Method (Regula Falsi)**.  
The goal is to understand their implementation, performance, and **convergence behavior**.

---

## 🎯 Objective
- Implement the **Secant Method** and the **Modified False Position Method** in C++.  
- Compare their efficiency and convergence towards the root.  
- Analyze how each method approaches the solution.

---

## 📂 Project Structure

| File Name                 | Description |
|----------------------------|-------------|
| `secant.cpp`              | Implements the **Secant Method** to approximate the root of a nonlinear equation using two initial guesses and iterative refinement. |
| `m-falseposition.cpp`     | Implements the **Modified False Position Method**, an improved version of the simple False Position Method for better convergence. |
| `compare.cpp`             | Runs **both methods side by side** and provides a comparative analysis of their **convergence behavior**. |

---

## ⚙️ How to Run

You can either **clone this repository** or simply copy the `.cpp` files and run them with any GNU C++ compiler.

### 🔹 Clone & Compile
```bash
# Clone the repository
git clone https://github.com/your-username/your-repo-name.git

# Navigate to project folder
cd your-repo-name

# Compile individual files
g++ secant.cpp -o secant
g++ m-falseposition.cpp -o mfalse
g++ compare.cpp -o compare

# Run executables
./secant
./mfalse
./compare

