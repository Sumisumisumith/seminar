#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi 3.1415
#define N 200
#define I 100
#define J 100
#define mu 4*pi*powf(10,-7)
#define eps 8.8541*powf(10,-12)
#define sig 0
#define dt 5*powf(10,-13)
#define dx 0.00025
#define dy 0.00025
#define w 2*pi*30*powf(10,9)*3
#define v 1/sqrt(mu*eps)
#define C1 2*dt/(dx*(2*eps+sig*dt))
#define C2 -C1
#define C3 -2*dt/(dy*(2*eps+sig*dt))
#define C4 -C3
#define C5 (2*eps-sig*dt)/(2*eps+sig*dt)
#define C6 -dt/(mu*dy)
#define C7 -C6
#define C8 1
#define C9 dt/(mu*dx)
#define C10 -C9
#define C11 1