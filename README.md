*This project has been created as part of the 42 curriculum by dael-ter, skheir*

---

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using two stacks — **stack A** and **stack B** — and a limited set of operations, while minimizing the total number of operations used.

The project challenges you to think about algorithm efficiency, complexity, and how different sorting strategies perform depending on the size and disorder of the input.

---

## Instructions

### Compilation

```bash
make
```

This will compile all source files and produce the `push_swap` binary.

### Cleaning

```bash
make clean    # removes object files
make fclean   # removes object files and binary
make re       # recompiles everything from scratch
```

### Execution

```bash
./push_swap [FLAGS] [NUMBERS]
```

**Flags (optional):**

| Flag | Description |
|------|-------------|
| `--simple` | Force the Simple algorithm O(n²) |
| `--medium` | Force the Medium algorithm O(n√n) |
| `--complex` | Force the Complex algorithm O(n log n) |
| `--adaptive` | Force the Adaptive algorithm (auto-selects based on disorder) |
| `--bench` | Display benchmark statistics after sorting |

**Examples:**

```bash
./push_swap 4 67 3 87 23
./push_swap --simple 5 3 8 2 1
./push_swap --bench --adaptive 4 67 3 87 23
./push_swap --bench --complex 4 67 3 87 23 2> bench.txt | ./checker_linux 4 67 3 87 23
```

### Checking correctness

Using the provided checker:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

### Performance testing

```bash
# Test 100 numbers (target: < 2000 ops)
shuf -i 1-10000 -n 100 | tr '\n' ' ' | xargs ./push_swap | wc -l

# Test 500 numbers (target: < 12000 ops)
shuf -i 1-10000 -n 500 | tr '\n' ' ' | xargs ./push_swap | wc -l
```

---

## Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of stack B onto stack A |
| `pb` | Push the top of stack A onto stack B |
| `ra` | Rotate stack A upward (first element becomes last) |
| `rb` | Rotate stack B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Algorithm Justification

This project implements four sorting strategies. The adaptive algorithm automatically selects the best one based on the **disorder** of the input — the ratio of out-of-order pairs to total pairs.

### Simple Algorithm — O(n²)
Used for small inputs (≤ 5 numbers) or when disorder is low (< 20%).

All elements except the top three are pushed to stack B. The top three are sorted directly using `sa`, `ra`, and `rra`. Then each element from stack B is inserted back into the correct position in stack A by rotating until the right slot is found.

This is essentially an insertion sort adapted for the stack structure. It works well for small inputs but becomes expensive for large ones due to its quadratic nature.

### Medium Algorithm — O(n√n)
Used for medium inputs (≤ 100 numbers) or when disorder is moderate (20%–50%).

The stack values are first replaced with their sorted indices (0 to n-1) to normalize the input. Then elements are pushed to stack B in chunks of size √n. Within each chunk, the largest element is always brought to the top of B before pushing back to A. This reduces the number of rotations needed compared to simple insertion.

The chunk-based approach is inspired by the idea that grouping nearby values together reduces unnecessary movement, giving it a O(n√n) average complexity.

### Complex Algorithm — O(n log n)
Used for large inputs (> 100 numbers) or when disorder is high (≥ 50%).

This is a **radix sort** adapted for stacks. Stack values are replaced with sorted indices, then sorted bit by bit from the least significant bit to the most significant bit. For each bit, elements with a 0 bit are pushed to stack B, and elements with a 1 bit are rotated to the back of stack A. After each pass, all elements are pushed back from B to A.

Radix sort has O(n log n) complexity and works well for large inputs. It doesn't require comparisons between elements — only bitwise checks — making it very efficient at scale.

### Adaptive Algorithm
Automatically selects the best strategy based on the disorder value:

| Disorder | Strategy chosen |
|----------|----------------|
| < 20% | Simple / O(n) |
| 20% – 50% | Medium / O(n√n) |
| ≥ 50% | Complex / O(n log n) |

The disorder is computed as the ratio of inverted pairs (pairs where a larger number appears before a smaller one) to the total number of pairs. A low disorder means the input is nearly sorted, so a lightweight algorithm suffices. A high disorder means the input is chaotic, requiring a more powerful algorithm.

---

## Performance Results

| Input size | Operations | Rating |
|------------|------------|--------|
| 100 numbers | ~800–860 | Good (< 1500) ✅ |
| 500 numbers | ~6784 | Good (< 8000) ✅ |

---

## Resources

- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Insertion Sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [Sorting Algorithms Visualizer](https://visualgo.net/en/sorting)
- [Big-O Complexity Cheat Sheet](https://www.bigocheatsheet.com/)
- [42 push_swap subject](https://cdn.intra.42.fr/pdf/pdf/143970/en.subject.pdf)
- [YouTube](https://www.youtube.com) — various tutorials on sorting algorithms, stack operations, and algorithm complexity

### AI Usage

AI tools were used throughout this project as a learning and debugging aid. Their role was supportive, helping to accelerate understanding and improve code quality. Specifically:

- **Debugging**: Assisting in identifying and resolving segmentation faults, memory leaks, and other runtime issues.
- **Architecture guidance**: Providing input on data structure design for operation counting and planning the benchmarking feature.
- **Code review**: Offering feedback on correctness, efficiency, and compliance with Norm standards.
- **Explanation**: Clarifying topics such as pointer handling, typedef conventions, and algorithmic complexity trade‑offs.

All final code was written and understood by the authors. AI was used as a learning aid, not a code generator.