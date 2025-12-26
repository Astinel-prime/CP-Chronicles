# Notes for Meeting on the Line (Codeforces 1730/B)

## Learnings

- This problem involves finding the optimal meeting point on a number line to minimize the maximum time for all people to arrive.
- Key insight: Use binary search on the time T, and for each T, check if the intervals each person can reach have a non-empty intersection.
- The intervals are [x_i - (T - t_i), x_i + (T - t_i)] for each person i, but only if T >= t_i.
- Maintain the intersection by updating L = max(L, left) and R = min(R, right), and check if L <= R.
- The optimal position is the midpoint of the final intersection.

## Optimizations

- Binary search on T from 0 to 2e8, with 50 iterations for precision (since log(2e8) ~ 28, but 50 ensures enough precision for 1e-6 error).
- Time complexity: O(n log 2e8), which is efficient for n <= 1e5.
- Space: O(n) for storing positions and times.

## Mistakes

- Initially, I forgot to handle the case where T < t_i, but the code uses max(0, T - t_i) to avoid negative distances.
- Precision: Used long double for calculations and setprecision(16) for output to meet the 1e-6 error requirement.
- Edge cases: Single person (n=1), zero dressing time (t_i=0), all at same position.

## Approach Summary

1. Read t (test cases).
2. For each test case:
   - Read n, then arrays x and t.
   - Binary search on T: low=0, high=2e8.
   - For each mid T, check if possible (intervals intersect).
   - If possible, high = mid; else low = mid.
   - After 50 iterations, output the best position (midpoint of intersection).
