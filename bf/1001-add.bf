,               // Read first digit
-[-----<+>]-    // Subtract 48 to convert ASCII digit to actual number
>++++++[->++++++<]>.,   // Move to next cell to store the next digit
-[-----<+>]-    // Subtract 48 from the second input digit
[->+<]          // Add both digits (in the second cell)
++++++++++[->++++++++++<]>. // Output the result
