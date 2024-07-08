/*
 * Nvic_Private.h
 *
 *  Created on: May 21, 2024
 *      Author: Omar Abd Elnasser
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NVIC_BASE (0xE000E100)

// Interrupt set-enable register
#define NVIC_ISER0 (*(uint32 *)(NVIC_BASE + (0x04 * 0)))
#define NVIC_ISER1 (*(uint32 *)(NVIC_BASE + (0x04 * 1)))
#define NVIC_ISER2 (*(uint32 *)(NVIC_BASE + (0x04 * 2)))
#define NVIC_ISER3 (*(uint32 *)(NVIC_BASE + (0x04 * 3)))
#define NVIC_ISER4 (*(uint32 *)(NVIC_BASE + (0x04 * 4)))
#define NVIC_ISER5 (*(uint32 *)(NVIC_BASE + (0x04 * 5)))
#define NVIC_ISER6 (*(uint32 *)(NVIC_BASE + (0x04 * 6)))
#define NVIC_ISER7 (*(uint32 *)(NVIC_BASE + (0x04 * 7)))

// Interrupt clear-enable register
#define NVIC_ICER0 (*(uint32 *)(NVIC_BASE + 0x80 + (0x04 * 0)))
#define NVIC_ICER1 (*(uint32 *)(NVIC_BASE + 0x80 + (0x04 * 1)))
#define NVIC_ICER2 (*(uint32 *)(NVIC_BASE + 0x80 + (0x04 * 2)))
#define NVIC_ICER3 (*(uint32 *)(NVIC_BASE + 0x80 + (0x04 * 3)))
#define NVIC_ICER4 (*(uint32 *)(NVIC_BASE + 0x80 + (0x04 * 4)))
#define NVIC_ICER5 (*(uint32 *)(NVIC_BASE + 0x80 + (0x04 * 5)))
#define NVIC_ICER6 (*(uint32 *)(NVIC_BASE + 0x80 + (0x04 * 6)))
#define NVIC_ICER7 (*(uint32 *)(NVIC_BASE + 0x80 + (0x04 * 7)))

// Interrupt set-pending register
#define NVIC_ISPR0 (*(uint32 *)(NVIC_BASE + 0x100 + (0x04 * 0)))
#define NVIC_ISPR1 (*(uint32 *)(NVIC_BASE + 0x100 + (0x04 * 1)))
#define NVIC_ISPR2 (*(uint32 *)(NVIC_BASE + 0x100 + (0x04 * 2)))
#define NVIC_ISPR3 (*(uint32 *)(NVIC_BASE + 0x100 + (0x04 * 3)))
#define NVIC_ISPR4 (*(uint32 *)(NVIC_BASE + 0x100 + (0x04 * 4)))
#define NVIC_ISPR5 (*(uint32 *)(NVIC_BASE + 0x100 + (0x04 * 5)))
#define NVIC_ISPR6 (*(uint32 *)(NVIC_BASE + 0x100 + (0x04 * 6)))
#define NVIC_ISPR7 (*(uint32 *)(NVIC_BASE + 0x100 + (0x04 * 7)))

// Interrupt clear-pending register
#define NVIC_ICPR0 (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * 0)))
#define NVIC_ICPR1 (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * 1)))
#define NVIC_ICPR2 (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * 2)))
#define NVIC_ICPR3 (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * 3)))
#define NVIC_ICPR4 (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * 4)))
#define NVIC_ICPR5 (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * 5)))
#define NVIC_ICPR6 (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * 6)))
#define NVIC_ICPR7 (*(uint32 *)(NVIC_BASE + 0x180 + (0x04 * 7)))


// Interrupt active bit register
#define NVIC_IABR0 (*(uint32 *)(NVIC_BASE + 0x200 + (0x04 * 0)))
#define NVIC_IABR1 (*(uint32 *)(NVIC_BASE + 0x200 + (0x04 * 1)))
#define NVIC_IABR2 (*(uint32 *)(NVIC_BASE + 0x200 + (0x04 * 2)))
#define NVIC_IABR3 (*(uint32 *)(NVIC_BASE + 0x200 + (0x04 * 3)))
#define NVIC_IABR4 (*(uint32 *)(NVIC_BASE + 0x200 + (0x04 * 4)))
#define NVIC_IABR5 (*(uint32 *)(NVIC_BASE + 0x200 + (0x04 * 5)))
#define NVIC_IABR6 (*(uint32 *)(NVIC_BASE + 0x200 + (0x04 * 6)))
#define NVIC_IABR7 (*(uint32 *)(NVIC_BASE + 0x200 + (0x04 * 7)))



#endif /* NVIC_PRIVATE_H_ */
