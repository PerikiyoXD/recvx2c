#pragma once

#include <cri_mw.h>
#include <cri_aixp.h>

void InitMwSystem(Uint32 Mode, MWS_PLY_INIT_SFD* pPrm);
void ReinitMwSystem(MWS_PLY_INIT_SFD* pPrm);
void ExitMwSystem();
void SetMwSoundMode(Uint32 Mode);
void GetMwPlayTime(int* ncount, int* tscale);
int GetMwPlayTimeEx();
void CreateSfdHandle(Sint8 * mp, MWS_PLY_CPRM_SFD *pp, Sint8 *fname);
void CreateWaveHandle(Sint32 unk);
void CreateTmHandle();
void PlayMwOpenMain(Sint8 *FileName,Sint32 Mode,Sint8 *mp,MWS_PLY_CPRM_SFD *pp,Sint32 PauseFlag);
void PlayMw2(Sint8* FileName, Sint32 Mode, Sint8* mp, MWS_PLY_CPRM_SFD* pp, Sint32 PauseFlag);
void StopMw();
MWE_PLY_STAT GetMwStatus();
int PlayMwMain2(void(*Func)());
int PlayMwMain();
void PauseMw();
void RestartMw();
void SetMwVolume(int Volume);
int GetSfdFadeRate();
void SetSfdDislpaySize(Float32 PosX, Float32 PosY, Float32 SizeX, Float32 SizeY);