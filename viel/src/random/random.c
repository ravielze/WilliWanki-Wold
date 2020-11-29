#include <time.h>
#include <stdlib.h>
#include <stdio.h>
time_t t;

void initRNG(){
    srand((unsigned) time(&t));
}

void printRNG(){
    printf("%d\n", RNG());
}

/* How to use */
/* 1. edit the maxval desired */
/* 2. run initRNG in start up */
/* 3. you can now use RNG function */