# Maximum Number of Ways to Partition an Array
import std/tables

proc waysToPartition(nums: ptr UncheckedArray[cint], n: int, k: int): cint {.exportc.} =
  var
    s = 0
    prefix = 0
    left = initTable[int, int]()
    right = initTable[int, int]()
    ans = 0
  for i in 0..<n:
    s += cast[int](nums[i])
    inc right.mgetOrPut(s, 0)
  dec right[s]
  if s mod 2 == 0:
    ans = right.getOrDefault(s div 2, 0)

  for i in 0..<n:
    let a = cast[int](nums[i])
    if a != k:
      let s1 = s+k-a
      if s1 mod 2 == 0:
        ans = ans.max(left.getOrDefault(s1 div 2, 0) + right.getOrDefault(s1 div 2+a-k, 0))
    prefix += a
    inc left.mgetOrPut(prefix, 0)
    dec right[prefix]

  return cast[cint](ans)
