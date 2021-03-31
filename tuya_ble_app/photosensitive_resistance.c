#include "photosensitive_resistance.h"

#define 	TIME_MS		1000
#define		BUF_LEN		(sizeof(DP_buf) / sizeof(DP_buf[0]))

unsigned long sys_time;
uint8_t DP_buf[4] = {0x65, 0x01, 0x01, 0x00}; //{DP_ID, DP_type, DP_len, DP_data}

void photoresistor_init(void)
{
    gpio_set_func(SWITCH_PIN, AS_GPIO);
    gpio_set_input_en(SWITCH_PIN, 1);
    
    sys_time = clock_time();
}

void photoresistor_fun(void)
{
	if(!clock_time_exceed(sys_time, 1000 * TIME_MS)){
		return;
	}
	sys_time = clock_time();

	if(gpio_read(SWITCH_PIN) == FALSE) {
		DP_buf[3] = OFF;
		TUYA_APP_LOG_INFO("switch_OFF");
		tuya_ble_dp_data_report(DP_buf, BUF_LEN);		// 亮->输出低电平->关
	} else {
		DP_buf[3] = ON;
		TUYA_APP_LOG_INFO("switch_ON");
		tuya_ble_dp_data_report(DP_buf, BUF_LEN);		// 灭->输出高电平->开
	}

}
