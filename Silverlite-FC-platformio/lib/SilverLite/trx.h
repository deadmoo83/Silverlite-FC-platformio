#ifndef __TRX_H__
#define __TRX_H__

#include "_my_config.h"	// for RX_SILVERLITE_BAYANG_PROTOCOL
#if defined(RX_SILVERLITE_BAYANG_PROTOCOL)
#include <stdint.h>
#include <stdbool.h>

//------------------------------------------------------------------------------
// Exactly one of these definitions should be provided. This should normally be
// done within file '_my_config.h'
//#define TRX_NRF
//#define TRX_XN297
//#define TRX_XN297L
//#define TRX_LT8900
#if !defined(TRX_NRF) && !defined(TRX_XN297) && !defined(TRX_XN297L) && !defined(TRX_LT8900)
#error "Edit _myc_config.h and enable exactly one of the TRX_??? definitions"
#endif


#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
extern void trx_Init();
extern void trx_SetAddr(uint8_t addr[]);
extern void trx_SetChannel(uint8_t channel);
extern bool trx_TelemetrySent();
extern uint8_t trx_PacketAvailable();
extern void trx_FlushTX();
extern void trx_FlushRX();
extern void trx_SetToRXMode();
extern void trx_PrepareToSendTelemetry();
extern void trx_SendTelemetryPacket(int data[], int size);
extern bool trx_ReadPayload(int data[], int size);

//------------------------------------------------------------------------------
extern void trx_spi_write(int data);
extern int trx_spi_read();
extern void trx_spi_init();
extern void trx_spi_cs_enable();
extern void trx_spi_cs_disable();

extern uint32_t gettime();
extern int xprintf(const char* fmt, ...);

#ifdef __cplusplus
}
#endif


//------------------------------------------------------------------------------
extern void delay_ms(uint32_t ms);
extern void delay_us(uint32_t us);

#if defined(__MODULE_DEV__) || defined(ARDUINO)
	#define XPRINTF  xprintf
#else
	#define XPRINTF(fmt, ...)
#endif

#endif 	// #if defined(RX_SILVERLITE_BAYANG_PROTOCOL)
#endif 
