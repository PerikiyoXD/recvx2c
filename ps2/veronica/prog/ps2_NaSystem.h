#pragma once

#ifndef _PS2_NASYSTEM_H_
#define _PS2_NASYSTEM_H_

#include <shinobi.h>

#include "types.h"

#include "libgraph.h"

typedef struct PS2_NJ_SAVE {
    unsigned char mode_bk[2];
    unsigned char set_last;
    unsigned char dc_alpha;
    int mode;
} PS2_NJ_SAVE;

void njSetTextureMemorySize(Uint32 size);
void njSetVertexBuffer(Uint32* buffer, Sint32 size);
void njInitSystem(Int mode, Int frame, Int count);
void njInitVertexBuffer(Sint32 op, Sint32 om, Sint32 tp, Sint32 tm, Sint32 pt);
void njWaitVSync(void);
void null_func();
void Ps2InitFunc();
void njSetEORFunction(void (*func)(void));
void Ps2SwapDBuff();
void Ps2SetVSyncCounter();
void njSetVSyncFunction(void (*func)(void));
void njExitSystem(void);
void njSetBackColor(Uint32 col1, Uint32 col2, Uint32 col3);
void njTextureFilterMode(Int mode);
void njPolygonCullingMode(Int mode);
void njColorBlendingModeSys(int s_mode, int d_mode); // Not a known NinjaAPI function
void njColorBlendingMode(Int target, Int mode);
void njTextureShadingMode(Int mode);
void njSetCheapShadowMode(Int mode);
void njUserClipping(Int mode, NJS_POINT2* p);
void njGetSystemAttr(NJS_SYS_ATTR* attr);
void njSetSystemAttr(NJS_SYS_ATTR* attr);
void njChangeSystem(Int mode, Int frame, Int count);
void njAdjustDisplay(Sint32 xadjust, Sint32 yadjust);
void njSetBorderColor(Uint32 color);

extern void (*VsyncFunc)();
extern void (*EorFunc)();

#endif /* _PS2_NASYSTEM_H */