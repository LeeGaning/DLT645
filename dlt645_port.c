#include "dlt645_private.h"
#include "dlt645_port.h"
#include <stdio.h>
#define WAIT_EOI 2  //等待停止位
#define WAIT_AOI 1  //等待第二位
#define WAIT_SOI 0  //等待起始位
#define MaxPacketLen (256)
#define HeaderLen    (8)

int check_dlt645(dlt645_t* drv, const char* data, int len) {
    static int         frame_state = WAIT_SOI;
    static PACKET_T packet;
    for (int i = 0; i < len; i++) {
        switch (frame_state) {
        case WAIT_EOI:  //等待停止位
            if (data[i] == DL645_STOP_CODE) {
                frame_state               = WAIT_SOI;
                packet.data[packet.len++] = data[i];
                drv->port_data            = &packet;
                //获取到完整帧，处理一下
                return 1;
            } else {
                packet.data[packet.len++] = data[i];
            }
            //长度过长则舍弃
            if (packet.len > MaxPacketLen) {
                frame_state = WAIT_SOI;
            }
            break;
        case WAIT_AOI:  //等待信息起始位,第二个0x68
            if (data[i] == DL645_START_CODE && packet.len == HeaderLen - 1) {
                frame_state               = WAIT_EOI;
                packet.data[packet.len++] = data[i];
            } else {
                packet.data[packet.len++] = data[i];
            }
            //长度过长则舍弃
            if (packet.len > HeaderLen) {
                frame_state = WAIT_SOI;
            }
            break;
        default:  //等待起始位，第一个0x68
            if (data[i] == DL645_START_CODE) {
                frame_state               = WAIT_AOI;
                packet.len                = 0;
                packet.data[packet.len++] = data[i];
            }
            break;
        }
    }
    return 0;
}
