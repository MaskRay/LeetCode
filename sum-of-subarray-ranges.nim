# Sum of Subarray Ranges
proc subArrayRanges(a: ptr UncheckedArray[cint], n: int): int {.exportc.} =
  var st = @[-1]
  for i in 0..n:
    let x = if i < n: a[i] else: cint.high
    while st.len > 1 and a[st[^1]] < x:
      let j = st.pop
      result += a[j] * (j-st[^1]) * (i-j)
    st.add i
  st = @[-1]
  for i in 0..n:
    let x = if i < n: a[i] else: cint.low
    while st.len > 1 and a[st[^1]] > x:
      let j = st.pop
      result -= a[j] * (j-st[^1]) * (i-j)
    st.add i
