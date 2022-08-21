include <stdio.h>
        #include "freertos/FreeRTOS.h"
        #include "freertos/task.h"
        


        TaskHandle_t task1_handle, task2_handle, task3_handle, task4_handle;
        

        void task1(void *data)
        {
            UBaseType_t prio1;
            prio1 = uxTaskPriorityGet(task1_handle);
            printf("task1:Started:%d\n", prio1);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            printf("task1 resume task2\n");
            vTaskResume(task2_handle);
            printf("task1 resume task3\n");
            vTaskResume(task3_handle);
            printf("task1 resume task4\n");
            vTaskResume(task4_handle);
            printf("task1 deleting itself\n");
            vTaskDelete(task1_handle);
        }

        void task2(void *data)
        {
            UBaseType_t prio2;
            prio2 = uxTaskPriorityGet(task2_handle);
            printf("task2:Started %d\n", prio2);
            vTaskDelay(1000 / portTICK_PERIOD_MS);  
            
            printf("task2 deleting itself\n");
            
             
            
            vTaskDelete(NULL);
        }
        void task3(void *data)
        {
            UBaseType_t prio3;
            prio3 = uxTaskPriorityGet(task3_handle);
            printf("task3:Started %d\n", prio3);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            printf("task3 deleting itself\n");
            vTaskDelete(NULL);//deleting own task by passing null
            
        }
        void task4(void *data)
        {
            UBaseType_t prio4;
            prio4 = uxTaskPriorityGet(task4_handle);
            printf("task4:Started %d\n", prio4);
            vTaskDelay(1000 / portTICK_PERIOD_MS); 
        
            printf("Task4 running and suspending all tasks\n"); 
            //suspend task2 and task3   
           
            vTaskSuspend(task2_handle);
            vTaskSuspend(task3_handle);
            vTaskSuspend(NULL); //task4 suspend own task
            printf("Back in task4, deleting itself\n");  
            vTaskDelete(task4_handle);
        }

        void app_main()
        {
            BaseType_t res;
            UBaseType_t mt_prio;
            
            
            printf("task suspend resume\n");
            mt_prio = uxTaskPriorityGet(NULL);
           
            printf("Task created successfully:Prio:%d\n", mt_prio);
            res = xTaskCreate(task1, "TASK1", 2048, NULL,1, &task1_handle);
            res = xTaskCreate(task2, "TASK2", 2048, NULL,2, &task2_handle);
            res = xTaskCreate(task3, "TASK3", 2048, NULL,3, &task3_handle);
            res = xTaskCreate(task4, "TASK4", 2048, NULL,4, &task4_handle);
            mt_prio = uxTaskPriorityGet(task4_handle);
            printf("end of the main......\n");
            
        }