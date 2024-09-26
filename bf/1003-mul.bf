,>[-]<[->+<]      Read first digit and convert to numeric value
>>[-]++++++++++++++++++++++++++++++++++++++++++++++++<<
>>[-><<->>]       Subtract 48 from first digit
<<,>>>[-]<[->>>+<<<]  Read second digit and convert to numeric value
>>[-]++++++++++++++++++++++++++++++++++++++++++++++++<<
>>[-><<<<->>]     Subtract 48 from second digit
<<<<<[           Multiply
  ->>[-]>[->+>+<<]>>[->>+<<]<<<
]
>>[              Division to get tens digit
  -----------    Subtract 10 from result
  >+             Increment tens digit
  <              Move back to result
  [              Loop if result >= 10
    -           Continue subtracting 10
    >+          Increment tens digit
    <           Move back to result
  ]
]
>[-]            Clear tens digit if necessary
>              Move to tens digit
[              Output tens digit if not zero
  ++++++++++++++++++++++++++++++++++++++++++++++++
  .            Output tens digit
  -            Decrement to exit loop
]
<<             Move back to units digit
++++++++++++++++++++++++++++++++++++++++++++++++
.             Output units digit
++++++++++.   Output newline character
