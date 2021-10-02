import sequtils, strutils

proc malloc(size: csize_t): pointer {.importc.}

proc diffWaysToCompute(s: cstring, returnSize: ptr cint): ptr UncheckedArray[cint] {.exportc.} =
  var
    i = 0
    nums = newSeq[int]()
    ops = newSeq[char]()
  while true:
    var x = 0
    while (x = x*10+s[i].ord-'0'.ord; inc i; s[i].isDigit):
      discard
    nums.add(x)
    if s[i] == 0.char: break
    ops.add(s[i])
    inc i
  let n = nums.len
  var s = newSeqWith(n, newSeqWith(n, newSeq[int]()))
  for i in 0..<n:
    s[i][i].add(nums[i])
  for i in countdown(n-2, 0):
    for j in i+1..<n:
      for k in i..<j:
        for x in s[i][k]:
          for y in s[k+1][j]:
            s[i][j].add(case ops[k]
            of '+': x+y
            of '-': x-y
            else: x*y)

  returnSize[] = cast[cint](s[0][n-1].len)
  result = cast[ptr UncheckedArray[cint]](malloc(cast[csize_t](cint.sizeof*returnSize[])))
  for i in 0..<s[0][n-1].len:
    result[i] = cast[cint](s[0][n-1][i])
