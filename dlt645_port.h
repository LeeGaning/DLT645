/*
 * @Descripttion:
 * @version:
 * @Author: Ganing
 * @Date: 2020-05-28 14:11:19
 * @LastEditors: Ganing
 * @LastEditTime: 2020-06-28 18:23:16
 */

#ifndef __DLT645_PORT_H_
#define __DLT645_PORT_H_
#include "dlt645.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct packet_t {
    int  len;
    char data[256];
} PACKET_T;
int check_dlt645(dlt645_t* drv, const char* data, int len);

#ifdef __cplusplus
}
#endif
#endif  // __DLT645_PORT_H_
