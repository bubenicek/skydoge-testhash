
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "trace.h"

void trace_hexdump(const void *buffer, uint16_t buff_len)
{
#define BYTES_PER_LINE 16
    int i;
    if (buff_len == 0)
        return;
    const char *ptr_line;
    // format: field[length]
    //  ADDR[10]+"   "+DATA_HEX[8*3]+" "+DATA_HEX[8*3]+"  |"+DATA_CHAR[8]+"|"
    char hd_buffer[10 + 3 + BYTES_PER_LINE * 3 + 3 + BYTES_PER_LINE + 1 + 1];
    char *ptr_hd;
    int bytes_cur_line;
    int offset = 0;

    do
    {
        if (buff_len > BYTES_PER_LINE)
        {
            bytes_cur_line = BYTES_PER_LINE;
        }
        else
        {
            bytes_cur_line = buff_len;
        }

        ptr_line = buffer;
        ptr_hd = hd_buffer;

        ptr_hd += sprintf(ptr_hd, "%08X ", offset);
        for (i = 0; i < BYTES_PER_LINE; i++, offset++)
        {
            if ((i & 7) == 0)
            {
                ptr_hd += sprintf(ptr_hd, " ");
            }
            if (i < bytes_cur_line)
            {
                ptr_hd += sprintf(ptr_hd, " %02x", (uint8_t)ptr_line[i]);
            }
            else
            {
                ptr_hd += sprintf(ptr_hd, "   ");
            }
        }

        ptr_hd += sprintf(ptr_hd, "  |");
        
        for (i = 0; i < bytes_cur_line; i++)
        {
            if (isprint((int)ptr_line[i]))
            {
                ptr_hd += sprintf(ptr_hd, "%c", ptr_line[i]);
            }
            else
            {
                ptr_hd += sprintf(ptr_hd, ".");
            }
        }
        
        ptr_hd += sprintf(ptr_hd, "|");

        printf("%s\n", hd_buffer);

        buffer += bytes_cur_line;
        buff_len -= bytes_cur_line;

    } while (buff_len);
}
