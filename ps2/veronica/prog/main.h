#pragma once

#include <ninja.h>

typedef struct {
    Uint32 type; /* Function code or identifier */
    Uint8 reserved[3]; /* Function definition block data */
    Uint8 is_root; /* Indicates if this is the root device */
    Uint8 area_code; /* Area or region code */
    Uint8 connector_dir[2]; /* Direction of the extension connector */
    char product_name[32]; /* Product name */
    char license[64]; /* License information */
    Uint16 stdby_pow; /* Standby power consumption (in mA) */
    Uint16 max_pow; /* Maximum power consumption (in mA) */
} KDS_DEVICEINFO;