# Maximize the Confusion of an Exam
proc maxConsecutiveAnswers(answerKey: cstring, k: int): cint {.exportc.} =
  var
    l = 0
    r = 0
    c = [0, 0]
  while answerKey[r] != '\0':
    inc c[if answerKey[r] == 'T': 1 else: 0]
    inc r
    if c[0].min(c[1]) > k:
      dec c[if answerKey[l] == 'T': 1 else: 0]
      inc l
  cast[cint](r-l)

###

proc maxConsecutiveAnswers(answerKey: cstring, k: int): cint {.exportc.} =
  var
    l = 0
    r = 0
    c = [0, 0]
  while answerKey[r] != '\0':
    inc c[if answerKey[r] == 'T': 1 else: 0]
    inc r
    while c[0].min(c[1]) > k:
      dec c[if answerKey[l] == 'T': 1 else: 0]
      inc l
    result = max(result, cast[cint](r-l))
