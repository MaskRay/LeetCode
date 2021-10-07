import std/[sequtils, sets]

proc scoreOfStudents(s: cstring, answers: ptr UncheckedArray[cint], answersSize: cint): cint {.exportc.} =
  let
    len = s.len
    n = (len+1) shr 1
  var
    nums = newSeq[int](n)
    ops = newSeq[char](n)
    expected = 0
    b = newSeqWith(n, newSeqWith(n, newSeq[int]()))
    tmp = initHashSet[int]()
  for i in 0..<n:
    nums[i] = s[2*i].ord-'0'.ord
    ops[i] = s[2*i+1]
  var i = 0
  while i < n:
    var x = nums[i]
    while ops[i] == '*':
      inc i
      x *= nums[i]
    expected += x
    inc i

  for i in countdown(n-1, 0):
    b[i][i].add(nums[i])
    for j in i+1..<n:
      tmp.clear
      for k in i..<j:
        for x in b[i][k]:
          for y in b[k+1][j]:
            tmp.incl(if ops[k] == '+': x+y else: x*y)
      for x in tmp:
        b[i][j].add(x)

  let tab = toHashSet(b[0][n-1])
  for i in 0..<answersSize:
    if answers[i] == expected:
      result += 5
    elif answers[i] in tab:
      result += 2
