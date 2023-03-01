# CSCE451_T3_0

Sometimes "caches" words and if you don't type out full 5 letters gives the cached output.
Probably something to do with how the Trie is implemented.
```
key: 
a
adieu
key: a
adieu
key: *ee**
beech
beefy
geeky
geese
leech
leery
needy
reedy
seedy
teeth
weedy
key: g
key: l
key: w
weedy
key: t
key: n
needy
key: *e
beady
heady
needy
nerdy
ready
reedy
seedy
teddy
weedy
```

Seg fault when you input `a***!`:
Seg faults:
```
key: aaaa!
key: ****!
Segmentation fault (core dumped)
key: a!***
key: abc**
key: a*b!
Segmentation fault (core dumped)
key: !
key: a!
key: *!
Segmentation fault (core dumped)
```

Weird characters like @,#,$,%,^,&,*,(,),-,+ etc gives "cached" answers except for ! which seg faults for some input.

Ctrl+D prints output repeatedly, like when you don't check for input properly in c++.
