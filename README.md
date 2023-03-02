# Trignometry-Program-Using-C++
In this program I have  developed sine, cosine and tangent functions by implementing the Taylor series and  have shown how the Taylor series compute the values until the accurate result

Trigonometry, a term that most people who studied basic mathematics are familiar 
with it. It is basically all about triangles and finding the missing angle and sides of a 
triangle. When we were studying in secondary school, if we want to solve any 
problem related to trigonometry, we would easily use our calculators to carry out sin, 
cos and tan functions and get our answer! However, the calculator does not do 
some kind of magic to get you the answers, in fact it carries out a process of 
calculations before it delivers to you the answer.
For students to understand how such values are computed , in this program I have 
developed sine, cosine and tangent functions by implementing the Taylor series and 
have shown how the Taylor series compute the values until the accurate result, 
depending on the precision of the user. The sine and cosine function will take the 
angle (converted to radian) and use the Taylor series

The program compute the most accurate result depending on the precision (which is 
by default 10, but the user can adjust it). Each term is calculated by using the 
formula: power(x,c) / factorial(c), where x is the angle in radians and c is the 
counter. The new term then is added to the previous term by using the formula 
termOld+ (termNew x sign) and the sum of this is stored in a variable called “result”,
then termOld is set to be the termNew , after that the counter is incremented by 2 
and the termNew is calculated, the process repeats until the difference between the 
termOld and termNew is less than the precision (for example 0.000001), then the 
computation will stop and the final result will be printed out with the computation that 
was carried out by the sine and cosine functions and how it was derived to illustrate 
to the students how the Taylor series is actually implemented in a practical way.
Therefore, the program helps the students to understand the Taylor series 
practically rather than looking at the formula and imagining how it is implemented
Adding to that, the program provides the option for the user to calculate the area of 
triangle using the formula, (1/2) x hypotenuse x adjacent x sin(opposite) which helps the 
students in their assignments to calculate the accurate areas of triangle.

