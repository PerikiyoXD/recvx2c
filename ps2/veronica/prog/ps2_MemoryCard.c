#include "ps2_MemoryCard.h"
#include <string.h>





























































































/* 100% match */
MEMORYCARDSTATE * CreateMemoryCard(MEMORYCARDSTATE *pCard) { // Line 97, Address: 0x2735b0, Func Offset: 0
    pCard->ulState = 0; // Line 98, Address: 0x2735bc, Func Offset: 0xc
    pCard->ulError = 0;  // Line 99, Address: 0x2735c0, Func Offset: 0x10
    pCard->ulMcSubState = 0;  // Line 100, Address: 0x2735c4, Func Offset: 0x14
    pCard->ulFileSize = 0; // Line 101, Address: 0x2735c8, Func Offset: 0x18
    pCard->lCurrentPort = 0; // Line 102, Address: 0x2735cc, Func Offset: 0x1c
    pCard->lOpenFileNumber = 0; // Line 103, Address: 0x2735d0, Func Offset: 0x20
    pCard->lSelectFileNumber = 0; // Line 104, Address: 0x2735d4, Func Offset: 0x24
    pCard->lOpenMode = 0; // Line 105, Address: 0x2735d8, Func Offset: 0x28
    pCard->usMcSysState = 0; // Line 106, Address: 0x2735dc, Func Offset: 0x2c
    pCard->vpAddr = 0; // Line 107, Address: 0x2735e0, Func Offset: 0x30
    pCard->cRetryCount = 0; // Line 108, Address: 0x2735e4, Func Offset: 0x34
    pCard->cMcCheckFlag = 0; // Line 109, Address: 0x2735ec, Func Offset: 0x3c
    pCard->cCheckMcFlag = 0; // Line 110, Address: 0x2735f4, Func Offset: 0x44
    
    
    SetMemoryCardCurrentDirectoryAbsolute(pCard, "/BASLUS-20184"); // Line 113, Address: 0x2735e8, Func Offset: 0x38
  
    
    strcpy(pCard->cOpenFileName,"BASLUS-20184"); // Line 116, Address: 0x273600, Func Offset: 0x50
    
  return pCard; // Line 118, Address: 0x273610, Func Offset: 0x60
} // Line 119, Address: 0x273614, Func Offset: 0x64











#define MEMORYCARD_STANDBY 0
#define MEMORYCARD_READ 1
#define MEMORYCARD_WRITE 2
#define MEMORYCARD_FORMAT 4
#define MEMORYCARD_UNFORMAT 5
#define MEMORYCARD_DELETE 7
#define MEMORYCARD_ANALYZE 17

/* 100% match */
int ExecuteMemoryCard(MEMORYCARDSTATE* pCard) { // Line 140, Address: 0x273630, Func Offset: 0
 
    if (pCard->ulError != 0) // Line 142, Address: 0x273638, Func Offset: 0x8
    {
        return -1; // Line 144, Address: 0x273644, Func Offset: 0x14
    }
    
    switch (pCard->ulState) // Line 147, Address: 0x27364c, Func Offset: 0x1c
    {
        case MEMORYCARD_STANDBY:
            return ExecuteMemoryCardStandby(pCard); // Line 150, Address: 0x2736a8, Func Offset: 0x78

        case MEMORYCARD_READ:
            ExecuteMemoryCardRead(pCard); // Line 153, Address: 0x2736b8, Func Offset: 0x88
            break; // Line 154, Address: 0x2736c0, Func Offset: 0x90
        case MEMORYCARD_WRITE:
            ExecuteMemoryCardWrite(pCard); // Line 156, Address: 0x2736c8, Func Offset: 0x98
            break; // Line 157, Address: 0x2736d0, Func Offset: 0xa0
        case MEMORYCARD_FORMAT:
            ExecuteMemoryCardFormat(pCard); // Line 159, Address: 0x2736d8, Func Offset: 0xa8
            break; // Line 160, Address: 0x2736e0, Func Offset: 0xb0
        case MEMORYCARD_UNFORMAT:
            ExecuteMemoryCardUnFormat(pCard); // Line 162, Address: 0x2736e8, Func Offset: 0xb8
            break; // Line 163, Address: 0x2736f0, Func Offset: 0xc0




            
        case MEMORYCARD_DELETE:
            ExecuteMemoryCardDelete(pCard);  // Line 170, Address: 0x2736f8, Func Offset: 0xc8
            break; // Line 171, Address: 0x273700, Func Offset: 0xd0

        case MEMORYCARD_ANALYZE:
            ExecuteAnalyzeMemoryCardAll(pCard);  // Line 174, Address: 0x273708, Func Offset: 0xd8
            break;
    }
    
    return 0x68; // Line 178, Address: 0x273710, Func Offset: 0xe0
} // Line 179, Address: 0x273714, Func Offset: 0xe4

















/* 100% match */
int ExecuteMemoryCardStandby(MEMORYCARDSTATE* pCard) { // Line 198, Address: 0x273720, Func Offset: 0
    int lCmd, lResult;

    if (pCard->cCheckMcFlag == 0)  // Line 201, Address: 0x27372c, Func Offset: 0xc
    {
        if (sceMcSync(1, &lCmd, &lResult) == -1)  // Line 203, Address: 0x273738, Func Offset: 0x18
        {
            return CheckMemoryCardChangeConnectTypeAll(pCard); // Line 205, Address: 0x273754, Func Offset: 0x34
        }
    }

    return 0; // Line 209, Address: 0x273764, Func Offset: 0x44
} // Line 210, Address: 0x273768, Func Offset: 0x48




















/* 100% match */
int AnalyzeMemoryCardAll(MEMORYCARDSTATE* pCard) {
    if (pCard->ulState != 0)  // Line 233, Address: 0x273780, Func Offset: 0
    {
        
        return 0; // Line 236, Address: 0x27378c, Func Offset: 0xc
    
    }
    
    pCard->ulState = 0x11; // Line 240, Address: 0x273794, Func Offset: 0x14
    
    pCard->ulError = 0; // Line 242, Address: 0x27379c, Func Offset: 0x1c

    
    pCard->ulMcSubState = 0; // Line 245, Address: 0x2737a4, Func Offset: 0x24

    
    return 1; // Line 248, Address: 0x2737a0, Func Offset: 0x20
} // Line 249, Address: 0x2737a8, Func Offset: 0x28












/* 100% match */
int ExecuteAnalyzeMemoryCardAll(MEMORYCARDSTATE* pCard) { // Line 263, Address: 0x2737b0, Func Offset: 0
    int lSyncResult, lCmd, lResult;    
    
    switch (pCard->usMcSysState) { // Line 266, Address: 0x2737bc, Func Offset: 0xc
    case 0:
        
        pCard->cRetryCount = 5; // Line 269, Address: 0x2737e8, Func Offset: 0x38
        pCard->usMcSysState = 1; // Line 270, Address: 0x2737f0, Func Offset: 0x40
    case 1:
        lResult = sceMcGetInfo(0, 0, &pCard->Port[0].lCrntType, &pCard->Port[0].lFreeSize, &pCard->Port[0].lFormatType); // Line 272, Address: 0x2737f8, Func Offset: 0x48
        
        
        
        if (lResult == -1) { // Line 276, Address: 0x273814, Func Offset: 0x64
            
            return 0; // Line 278, Address: 0x273824, Func Offset: 0x74

        } else if ((lResult == 0) || (pCard->cRetryCount == 0)) { // Line 280, Address: 0x27382c, Func Offset: 0x7c 
            
            pCard->usMcSysState = 2; // Line 282, Address: 0x273840, Func Offset: 0x90
        } else { // Line 283, Address: 0x273844, Func Offset: 0x94

            
            pCard->cRetryCount--; // Line 286, Address: 0x27384c, Func Offset: 0x9c
        }
        break; // Line 288, Address: 0x273850, Func Offset: 0xa0
    
    case 2:
        lSyncResult = sceMcSync(1, &lCmd, &lResult); // Line 291, Address: 0x273858, Func Offset: 0xa8

        if (lSyncResult == 1) { // Line 293, Address: 0x273868, Func Offset: 0xb8
            
            if (pCard->cRetryCount < 5) { // Line 295, Address: 0x273874, Func Offset: 0xc4
                pCard->usMcSysState = 0;


                
            } else { // Line 300, Address: 0x273884, Func Offset: 0xd4

                
                pCard->Port[0].lFreeSize -= 2; // Line 303, Address: 0x27388c, Func Offset: 0xdc
                if (pCard->Port[0].lFreeSize < 0) { // Line 304, Address: 0x273898, Func Offset: 0xe8
                
                    pCard->Port[0].lFreeSize = 0; // Line 306, Address: 0x2738a4, Func Offset: 0xf4
                }
                
                pCard->cRetryCount = 0; // Line 309, Address: 0x2738ac, Func Offset: 0xfc
                
                pCard->usMcSysState = 3; // Line 311, Address: 0x2738a8, Func Offset: 0xf8
            }
        } else { // Line 313, Address: 0x2738b0, Func Offset: 0x100
            if (lSyncResult == -1) { // Line 314, Address: 0x2738b8, Func Offset: 0x108
                
                
                pCard->ulState = 0; // Line 317, Address: 0x2738cc, Func Offset: 0x11c
                
                pCard->ulError = 9; // Line 319, Address: 0x2738c8, Func Offset: 0x118
                
                pCard->usMcSysState = 0; // Line 321, Address: 0x2738d4, Func Offset: 0x124
                pCard->cRetryCount = 0;
                
                return -1; // Line 324, Address: 0x2738c4, Func Offset: 0x114
            }
        }
        break;
    case 3:
        pCard->cRetryCount = 5; // Line 329, Address: 0x2738e0, Func Offset: 0x130
        pCard->usMcSysState = 4; // Line 330, Address: 0x2738e8, Func Offset: 0x138
    case 4:
        lResult = sceMcGetInfo(1, 0, &pCard->Port[1].lCrntType, &pCard->Port[1].lFreeSize, &pCard->Port[1].lFormatType); // Line 332, Address: 0x2738f0, Func Offset: 0x140
        
        
        
        if (lResult == -1) { // Line 336, Address: 0x27390c, Func Offset: 0x15c
        
        return 0; // Line 338, Address: 0x27391c, Func Offset: 0x16c
            
        } else if ((lResult == 0) || (pCard->cRetryCount == 0)) { // Line 340, Address: 0x273924, Func Offset: 0x174
            
            pCard->usMcSysState = 5; // Line 342, Address: 0x273938, Func Offset: 0x188
        } else { // Line 343, Address: 0x27393c, Func Offset: 0x18c
            
            
            pCard->cRetryCount--; // Line 346, Address: 0x273944, Func Offset: 0x194
        }
        break; // Line 348, Address: 0x273948, Func Offset: 0x198
    case 5:
        lSyncResult = sceMcSync(1, &lCmd, &lResult); // Line 351, Address: 0x273950, Func Offset: 0x1a0
        if (lSyncResult == 1) { // Line 353, Address: 0x273960, Func Offset: 0x1b0
            
            if (pCard->cRetryCount < 5) { // Line 355, Address: 0x27396c, Func Offset: 0x1bc
            
                



                pCard->usMcSysState = 3; // Line 359, Address: 0x27397c, Func Offset: 0x1cc
            } else { // Line 360, Address: 0x273980, Func Offset: 0x1d0
                
                
                pCard->Port[1].lFreeSize -= 2; // Line 363, Address: 0x273988, Func Offset: 0x1d8
                if (pCard->Port[1].lFreeSize < 0) { // Line 364, Address: 0x273994, Func Offset: 0x1e4
                    
                    pCard->Port[1].lFreeSize = 0; // Line 366, Address: 0x2739a0, Func Offset: 0x1f0
                }
                
                pCard->ulState = 0x12; // Line 369, Address: 0x2739a4, Func Offset: 0x1f4
                
                pCard->ulError = 0; // Line 371, Address: 0x2739ac, Func Offset: 0x1fc
                
                pCard->cRetryCount = 0; // Line 373, Address: 0x2739b0, Func Offset: 0x200
                
                pCard->usMcSysState = 0;
            }
        } else { // Line 377, Address: 0x2739b4, Func Offset: 0x204
            if (lSyncResult == -1) { // Line 378, Address: 0x2739bc, Func Offset: 0x20c

                
                pCard->ulState = 0;  // Line 381, Address: 0x2739d0, Func Offset: 0x220
                
                pCard->ulError = 9; // Line 383, Address: 0x2739cc, Func Offset: 0x21c
                
                pCard->cRetryCount = 0; // Line 385, Address: 0x2739d8, Func Offset: 0x228
                
                pCard->usMcSysState = 0;
                return -1; // Line 388, Address: 0x2739c8, Func Offset: 0x218
            }
        }
        break;
    }
    return 0; // Line 393, Address: 0x2739e4, Func Offset: 0x234
} // Line 394, Address: 0x2739e8, Func Offset: 0x238















/* 100% match */
int RecoveryMemoryCardAnalyzeAllEnd(MEMORYCARDSTATE* pCard) { // Line 411, Address: 0x273a00, Func Offset: 0

    if (pCard->ulState != 0x12) { // Line 413, Address: 0x273a08, Func Offset: 0x8
        
        if (GetMemoryCardError(pCard) == 0) {
            
            return 0; // Line 417, Address: 0x273a18, Func Offset: 0x18
            
        } else {
            
            return -1;
            
        }
    }
    
    pCard->ulState = 0; // Line 426, Address: 0x273a38, Func Offset: 0x38

    
    return 1; // Line 429, Address: 0x273a34, Func Offset: 0x34
} // Line 430, Address: 0x273a3c, Func Offset: 0x3c















/* 100% match */
void SetCheckMcFlag(MEMORYCARDSTATE* pCard, unsigned int ulFlag) {
    pCard->cCheckMcFlag = ulFlag;  

    if (ulFlag == 1) {             // Line 450, Address: 0x273a50, Func Offset: 0
        
        pCard->cMcCheckFlag = 0;   // Line 452, Address: 0x273a5c, Func Offset: 0xc
    }                              
}                                  // Line 454, Address: 0x273a60, Func Offset: 0x10


















/* 100% match */
int ExecuteMemoryCardRead(MEMORYCARDSTATE* pCard) { // Line 474, Address: 0x273a70, Func Offset: 0
    int lResult;

    switch (pCard->ulMcSubState) // Line 477, Address: 0x273a7c, Func Offset: 0xc
    {
        
        case 0:
            lResult = MemoryCardFileOpen(pCard); // Line 481, Address: 0x273aa8, Func Offset: 0x38
            
            if (lResult == -1) // Line 483, Address: 0x273ab0, Func Offset: 0x40
            {
                
                pCard->ulState = 0; // Line 486, Address: 0x273ac4, Func Offset: 0x54
                
                pCard->ulError = 3; // Line 488, Address: 0x273ac0, Func Offset: 0x50
                
                return -1; // Line 490, Address: 0x273abc, Func Offset: 0x4c
            }
            if (lResult == 1) // Line 492, Address: 0x273ad0, Func Offset: 0x60
            {
                
                pCard->ulMcSubState = 1;
            }
            break; // Line 497, Address: 0x273adc, Func Offset: 0x6c

        case 1:
            lResult = MemoryCardFileRead(pCard); // Line 500, Address: 0x273ae4, Func Offset: 0x74
            
            if (lResult == 1) // Line 502, Address: 0x273aec, Func Offset: 0x7c
            {
                
                pCard->ulMcSubState = 2; // Line 505, Address: 0x273af8, Func Offset: 0x88
            } // Line 506, Address: 0x273afc, Func Offset: 0x8c
            else if (lResult == -1) // Line 507, Address: 0x273b04, Func Offset: 0x94
            {
                
                return -1; // Line 510, Address: 0x273b10, Func Offset: 0xa0
            }
            break;

        case 2:
            lResult = MemoryCardFileClose(pCard); // Line 515, Address: 0x273b18, Func Offset: 0xa8
            
            if (lResult == -1) // Line 517, Address: 0x273b20, Func Offset: 0xb0
            {
                
                pCard->ulState = 0; // Line 520, Address: 0x273b34, Func Offset: 0xc4
                
                pCard->ulError = 8;  // Line 522, Address: 0x273b30, Func Offset: 0xc0
                
                return -1; // Line 524, Address: 0x273b2c, Func Offset: 0xbc
            }
            if (lResult == 1) // Line 526, Address: 0x273b40, Func Offset: 0xd0
            {
                
                pCard->ulState = 9; // Line 529, Address: 0x273b50, Func Offset: 0xe0
                
                pCard->ulError = 0;
                
                return 1; // Line 533, Address: 0x273b4c, Func Offset: 0xdc
            }
            break;

    }
    return 0; // Line 538, Address: 0x273b60, Func Offset: 0xf0
} // Line 539, Address: 0x273b64, Func Offset: 0xf4

















/* 100% match */
int ExecuteMemoryCardWrite(MEMORYCARDSTATE* pCard) { // Line 558, Address: 0x273b80, Func Offset: 0
    int lResult;

    switch (pCard->ulMcSubState)  // Line 561, Address: 0x273b8c, Func Offset: 0xc
    {
        
        case 0:
            lResult = MemoryCardFileOpen(pCard); // Line 565, Address: 0x273bc4, Func Offset: 0x44
            
            if (lResult == -1) // Line 567, Address: 0x273bcc, Func Offset: 0x4c
            {
                
                pCard->ulState = 0;  // Line 570, Address: 0x273be0, Func Offset: 0x60
                
                pCard->ulError = 3; // Line 572, Address: 0x273bdc, Func Offset: 0x5c
                
                pCard->cRetryCount = 5;  // Line 574, Address: 0x273be8, Func Offset: 0x68
                
                return -1; // Line 576, Address: 0x273bd8, Func Offset: 0x58
            }
            if (lResult == 1) // Line 578, Address: 0x273bf4, Func Offset: 0x74
            {
                
                pCard->ulMcSubState = 1; // Line 581, Address: 0x273c04, Func Offset: 0x84
                
                pCard->cRetryCount = 5; // Line 583, Address: 0x273c00, Func Offset: 0x80
            }
            break; // Line 585, Address: 0x273c08, Func Offset: 0x88

        case 1:
            lResult = MemoryCardFileWrite(pCard); // Line 588, Address: 0x273c10, Func Offset: 0x90
            
            if (lResult == 1) // Line 590, Address: 0x273c18, Func Offset: 0x98
            {
                
                pCard->ulMcSubState = 2; // Line 593, Address: 0x273c24, Func Offset: 0xa4
                
                pCard->cRetryCount = 5; // Line 595, Address: 0x273c2c, Func Offset: 0xac
            } // Line 596, Address: 0x273c30, Func Offset: 0xb0
            else if (lResult == -1) // Line 597, Address: 0x273c38, Func Offset: 0xb8
            {
                
                return -1; // Line 600, Address: 0x273c44, Func Offset: 0xc4
            }
            break;

        case 2:
            lResult = MemoryCardFileClose(pCard);  // Line 605, Address: 0x273c4c, Func Offset: 0xcc
            
            if (lResult == 1) // Line 607, Address: 0x273c54, Func Offset: 0xd4
            {
                pCard->ulMcSubState = 3; // Line 609, Address: 0x273c60, Func Offset: 0xe0
            }  // Line 610, Address: 0x273c64, Func Offset: 0xe4
            else if (lResult == -1) // Line 611, Address: 0x273c6c, Func Offset: 0xec
            {
                
                return -1; // Line 614, Address: 0x273c78, Func Offset: 0xf8
            }
            break;

        case 3:
            lResult = CheckMemoryCardExistFile(pCard); // Line 619, Address: 0x273c80, Func Offset: 0x100
            
            if (lResult == -1) // Line 621, Address: 0x273c88, Func Offset: 0x108
            {
                
                pCard->ulState = 0; // Line 624, Address: 0x273c9c, Func Offset: 0x11c
                
                pCard->ulError = 2; // Line 626, Address: 0x273c98, Func Offset: 0x118
                
                return -1; // Line 628, Address: 0x273c94, Func Offset: 0x114
            }
            if (lResult == 1) // Line 630, Address: 0x273ca8, Func Offset: 0x128
            {
                
                pCard->ulState = 0xA; // Line 633, Address: 0x273cb8, Func Offset: 0x138
                pCard->ulError = 0;                 
                return 1;  // Line 635, Address: 0x273cb4, Func Offset: 0x134
            }
            break;
    }

    return 0; // Line 640, Address: 0x273cc8, Func Offset: 0x148
} // Line 641, Address: 0x273ccc, Func Offset: 0x14c

















/* 100% match */
int ExecuteMemoryCardFormat(MEMORYCARDSTATE* pCard) { // Line 660, Address: 0x273ce0, Func Offset: 0
    int lResult;


    lResult = MemoryCardFormat(pCard); // Line 664, Address: 0x273cec, Func Offset: 0xc

    if (lResult == -1) { // Line 666, Address: 0x273cf4, Func Offset: 0x14

        pCard->ulState = 0; // Line 668, Address: 0x273d08, Func Offset: 0x28
        pCard->ulError = 4; // Line 669, Address: 0x273d04, Func Offset: 0x24
        pCard->cRetryCount = 5; // Line 670, Address: 0x273d10, Func Offset: 0x30
        return -1;  // Line 671, Address: 0x273d00, Func Offset: 0x20
        
    } else if (lResult == 1) { // Line 673, Address: 0x273d1c, Func Offset: 0x3c


        pCard->ulState = 0xC; // Line 676, Address: 0x273d2c, Func Offset: 0x4c
        pCard->ulError = 0; 

        
        return 1; // Line 680, Address: 0x273d28, Func Offset: 0x48
    }   

    
    return 0; // Line 684, Address: 0x273d3c, Func Offset: 0x5c
} // Line 685, Address: 0x273d40, Func Offset: 0x60


/* 94.35% match */ // @DIFF: Wrong scheduling
int ExecuteMemoryCardUnFormat(MEMORYCARDSTATE* pCard) { // Line 704, Address: 0x273d50, Func Offset: 0
    int lCmd, lResult;

    switch (pCard->ulMcSubState) // Line 707, Address: 0x273d5c, Func Offset: 0xc
    {
        
        case 0:
            lResult = MemoryCardUnFormat(); // Line 711, Address: 0x273d7c, Func Offset: 0x2c
            
            if (lResult != 0) // Line 713, Address: 0x273d88, Func Offset: 0x38
            {
                
                if (--pCard->cRetryCount != 0) // Line 716, Address: 0x273d94, Func Offset: 0x44
                {
                    return 0; // Line 718, Address: 0x273db0, Func Offset: 0x60
                }
                else
                {
                    pCard->ulState = 0; // Line 722, Address: 0x273dbc, Func Offset: 0x6c
                    pCard->ulError = 5; // Line 723, Address: 0x273dc0, Func Offset: 0x68
                    pCard->cRetryCount = 5; // Line 724, Address: 0x273dc4, Func Offset: 0x74
                    return -1; // Line 725, Address: 0x273dc8, Func Offset: 0x78
                }
            }

            
            pCard->ulMcSubState = 1; // Line 730, Address: 0x273dd0, Func Offset: 0x80
            pCard->cRetryCount = 5; // Line 731, Address: 0x273dd8, Func Offset: 0x88
            
            break; // Line 733, Address: 0x273ddc, Func Offset: 0x8c
        case 1:
            if (sceMcSync(1, &lCmd, &lResult) == 1) // Line 735, Address: 0x273de4, Func Offset: 0x94
            {
                if (lResult < 0) // Line 737, Address: 0x273e00, Func Offset: 0xb0
                {
            
                    pCard->ulState = 0; // Line 740, Address: 0x273e10, Func Offset: 0xc0
                    
                    pCard->ulError = 5; // Line 742, Address: 0x273e0c, Func Offset: 0xbc
                    return -1; // Line 743, Address: 0x273e18, Func Offset: 0xc8
                }


                
                pCard->ulState = 0xD; // Line 748, Address: 0x273e24, Func Offset: 0xd4
                pCard->ulError = 0;
                return 1; // Line 750, Address: 0x273e2c, Func Offset: 0xd0
            }
    }
    
    
    return 0; // Line 755, Address: 0x273e34, Func Offset: 0xe4
} // Line 756, Address: 0x273e38, Func Offset: 0xe8


/* 94.44% match */ // @DIFF: Wrong scheduling
int ExecuteMemoryCardDelete(MEMORYCARDSTATE* pCard) {
    int lCmd, lResult;

    switch (pCard->ulMcSubState)
    {
        
        case 0:
            lResult = DeleteMemoryCard();

            if (lResult != 0) // Line 713, Address: 0x273d88, Func Offset: 0x38
            {
                
                if (--pCard->cRetryCount != 0) // Line 716, Address: 0x273d94, Func Offset: 0x44
                {
                    return 0; // Line 718, Address: 0x273db0, Func Offset: 0x60
                }
                else
                {
                    pCard->ulState = 0;
                    pCard->ulError = 7;
                    pCard->cRetryCount = 5;
                    return -1; // Line 725, Address: 0x273dc8, Func Offset: 0x78
                }
            } 
            
            pCard->ulMcSubState = 1;
            pCard->cRetryCount = 5;
            break;
        case 1:
            if (sceMcSync(1, &lCmd, &lResult) == 1) // Line 735, Address: 0x273de4, Func Offset: 0x94
            {
                if (lResult < 0) // Line 737, Address: 0x273e00, Func Offset: 0xb0
                {
            
                    pCard->ulState = 0; // Line 740, Address: 0x273e10, Func Offset: 0xc0
                    
                    pCard->ulError = 7; // Line 742, Address: 0x273e0c, Func Offset: 0xbc
                    return -1; // Line 743, Address: 0x273e18, Func Offset: 0xc8
                }


                
                pCard->ulState = 0xF; // Line 748, Address: 0x273e24, Func Offset: 0xd4
                pCard->ulError = 0;
                return 1; // Line 750, Address: 0x273e2c, Func Offset: 0xd0
            }
    }

    
    return 0;
}

// 
// Start address: 0x273e50
int ExecuteMemoryCardDelete(MEMORYCARDSTATE* pCard)
{
    int lResult;
    int lCmd;
    // Line 775, Address: 0x273e50, Func Offset: 0
    // Line 778, Address: 0x273e5c, Func Offset: 0xc
    // Line 781, Address: 0x273e7c, Func Offset: 0x2c
    // Line 782, Address: 0x273e88, Func Offset: 0x38
    // Line 785, Address: 0x273e94, Func Offset: 0x44
    // Line 787, Address: 0x273eb0, Func Offset: 0x60
    // Line 792, Address: 0x273eb8, Func Offset: 0x68
    // Line 791, Address: 0x273ebc, Func Offset: 0x6c
    // Line 792, Address: 0x273ec0, Func Offset: 0x70
    // Line 793, Address: 0x273ec4, Func Offset: 0x74
    // Line 794, Address: 0x273ecc, Func Offset: 0x7c
    // Line 799, Address: 0x273ed4, Func Offset: 0x84
    // Line 800, Address: 0x273edc, Func Offset: 0x8c
    // Line 802, Address: 0x273ee0, Func Offset: 0x90
    // Line 805, Address: 0x273ee8, Func Offset: 0x98
    // Line 807, Address: 0x273f04, Func Offset: 0xb4
    // Line 812, Address: 0x273f10, Func Offset: 0xc0
    // Line 810, Address: 0x273f14, Func Offset: 0xc4
    // Line 812, Address: 0x273f18, Func Offset: 0xc8
    // Line 813, Address: 0x273f1c, Func Offset: 0xcc
    // Line 820, Address: 0x273f24, Func Offset: 0xd4
    // Line 818, Address: 0x273f28, Func Offset: 0xd8
    // Line 820, Address: 0x273f30, Func Offset: 0xe0
    // Line 825, Address: 0x273f38, Func Offset: 0xe8
    // Line 826, Address: 0x273f3c, Func Offset: 0xec
    // Func End, Address: 0x273f4c, Func Offset: 0xfc
}


/* 100% match */
unsigned int GetMemoryCardError(MEMORYCARDSTATE* pCard) {
    return pCard->ulError;
} // Line 861, Address: 0x273f50, Func Offset: 0

/* 100% match */
void RecoveryMemoryCardError(MEMORYCARDSTATE* pCard) {
    pCard->ulState = 0; // Line 879, Address: 0x273f60, Func Offset: 0
    pCard->ulError = 0; 
} // Line 882, Address: 0x273f64, Func Offset: 0x4

/* 100% match */
void SetMemoryCardCurrentPort(MEMORYCARDSTATE* pCard, int lPort) {
    pCard->lCurrentPort = lPort;
} // Line 917, Address: 0x273f70, Func Offset: 0

/* 100% match */
int GetMemoryCardCurrentPort(MEMORYCARDSTATE* pCard) {
    return pCard->lCurrentPort;
} // Line 935, Address: 0x273f80, Func Offset: 0



/* 100% match */
void SetMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort, unsigned int ulResult) {
    pCard->Port[ulPort].lCrntType = ulResult; // Line 1020, Address: 0x273f90, Func Offset: 0
} // Line 1021, Address: 0x273f98, Func Offset: 0x8


/* 100% match */
void SaveMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort) {
    pCard->Port[ulPort].lPrevType = pCard->Port[ulPort].lCrntType; // Line 1040, Address: 0x273fa0, Func Offset: 0
} // Line 1041, Address: 0x273fac, Func Offset: 0xc


/* 100% match */
int CompMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort) {
    if (pCard->Port[ulPort].lPrevType == pCard->Port[ulPort].lCrntType) {
        return 0; // Line 1063, Address: 0x273fc0, Func Offset: 0
    } else {
        return 1;
    }
} // Line 1067, Address: 0x273fe0, Func Offset: 0x20


/* 100% match */
int GetMemoryCardSelectPortState(MEMORYCARDSTATE* pCard, unsigned int ulPort) {
    return pCard->Port[ulPort].lCrntType; // Line 1089, Address: 0x273ff0, Func Offset: 0
} // Line 1090, Address: 0x273ff8, Func Offset: 0x8


/* 100% match */
int GetMemoryCardFileNumber(MEMORYCARDSTATE* pCard) {
    return pCard->lSelectFileNumber;
} // Line 1131, Address: 0x274000, Func Offset: 0


/* 100% match */
void SetMemoryCardFileNumber(MEMORYCARDSTATE* pCard, int lFileNumber) {
    pCard->lSelectFileNumber = lFileNumber;
} // Line 1150, Address: 0x274010, Func Offset: 0


/* 100% match */
int SetMemoryCardCurrentDirectoryAbsolute(MEMORYCARDSTATE *pCard, char *cpPath) {
    char *src = cpPath;
    char *dest = pCard->cCurrentDir;
    
    while (*src) // Line 1172, Address: 0x274020, Func Offset: 0
    {     
        *dest++ = *src++; // Line 1174, Address: 0x274028, Func Offset: 0x8
    } // Line 1175, Address: 0x274034, Func Offset: 0x14
    *dest = '\0'; // Line 1176, Address: 0x274048, Func Offset: 0x28
    
    return 0;
} // Line 1179, Address: 0x27404c, Func Offset: 0x2c


/* 100% match */
int ReadMemoryCard(MEMORYCARDSTATE *pCard, void *pvReadFile, unsigned int ulFileSize, char *cpFileName, int lMode) { // Line 1231, Address: 0x274060, Func Offset: 0

    if (pCard->ulState != 0) // Line 1233, Address: 0x27407c, Func Offset: 0x1c
    {
        
        return 0;                // Line 1236, Address: 0x274098, Func Offset: 0x38
    
    }

    strcpy(pCard->cCurrentDir, "/BASLUS-20184"); // Line 1240, Address: 0x2740a0, Func Offset: 0x40
    strcat(pCard->cCurrentDir, "BASLUS-20184"); // Line 1241, Address: 0x2740b0, Func Offset: 0x50
        
    strcat(pCard->cCurrentDir, cpFileName); // Line 1243, Address: 0x2740c0, Func Offset: 0x60
        
    strcpy(pCard->cOpenFileName, cpFileName); // Line 1245, Address: 0x2740cc, Func Offset: 0x6c
        
    pCard->lOpenMode = lMode; // Line 1247, Address: 0x2740d8, Func Offset: 0x78
        
    pCard->ulFileSize = ulFileSize; // Line 1249, Address: 0x2740dc, Func Offset: 0x7c
        
    pCard->vpAddr = pvReadFile; // Line 1251, Address: 0x2740e4, Func Offset: 0x84
        
    pCard->ulState = 1; // Line 1253, Address: 0x2740e0, Func Offset: 0x80
        
    pCard->ulMcSubState = 0; // Line 1255, Address: 0x2740ec, Func Offset: 0x8c
        
    pCard->usMcSysState = 0; // Line 1257, Address: 0x2740f4, Func Offset: 0x94
        
    pCard->cRetryCount = 5; // Line 1259, Address: 0x2740f0, Func Offset: 0x90
        
    return 1; 
} // Line 1262, Address: 0x2740fc, Func Offset: 0x9c


/* 100% match */
int RecoveryMemoryCardReadEnd(MEMORYCARDSTATE* pCard) { // Line 1279, Address: 0x274120, Func Offset: 0
    if (pCard->ulState != 9) { // Line 1280, Address: 0x274128, Func Offset: 0x8
        
        if ( GetMemoryCardError(pCard) == 0) {
            
            return 0; // Line 1284, Address: 0x274138, Func Offset: 0x18
            
        } else {
      
            return -1;
      
        }     
    }
    
    pCard->ulState = 0; // Line 1293, Address: 0x274158, Func Offset: 0x38

    
    return 1; // Line 1296, Address: 0x274154, Func Offset: 0x34
} // Line 1297, Address: 0x27415c, Func Offset: 0x3c


/* 100% match */
int WriteMemoryCard(MEMORYCARDSTATE* pCard, void* pvReadFile, unsigned int ulFileSize, char* cpFileName, int lMode) { // Line 1321, Address: 0x274170, Func Offset: 0
    
    if (pCard->ulState != 0) { // Line 1323, Address: 0x27418c, Func Offset: 0x1c
        
        return 0; // Line 1325, Address: 0x2741a8, Func Offset: 0x38
    
    } 

    strcpy(pCard->cCurrentDir, "/BASLUS-20184"); // Line 1329, Address: 0x2741b0, Func Offset: 0x40
    strcat(pCard->cCurrentDir, "BASLUS-20184"); // Line 1330, Address: 0x2741c0, Func Offset: 0x50
    strcat(pCard->cCurrentDir, cpFileName); // Line 1331, Address: 0x2741d0, Func Offset: 0x60
    
    strcpy(pCard->cOpenFileName, cpFileName); // Line 1333, Address: 0x2741dc, Func Offset: 0x6c
    
    pCard->lOpenMode = lMode; // Line 1335, Address: 0x2741e8, Func Offset: 0x78
    
    pCard->ulFileSize = ulFileSize; // Line 1337, Address: 0x2741ec, Func Offset: 0x7c
    
    pCard->vpAddr = pvReadFile; // Line 1339, Address: 0x2741f4, Func Offset: 0x84
    
    pCard->ulState = 2; // Line 1341, Address: 0x2741f0, Func Offset: 0x80
    
    pCard->ulMcSubState = 0; // Line 1343, Address: 0x2741fc, Func Offset: 0x8c
    
    pCard->usMcSysState = 0; // Line 1345, Address: 0x274204, Func Offset: 0x9
    
    pCard->cRetryCount = 5;  // Line 1347, Address: 0x274208, Func Offset: 0x98
    
    return 1; // Line 1349, Address: 0x27420c, Func Offset: 0x9c
} // Line 1350, Address: 0x274210, Func Offset: 0xa0


// 
// Start address: 0x274230
int RecoveryMemoryCardWriteEnd(MEMORYCARDSTATE* pCard)
{
    // Line 1366, Address: 0x274230, Func Offset: 0
    // Line 1368, Address: 0x274238, Func Offset: 0x8
    // Line 1374, Address: 0x274248, Func Offset: 0x18
    // Line 1388, Address: 0x274264, Func Offset: 0x34
    // Line 1385, Address: 0x274268, Func Offset: 0x38
    // Line 1389, Address: 0x27426c, Func Offset: 0x3c
    // Func End, Address: 0x274278, Func Offset: 0x48
}

// 
// Start address: 0x274280
int FormatMemoryCard(MEMORYCARDSTATE* pCard)
{
    // Line 1407, Address: 0x274280, Func Offset: 0
    // Line 1410, Address: 0x27428c, Func Offset: 0xc
    // Line 1414, Address: 0x274294, Func Offset: 0x14
    // Line 1418, Address: 0x27429c, Func Offset: 0x1c
    // Line 1416, Address: 0x2742a0, Func Offset: 0x20
    // Line 1419, Address: 0x2742a4, Func Offset: 0x24
    // Func End, Address: 0x2742ac, Func Offset: 0x2c
}

// 
// Start address: 0x2742b0
int RecoveryMemoryCardFormatEnd(MEMORYCARDSTATE* pCard)
{
    // Line 1435, Address: 0x2742b0, Func Offset: 0
    // Line 1437, Address: 0x2742b8, Func Offset: 0x8
    // Line 1441, Address: 0x2742c8, Func Offset: 0x18
    // Line 1453, Address: 0x2742e4, Func Offset: 0x34
    // Line 1450, Address: 0x2742e8, Func Offset: 0x38
    // Line 1454, Address: 0x2742ec, Func Offset: 0x3c
    // Func End, Address: 0x2742f8, Func Offset: 0x48
}

// 
// Start address: 0x274300
int GetMcSelectPortType(MEMORYCARDSTATE* pCard, unsigned int ulPort)
{
    int lResult;
    // Line 1644, Address: 0x274300, Func Offset: 0
    // Line 1648, Address: 0x274314, Func Offset: 0x14
    // Line 1651, Address: 0x274324, Func Offset: 0x24
    // Line 1654, Address: 0x27432c, Func Offset: 0x2c
    // Line 1657, Address: 0x274338, Func Offset: 0x38
    // Line 1660, Address: 0x274340, Func Offset: 0x40
    // Line 1662, Address: 0x274350, Func Offset: 0x50
    // Line 1664, Address: 0x274358, Func Offset: 0x58
    // Line 1667, Address: 0x274360, Func Offset: 0x60
    // Line 1669, Address: 0x274370, Func Offset: 0x70
    // Line 1674, Address: 0x274378, Func Offset: 0x78
    // Line 1676, Address: 0x27437c, Func Offset: 0x7c
    // Func End, Address: 0x274394, Func Offset: 0x94
}

// 
// Start address: 0x2743a0
int CheckMemoryCardChangeConnectTypeAll(MEMORYCARDSTATE* pCard)
{
    int lPort1Result;
    int lPort0Result;
    // Line 1750, Address: 0x2743a0, Func Offset: 0
    // Line 1754, Address: 0x2743b4, Func Offset: 0x14
    // Line 1756, Address: 0x2743c0, Func Offset: 0x20
    // Line 1759, Address: 0x2743c8, Func Offset: 0x28
    // Line 1763, Address: 0x2743d4, Func Offset: 0x34
    // Line 1765, Address: 0x2743dc, Func Offset: 0x3c
    // Line 1767, Address: 0x2743e4, Func Offset: 0x44
    // Line 1769, Address: 0x2743f4, Func Offset: 0x54
    // Line 1771, Address: 0x2743fc, Func Offset: 0x5c
    // Line 1776, Address: 0x274404, Func Offset: 0x64
    // Line 1778, Address: 0x274410, Func Offset: 0x70
    // Line 1779, Address: 0x27441c, Func Offset: 0x7c
    // Line 1781, Address: 0x27442c, Func Offset: 0x8c
    // Line 1786, Address: 0x27443c, Func Offset: 0x9c
    // Line 1788, Address: 0x274468, Func Offset: 0xc8
    // Line 1791, Address: 0x274470, Func Offset: 0xd0
    // Line 1793, Address: 0x274484, Func Offset: 0xe4
    // Line 1796, Address: 0x274490, Func Offset: 0xf0
    // Line 1798, Address: 0x2744b4, Func Offset: 0x114
    // Line 1803, Address: 0x2744c0, Func Offset: 0x120
    // Line 1807, Address: 0x2744c4, Func Offset: 0x124
    // Func End, Address: 0x2744dc, Func Offset: 0x13c
}

// 
// Start address: 0x2744e0
int SetMemoryCardFreeCapacity(MEMORYCARDSTATE* pCard, int Free)
{
    // Line 1826, Address: 0x2744e0, Func Offset: 0
    // Line 1829, Address: 0x2744f0, Func Offset: 0x10
    // Line 1830, Address: 0x2744fc, Func Offset: 0x1c
    // Func End, Address: 0x274504, Func Offset: 0x24
}

// 
// Start address: 0x274510
int GetMemoryCardFreeCapacity(MEMORYCARDSTATE* pCard)
{
    int lResult;
    // Line 1848, Address: 0x274510, Func Offset: 0
    // Line 1852, Address: 0x27451c, Func Offset: 0xc
    // Line 1855, Address: 0x274528, Func Offset: 0x18
    // Line 1858, Address: 0x274530, Func Offset: 0x20
    // Line 1861, Address: 0x274538, Func Offset: 0x28
    // Line 1863, Address: 0x274540, Func Offset: 0x30
    // Line 1868, Address: 0x274554, Func Offset: 0x44
    // Line 1875, Address: 0x27456c, Func Offset: 0x5c
    // Func End, Address: 0x27457c, Func Offset: 0x6c
}

/* 100% match */
int GetMemoryCardSelectPortFreeCapacity(MEMORYCARDSTATE* pCard, unsigned int ulPort) {
    return pCard->Port[ulPort].lFreeSize; // Line 1893, Address: 0x274580, Func Offset: 0
} // Line 1894, Address: 0x274588, Func Offset: 0x8


/* 100% match */
int CheckMemoryCardFormatStatus(MEMORYCARDSTATE* pCard) { // Line 1912, Address: 0x274590, Func Offset: 0
    int lResult;

    if (pCard->ulState != 0)  // Line 1915, Address: 0x274598, Func Offset: 0x8
    {
        
        return 0; // Line 1918, Address: 0x2745a4, Func Offset: 0x14
    
    }
    
    lResult = CheckMemoryCardInfoUnformat(pCard); // Line 1922, Address: 0x2745ac, Func Offset: 0x1c
    
    if (lResult == 0)  // Line 1924, Address: 0x2745b4, Func Offset: 0x24
    {
        return 1; // Line 1926, Address: 0x2745bc, Func Offset: 0x2c
    }
    
    else if (lResult == 1)   
    { 
        return 2; // Line 1931, Address: 0x2745c4, Func Offset: 0x34
    }
    
    else 
    {
        return -1;
    }
    
} // Line 1939, Address: 0x2745dc, Func Offset: 0x4c

/* 100% match */
int CreateMemoryCardSubDirectory(MEMORYCARDSTATE* pCard) { // Line 1956, Address: 0x2745f0, Func Offset: 0

    
    if (pCard->ulState != 0) { // Line 1959, Address: 0x2745fc, Func Offset: 0xc
    
        
        return 0; // Line 1962, Address: 0x274608, Func Offset: 0x18
    }
    
    if (MakeMemoryCardDir(pCard) == 0) { // Line 1965, Address: 0x274610, Func Offset: 0x20
    
        return -1; // Line 1967, Address: 0x274620, Func Offset: 0x30
    }
    
    
    pCard->cRetryCount = 5; // Line 1971, Address: 0x274628, Func Offset: 0x38
    return 1; // Line 1972, Address: 0x274630, Func Offset: 0x40



} // Line 1976, Address: 0x274634, Func Offset: 0x44

/* 100% match */
int CheckMemoryCardExistSubDirectory(MEMORYCARDSTATE* pCard) { // Line 2106, Address: 0x274650, Func Offset: 0
    
    if (pCard->ulState != 0)  // Line 2108, Address: 0x27465c, Func Offset: 0xc
    {    
        
        return 0; // Line 2111, Address: 0x274668, Func Offset: 0x18
    
    }
    
    strcpy(pCard->cCurrentDir, "/BASLUS-20184"); // Line 2115, Address: 0x274670, Func Offset: 0x20
    
    return ChangeMemoryCardDir(pCard, pCard->cCurrentDir, NULL); // Line 2117, Address: 0x274680, Func Offset: 0x30
} // Line 2118, Address: 0x274690, Func Offset: 0x40

/* 100% match */
int CheckMemoryCardExistFile(MEMORYCARDSTATE* pCard) { // Line 2136, Address: 0x2746a0, Func Offset: 0
    static sceMcTblGetDir CardInfo; 

    
    if (GetMemoryCardDir(pCard, pCard->cCurrentDir, 0, 1, &CardInfo) < 0) // Line 2140, Address: 0x2746b0, Func Offset: 0x10
    { 
        
        return -1; // Line 2143, Address: 0x2746d0, Func Offset: 0x30
    
    }

    
    if (strcmp(&CardInfo.EntryName, pCard->cOpenFileName) == 0)  // Line 2148, Address: 0x2746d8, Func Offset: 0x38
    {
        if ((CardInfo.AttrFile & 0x80) != 0) 
        {
            return 1; // Line 2152, Address: 0x2746f0, Func Offset: 0x50
        }
        else 
        {
            return -1;
        }
        
    
    }
    
    return -1; // Line 2162, Address: 0x27470c, Func Offset: 0x6c



} // Line 2166, Address: 0x274710, Func Offset: 0x70


/* 100% match */
int CheckMemoryCardExistFileList(MEMORYCARDSTATE* pCard, char** cppPathList, unsigned int FileCount) { 	// Line 2188, Address: 0x274720, Func Offset: 0
    char cEntryName[32];
    unsigned short usCheckFileNameCounter;
    unsigned short usCheckCounter;
    int lResult;
    static sceMcTblGetDir CardInfo[21];

    if (pCard->ulState != 0) { // Line 2195, Address: 0x274748, Func Offset: 0x28
        return 0; // Line 2198, Address: 0x27475c, Func Offset: 0x3c
    }

    strcpy(cEntryName, "/BASLUS-20184"); // Line 2202, Address: 0x274764, Func Offset: 0x44
    strcat(cEntryName, "/*"); // Line 2203, Address: 0x274774, Func Offset: 0x54

    lResult = GetMemoryCardDir(pCard, cEntryName, 0, FileCount + 2, &CardInfo[0]);

    if (lResult != (FileCount + 2)) { // Line 2209, Address: 0x2747a0, Func Offset: 0x80
        return -1; // Line 2213, Address: 0x2747ac, Func Offset: 0x8c
    }

    // Skip the first two entries (i.e., '.' and '..')
    for (usCheckCounter = 2; usCheckCounter < (FileCount + 2); usCheckCounter++) { // Line 2218, Address: 0x2747bc, Func Offset: 0x9c
        for (usCheckFileNameCounter = 0; usCheckFileNameCounter < FileCount; usCheckFileNameCounter++) { // Line 2221, Address: 0x2747c8, Func Offset: 0xa8
            if (strcmp(&CardInfo[usCheckCounter].EntryName, cppPathList[usCheckFileNameCounter]) == 0) { // Line 2223, Address: 0x2747d4, Func Offset: 0xb4
                break;
            }
            
            if (usCheckFileNameCounter >= 0x11) { // Line 2227, Address: 0x2747e8, Func Offset: 0xc8
                return -1; // Line 2230, Address: 0x2747f4, Func Offset: 0xd4
            }
        } // Line 2232, Address: 0x2747fc, Func Offset: 0xdc
    } // Line 2233, Address: 0x274818, Func Offset: 0xf8

    return 1; // Line 2236, Address: 0x27483c, Func Offset: 0x11c
} // Line 2237, Address: 0x274840, Func Offset: 0x120

// 
// Start address: 0x274870
int MemoryCardGetSum(unsigned char* ucpTop, unsigned int ulSize)
{
    unsigned int ulSum;
    // Line 2258, Address: 0x274870, Func Offset: 0
    // Line 2260, Address: 0x274878, Func Offset: 0x8
    // Line 2261, Address: 0x27487c, Func Offset: 0xc
    // Line 2260, Address: 0x274880, Func Offset: 0x10
    // Line 2261, Address: 0x274888, Func Offset: 0x18
    // Line 2265, Address: 0x274898, Func Offset: 0x28
    // Func End, Address: 0x2748a0, Func Offset: 0x30
}

// 
// Start address: 0x2748a0
int GetMemoryCardSelectPortFormatType(MEMORYCARDSTATE* pCard, unsigned int ulPort)
{
    // Line 2285, Address: 0x2748a0, Func Offset: 0
    // Line 2286, Address: 0x2748a8, Func Offset: 0x8
    // Func End, Address: 0x2748b0, Func Offset: 0x10
}

// 
// Start address: 0x2748b0
int CheckMcSelectPortInfoType(unsigned int ulPort)
{
    int lPortResult;
    int lRetry;
    int lResult;
    int lCmd;
    // Line 2395, Address: 0x2748b0, Func Offset: 0
    // Line 2398, Address: 0x2748c0, Func Offset: 0x10
    // Line 2401, Address: 0x2748c8, Func Offset: 0x18
    // Line 2403, Address: 0x2748e8, Func Offset: 0x38
    // Line 2405, Address: 0x274904, Func Offset: 0x54
    // Line 2409, Address: 0x27490c, Func Offset: 0x5c
    // Line 2411, Address: 0x274910, Func Offset: 0x60
    // Line 2414, Address: 0x274918, Func Offset: 0x68
    // Line 2415, Address: 0x27491c, Func Offset: 0x6c
    // Line 2416, Address: 0x274920, Func Offset: 0x70
    // Line 2418, Address: 0x274928, Func Offset: 0x78
    // Line 2419, Address: 0x27492c, Func Offset: 0x7c
    // Func End, Address: 0x274940, Func Offset: 0x90
}

// 
// Start address: 0x274940
int CheckMemoryCardInfoFree(MEMORYCARDSTATE* pCard)
{
    int lResultFreeCapacity;
    int lResult;
    int lRetry;
    int lCmd;
    // Line 2439, Address: 0x274940, Func Offset: 0
    // Line 2442, Address: 0x274950, Func Offset: 0x10
    // Line 2445, Address: 0x274958, Func Offset: 0x18
    // Line 2447, Address: 0x274978, Func Offset: 0x38
    // Line 2450, Address: 0x274994, Func Offset: 0x54
    // Line 2457, Address: 0x2749a4, Func Offset: 0x64
    // Line 2470, Address: 0x2749c0, Func Offset: 0x80
    // Line 2475, Address: 0x2749cc, Func Offset: 0x8c
    // Line 2477, Address: 0x2749d0, Func Offset: 0x90
    // Line 2480, Address: 0x2749d8, Func Offset: 0x98
    // Line 2481, Address: 0x2749dc, Func Offset: 0x9c
    // Line 2482, Address: 0x2749e0, Func Offset: 0xa0
    // Line 2484, Address: 0x2749e8, Func Offset: 0xa8
    // Line 2485, Address: 0x2749ec, Func Offset: 0xac
    // Func End, Address: 0x274a00, Func Offset: 0xc0
}

// 
// Start address: 0x274a00
int CheckMcSelectPortInfoState(unsigned int ulPort)
{
    int lPortResult;
    int lRetry;
    int lResult;
    int lCmd;
    // Line 2501, Address: 0x274a00, Func Offset: 0
    // Line 2504, Address: 0x274a10, Func Offset: 0x10
    // Line 2507, Address: 0x274a18, Func Offset: 0x18
    // Line 2509, Address: 0x274a38, Func Offset: 0x38
    // Line 2513, Address: 0x274a54, Func Offset: 0x54
    // Line 2522, Address: 0x274a78, Func Offset: 0x78
    // Line 2524, Address: 0x274a7c, Func Offset: 0x7c
    // Line 2527, Address: 0x274a84, Func Offset: 0x84
    // Line 2529, Address: 0x274a88, Func Offset: 0x88
    // Line 2531, Address: 0x274a90, Func Offset: 0x90
    // Line 2532, Address: 0x274a94, Func Offset: 0x94
    // Func End, Address: 0x274aa8, Func Offset: 0xa8
}

// 
// Start address: 0x274ab0
int CheckMemoryCardInfoUnformat(MEMORYCARDSTATE* pCard)
{
    int lPortFormt;
    int lResult;
    int lRetry;
    int lCmd;
    // Line 2549, Address: 0x274ab0, Func Offset: 0
    // Line 2552, Address: 0x274ac0, Func Offset: 0x10
    // Line 2555, Address: 0x274ac8, Func Offset: 0x18
    // Line 2557, Address: 0x274ae8, Func Offset: 0x38
    // Line 2559, Address: 0x274b04, Func Offset: 0x54
    // Line 2564, Address: 0x274b30, Func Offset: 0x80
    // Line 2567, Address: 0x274b38, Func Offset: 0x88
    // Line 2573, Address: 0x274b40, Func Offset: 0x90
    // Line 2575, Address: 0x274b44, Func Offset: 0x94
    // Line 2578, Address: 0x274b4c, Func Offset: 0x9c
    // Line 2580, Address: 0x274b50, Func Offset: 0xa0
    // Line 2582, Address: 0x274b58, Func Offset: 0xa8
    // Line 2583, Address: 0x274b5c, Func Offset: 0xac
    // Func End, Address: 0x274b70, Func Offset: 0xc0
}

// 
// Start address: 0x274b70
int GetMemoryCardDir(MEMORYCARDSTATE* pCard, char* cpPath, int lFlag, int lMaxent, sceMcTblGetDir* pbuff)
{
    int lResult;
    int lRetry;
    int lCmd;
    // Line 2608, Address: 0x274b70, Func Offset: 0
    // Line 2611, Address: 0x274b90, Func Offset: 0x20
    // Line 2614, Address: 0x274ba8, Func Offset: 0x38
    // Line 2616, Address: 0x274bcc, Func Offset: 0x5c
    // Line 2620, Address: 0x274be8, Func Offset: 0x78
    // Line 2630, Address: 0x274c08, Func Offset: 0x98
    // Line 2632, Address: 0x274c0c, Func Offset: 0x9c
    // Line 2635, Address: 0x274c14, Func Offset: 0xa4
    // Line 2637, Address: 0x274c18, Func Offset: 0xa8
    // Line 2639, Address: 0x274c20, Func Offset: 0xb0
    // Line 2640, Address: 0x274c24, Func Offset: 0xb4
    // Func End, Address: 0x274c48, Func Offset: 0xd8
}

// 
// Start address: 0x274c50
int ChangeMemoryCardDir(MEMORYCARDSTATE* pCard, char* cpPath, char* cpbuff)
{
    int lRetry;
    int lResult;
    int lCmd;
    // Line 2661, Address: 0x274c50, Func Offset: 0
    // Line 2664, Address: 0x274c68, Func Offset: 0x18
    // Line 2667, Address: 0x274c78, Func Offset: 0x28
    // Line 2669, Address: 0x274c94, Func Offset: 0x44
    // Line 2673, Address: 0x274cb0, Func Offset: 0x60
    // Line 2682, Address: 0x274cc4, Func Offset: 0x74
    // Line 2684, Address: 0x274cc8, Func Offset: 0x78
    // Line 2687, Address: 0x274cd0, Func Offset: 0x80
    // Line 2688, Address: 0x274cd4, Func Offset: 0x84
    // Line 2689, Address: 0x274cd8, Func Offset: 0x88
    // Line 2691, Address: 0x274ce0, Func Offset: 0x90
    // Line 2692, Address: 0x274ce4, Func Offset: 0x94
    // Func End, Address: 0x274d00, Func Offset: 0xb0
}

// 
// Start address: 0x274d00
int MakeMemoryCardDir(MEMORYCARDSTATE* pCard)
{
    int lRetry;
    int lResult;
    int lCmd;
    // Line 2708, Address: 0x274d00, Func Offset: 0
    // Line 2711, Address: 0x274d10, Func Offset: 0x10
    // Line 2714, Address: 0x274d18, Func Offset: 0x18
    // Line 2716, Address: 0x274d30, Func Offset: 0x30
    // Line 2720, Address: 0x274d4c, Func Offset: 0x4c
    // Line 2729, Address: 0x274d5c, Func Offset: 0x5c
    // Line 2731, Address: 0x274d60, Func Offset: 0x60
    // Line 2734, Address: 0x274d68, Func Offset: 0x68
    // Line 2735, Address: 0x274d6c, Func Offset: 0x6c
    // Line 2736, Address: 0x274d70, Func Offset: 0x70
    // Line 2738, Address: 0x274d78, Func Offset: 0x78
    // Line 2739, Address: 0x274d7c, Func Offset: 0x7c
    // Func End, Address: 0x274d90, Func Offset: 0x90
}

// 
// Start address: 0x274d90
int MemoryCardFormat(MEMORYCARDSTATE* pCard)
{
    int lSyncResult;
    int lResult;
    int lCmd;
    // Line 2755, Address: 0x274d90, Func Offset: 0
    // Line 2758, Address: 0x274d9c, Func Offset: 0xc
    // Line 2761, Address: 0x274dc0, Func Offset: 0x30
    // Line 2763, Address: 0x274dd0, Func Offset: 0x40
    // Line 2768, Address: 0x274ddc, Func Offset: 0x4c
    // Line 2775, Address: 0x274e00, Func Offset: 0x70
    // Line 2777, Address: 0x274e08, Func Offset: 0x78
    // Line 2779, Address: 0x274e0c, Func Offset: 0x7c
    // Line 2782, Address: 0x274e14, Func Offset: 0x84
    // Line 2784, Address: 0x274e20, Func Offset: 0x90
    // Line 2786, Address: 0x274e2c, Func Offset: 0x9c
    // Line 2790, Address: 0x274e38, Func Offset: 0xa8
    // Line 2795, Address: 0x274e44, Func Offset: 0xb4
    // Line 2797, Address: 0x274e48, Func Offset: 0xb8
    // Line 2800, Address: 0x274e50, Func Offset: 0xc0
    // Line 2803, Address: 0x274e5c, Func Offset: 0xcc
    // Line 2804, Address: 0x274e60, Func Offset: 0xd0
    // Line 2809, Address: 0x274e68, Func Offset: 0xd8
    // Line 2810, Address: 0x274e6c, Func Offset: 0xdc
    // Func End, Address: 0x274e7c, Func Offset: 0xec
}

// 
// Start address: 0x274e80
int MemoryCardUnFormat()
{
    // Line 2859, Address: 0x274e80, Func Offset: 0
    // Func End, Address: 0x274e88, Func Offset: 0x8
}

// 
// Start address: 0x274e90
int DeleteMemoryCard()
{
    // Line 2899, Address: 0x274e90, Func Offset: 0
    // Func End, Address: 0x274e98, Func Offset: 0x8
}

// 
// Start address: 0x274ea0
int MemoryCardFileOpen(MEMORYCARDSTATE* pCard)
{
    int lSyncResult;
    int lResult;
    int lCmd;
    // Line 2918, Address: 0x274ea0, Func Offset: 0
    // Line 2921, Address: 0x274eac, Func Offset: 0xc
    // Line 2926, Address: 0x274ed0, Func Offset: 0x30
    // Line 2927, Address: 0x274ee8, Func Offset: 0x48
    // Line 2932, Address: 0x274ef4, Func Offset: 0x54
    // Line 2939, Address: 0x274f18, Func Offset: 0x78
    // Line 2941, Address: 0x274f20, Func Offset: 0x80
    // Line 2943, Address: 0x274f24, Func Offset: 0x84
    // Line 2946, Address: 0x274f2c, Func Offset: 0x8c
    // Line 2947, Address: 0x274f38, Func Offset: 0x98
    // Line 2949, Address: 0x274f44, Func Offset: 0xa4
    // Line 2953, Address: 0x274f50, Func Offset: 0xb0
    // Line 2958, Address: 0x274f5c, Func Offset: 0xbc
    // Line 2960, Address: 0x274f60, Func Offset: 0xc0
    // Line 2965, Address: 0x274f68, Func Offset: 0xc8
    // Line 2967, Address: 0x274f74, Func Offset: 0xd4
    // Line 2969, Address: 0x274f78, Func Offset: 0xd8
    // Line 2973, Address: 0x274f80, Func Offset: 0xe0
    // Line 2974, Address: 0x274f84, Func Offset: 0xe4
    // Func End, Address: 0x274f94, Func Offset: 0xf4
}

// 
// Start address: 0x274fa0
int MemoryCardFileClose(MEMORYCARDSTATE* pCard)
{
    int lSyncResult;
    int lResult;
    int lCmd;
    // Line 2991, Address: 0x274fa0, Func Offset: 0
    // Line 2994, Address: 0x274fac, Func Offset: 0xc
    // Line 2998, Address: 0x274fd0, Func Offset: 0x30
    // Line 3000, Address: 0x274fdc, Func Offset: 0x3c
    // Line 3003, Address: 0x274fe8, Func Offset: 0x48
    // Line 3005, Address: 0x275004, Func Offset: 0x64
    // Line 3012, Address: 0x27500c, Func Offset: 0x6c
    // Line 3010, Address: 0x275010, Func Offset: 0x70
    // Line 3012, Address: 0x275014, Func Offset: 0x74
    // Line 3014, Address: 0x275018, Func Offset: 0x78
    // Line 3015, Address: 0x275020, Func Offset: 0x80
    // Line 3018, Address: 0x275028, Func Offset: 0x88
    // Line 3021, Address: 0x275030, Func Offset: 0x90
    // Line 3025, Address: 0x275038, Func Offset: 0x98
    // Line 3027, Address: 0x275040, Func Offset: 0xa0
    // Line 3029, Address: 0x275044, Func Offset: 0xa4
    // Line 3032, Address: 0x27504c, Func Offset: 0xac
    // Line 3033, Address: 0x275058, Func Offset: 0xb8
    // Line 3035, Address: 0x275064, Func Offset: 0xc4
    // Line 3040, Address: 0x275070, Func Offset: 0xd0
    // Line 3038, Address: 0x275074, Func Offset: 0xd4
    // Line 3040, Address: 0x275078, Func Offset: 0xd8
    // Line 3044, Address: 0x27507c, Func Offset: 0xdc
    // Line 3049, Address: 0x275088, Func Offset: 0xe8
    // Line 3051, Address: 0x27508c, Func Offset: 0xec
    // Line 3054, Address: 0x275094, Func Offset: 0xf4
    // Line 3063, Address: 0x2750a0, Func Offset: 0x100
    // Line 3059, Address: 0x2750a4, Func Offset: 0x104
    // Line 3057, Address: 0x2750a8, Func Offset: 0x108
    // Line 3059, Address: 0x2750ac, Func Offset: 0x10c
    // Line 3063, Address: 0x2750b0, Func Offset: 0x110
    // Line 3067, Address: 0x2750b8, Func Offset: 0x118
    // Line 3068, Address: 0x2750bc, Func Offset: 0x11c
    // Func End, Address: 0x2750cc, Func Offset: 0x12c
}

// 
// Start address: 0x2750d0
int MemoryCardFileRead(MEMORYCARDSTATE* pCard)
{
    int lSyncResult;
    int lResult;
    int lCmd;
    // Line 3087, Address: 0x2750d0, Func Offset: 0
    // Line 3090, Address: 0x2750dc, Func Offset: 0xc
    // Line 3093, Address: 0x275100, Func Offset: 0x30
    // Line 3095, Address: 0x275114, Func Offset: 0x44
    // Line 3098, Address: 0x275120, Func Offset: 0x50
    // Line 3100, Address: 0x27513c, Func Offset: 0x6c
    // Line 3107, Address: 0x275144, Func Offset: 0x74
    // Line 3105, Address: 0x275148, Func Offset: 0x78
    // Line 3107, Address: 0x27514c, Func Offset: 0x7c
    // Line 3109, Address: 0x275150, Func Offset: 0x80
    // Line 3110, Address: 0x275158, Func Offset: 0x88
    // Line 3113, Address: 0x275160, Func Offset: 0x90
    // Line 3116, Address: 0x275168, Func Offset: 0x98
    // Line 3120, Address: 0x275170, Func Offset: 0xa0
    // Line 3121, Address: 0x275178, Func Offset: 0xa8
    // Line 3123, Address: 0x27517c, Func Offset: 0xac
    // Line 3126, Address: 0x275184, Func Offset: 0xb4
    // Line 3127, Address: 0x275190, Func Offset: 0xc0
    // Line 3129, Address: 0x27519c, Func Offset: 0xcc
    // Line 3132, Address: 0x2751a8, Func Offset: 0xd8
    // Line 3134, Address: 0x2751ac, Func Offset: 0xdc
    // Line 3138, Address: 0x2751b0, Func Offset: 0xe0
    // Line 3143, Address: 0x2751bc, Func Offset: 0xec
    // Line 3145, Address: 0x2751c0, Func Offset: 0xf0
    // Line 3148, Address: 0x2751c8, Func Offset: 0xf8
    // Line 3151, Address: 0x2751d4, Func Offset: 0x104
    // Line 3153, Address: 0x2751d8, Func Offset: 0x108
    // Line 3155, Address: 0x2751dc, Func Offset: 0x10c
    // Line 3157, Address: 0x2751e0, Func Offset: 0x110
    // Line 3162, Address: 0x2751e8, Func Offset: 0x118
    // Line 3163, Address: 0x2751ec, Func Offset: 0x11c
    // Func End, Address: 0x2751fc, Func Offset: 0x12c
}

// 
// Start address: 0x275200
int MemoryCardFileWrite(MEMORYCARDSTATE* pCard)
{
    int lSyncResult;
    int lResult;
    int lCmd;
    // Line 3180, Address: 0x275200, Func Offset: 0
    // Line 3183, Address: 0x27520c, Func Offset: 0xc
    // Line 3186, Address: 0x275230, Func Offset: 0x30
    // Line 3188, Address: 0x275244, Func Offset: 0x44
    // Line 3191, Address: 0x275250, Func Offset: 0x50
    // Line 3193, Address: 0x27526c, Func Offset: 0x6c
    // Line 3200, Address: 0x275274, Func Offset: 0x74
    // Line 3198, Address: 0x275278, Func Offset: 0x78
    // Line 3200, Address: 0x27527c, Func Offset: 0x7c
    // Line 3202, Address: 0x275280, Func Offset: 0x80
    // Line 3203, Address: 0x275288, Func Offset: 0x88
    // Line 3206, Address: 0x275290, Func Offset: 0x90
    // Line 3209, Address: 0x275298, Func Offset: 0x98
    // Line 3213, Address: 0x2752a0, Func Offset: 0xa0
    // Line 3215, Address: 0x2752a8, Func Offset: 0xa8
    // Line 3217, Address: 0x2752ac, Func Offset: 0xac
    // Line 3220, Address: 0x2752b4, Func Offset: 0xb4
    // Line 3222, Address: 0x2752c0, Func Offset: 0xc0
    // Line 3224, Address: 0x2752cc, Func Offset: 0xcc
    // Line 3229, Address: 0x2752d8, Func Offset: 0xd8
    // Line 3227, Address: 0x2752dc, Func Offset: 0xdc
    // Line 3229, Address: 0x2752e0, Func Offset: 0xe0
    // Line 3233, Address: 0x2752e4, Func Offset: 0xe4
    // Line 3238, Address: 0x2752f0, Func Offset: 0xf0
    // Line 3240, Address: 0x2752f4, Func Offset: 0xf4
    // Line 3243, Address: 0x2752fc, Func Offset: 0xfc
    // Line 3252, Address: 0x275308, Func Offset: 0x108
    // Line 3248, Address: 0x27530c, Func Offset: 0x10c
    // Line 3246, Address: 0x275310, Func Offset: 0x110
    // Line 3248, Address: 0x275314, Func Offset: 0x114
    // Line 3252, Address: 0x275318, Func Offset: 0x118
    // Line 3257, Address: 0x275320, Func Offset: 0x120
    // Line 3258, Address: 0x275324, Func Offset: 0x124
    // Func End, Address: 0x275334, Func Offset: 0x134
}

