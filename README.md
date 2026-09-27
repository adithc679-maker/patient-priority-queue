# Hospital Patient Priority Queue – Max Heap, Heap Sort and Quick Sort

## 1. Assignment Title

**Hospital Patient Priority Queue using Max Heap, Heap Sort and Quick Sort**

---

## 2. Problem Statement

A hospital uses a priority queue to manage patients according to the severity of their condition. A higher severity score represents a higher priority.

The given patient severity scores are:

```text
45, 72, 30, 90, 65, 50, 85
```

The assignment requires implementing a **Max Heap** for priority-queue operations and implementing **Heap Sort** and **Quick Sort** for the same set of severity scores. The algorithms are then compared based on their structure, intermediate operations, time complexity and space requirements.

---

## 3. Objectives

The main objectives of this assignment are:

1. Implement a Max Heap in C.
2. Insert the given patient severity scores one by one.
3. Display the heap after every insertion.
4. Implement Heap Sort using a Max Heap.
5. Implement Quick Sort using the given severity scores.
6. Record important intermediate steps during execution.
7. Compare the number of comparisons and swaps.
8. Analyze time and space complexity.
9. Determine which approach is appropriate for a hospital that continuously inserts patients and needs the highest-priority patient immediately.

---

## 4. Input Data

The patient severity scores used for the program are:

```text
45 72 30 90 65 50 85
```

There are **7 patients** in the input.

A larger number indicates a more severe condition and therefore a higher priority.

---

## 5. Algorithms Implemented

### 5.1 Max Heap Insertion

A **Max Heap** is a complete binary tree in which every parent node has a value greater than or equal to its children.

For this problem:

```text
Higher severity score = Higher priority
```

Each new patient is inserted at the end of the heap and then moved upward while its value is greater than its parent.

For the given input, the heap after each insertion is:

| Step | Inserted Score | Heap |
|---|---:|---|
| 1 | 45 | 45 |
| 2 | 72 | 72 45 |
| 3 | 30 | 72 45 30 |
| 4 | 90 | 90 72 30 45 |
| 5 | 65 | 90 72 30 45 65 |
| 6 | 50 | 90 72 50 45 65 30 |
| 7 | 85 | 90 72 85 45 65 30 50 |

Final Max Heap:

```text
          90
        /    \
      72      85
     /  \    /  \
   45   65  30   50
```

Array representation:

```text
90 72 85 45 65 30 50
```

The highest-priority patient is therefore the patient with severity score **90**.

---

## 6. Heap Structure and Height

A heap is stored as a complete binary tree.

For 7 elements:

```text
Height = floor(log2(7)) = 2
```

The root contains the maximum severity score.

The array representation uses:

```text
Parent of i = (i - 1) / 2
Left child   = 2i + 1
Right child  = 2i + 2
```

The Max Heap does not require additional pointer-based tree nodes because it can be stored efficiently in an array.

---

## 7. Heap Sort

Heap Sort first builds a Max Heap and then repeatedly moves the maximum element from the root to the end of the array.

Important intermediate states for the given data are:

```text
Initial Max Heap:
90 72 85 45 65 50 30

After placing 90:
85 72 50 45 65 30 90

After placing 85:
72 65 50 45 30 85 90

After placing 72:
65 45 50 30 72 85 90

After placing 65:
50 45 30 65 72 85 90

After placing 50:
45 30 50 65 72 85 90

After placing 45:
30 45 50 65 72 85 90
```

Final Heap Sort result:

```text
30 45 50 65 72 85 90
```

---

## 8. Quick Sort

Quick Sort divides the array around a pivot.

This implementation uses the **Lomuto partition method**, with the last element selected as the pivot.

Important partition steps for the given input include:

```text
Initial:
45 72 30 90 65 50 85

Pivot = 85:
45 72 30 65 50 85 90

Pivot = 50:
45 30 50 65 72 85 90

Pivot = 30:
30 45 50 65 72 85 90

Pivot = 72:
30 45 50 65 72 85 90
```

Final Quick Sort result:

```text
30 45 50 65 72 85 90
```

---

## 9. Performance Comparison

For the particular C implementation and input used in this assignment, the observed operation counts are:

| Algorithm | Comparisons | Swaps |
|---|---:|---:|
| Heap Sort | 21 | 18 |
| Quick Sort | 12 | 6 |

These counts depend on the implementation, pivot selection and input order. They should not be confused with the general asymptotic complexity.

---

## 10. Complexity Analysis

### Max Heap

| Operation | Time Complexity |
|---|---|
| Insert | O(log n) |
| Get maximum | O(1) |
| Delete maximum | O(log n) |
| Build heap | O(n) |

Space required for storing the heap:

```text
O(n)
```

---

### Heap Sort

| Case | Time Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

Auxiliary space:

```text
O(1)
```

Heap Sort performs the sorting in-place.

---

### Quick Sort

| Case | Time Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n²) |

The average recursion stack requires approximately:

```text
O(log n)
```

The worst-case recursion depth can become:

```text
O(n)
```

depending on pivot selection.

---

## 11. Comparison of Approaches

| Feature | Max Heap Priority Queue | Heap Sort | Quick Sort |
|---|---|---|---|
| Main purpose | Dynamic priority management | Sorting | Sorting |
| Highest-priority access | O(1) | Not maintained dynamically | Not directly available |
| Patient insertion | O(log n) | Not designed for this | Not designed for this |
| Highest-priority deletion | O(log n) | Not applicable | Not applicable |
| Average sorting time | — | O(n log n) | O(n log n) |
| Worst sorting time | — | O(n log n) | O(n²) |
| Suitable for continuous patient arrival | Yes | No | No |

---

## 12. Why Max Heap is Suitable for the Hospital

The hospital does not simply need the patients to be sorted once. New patients can continuously arrive, and the hospital needs to identify the patient with the highest severity immediately.

A Max Heap maintains the highest severity score at the root.

For example:

```text
          90
        /    \
      72      85
     /  \    /  \
   45   65  30   50
```

The highest-priority patient, score **90**, can be accessed directly from the root.

When a new patient arrives, the new severity score can be inserted in **O(log n)** time while preserving the heap property.

Therefore, repeatedly sorting the complete list using Heap Sort or Quick Sort is unnecessary for a dynamic priority queue.

---

## 13. Final Conclusion

For a hospital that continuously receives patients and needs to attend to the most severe patient first, a **Max Heap Priority Queue** is the appropriate data structure.

The Max Heap provides:

- **O(1)** access to the highest-priority patient.
- **O(log n)** insertion of a new patient.
- **O(log n)** deletion of the highest-priority patient.
- Efficient dynamic priority management.

Heap Sort and Quick Sort are useful when the requirement is to sort a fixed collection of severity scores. However, they are not priority-queue data structures and would require additional processing if the patient list keeps changing.

Hence, for the stated hospital scenario, the recommended data structure based on the required operations is a **Max Heap Priority Queue**.

---

## 14. Files Included in This Repository

```text
Hospital-Patient-Priority-Queue/
│
├── patient_priority_assignment.c
├── input.txt
├── output.txt
├── trace_table.txt
├── comparison.txt
└── README.md
```

### File descriptions

**patient_priority_assignment.c**  
Contains the C implementation of Max Heap insertion, Heap Sort and Quick Sort.

**input.txt**  
Contains the given patient severity scores.

**output.txt**  
Contains the execution output of the C program.

**trace_table.txt**  
Contains important intermediate steps of heap insertion and sorting.

**comparison.txt**  
Contains complexity and performance comparisons.

**README.md**  
Contains the complete description of the problem, algorithms, results, complexity analysis and conclusion.

---

## 15. How to Compile and Run

### Using GCC

Open a terminal in the project directory and run:

```bash
gcc patient_priority_assignment.c -o patient_priority_assignment
```

Then run:

### Windows

```powershell
.\patient_priority_assignment.exe
```

### Linux/macOS

```bash
./patient_priority_assignment
```

The program displays the Max Heap insertion steps, Heap Sort steps, Quick Sort partition steps and final results.

---

## 16. Expected Final Output

Both sorting algorithms produce the same sorted sequence:

```text
30 45 50 65 72 85 90
```

The final Max Heap for the priority queue is:

```text
90 72 85 45 65 30 50
```

---

## 17. GitHub Submission

The complete project should be uploaded to a GitHub repository.

Suggested repository name:

```text
Hospital-Patient-Priority-Queue
```

The repository should contain:

- Source code
- Input data
- Execution output
- Trace table
- Complexity analysis
- Comparison table
- Final conclusion

After uploading all files, copy the GitHub repository URL and submit it as the assignment submission link.
