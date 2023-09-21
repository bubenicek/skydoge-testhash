
#ifndef __TRACE_H
#define __TRACE_H

#define TRACE_NL  "\n"

#if defined(CFG_DEBUG) && (CFG_DEBUG == 1)

#include <stdio.h>

 #define TRACE(_format, ...) 	     fprintf(stderr, _format TRACE_NL, ## __VA_ARGS__)
 #define TRACE_PRINTFF(_format, ...) fprintf(stderr, _format, ## __VA_ARGS__)
 #define TRACE_PRINTF(_format, ...)  fprintf(stderr, _format, ## __VA_ARGS__)
 #define TRACE_ERROR(_format, ...)   fprintf(stderr, "**ERROR** " _format "  %s:%d" TRACE_NL, ## __VA_ARGS__, __FILE__, __LINE__)

 #ifndef ASSERT
 #define ASSERT(EX)                                                             \
  if (!(EX))                                                                    \
  {                                                                             \
    TRACE_ERROR("(%s) Assert failed at %s:%d", #EX, __FUNCTION__, __LINE__);   \
    exit(1);                                                                  \
  }
 #endif   // ASSERT

 #define VERIFY(EX)                                                             \
  if (!(EX))                                                                    \
  {                                                                             \
    TRACE_ERROR("(%s) Verify failed at %s:%d", #EX, __FUNCTION__, __LINE__);   \
  }

#else

 #define TRACE(...)
 #define TRACE_PRINTFF(...)
 #define TRACE_PRINTF(...)
 #define TRACE_ERROR(...)
 #ifndef ASSERT
 #define ASSERT(...) 
 #endif
 #define VERIFY(EX)  (EX)
 #define TRACE_DUMP 

#endif   // CFG_DEBUG

#ifndef VERIFY_FATAL
#define VERIFY_FATAL(EX) {             \
 if (!(EX))                                                               \
 {                                                                        \
    TRACE_ERROR("(%s) Fatal error at %s:%d", #EX, __FUNCTION__, __LINE__);\
    exit(1); \
 } \
}
#endif   // VERIFY_FATAL

void trace_hexdump(const void *buffer, uint16_t buff_len);

#endif   // __TRACE_H

