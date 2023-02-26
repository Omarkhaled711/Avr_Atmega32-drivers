/*
 *  Author: Omar Khaled
 */


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(REG,BIT) (REG=REG|(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG=REG &~(1<<BIT))
#define READ_BIT(REG,BIT) ((REG>>BIT)&1)
#define TOG_BIT(REG,BIT)  (REG=REG^(1<<BIT))



#endif /* UTILS_H_ */