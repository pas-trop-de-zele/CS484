//============================================================
// file: main.cpp
//============================================================
#include <cassert>
#include <cstring>
#include <initializer_list>
#include <iostream>

// MATRIX and VECTOR classes assignment
#include "matrix3dT.h"
#include "vector3dT.h"

int main(int argc, const char *argv[]) {
    vector3D::run_tests();
    matrix3D::run_tests();

    return 0;
    /**
     * OUTPUT
     *
====================  TESTING VECTORS  ========================
u
<u,   1   2   4   0>
u.name_ is: u
<u,   1   2   4   0>
<u,   1   2   4   0>
<v,   8  16  32   0>
<i,   1   0   0   0>
<j,   0   1   0   0>
<k,   0   0   1   0>
j + k is: <j+k,   0   1   1   0>
<i*3.000000+j*4.000000-k*2.000000,   3   4  -2   0>
*** asserting u == u and u != v
*** asserting u + v == v + u   and  u - v == -(v - u)    and   -(-u) == u
*** 3.0 + u == u + 3.0   and   3.0 * u == u * 3.0
<u,   1   2   4   0>
<u-3.000000,  -2  -1   1   0>
<-u*-1.000000+3.000000,  -2  -1   1   0>
*** asserting u - 3.- == -(3.0 - u)
*** asserting 5.0 * u == u * 5.0
*** asserting u + vector3D::zero() == u
*** asserting i.dot(j) == j.dot(k) == k.dot(i) == 0
*** asserting i.cross(j) == k   and  j.cross(k) == i   and   k.cross(i) == j
*** asserting u.cross(v) == -v.cross(u)
i.angle(j) is: 1.57
pi/2 is: 1.57
*** asserting i.angle(j) == j.angle(k) == k.angle(i) == M_PI/2
<u,   1   2   4   0>
<u*0.218218,   0   0   0   0>
length of uhat.mag() is... 1
*** asserting u.hat.mag() - 1.0 < 1.0e-10
...test vectors assertions passed
====================  FINISHED testing vectors  ========================


====================  TESTING MATRICES  ====================================================
<'a', <col0,   3   2   0   0><col1,   0   0   1   0><col2,   2  -2   1   0>> OR by rows...
  3   0   2
  2   0  -2
  0   1   1
>
<'b', <col0,   1   0   5   0><col1,   2   1   6   0><col2,   3   4   0   0>> OR by rows...
  1   2   3
  0   1   4
  5   6   0
>
<'', <col0,   1   0   0   0><col1,   0   1   0   0><col2,   0   0   1   0>> OR by rows...
  1   0   0
  0   1   0
  0   0   1
>
<'a*b', <col0,  13  -8   5   0><col1,  18  -8   7   0><col2,   9   6   4   0>> OR by rows...
 13  18   9
 -8  -8   6
  5   7   4
>
<'a*', <col0,   3   2   0   0><col1,   0   0   1   0><col2,   2  -2   1   0>> OR by rows...
  3   0   2
  2   0  -2
  0   1   1
>
<'a*b', <col0,  13  -8   5   0><col1,  18  -8   7   0><col2,   9   6   4   0>> OR by rows...
 13  18   9
 -8  -8   6
  5   7   4
>
<'b*a', <col0,   7   2  27   0><col1,   3   4   0   0><col2,   1   2  -2   0>> OR by rows...
  7   3   1
  2   4   2
 27   0  -2
>
<'-b*a', <col0,  -7  -2 -27   0><col1,  -3  -4   0   0><col2,  -1  -2   2   0>> OR by rows...
 -7  -3  -1
 -2  -4  -2
-27   0   2
>
so far so good
<'aTranspose', <col0,   3   0   2   0><col1,   2   0  -2   0><col2,   0   1   1   0>> OR by rows...
  3   2   0
  0   0   1
  2  -2   1
>
<'bTranspose', <col0,   1   2   3   0><col1,   0   1   4   0><col2,   5   6   0   0>> OR by rows...
  1   0   5
  2   1   6
  3   4   0
>
<'a*bTranspose', <col0,  13  18   9   0><col1,  -8  -8   6   0><col2,   5   7   4   0>> OR by rows...
 13  -8   5
 18  -8   7
  9   6   4
>
test copy constructor -- program will crash at end if this is incorrect
<'a', <col0,   3   2   0   0><col1,   0   0   1   0><col2,   2  -2   1   0>> OR by rows...
  3   0   2
  2   0  -2
  0   1   1
>
test copy constructor using =  -- program will crash at end if this is incorrect
<'a', <col0,   3   2   0   0><col1,   0   0   1   0><col2,   2  -2   1   0>> OR by rows...
  3   0   2
  2   0  -2
  0   1   1
>
test assignment operator  -- program will crash at end if this is incorrect
<'b', <col0,   1   0   5   0><col1,   2   1   6   0><col2,   3   4   0   0>> OR by rows...
  1   2   3
  0   1   4
  5   6   0
>
test negative unary operator
<'-a', <-col0,  -3  -2   0   0><-col1,   0   0  -1   0><-col2,  -2   2  -1   0>> OR by rows...
 -3  -0  -2
 -2  -0   2
 -0  -1  -1
>
<'-b', <-col0,  -1   0  -5   0><-col1,  -2  -1  -6   0><-col2,  -3  -4   0   0>> OR by rows...
 -1  -2  -3
 -0  -1  -4
 -5  -6  -0
>
test determinant
|a| = 10.00
|b| = 1.00
test tranpose
<'aTranspose', <col0,   3   0   2   0><col1,   2   0  -2   0><col2,   0   1   1   0>> OR by rows...
  3   2   0
  0   0   1
  2  -2   1
>
<'bTranspose', <col0,   1   2   3   0><col1,   0   1   4   0><col2,   5   6   0   0>> OR by rows...
  1   0   5
  2   1   6
  3   4   0
>
test minors
<'a_Minors', <col0,   2  -2   0   0><col1,   2   3 -10   0><col2,   2   3   0   0>> OR by rows...
  2   2   2
 -2   3   3
 -0 -10   0
>
<'b_Minors', <col0, -24 -18   5   0><col1, -20 -15   4   0><col2,  -5  -4   1   0>> OR by rows...
-24 -20  -5
-18 -15  -4
  5   4   1
>
test cofactor
<'a_Cofactor', <col0,   2   2   0   0><col1,  -2   3  10   0><col2,   2  -3   0   0>> OR by rows...
  2  -2   2
  2   3  -3
 -0  10   0
>
<'b_Cofactor', <col0, -24  18   5   0><col1,  20 -15  -4   0><col2,  -5   4   1   0>> OR by rows...
-24  20  -5
 18 -15   4
  5  -4   1
>
test adjoint
<'a_CofactorTranspose', <col0,   2  -2   2   0><col1,   2   3  -3   0><col2,   0  10   0   0>> OR by rows...
  2   2  -0
 -2   3  10
  2  -3   0
>
<'b_CofactorTranspose', <col0, -24  20  -5   0><col1,  18 -15   4   0><col2,   5  -4   1   0>> OR by rows...
-24  18   5
 20 -15  -4
 -5   4   1
>
test inverse
<'0.100000*a_CofactorTranspose', <col0*0.100000,   0   0   0   0><col1*0.100000,   0   0   0   0><col2*0.100000,   0   1   0   0>> OR by rows...
0.2 0.2  -0
-0.2 0.3   1
0.2 -0.3   0
>
<'1.000000*b_CofactorTranspose', <col0*1.000000, -24  20  -5   0><col1*1.000000,  18 -15   4   0><col2*1.000000,   5  -4   1   0>> OR by rows...
-24  18   5
 20 -15  -4
 -5   4   1
>
test a * ainv, b * binv
<'a*0.100000*a_CofactorTranspose', <col0,   1   0   0   0><col1,   0   1   0   0><col2,   0   0   1   0>> OR by rows...
  1   0   0
  0   1   0
  0   0   1
>
<'b*1.000000*b_CofactorTranspose', <col0,   1   0   0   0><col1,   0   1   0   0><col2,   0   0   1   0>> OR by rows...
  1   0   0
  0   1   0
  0   0   1
>
<'', <col0,   1   0   0   0><col1,   0   1   0   0><col2,   0   0   1   0>> OR by rows...
  1   0   0
  0   1   0
  0   0   1
>
test a.transpose().tranpose() == a
test a.determinant() == a.transpose().determinant()
test a + b == b + a
test a - b == -(b - a)
test 3.0 + a == a + 3.0
test 3.0 * a == a * 3.0
test a + 3.0 - 3.0 == a
<'3.000000+a', <col0+3.000000,   6   5   3   0><col1+3.000000,   3   3   4   0><col2+3.000000,   5   1   4   0>> OR by rows...
  6   3   5
  5   3   1
  3   4   4
>
<'3.000000-a', <col0-3.000000,   0  -1  -3   0><col1-3.000000,  -3  -3  -2   0><col2-3.000000,  -1  -5  -2   0>> OR by rows...
  0  -3  -1
 -1  -3  -5
 -3  -2  -2
>
<'3.000000-3.000000+a', <col0+3.000000-3.000000,   3   2   0   0><col1+3.000000-3.000000,   0   0   1   0><col2+3.000000-3.000000,   2  -2   1   0>> OR by rows...
  3   0   2
  2   0  -2
  0   1   1
>
test a * 3.0 / 3.0 == a
<'3.000000*a', <col0*3.000000,   9   6   0   0><col1*3.000000,   0   0   3   0><col2*3.000000,   6  -6   3   0>> OR by rows...
  9   0   6
  6   0  -6
  0   3   3
>
<'0.333333*a', <col0*0.333333,   1   0   0   0><col1*0.333333,   0   0   0   0><col2*0.333333,   0   0   0   0>> OR by rows...
  1   0 0.667
0.667   0 -0.667
  0 0.333 0.333
>
-(-a) == a
test matrix(1 2 3   4 5 6   7 8 9) has determinant 0
testing matrix vector multiplication
<p,   1   2   0>
<'m', <col0,   1   2   3   0><col1,   4   0   0   0><col2,   0   0   0   0>> OR by rows...
  1   4   0
  2   0   0
  3   0   0
>
asserting that p * m == m * p
<q,   1   2   3   0>
<'n', <col0,   1   2   3   0><col1,   4   5   6   0><col2,   7   8   9   0>> OR by rows...
  1   4   7
  2   5   8
  3   6   9
>
asserting that q * n == n * q


...test matrices assertions passed

====================  FINISHED testing matrices  ============================================


                >>>>>>>>>>  CONGRATULATIONS -- all assertions passed  <<<<<<<<<<



     *
     */
}
