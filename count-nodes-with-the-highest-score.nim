# Count Nodes With the Highest Score
import std/sequtils

proc countHighestScoreNodes(parents: ptr UncheckedArray[cint], n: int): int {.exportc.} =
  var
    indegree = newSeq[int](n)
    size = newSeqWith[int](n, 1)
    product = newSeqWith[int](n, 1)
    top = -1
    best = 0
  for i in 0..<n:
    if parents[i] >= 0:
      inc indegree[parents[i]]
  for i in 0..<n:
    if indegree[i] == 0:
      indegree[i] = top
      top = i
  while top >= 0:
    let
      u = top
      v = parents[u]
    top = indegree[top]
    if v >= 0:
      size[v] += size[u]
      product[v] *= size[u]
      dec indegree[v]
      if indegree[v] == 0:
        indegree[v] = top
        top = v

    if n > size[u]:
      product[u] *= n-size[u]
    if product[u] > best:
      best = product[u]
      result = 0
    if product[u] == best:
      inc result
