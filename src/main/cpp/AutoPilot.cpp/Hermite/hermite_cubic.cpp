// https://people.sc.fsu.edu/~jburkardt/cpp_src/hermite_cubic/hermite_cubic.cpp

# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

using namespace std;

#include "AutoPilot/Hermite/hermite_cubic.h"

//****************************************************************************80

void hermite_cubic_to_power_cubic ( double x1, double f1, double d1, double x2,
  double f2, double d2, double *c0, double *c1, double *c2, double *c3 )

//****************************************************************************80
//
//  Purpose:
//
//    HERMITE_CUBIC_TO_POWER_CUBIC converts a Hermite cubic to power form.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 February 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Fred Fritsch, Ralph Carlson,
//    Monotone Piecewise Cubic Interpolation,
//    SIAM Journal on Numerical Analysis,
//    Volume 17, Number 2, April 1980, pages 238-246.
//
//  Parameters:
//
//    Input, double X1, F1, D1, the left endpoint, function value
//    and derivative.
//
//    Input, double X2, F2, D2, the right endpoint, function value
//    and derivative.
//
//    Output, double *C0, *C1, *C2, *C3, the power form of the polynomial.
//
{
  double df;
  double h;

  h =    x2 - x1;
  df = ( f2 - f1 ) / h;
//
//  Polynomial in terms of X - X1:
//
  *c0 = f1;
  *c1 = d1;
  *c2 = - ( 2.0 * d1 - 3.0 * df + d2 ) / h;
  *c3 =   (       d1 - 2.0 * df + d2 ) / h / h;
//
//  Shift polynomial to X.
//
  *c2 = *c2 - x1 * *c3;
  *c1 = *c1 - x1 * *c2;
  *c0 = *c0 - x1 * *c1;
  *c2 = *c2 - x1 * *c3;
  *c1 = *c1 - x1 * *c2;
  *c2 = *c2 - x1 * *c3;

  return;
}
//****************************************************************************80