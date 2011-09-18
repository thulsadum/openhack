#ifndef CONFIG_H
#define CONFIG_H

/**
 * @author Sebastian Claus <anthrax2k4@freenet.de>
 * @date 2011-08-24
 * Feature configuration of openhack
 */

#define CFG_COLORS // use colors
#ifdef CFG_COLORS
// use default colours when undefined or define a color override like
// #define CFG_<COLOR> <r>, <g>, <b>
// #define CFG_BLACK 20,20,20 
#endif
#define CFG_MAX_MSG_LEN 4096

#undef CFG_DEBUG_TESTS // debug output from tests
#endif
