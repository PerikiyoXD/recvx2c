#include "ps2_NaSystem.h"
#include "eestruct.h"
#include "libvu0.h"
#include "ps2_dummy.h"
#include "ps2_loadtim2.h"
#include <cpureg.h>

extern SYS* sys;
sceGsDBuffDc Db;
extern u_int Ps2_dbuff;
extern u_int Ps2_vcount;
void(* EorFunc)();
void(* VsyncFunc)();
PS2_NJ_SAVE Ps2_nj_save_current;
PS2_GS_SAVE Ps2_gs_save;
/* not in original code, assumed to be a macro */
#define CHECK_AND_INCREMENT_TIME(sys_ptr) \
    if (((sys_ptr->tk_flg & 0x80) != 0) && ((sys_ptr->gm_flg & 0x80000000) != 0) && (sys_ptr->time < 216000000)) { \
        sys_ptr->time++; \
    }




/* not in original code, scratchpad memory */
#define WORKBASE (0x70000000)






// DMA code
#define DMArefe (0<<28)
#define DMAcnt  (1<<28)
#define DMAnext (2<<28)
#define DMAref  (3<<28)
#define DMArefs (4<<28)
#define DMAcall (5<<28)
#define DMAret  (6<<28)
#define DMAend  (7<<28)

#define DISP_WIDTH 640
#define DISP_HEIGHT 480



























/* empty */
void njSetTextureMemorySize(Uint32 size) { } // Line 73, Address: 0x2e1380, Func Offset: 0












/* empty */
void njSetVertexBuffer(Uint32* buffer, Sint32 size) { } // Line 87, Address: 0x2e1390, Func Offset: 0











/* 100% match */
void njInitSystem(int mode, int frame, int count) { Ps2Init(); } // Line 100, Address: 0x2e13a0, Func Offset: 0

















/* empty */
void njInitVertexBuffer(Sint32 op, Sint32 om, Sint32 tp, Sint32 tm, Sint32 pt) { } // Line 119, Address: 0x2e13b0, Func Offset: 0











/* empty */
void njWaitVSync() { } // Line 132, Address: 0x2e13c0, Func Offset: 0




/* empty */
void null_func() { } // Line 138, Address: 0x2e13d0, Func Offset: 0

/* 100% match */
void Ps2InitFunc() {
    EorFunc = &null_func; // Line 142, Address: 0x2e13e0, Func Offset: 0
    VsyncFunc = &null_func; // Line 143, Address: 0x2e13f0, Func Offset: 0x10
} // Line 144, Address: 0x2e13fc, Func Offset: 0x1c








/* 100% match */
void njSetEORFunction(void (*func)()) {

    if (func == NULL) { // Line 156, Address: 0x2e1410, Func Offset: 0
        EorFunc = &null_func; // Line 157, Address: 0x2e1418, Func Offset: 0x8
        return; // Line 158, Address: 0x2e1424, Func Offset: 0x14
    } EorFunc = func; // Line 159, Address: 0x2e142c, Func Offset: 0x1c

} // Line 161, Address: 0x2e1434, Func Offset: 0x24







/* 100% match */
void Ps2SwapDBuff(void) { // Line 170, Address: 0x2e1440, Func Offset: 0
    SyncPath(); // Line 171, Address: 0x2e1448, Func Offset: 0x8
    Ps2DrawOTag(); // Line 172, Address: 0x2e1450, Func Offset: 0x10
    Ps2ClearOT(); // Line 173, Address: 0x2e1458, Func Offset: 0x18
    SyncPath(); // Line 174, Address: 0x2e1460, Func Offset: 0x20









    EorFunc(); // Line 184, Address: 0x2e1468, Func Offset: 0x28










    for (;Ps2_vcount < 2;) { // Line 195, Address: 0x2e1478, Func Offset: 0x38
        asm (
            nop; // Line 197, Address: 0x2e1480, Func Offset: 0x40
            nop; // Line 198, Address: 0x2e1484, Func Offset: 0x44
        );
    } // Line 200, Address: 0x2e1488, Func Offset: 0x48



    PS2_swap(); // Line 204, Address: 0x2e149c, Func Offset: 0x5c
    sceGsSwapDBuffDc(&Db, Ps2_dbuff); // Line 205, Address: 0x2e14a4, Func Offset: 0x64
    Ps2_dbuff = (Ps2_dbuff + 1) & 1; // Line 206, Address: 0x2e14bc, Func Offset: 0x7c
    Ps2_vcount = 0; // Line 207, Address: 0x2e14d4, Func Offset: 0x94





    printf("TICK = %d\n", *(volatile u_int *)SR_CU0); // Line 213, Address: 0x2e14dc, Func Offset: 0x9c
    *(volatile u_int *)SR_CU0 = 0; // Line 214, Address: 0x2e14f4, Func Offset: 0xb4

    VsyncFunc(); // Line 216, Address: 0x2e14fc, Func Offset: 0xbc
} // Line 217, Address: 0x2e150c, Func Offset: 0xcc

#pragma optimization_level 0 /* 100% match */
int vsync_func(int param) {
    Ps2_vcount++; // Line 221, Address: 0x2e1520, Func Offset: 0

    CHECK_AND_INCREMENT_TIME(sys); // Line 223, Address: 0x2e1534, Func Offset: 0x14


    ExitHandler(); // Line 226, Address: 0x2e159c, Func Offset: 0x7c

} // Line 228, Address: 0x2e15a4, Func Offset: 0x84
#pragma optimization_level reset

/* 100% match */
void Ps2SetVSyncCounter() { // Line 232, Address: 0x2e15b0, Func Offset: 0
    DisableIntc(2); // Line 233, Address: 0x2e15b8, Func Offset: 0x8
    AddIntcHandler(2, &vsync_func, 0); // Line 234, Address: 0x2e15c0, Func Offset: 0x10
    EnableIntc(2); // Line 235, Address: 0x2e15d4, Func Offset: 0x24
} // Line 236, Address: 0x2e15dc, Func Offset: 0x2c












/* 100% match */
void njSetVSyncFunction(void (*func)()) {
    Ps2_vcount = 0; // Line 251, Address: 0x2e15f0, Func Offset: 0
    if (func == NULL) { // Line 253, Address: 0x2e15f4, Func Offset: 0x4
        VsyncFunc = &null_func; // Line 254, Address: 0x2e15fc, Func Offset: 0xc
        return; // Line 255, Address: 0x2e1608, Func Offset: 0x18
    }
    VsyncFunc = func; // Line 256, Address: 0x2e1610, Func Offset: 0x20


} // Line 259, Address: 0x2e1618, Func Offset: 0x28




/* empty */
void njExitSystem(void) { } // Line 265, Address: 0x2e1620, Func Offset: 0











#define UNCACHED(x)         ((u_int)(x)|0x20000000)

/* 100% match */
void njSetBackColor(Uint32 col1, Uint32 col2, Uint32 col3) {
    unsigned long tmp;

    tmp = SCE_GS_SET_RGBAQ((col1 >> 0x10) & 0xFF, (col1 >> 0x8) & 0xFF, (col1 >> 0x0) & 0xFF, (col1 >> 0x18) & 0xFF, 0); // Line 283, Address: 0x2e1630, Func Offset: 0
    *((unsigned long *)UNCACHED(&Db.clear0.rgbaq)) = tmp; // Line 284, Address: 0x2e1664, Func Offset: 0x34
    *((unsigned long *)UNCACHED(&Db.clear1.rgbaq)) = tmp; // Line 285, Address: 0x2e1678, Func Offset: 0x48
} // Line 286, Address: 0x2e1684, Func Offset: 0x54

#undef UNCACHED






/* 100% match */
void njTextureFilterMode(int mode) {
  Ps2_nj_save_current.mode = mode; // Line 297, Address: 0x2e1690, Func Offset: 0

}// Line 299, Address: 0x2e1694, Func Offset: 0x4





/* empty */
void njPolygonCullingMode(Int mode) { } // Line 306, Address: 0x2e16a0, Func Offset: 0







































void njColorBlendingModeSys(int s_mode, int d_mode) { // Line 346, Address: 0x2e16b0, Func Offset: 0
    unsigned long alpha_value;
    static unsigned long alpha_tbl[13][12];
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    Ps2_gs_save.mode_bk[0] = (Uint8)s_mode; // Line 447, Address: 0x2e16bc, Func Offset: 0xc
    Ps2_gs_save.mode_bk[1] = (Uint8)d_mode; // Line 448, Address: 0x2e16c4, Func Offset: 0x14
    
    Ps2_gs_save.set_last = Ps2_nj_save_current.set_last; // Line 450, Address: 0x2e16cc, Func Offset: 0x1c
    Ps2_gs_save.dc_alpha = 0; // Line 451, Address: 0x2e16e4, Func Offset: 0x34
    if (Ps2_gs_save.mode_bk[Ps2_gs_save.set_last] < 2) { // Line 452, Address: 0x2e16d4, Func Offset: 0x24
        if (Ps2_gs_save.mode_bk[Ps2_gs_save.set_last] == 0) { // Line 453, Address: 0x2e1708, Func Offset: 0x58
            alpha_value = 1; 
        } else { // Line 455, Address: 0x2e1710, Func Offset: 0x60
            alpha_value = 0x44; 
        }
    } else { // Line 458, Address: 0x2e1718, Func Offset: 0x68        
        if ((Ps2_gs_save.mode_bk[0] < 2) || (Ps2_gs_save.mode_bk[1] < 2)) return; // Line 459, Address: 0x2e1720, Func Offset: 0x70
        alpha_value = alpha_tbl[Ps2_gs_save.mode_bk[0]][Ps2_gs_save.mode_bk[1]]; // Line 460, Address: 0x2e1748, Func Offset: 0x98
    }
    
    if (alpha_value == 0xffffffff) { // Line 463, Address: 0x2e1774, Func Offset: 0xc4
        printf("CALL ISHIKAWA ! ALPHA ERROR !!!!!!! MODE %d %d", Ps2_gs_save.mode_bk[0], Ps2_gs_save.mode_bk[1]); // Line 464, Address: 0x2e1788, Func Offset: 0xd8
        while (1); // Line 465, Address: 0x2e17a0, Func Offset: 0xf0
    }


    
    D2_SyncTag(); // Line 470, Address: 0x2e17a8, Func Offset: 0xf8
    
    ((long*)WORKBASE)[0] = DMAend | 4; // Line 472, Address: 0x2e17b0, Func Offset: 0x100
    ((long*)WORKBASE)[1] = 0; // Line 473, Address: 0x2e17c4, Func Offset: 0x114

    ((long*)WORKBASE)[2] = SCE_GIF_SET_TAG(3, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); // Line 475, Address: 0x2e17c0, Func Offset: 0x110
    ((long*)WORKBASE)[3] = SCE_GIF_PACKED_AD; // Line 476, Address: 0x2e17e0, Func Offset: 0x130
    
    ((long*)WORKBASE)[4] = Ps2_gs_save.ALPHA = alpha_value; // Line 478, Address: 0x2e17ec, Func Offset: 0x13c
    ((long*)WORKBASE)[5] = SCE_GS_ALPHA_1; // Line 479, Address: 0x2e17fc, Func Offset: 0x14c
    
    ((long*)WORKBASE)[6] = 0; // Line 481, Address: 0x2e1808, Func Offset: 0x158
    ((long*)WORKBASE)[7] = SCE_GS_PABE; // Line 482, Address: 0x2e1810, Func Offset: 0x160
    
    ((long*)WORKBASE)[8] = Ps2_gs_save.FBA = 0; // Line 484, Address: 0x2e181c, Func Offset: 0x16c
    ((long*)WORKBASE)[9] = SCE_GS_FBA_1; // Line 485, Address: 0x2e182c, Func Offset: 0x17c
    
    loadImage((void*)0xf0000000); // Line 487, Address: 0x2e1838, Func Offset: 0x188
    SyncPath(); // Line 488, Address: 0x2e1840, Func Offset: 0x190
} // Line 489, Address: 0x2e1848, Func Offset: 0x198







































void njColorBlendingMode(Int target, Int mode) {
    Ps2_nj_save_current.mode_bk[target] = mode; // Line 530, Address: 0x2e1860, Func Offset: 0
    Ps2_nj_save_current.set_last = target; // Line 531, Address: 0x2e1870, Func Offset: 0x10
    Ps2_nj_save_current.dc_alpha = 0; // Line 532, Address: 0x2e1878, Func Offset: 0x18
    njColorBlendingModeSys(Ps2_nj_save_current.mode_bk[0],Ps2_nj_save_current.mode_bk[1]); // Line 534, Address: 0x2e1880, Func Offset: 0x20
}

















/* empty */
void njTextureShadingMode(Int mode) { } // Line 553, Address: 0x2e18a0, Func Offset: 0










/* empty */
void njSetCheapShadowMode(Int mode) { } // Line 565, Address: 0x2e18b0, Func Offset: 0





















/* 100% match */
void njUserClipping(int mode, NJS_POINT2* np) { // Line 588, Address: 0x2e18c0, Func Offset: 0
    sceVu0FVECTOR posf;
    sceVu0IVECTOR posi;
    unsigned long * p = (u_long*)WORKBASE;



    
    D2_SyncTag(); // Line 596, Address: 0x2e18dc, Func Offset: 0x1c
    
    *p++ = DMAend | 2; // Line 598, Address: 0x2e18e4, Func Offset: 0x24
    *p++ = 0; // Line 599, Address: 0x2e18f8, Func Offset: 0x38
    
    *p++ = SCE_GIF_SET_TAG(1, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1); // Line 601, Address: 0x2e18f4, Func Offset: 0x34
    *p++ = SCE_GIF_PACKED_AD; // Line 602, Address: 0x2e1914, Func Offset: 0x54

    if (mode == 2) { // Line 604, Address: 0x2e1920, Func Offset: 0x60
        posf[0] = np[0].x * 32.0f; // Line 605, Address: 0x2e192c, Func Offset: 0x6c
        posf[1] = np[0].y * 32.0f; // Line 606, Address: 0x2e1948, Func Offset: 0x88
        posf[2] = np[1].x * 32.0f; // Line 607, Address: 0x2e1954, Func Offset: 0x94
        posf[3] = np[1].y * 32.0f; // Line 608, Address: 0x2e1960, Func Offset: 0xa0
        sceVu0FTOI0Vector(posi, posf); // Line 609, Address: 0x2e1938, Func Offset: 0x78


        
        *p++ = Ps2_gs_save.SCISSOR = SCE_GS_SET_SCISSOR(posi[0], posi[2] + 32, posi[1], posi[3] + 32); // Line 613, Address: 0x2e1970, Func Offset: 0xb0
    
    } else if (mode == 0) { // Line 615, Address: 0x2e19bc, Func Offset: 0xfc
        *p++ = Ps2_gs_save.SCISSOR = SCE_GS_SET_SCISSOR(0, DISP_WIDTH, 0, DISP_HEIGHT); // Line 616, Address: 0x2e19cc, Func Offset: 0x10c
    } else { // Line 617, Address: 0x2e19e8, Func Offset: 0x128
        printf("njUserClipping ERROR!\n"); // Line 618, Address: 0x2e19f0, Func Offset: 0x130
        exit(0); // Line 619, Address: 0x2e19fc, Func Offset: 0x13c
    }
    *p++ = SCE_GS_SCISSOR_1; // Line 621, Address: 0x2e1a04, Func Offset: 0x144
    
    loadImage((void *)0xf0000000); // Line 623, Address: 0x2e1a0c, Func Offset: 0x14c
    D2_SyncTag(); // Line 624, Address: 0x2e1a14, Func Offset: 0x154
} // Line 625, Address: 0x2e1a1c, Func Offset: 0x15c
















/* 100% match */
void njGetSystemAttr(NJS_SYS_ATTR *attr) { 
    
    *(PS2_NJ_SAVE*)attr = Ps2_nj_save_current; // Line 645, Address: 0x2e1a40, Func Offset: 0
    
}  // Line 647, Address: 0x2e1a54, Func Offset: 0x14


/* 100% match */
void njSetSystemAttr(NJS_SYS_ATTR *attr) { 
    
    Ps2_nj_save_current = *(PS2_NJ_SAVE*)attr; // Line 653, Address: 0x2e1a60, Func Offset: 0
    
}  // Line 655, Address: 0x2e1a74, Func Offset: 0x14









/* 100% match */
void njChangeSystem(Int mode, Int frame, Int count) { printf("ChangeSystem\n"); } // Line 666, Address: 0x2e1a80, Func Offset: 0








/* 100% match */
void njAdjustDisplay(Sint32 xadjust, Sint32 yadjust) { 
    if (xadjust < -0x64) xadjust = -0x64; // Line 677, Address: 0x2e1a90, Func Offset: 0
    if (xadjust > 0x280) xadjust = 0x280; // Line 678, Address: 0x2e1aa0, Func Offset: 0x10
    if (yadjust < -0xF)  yadjust = -0xF; // Line 679, Address: 0x2e1ab0, Func Offset: 0x20
    if (yadjust > 0xF0) yadjust = 0xF0; // Line 680, Address: 0x2e1ac0, Func Offset: 0x30
    Db.disp[0].display.DX = xadjust * 3 + 0x27C; // Line 681, Address: 0x2e1adc, Func Offset: 0x4c
    Db.disp[0].display.DY = yadjust * 2 + 0x20; // Line 682, Address: 0x2e1ad0, Func Offset: 0x40
    Db.disp[1].display.DX = xadjust * 3 + 0x27C; // Line 683, Address: 0x2e1b30, Func Offset: 0xa0
    Db.disp[1].display.DY = yadjust * 2 + 0x20; // Line 684, Address: 0x2e1b48, Func Offset: 0xb8
    FlushCache(0); // Line 685, Address: 0x2e1b1c, Func Offset: 0x8c
}







/* empty */
void njSetBorderColor(Uint32 color) { } // Line 695, Address: 0x2e1b70, Func Offset: 0
