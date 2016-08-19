/* 
 * File:   core.h
 * Author: Andrea
 *
 * Created on August 19, 2016, 10:41 AM
 */

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int count=0;
sem_t active, available;

void *SensorManagement(void *threadid);
void *RedundancyManagement(void *threadid);

void *SensorManagement(void *threadid) {
    printf("\nHello I am the Sensor Management Thread, number %d\n", threadid);
    count++;
    sem_post(&available);
    //pthread_exit(NULL);
}

void *RedundancyManagement(void *threadid) {
    sem_wait(&available);
    printf("\nHello I am the Redundancy Management Thread, number %d\n", threadid);
    count++;
    //pthread_exit (NULL);
}

