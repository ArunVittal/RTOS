

/************************** SOLUTION *******************************
 * Following are the two APIs for enabling and disabling the interrupts respectively.
 * 1. void taskENABLE_INTERRUPTS( void );
 * 2. void taskDISABLE_INTERRUPTS( void );
 * 
 * if nesting is required then use "taskENTER_CRITICAL()" and "taskEXIT_CRITICAL()" in place of
 * taskDISABLE_INTERRUPTS() and taskENABLE_INTERRUPTS() respectively.
 *  
 */
