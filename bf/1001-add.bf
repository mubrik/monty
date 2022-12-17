>,    //read first char c1
>,   // read second char c2

//add c0 to c1 = c1 + c0
[
< +    //add 1 to c1
> -    // sub 1 from c0
]

//substract 48 from c2
++++ ++++    //c1 = 8
[
< --- ---   //add 6 to c0
> -    // sub 1 from c1
]

< - .   //print the c0(sum)
