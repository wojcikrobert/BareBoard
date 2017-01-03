/*
 * core_cm7.h
 *
 *  Created on: Dec 31, 2016
 *      Author: 502546347
 */

#ifndef SRC_CORE_CM7_H_
#define SRC_CORE_CM7_H_

typedef struct
{
  volatile const  uint32_t CPUID;
  volatile        uint32_t ICSR;
  volatile        uint32_t VTOR;
  volatile        uint32_t AIRCR;
  volatile        uint32_t SCR;
  volatile        uint32_t CCR;
  volatile        uint8_t  SHPR[12U];
  volatile        uint32_t SHCSR;
  volatile        uint32_t CFSR;
  volatile        uint32_t HFSR;
  volatile        uint32_t DFSR;
  volatile        uint32_t MMFAR;
  volatile        uint32_t BFAR;
  volatile        uint32_t AFSR;
  volatile const  uint32_t ID_PFR[2U];
  volatile const  uint32_t ID_DFR;
  volatile const  uint32_t ID_AFR;
  volatile const  uint32_t ID_MFR[4U];
  volatile const  uint32_t ID_ISAR[5U];
                  uint32_t        RESERVED0[1U];
  volatile const  uint32_t CLIDR;
  volatile const  uint32_t CTR;
  volatile const  uint32_t CCSIDR;
  volatile        uint32_t CSSELR;
  volatile        uint32_t CPACR;
                  uint32_t RESERVED3[93U];
  volatile        uint32_t STIR;
                  uint32_t RESERVED4[15U];
  volatile const  uint32_t MVFR0;
  volatile const  uint32_t MVFR1;
  volatile const  uint32_t MVFR2;
                  uint32_t RESERVED5[1U];
  volatile        uint32_t ICIALLU;
                  uint32_t RESERVED6[1U];
  volatile        uint32_t ICIMVAU;
  volatile        uint32_t DCIMVAC;
  volatile        uint32_t DCISW;
  volatile        uint32_t DCCMVAU;
  volatile        uint32_t DCCMVAC;
  volatile        uint32_t DCCSW;
  volatile        uint32_t DCCIMVAC;
  volatile        uint32_t DCCISW;
                  uint32_t RESERVED7[6U];
  volatile        uint32_t ITCMCR;
  volatile        uint32_t DTCMCR;
  volatile        uint32_t AHBPCR;
  volatile        uint32_t CACR;
  volatile        uint32_t AHBSCR;
                  uint32_t RESERVED8[1U];
  volatile        uint32_t ABFSR;
} SCB_Type;

#define SCS_BASE            (0xE000E000UL)
#define SysTick_BASE        (SCS_BASE + 0x0010UL)
#define NVIC_BASE           (SCS_BASE + 0x0100UL)
#define SCB_BASE            (SCS_BASE + 0x0D00UL)
#define SCB                 ((SCB_Type       *) SCB_BASE      )
#define SysTick             ((SysTick_Type   *) SysTick_BASE  )
#define NVIC                ((NVIC_Type      *) NVIC_BASE     )

/* SCB Vector Table Offset Register Definitions */
#define SCB_VTOR_TBLOFF_Pos                 7U
#define SCB_VTOR_TBLOFF_Msk                (0x1FFFFFFUL << SCB_VTOR_TBLOFF_Pos)

#endif /* SRC_CORE_CM7_H_ */
