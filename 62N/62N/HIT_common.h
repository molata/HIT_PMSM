#ifndef HIT_COMMON_H
#define HIT_COMMON_H

uchar ucShake_success = 0;       // serial receive Loop status
uchar ucSerial_send_status = 0;  // serial send Loop status
ST_SERIAL_DECODE stSerial_decode = {0};     //�������ݵĽṹ��
ST_SERIAL_DATA stSerial_data = {0};       // �������ݵĽṹ��
uint u32Error_count = 0;              // �������

#endif