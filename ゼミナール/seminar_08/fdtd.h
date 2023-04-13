#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi 3.1415
#define N 2600
#define K 900
#define mu 4*pi*powf(10,-7)
#define eps 8.8541*powf(10,-12)
#define sig 0
#define dz 0.00025
#define dt 7*powf(10,-13)
#define v 1/sqrt(mu*eps)
#define C1 (2*eps-sig*dt)/(2*eps+sig*dt)
#define C2 2*dt/(dz*(2*eps+sig*dt))
#define C3 -C2
#define C4 1
#define C5 dt/(mu*dz)
#define C6 -C5