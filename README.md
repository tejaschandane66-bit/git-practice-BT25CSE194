# git-practice-BT25CSE194

## Student Details
- **Name:** Tejas Chandane
- **Roll Number:** BT25CSE194
- **Section:** CSE C
- **Course:** IT Workshop - I (CSP 201) / Data Structures and Algorithms Lab
- **Institution:** Indian Institute of Information Technology, Nagpur (IIITN)
- **Repository URL:** [https://github.com/tejaschandane-cyber/git-practice-BT25CSE194](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194)

---

## Assignment Overview
This repository contains the complete implementation and Git version-control workflow for the assigned practical laboratory exercises on **Red-Black Trees** and **Binary Tree Properties**, including:
1. **Creation and Insertion:** Insertion of 21 character keys into an empty Red-Black Tree maintaining the five core Red-Black invariants using left/right rotations and recoloring.
2. **Key Search & Color Inspection:** Searching keys in $O(\log n)$ time and reporting presence and node color.
3. **Rotation Counting:** Tracking all left and right rotations executed during insertion balance restoration.
4. **Visual Tree Display:** 2D horizontal hierarchical tree representation displaying node keys and colors.
5. **Node Deletion with Fixup:** CLRS-based Red-Black tree deletion with `rbTransplant`, in-order successor lookup, and full 4-case `deleteFixup` balance restoration.
6. **Deletion Cases Demonstration:** Explicit verification of leaf node deletion, single-child node deletion, and two-children node deletion.
7. **Binary Tree Property Checker:** Automated verification of AVL Tree property (BST + balance factor), Red-Black Tree properties (BST, root black, red property, equal black-height), and Heap property (Complete binary tree + Min/Max heap order).

---

## Completed Exercises

| Exercise | Directory | Description | Source File | Status |
|---|---|---|---|---|
| **Exercise 01** | `exercise-01/` | Creation of Red-Black Tree & Sequential Key Insertion (`F, S, Q, K, C, L, H, T, V, W, M, R, N, P, A, B, X, Y, D, Z, E`) with Inorder Traversal | [`exercise-01/main.c`](exercise-01/main.c) | Verified [Branch: feature/conflict-demo] |
| **Exercise 02** | `exercise-02/` | Search function returning existence and node color (`Red` or `Black`) for existing ('M') and absent ('J') keys | [`exercise-02/main.c`](exercise-02/main.c) | Verified [Branch: feature/conflict-demo] |
| **Exercise 03** | `exercise-03/` | Rotation counter tracking total left and right rotations during full insertion sequence (10 rotations) | [`exercise-03/main.c`](exercise-03/main.c) | Verified [Branch: feature/conflict-demo] |
| **Exercise 04** | `exercise-04/` | 2D visual sideways tree representation showing node keys and colors | [`exercise-04/main.c`](exercise-04/main.c) | Verified [Branch: feature/conflict-demo] |
| **Exercise 05** | `exercise-05/` | Node deletion algorithm with `rbTransplant` and 4-case `deleteFixup` | [`exercise-05/main.c`](exercise-05/main.c) | Verified [Branch: feature/conflict-demo] |
| **Exercise 06** | `exercise-06/` | Demonstration of 3 deletion cases: Leaf ('A'), One Child ('E'), Two Children ('F') with tree visualization | [`exercise-06/main.c`](exercise-06/main.c) | Verified [Branch: feature/conflict-demo] |
| **Exercise 07** | `exercise-07/` | Binary tree property checker for AVL, Red-Black, and Min/Max Heap invariants | [`exercise-07/main.c`](exercise-07/main.c) | Verified [Branch: feature/conflict-demo] |

---

## Instructions to Compile and Run

All programs are implemented in standard C (C99/C11) and can be compiled using `gcc` on Linux, macOS, or Windows (MinGW/Git Bash).

### Exercise 01: Tree Creation & Insertion
```bash
gcc -Wall exercise-01/main.c -o exercise-01/main
./exercise-01/main
```

### Exercise 02: Search & Color Inspection
```bash
gcc -Wall exercise-02/main.c -o exercise-02/main
./exercise-02/main
```

### Exercise 03: Rotation Counter
```bash
gcc -Wall exercise-03/main.c -o exercise-03/main
./exercise-03/main
```

### Exercise 04: Visual Tree Representation
```bash
gcc -Wall exercise-04/main.c -o exercise-04/main
./exercise-04/main
```

### Exercise 05: Node Deletion
```bash
gcc -Wall exercise-05/main.c -o exercise-05/main
./exercise-05/main
```

### Exercise 06: Deletion Cases Demonstration
```bash
gcc -Wall exercise-06/main.c -o exercise-06/main
./exercise-06/main
```

### Exercise 07: Binary Tree Property Checker
```bash
gcc -Wall exercise-07/main.c -o exercise-07/main
./exercise-07/main
```

---

## Evidence of GitHub Activities

### Issues Created
- [Issue #1: Implement Red-Black Tree creation and sequential key insertion](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/issues/1)
- [Issue #2: Implement key search with node color display](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/issues/2)
- [Issue #3: Track and count rotations performed during insertion fixup](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/issues/3)
- [Issue #4: Implement 2D hierarchical visual representation for RB Tree](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/issues/4)
- [Issue #5: Implement Red-Black Tree node deletion and balance restoration](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/issues/5)
- [Issue #6: Demonstrate leaf, single-child, and two-children deletion cases](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/issues/6)
- [Issue #7: Implement tree property checker for AVL, Red-Black, and Heap](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/issues/7)

### Pull Requests Created and Merged
- [PR #1: Feature: Add Red-Black Tree creation and insertion module](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/pull/1) (Merged into `main`)
- [PR #2: Feature: Add key search and color inspection](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/pull/2) (Merged into `main`)
- [PR #3: Feature: Add rotation counter during insertion fixup](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/pull/3) (Merged into `main`)
- [PR #4: Feature: Add 2D visual tree representation](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/pull/4) (Merged into `main`)
- [PR #5: Feature: Add node deletion with transplant and deleteFixup](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/pull/5) (Merged into `main`)
- [PR #6: Feature: Add demonstration suite for three deletion cases](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/pull/6) (Merged into `main`)
- [PR #7: Feature: Add binary tree property verification for AVL, RB, and Heap](https://github.com/tejaschandane-cyber/git-practice-BT25CSE194/pull/7) (Merged into `main`)

### Git Practice Record
For detailed documentation of all Git commands used, their explanation, and the full merge conflict resolution log, refer to [`git-commands.md`](git-commands.md).
