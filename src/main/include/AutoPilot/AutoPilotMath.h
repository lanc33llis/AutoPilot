#ifndef AUTOPILOT_MATH_H
#define AUTOPILOT_MATH_H

#include <math.h>

double Angle2Deriv(double AngleInDegrees);

//boost C++
template<typename value_type, typename function_type>
inline value_type integral(const value_type a,
                           const value_type b,
                           const value_type tol,
                           function_type func)
{
   unsigned n = 1U;

   value_type h = (b - a);
   value_type I = (func(a) + func(b)) * (h / 2);

   for(unsigned k = 0U; k < 8U; k++)
   {
      h /= 2;

      value_type sum(0);
      for(unsigned j = 1U; j <= n; j++)
      {
         sum += func(a + (value_type((j * 2) - 1) * h));
      }

      const value_type I0 = I;
      I = (I / 2) + (h * sum);

      const value_type ratio     = I0 / I;
      const value_type delta     = ratio - 1;
      const value_type delta_abs = ((delta < 0) ? -delta : delta);

      if((k > 1U) && (delta_abs < tol))
      {
         break;
      }

      n *= 2U;
   }

   return I;
}
#endif