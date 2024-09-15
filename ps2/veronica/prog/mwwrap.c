#include "mwwrap.h"

#include "ps2_sfd_mw.h"

Sint32 MwMode;
Sint32 MwPlayFlag;
MWPLY MwPly;
MWS_PLY_CPRM_SFD MwsCprmSfd;
Sint32 MwMemoryMode;
Sint32 MwPlayMode;

extern void syFree(void *ap);
extern void *memset(void *, int, size_t);














/* 100% match */
void InitMwSystem(Uint32 Mode, MWS_PLY_INIT_SFD* pPrm) { // Line 29, Address: 0x290960, Func Offset: 0
    switch (Mode) { // Line 30, Address: 0x29096c, Func Offset: 0xc
        case 0:
      mwPlyInitSofdec(pPrm); // Line 32, Address: 0x29098c, Func Offset: 0x2c
        break; // Line 33, Address: 0x290998, Func Offset: 0x38





        case 2:
        mwPlyInitSofdec(pPrm); // Line 40, Address: 0x2909a0, Func Offset: 0x40
        break;
    }







    MwPlayFlag = 0; // Line 50, Address: 0x2909b4, Func Offset: 0x54

    MwMode = Mode; // Line 52, Address: 0x2909ac, Func Offset: 0x4c
} // Line 53, Address: 0x2909bc, Func Offset: 0x5c

/* 100% match */
void ReinitMwSystem(MWS_PLY_INIT_SFD *pPrm) { // Line 56, Address: 0x2909d0, Func Offset: 0
    switch (MwMode) { // Line 57, Address: 0x2909dc, Func Offset: 0xc
        case 0:
        case 2:
        mwPlySetDispMode(pPrm->vhz,pPrm->disp_cycle,pPrm->disp_latency,pPrm->dec_svr); // Line 60, Address: 0x290a00, Func Offset: 0x30
        break;
    }
} // Line 63, Address: 0x290a14, Func Offset: 0x44

/* 100% match */
void ExitMwSystem() { // Line 66, Address: 0x290a20, Func Offset: 0


    switch (MwMode) { // Line 69, Address: 0x290a28, Func Offset: 0x8
    case 0:
        mwPlyFinishSofdec(); // Line 71, Address: 0x290a4c, Func Offset: 0x2c
        break; // Line 72, Address: 0x290a54, Func Offset: 0x34





    case 2:
        mwPlyFinishSofdec(); // Line 79, Address: 0x290a5c, Func Offset: 0x3c
        break;
    }







    MwMode = -1; // Line 89, Address: 0x290a64, Func Offset: 0x44
} // Line 90, Address: 0x290a70, Func Offset: 0x50











/* 100% match */ 
void SetMwSoundMode(Uint32 Mode) { } // Line 103, Address: 0x290a80, Func Offset: 0


/* 100% match */
 void GetMwPlayTime(Sint32* ncount, Sint32* tscale) { MwPly->vtbl->GetTime(MwPly, ncount, tscale); } // Line 107, Address: 0x290a94, Func Offset: 0x4


/* 100% match */
Sint32 GetMwPlayTimeEx() { // Line 111, Address: 0x290ab0, Func Offset: 0
    Sint32 SampleCount, SamplingRate;

    GetMwPlayTime(&SampleCount, &SamplingRate);// Line 114, Address: 0x290ab4, Func Offset: 0x4

    return (((double)SampleCount / (double)SamplingRate) * 100); // Line 116, Address: 0x290ac8, Func Offset: 0x18
} // Line 117, Address: 0x290b00, Func Offset: 0x50




/* 100% match */ 
void CreateSfdHandle(Sint8 * mp, MWS_PLY_CPRM_SFD *pp, Sint8 *fname) { // Line 123, Address: 0x290b10, Func Offset: 0
    memset(&MwsCprmSfd,0,32); // Line 124, Address: 0x290b30, Func Offset: 0x20
    if (pp == (MWS_PLY_CPRM_SFD *)NULL) {// Line 125, Address: 0x290b44, Func Offset: 0x34
        MwsCprmSfd.ftype = 1; // Line 126, Address: 0x290b4c, Func Offset: 0x3c
        MwsCprmSfd.dtype = 0; // Line 127, Address: 0x290b58, Func Offset: 0x48
        MwsCprmSfd.max_bps = 3686400; // Line 128, Address: 0x290b60, Func Offset: 0x50
        MwsCprmSfd.max_width = 320; // Line 129, Address: 0x290b70, Func Offset: 0x60
        MwsCprmSfd.max_height = 240; // Line 130, Address: 0x290b7c, Func Offset: 0x6c
        MwsCprmSfd.nfrm_pool_wk = 3; // Line 131, Address: 0x290b88, Func Offset: 0x78
        MwsCprmSfd.wksize = mwPlyCalcWorkSofdec(MwsCprmSfd.ftype,
                                                MwsCprmSfd.max_bps,
                                                MwsCprmSfd.max_width,
                                                MwsCprmSfd.max_height,
                                                MwsCprmSfd.nfrm_pool_wk);
    } else {// Line 137, Address: 0x290bc4, Func Offset: 0xb4
        MwsCprmSfd.ftype = pp->ftype; // Line 138, Address: 0x290bcc, Func Offset: 0xbc
        MwsCprmSfd.dtype = pp->dtype; // Line 139, Address: 0x290bd8, Func Offset: 0xc8
        MwsCprmSfd.max_bps = pp->max_bps; // Line 140, Address: 0x290be4, Func Offset: 0xd4
        MwsCprmSfd.max_width = pp->max_width; // Line 141, Address: 0x290bf0, Func Offset: 0xe0
        MwsCprmSfd.max_height = pp->max_height; // Line 142, Address: 0x290bfc, Func Offset: 0xec
        MwsCprmSfd.nfrm_pool_wk = pp->nfrm_pool_wk; // Line 143, Address: 0x290c08, Func Offset: 0xf8
        MwsCprmSfd.wksize = pp->wksize; // Line 144, Address: 0x290c14, Func Offset: 0x104
    }

    if (mp == 0) {// Line 147, Address: 0x290c20, Func Offset: 0x110
        MwsCprmSfd.work = (Sint8 *)syMalloc(MwsCprmSfd.wksize); // Line 148, Address: 0x290c28, Func Offset: 0x118
    } else { // Line 149, Address: 0x290c38, Func Offset: 0x128
        MwsCprmSfd.work = (Sint8 *)mp; // Line 150, Address: 0x290c40, Func Offset: 0x130
        MwMemoryMode = 1; // Line 151, Address: 0x290c48, Func Offset: 0x138
    }


    MwPly = ps2mwPlyCreateSofdec(&MwsCprmSfd, fname);// Line 155, Address: 0x290c54, Func Offset: 0x144
                                  
    mwPlySetFastHalfpel(MwPly, 0); // Line 157, Address: 0x290c6c, Func Offset: 0x15c
}// Line 158, Address: 0x290c7c, Func Offset: 0x16c













/* 100% match */ void CreateWaveHandle(Sint32 unk) {} // Line 172, Address: 0x290ca0, Func Offset: 0






/* 100% match */ void CreateTmHandle() {} // Line 179, Address: 0x290cb0, Func Offset: 0


/* 100% match */ void PlayMwOpenMain(Sint8* FileName, Sint32 Mode, Sint8* mp, MWS_PLY_CPRM_SFD* pp, Sint32 PauseFlag) { // Line 182, Address: 0x290cc0, Func Offset: 0
    if (MwPlayFlag != 0) { return; } // Line 183, Address: 0x290cd4, Func Offset: 0x14
    MwMemoryMode = 0; // Line 184, Address: 0x290cec, Func Offset: 0x2c
    switch (MwMode) { // Line 185, Address: 0x290cf4, Func Offset: 0x34
    case 0:


        CreateSfdHandle(mp, pp, FileName); // Line 189, Address: 0x290d24, Func Offset: 0x64

        MwPlayMode = 0; // Line 191, Address: 0x290d34, Func Offset: 0x74
        break; // Line 192, Address: 0x290d38, Func Offset: 0x78
    case 1:
        CreateWaveHandle(0); // Line 194, Address: 0x290d40, Func Offset: 0x80
        MwPlayMode = 1; // Line 195, Address: 0x290d4c, Func Offset: 0x8c
        break; // Line 196, Address: 0x290d54, Func Offset: 0x94
    case 2:
        switch (Mode) { // Line 198, Address: 0x290d5c, Func Offset: 0x9c
        case 0: 


            CreateSfdHandle(mp, pp, FileName); // Line 202, Address: 0x290d84, Func Offset: 0xc4
            
            break; // Line 204, Address: 0x290d94, Func Offset: 0xd4
        case 1: 
            CreateWaveHandle(0); // Line 206, Address: 0x290d9c, Func Offset: 0xdc
            break; // Line 207, Address: 0x290da8, Func Offset: 0xe8
        case 4: 
            CreateTmHandle(); // Line 209, Address: 0x290db0, Func Offset: 0xf0
            break;
        }
        MwPlayMode = Mode; // Line 212, Address: 0x290db8, Func Offset: 0xf8
        break; 
    }
    SetMwSoundMode(GetSoundMode()); // Line 215, Address: 0x290dc0, Func Offset: 0x100
    if (PauseFlag != 0) { // Line 216, Address: 0x290dd0, Func Offset: 0x110
        PauseMw(); // Line 217, Address: 0x290dd8, Func Offset: 0x118
    }
    MwPly->vtbl->StartFname(MwPly, FileName); // Line 219, Address: 0x290de0, Func Offset: 0x120
    MwPlayFlag = 1; // Line 220, Address: 0x290df8, Func Offset: 0x138

} // Line 222, Address: 0x290e04, Func Offset: 0x144







/* 100% match */
 void PlayMw2(Sint8* FileName, Sint32 Mode, Sint8* mp, MWS_PLY_CPRM_SFD* pp, Sint32 PauseFlag) { PlayMwOpenMain(FileName, Mode, mp, pp, PauseFlag); } // Line 231, Address: 0x290e20, Func Offset: 0


/* 100% match */
void StopMw() { // Line 235, Address: 0x290e30, Func Offset: 0
    if (MwPlayFlag != 0) {  // Line 236, Address: 0x290e38, Func Offset: 0x8
        MwPly->vtbl->Stop(MwPly); // Line 237, Address: 0x290e48, Func Offset: 0x18
        MwPly->vtbl->Destroy(MwPly); // Line 238, Address: 0x290e60, Func Offset: 0x30
        if (MwMemoryMode == 0) { // Line 239, Address: 0x290e78, Func Offset: 0x48
            switch (MwPlayMode) { // Line 240, Address: 0x290e88, Func Offset: 0x58
                case 0:  
                syFree(MwsCprmSfd.work); // Line 242, Address: 0x290ea0, Func Offset: 0x70
            }  
        }





        
        MwPlayFlag = 0; // Line 251, Address: 0x290eac, Func Offset: 0x7c
    }
} // Line 253, Address: 0x290eb4, Func Offset: 0x84


/* 100% match */
MWE_PLY_STAT GetMwStatus() { return MwPly->vtbl->GetStat(MwPly); } // Line 257, Address: 0x290ec0, Func Offset: 0


/* 100% match */
int PlayMwMain2(void (*Func)()) { // Line 261, Address: 0x290ee0, Func Offset: 0
    MWE_PLY_STAT MweStat;

    if (MwPlayFlag != 0) { // Line 264, Address: 0x290eec, Func Offset: 0xc
        MweStat = GetMwStatus(); // Line 265, Address: 0x290efc, Func Offset: 0x1c
        if (MweStat == 3) { // Line 266, Address: 0x290f04, Func Offset: 0x24
            if (Func != NULL) { // Line 267, Address: 0x290f10, Func Offset: 0x30
                Func(); // Line 268, Address: 0x290f18, Func Offset: 0x38
            } 
            StopMw(); // Line 270, Address: 0x290f20, Func Offset: 0x40
            return 0; // Line 271, Address: 0x290f28, Func Offset: 0x48
        }

        mwPlyExecServer(); // Line 274, Address: 0x290f30, Func Offset: 0x50
    }
    
    return 1; // Line 277, Address: 0x290f38, Func Offset: 0x58
} // Line 278, Address: 0x290f3c, Func Offset: 0x5c


/* 100% match */
int PlayMwMain() { PlayMwMain2(0); } // Line 282, Address: 0x290f50, Func Offset: 0




/* 100% match */
void PauseMw() { MwPly->vtbl->Pause(MwPly, 1); } // Line 288, Address: 0x290f60, Func Offset: 0
















/* 100% match */
void RestartMw(void) { MwPly->vtbl->Pause(MwPly, 0); } // Line 306, Address: 0x290f80, Func Offset: 0














/* 100% match */
void SetMwVolume(Sint32 Volume) {MwPly->vtbl->SetOutVol(MwPly, Volume); } // Line 322, Address: 0x290fa4, Func Offset: 0x4



/* 100% match */
Sint32 GetSfdFadeRate() { return mwPlyGetBright(MwPly); } // Line 327, Address: 0x290fc0, Func Offset: 0









/* 100% match */
void SetSfdDislpaySize(Float32 PosX,Float32 PosY,Float32 SizeX,Float32 SizeY) { // Line 338, Address: 0x290fd0, Func Offset: 0
  mwPlySetDispPos(MwPly,PosX,PosY); // Line 339, Address: 0x290fe0, Func Offset: 0x10
  mwPlySetDispSize(MwPly,SizeX,SizeY); // Line 340, Address: 0x290ff4, Func Offset: 0x24
} // Line 341, Address: 0x291008, Func Offset: 0x38