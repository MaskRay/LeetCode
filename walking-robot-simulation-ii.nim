# Walking Robot Simulation II
type cintA = ptr UncheckedArray[cint]
type Robot {.exportc.} = object
  w, h, d, x, y: cint

proc malloc(size: csize_t): pointer {.importc.}

proc robotCreate(width: cint, height: cint): ptr Robot {.exportc.} =
  result = create(Robot)
  result[] = Robot(w: width, h: height)

proc robotStep(o: ptr Robot, num: cint) {.exportc.} =
  var s = num mod ((2*o.w+2*o.h-4) * 2)
  while s > 0:
    case o.d
    of 0:
      if o.x+s < o.w:
        o.x += s
        break
      s -= o.w-1-o.x
      o.x = o.w-1
      o.d = 1
    of 1:
      if o.y+s < o.h:
        o.y += s
        break
      s -= o.h-1-o.y
      o.y = o.h-1
      o.d = 2
    of 2:
      if s <= o.x:
        o.x -= s
        break
      s -= o.x
      o.x = 0
      o.d = 3
    else:
      if s <= o.y:
        o.y -= s
        break
      s -= o.y
      o.y = 0
      o.d = 0

proc robotGetPos(o: ptr Robot, retSize: ptr cint): cintA {.exportc.} =
  result = cast[cintA](malloc(cast[csize_t](cint.sizeof * 2)))
  retSize[] = 2
  result[0] = o.x
  result[1] = o.y

proc robotGetDir(o: ptr Robot): cstring {.exportc.} =
  let dir = ["East", "North", "West", "South"][o.d]
  result = cast[cstring](malloc(cast[csize_t](dir.len+1)))
  copyMem result, dir.cstring, dir.len+1

proc robotFree(o: ptr Robot) {.exportc.} = dealloc o
