1. [Gas station]()

   - Init need and left_gas variable.
   - need will keep count of how many extra gas is required to reach to the current index from the starting.
   - if we reach till the end of the array and we find that left_gas < need then it means that we are not able to collect the extra gas required to complete the circuit from any of the index. So we return -1
