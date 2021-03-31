#ifndef PHOTOSENSITIVE_RESISTANCE_H_
#define PHOTOSENSITIVE_RESISTANCE_H_

#include "tuya_ble_common.h"
#include "tuya_ble_log.h"

#define SWITCH_PIN		GPIO_PB4
#define ON	1
#define OFF 0

void photoresistor_init(void);
void photoresistor_fun(void);

#endif
