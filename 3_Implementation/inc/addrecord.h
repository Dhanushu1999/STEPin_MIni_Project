/**
 * @file addrecord.h
 */

#ifndef __ADDRECORD_H__
#define __ADDRECORD_H__

#include "baseinfo.h"
/**
 * @brief add record of employee
 * 
 * @param fp 
 * @param emp 
 * @param temp 
 * @return int 
 */

int addrecord(FILE *fp,struct employee *emp,int temp);

#endif  
