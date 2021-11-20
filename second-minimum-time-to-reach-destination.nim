# Second Minimum Time to Reach Destination
import std/sequtils

type cintArray = ptr UncheckedArray[cint]

proc secondMinimum(n: int, edges: ptr UncheckedArray[cintArray], edgesSize: int, _: cintArray, time: int, change: int): int {.exportc.} =
  var
    adj = newSeq[seq[cint]](n)
    d = newSeqWith[int](n, n)
    q = @[n-1]
    qi = 0
  for i in 0..<edgesSize:
    let
      u = edges[i][0]-1
      v = edges[i][1]-1
    adj[u].add v
    adj[v].add u

  d[n-1] = 0
  while qi < q.len:
    let u = q[qi]
    inc qi
    for v in adj[u]:
      if d[v] == n:
        d[v] = d[u]+1
        q.add v

  var length = d[0]+2 # A path of length d[0]+2 always exists
  q.setLen 1
  q[0] = 0
  qi = 0
  while qi < q.len:
    let u = q[qi]
    inc qi
    for v in adj[u]:
      if d[v] == d[u]:
        dec length
        qi = q.len
        break
      elif d[v] == d[u]-1:
        q.add v

  for i in 0..<length:
    let t = result div change
    if t mod 2 == 1:
      result = (t+1) * change
    result += time
