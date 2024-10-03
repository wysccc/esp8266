/**
 * relay ctrl
 *
 */



#ifndef RELAY_CTRL_H
#define RELAY_CTRL_H

#define RELAY_CTRL0     2
#define RELAY_CTRL1     4

void relay_init(void);

void relay_ctrl(int relay_num, int delay_ms);
#endif
