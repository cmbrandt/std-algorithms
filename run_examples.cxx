
<algorithm>

// Binary search
g++-10 -Wall -Wpedantic -Wextra -std=c++17 algorithm_lower_bound.cxx    -I /home/ava-569758-1/projects/std-algorithms/include -o ab1.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 algorithm_upper_bound.cxx    -I /home/ava-569758-1/projects/std-algorithms/include -o ab2.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 algorithm_equal_range.cxx    -I /home/ava-569758-1/projects/std-algorithms/include -o ab3.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 algorithm_binary_search.cxx  -I /home/ava-569758-1/projects/std-algorithms/include -o ab4.exe



<functional>

// Arithmetic operations
g++-10 -Wall -std=c++17 functional_plus.cxx          -I /Users/cmbrandt/projects/stl-algorithms/include -o fa1
g++-10 -Wall -std=c++17 functional_minus.cxx         -I /Users/cmbrandt/projects/stl-algorithms/include -o fa2
g++-10 -Wall -std=c++17 functional_multiplies.cxx    -I /Users/cmbrandt/projects/stl-algorithms/include -o fa3
g++-10 -Wall -std=c++17 functional_divides.cxx       -I /Users/cmbrandt/projects/stl-algorithms/include -o fa4
g++-10 -Wall -std=c++17 functional_modulus.cxx       -I /Users/cmbrandt/projects/stl-algorithms/include -o fa5
g++-10 -Wall -std=c++17 functional_negate.cxx        -I /Users/cmbrandt/projects/stl-algorithms/include -o fa6

// Comparisons
g++-9 -Wall -std=c++17 functional_equal_to.cxx      -I /Users/cmbrandt/projects/stl-algorithms/include -o fc1
g++-9 -Wall -std=c++17 functional_not_equal_to.cxx  -I /Users/cmbrandt/projects/stl-algorithms/include -o fc2
g++-9 -Wall -std=c++17 functional_greater.cxx       -I /Users/cmbrandt/projects/stl-algorithms/include -o fc3
g++-9 -Wall -std=c++17 functional_less.cxx          -I /Users/cmbrandt/projects/stl-algorithms/include -o fc4
g++-9 -Wall -std=c++17 functional_greater_equal.cxx -I /Users/cmbrandt/projects/stl-algorithms/include -o fc5
g++-9 -Wall -std=c++17 functional_less_equal.cxx    -I /Users/cmbrandt/projects/stl-algorithms/include -o fc6

// Logical operations
g++-9 -Wall -std=c++17 functional_logical_and.cxx   -I /Users/cmbrandt/projects/stl-algorithms/include -o fl1
g++-9 -Wall -std=c++17 functional_logical_or.cxx    -I /Users/cmbrandt/projects/stl-algorithms/include -o fl2
g++-9 -Wall -std=c++17 functional_logical_not.cxx   -I /Users/cmbrandt/projects/stl-algorithms/include -o fl3

// Bitwise operations
g++-9 -Wall -std=c++17 functional_bit_and.cxx       -I /Users/cmbrandt/projects/stl-algorithms/include -o fb1
g++-9 -Wall -std=c++17 functional_bit_or.cxx        -I /Users/cmbrandt/projects/stl-algorithms/include -o fb2
g++-9 -Wall -std=c++17 functional_bit_xor.cxx       -I /Users/cmbrandt/projects/stl-algorithms/include -o fb3
g++-9 -Wall -std=c++17 functional_bit_not.cxx       -I /Users/cmbrandt/projects/stl-algorithms/include -o fb4



<iterator>

// Iterator operations
g++-10 -Wall -Wpedantic -Wextra -std=c++17 iterator_advance.cxx         -I /home/ava-569758-1/projects/std-algorithms/include  -o i1.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 iterator_distance.cxx        -I /home/ava-569758-1/projects/std-algorithms/include  -o i2.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 iterator_next.cxx            -I /home/ava-569758-1/projects/std-algorithms/include  -o i3.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 iterator_prev.cxx            -I /home/ava-569758-1/projects/std-algorithms/include  -o i4.exe



<numeric>

// Generalized numeric operations
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_accumulate.cxx               -I /home/ava-569758-1/projects/std-algorithms/include -o n01.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_reduce.cxx                   -I /home/ava-569758-1/projects/std-algorithms/include -o n02.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_inner_product.cxx            -I /home/ava-569758-1/projects/std-algorithms/include -o n03.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_transform_reduce.cxx         -I /home/ava-569758-1/projects/std-algorithms/include -o n04.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_partial_sum.cxx              -I /home/ava-569758-1/projects/std-algorithms/include -o n05.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_exclusive_scan.cxx           -I /home/ava-569758-1/projects/std-algorithms/include -o n06.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_inclusive_scan.cxx           -I /home/ava-569758-1/projects/std-algorithms/include -o n07.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_transform_exclusive_scan.cxx -I /home/ava-569758-1/projects/std-algorithms/include -o n08.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_transform_inclusive_scan.cxx -I /home/ava-569758-1/projects/std-algorithms/include -o n09.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_adjacent_difference.cxx      -I /home/ava-569758-1/projects/std-algorithms/include -o n10.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_iota.cxx                     -I /home/ava-569758-1/projects/std-algorithms/include -o n11.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_gcd.cxx                      -I /home/ava-569758-1/projects/std-algorithms/include -o n12.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_lcm.cxx                      -I /home/ava-569758-1/projects/std-algorithms/include -o n13.exe
g++-10 -Wall -Wpedantic -Wextra -std=c++17 numeric_midpoint.cxx                 -I /home/ava-569758-1/projects/std-algorithms/include -o n14.exe
