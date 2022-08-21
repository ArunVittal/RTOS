#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t serial_task_handle;

void serial_task(void *data)
{
    printf("Serial task:Started\n");
}

int app_main()
{
    BaseType_t res;
    printf("DESD RTOS PROJECT\n");
    res = xTaskCreate(serial_task, "SERIALTASK", 2048, NULL,5, &serial_task_handle);
    if(res == pdPASS)
    {
        printf("Task created successfully\n");
    }    
return 0;
}