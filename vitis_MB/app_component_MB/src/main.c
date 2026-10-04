
#include "xparameters.h"
#include "xil_io.h"
#include "xgpio.h"
#include "xtmrctr.h"
#include <stdint.h>

#define LED 1
#define BTN 2
#define BTN_DEL 20

#ifdef SIM
#define TIME_DIV  100000U     
#else
#define TIME_DIV  1U        
#endif

#define TMR_FREQ  (XPAR_AXI_TIMER_0_CLOCK_FREQUENCY / TIME_DIV)

 XGpio gpio ;
 XTmrCtr TimerCounter; 

int main() {
    XGpio_Config *cfg_ptr;
    cfg_ptr = XGpio_LookupConfig(XPAR_XGPIO_0_BASEADDR);
    
    XGpio_CfgInitialize(&gpio, cfg_ptr, cfg_ptr->BaseAddress);
    // XGpio_SetDataDirection(&gpio, LED, 0x0); 
    // XGpio_SetDataDirection(&gpio, BTN, 0xF);     

    
    int Status;
   
    Status = XTmrCtr_Initialize(&TimerCounter, XPAR_AXI_TIMER_0_BASEADDR);
	XTmrCtr_SetOptions(&TimerCounter, 0,
			   XTC_DOWN_COUNT_OPTION);
    // XTmrCtr_SetResetValue(&TimerCounter, 0, TMR_FREQ/2);
    XTmrCtr_SetResetValue(&TimerCounter, 0, TMR_FREQ);
    XTmrCtr_Reset(&TimerCounter, 0);
    XTmrCtr_Start(&TimerCounter, 0);

    u32 led_val    = 0x01;     
    
    u32 speed_ms        = 1000;
    u32 direction       = 0;
    u32 state           = 1;
    u32 btn_up_cnt      = 0;
    u32 btn_dw_cnt      = 0;

    while (1) {
       
       u32 swt_value = XGpio_DiscreteRead(&gpio, BTN);
       
       if (swt_value & 0x01) {
            state = 1;
       }
       
       if (swt_value & 0x02) {
            state = 0;
       }
       
       if (swt_value & 0x04) {        
            if(btn_up_cnt==BTN_DEL){
                speed_ms = speed_ms + 100;
                if (speed_ms >= 2000){
                    speed_ms = 2000;
                }            
                
                XTmrCtr_SetResetValue(&TimerCounter, 0, TMR_FREQ/1000*speed_ms);
                XTmrCtr_Reset(&TimerCounter, 0);
                btn_up_cnt++;
            } else if (btn_up_cnt <BTN_DEL) {
                btn_up_cnt++; 
            }
       } else {
            btn_up_cnt = 0;
       }
       
       if (swt_value & 0x08) {
            if (btn_dw_cnt==BTN_DEL) {         
                speed_ms = speed_ms - 100;
                if (speed_ms == 0){
                    speed_ms = 100;
                }
                
                XTmrCtr_SetResetValue(&TimerCounter, 0, TMR_FREQ/1000*speed_ms);
                XTmrCtr_Reset(&TimerCounter, 0);
                btn_dw_cnt++;
            } else if (btn_dw_cnt <BTN_DEL) {
                btn_dw_cnt++; 
            }    
       }else {
            btn_dw_cnt = 0;
       }
       
       if(swt_value & 0x10){
           direction = 1;
       }else {
           direction = 0;
       }
       
       
       if (state) {
            if (XTmrCtr_IsExpired(&TimerCounter, 0)){
                if(direction){
                    led_val = led_val << 1;
                    if (led_val > 0x08) led_val = 0x01;
                }else {
                    led_val = led_val >> 1;
                    if (led_val == 0x0) led_val = 0x08; 
                }
                XGpio_DiscreteWrite(&gpio, LED,  led_val);
                XTmrCtr_Reset(&TimerCounter, 0);

            }    
       }
       


    }

    return 0;
}