# Find Valid Matrix Given Row and Column Sums
type cintA = ptr UncheckedArray[cint]
proc malloc(size: csize_t): pointer {.importc.}

proc restoreMatrix(row: cintA, m: int, col: cintA, n: int, returnSize: ptr cint,
                   returnColumnSizes:ptr cintA): ptr UncheckedArray[cintA] {.exportc.} =
  var page = cast[cintA](malloc(cast[csize_t](cint.sizeof * m * n)))
  result = cast[ptr UncheckedArray[cintA]](malloc(cast[csize_t](pointer.sizeof * m)))
  returnSize[] = m.cint
  returnColumnSizes[] = cast[cintA](malloc(cast[csize_t](cint.sizeof * m)))
  for i in 0..<m:
    let resi = page
    page = cast[cintA](addr page[n])
    result[i] = resi
    var rowi = row[i]
    returnColumnSizes[][i] = n.cint
    for j in 0..<n:
      let x = min(rowi, col[j])
      resi[j] = x
      rowi -= x
      col[j] -= x
