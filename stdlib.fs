: ? @ . ; \ comment test
CREATE _tos1
CREATE _tos2
CREATE _tos3
: dup _tos1 ! _tos1 @ _tos1 @ ;
: drop _tos1 ! ;
: swap _tos1 ! _tos2 ! _tos1 @ _tos2 @ ;
: over _tos1 ! _tos2 ! _tos2 @ _tos1 @ _tos2 @ ;
: rot _tos1 ! _tos2 ! _tos3 ! _tos2 @ _tos1 @ _tos3 @ ;
: nip swap drop ;
: tuck swap over ;