/* 
 * File:   controller.c
 * Author: Andrea
 *
 * Created on August 19, 2016, 10:41 AM
 */
//Management module! 
#include "controller.h"

int main() {
    
    printf("\nThe value of count is: %d", count);
    printf("\nCreating thread SensorManagement\n");
    pthread_create (&thr_sensor, NULL, SensorManagement, (void *) 1);
    pthread_join(thr_sensor, NULL);
    printf("\nThe value of count is: %d", count);
    printf("\nThread Sensor finished\n");
    printf("\nCreating thread RedundancyManagement\n");
    pthread_create (&thr_redundancy, NULL, RedundancyManagement, (void *) 2);
    
    
    pthread_join(thr_redundancy, NULL);
   
    
    
    printf("\nThe value of count is: %d", count);
    //pthread_exit (NULL); 
    
}
