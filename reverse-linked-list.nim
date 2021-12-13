type ListNode {.importc.} = ptr object
  val: cint
  next: ListNode

proc reverseList(head: ListNode): ListNode {.exportc.} =
  var x = head
  while x != nil:
    let y = x.next
    x.next = result
    result = x
    x = y
