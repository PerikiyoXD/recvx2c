#pragma once

#include <cri_mw.h>
#include <cri_aixp.h>

int mwPlyCalcWorkSofdec();
MWPLY* ps2mwPlyCreateSofdec(char* fname);
void mwPlyExecServer();
void mwPlyFinishSofdec();
int mwPlyGetBright();
void mwPlyInitSofdec();
void mwPlyPreInitSofdec();
void mwPlySetDispMode();
void mwPlySetDispPos(float lx, float ly);
void mwPlySetFastHalfpel();
void mwPlyStartFrame();
void mwPlySetDispSize(float sx, float sy);
void ps2mwPlyVsyncHndl();
void ps2mwPlyExecSvrHndl();
void ps2mwPlyDestroy();
void ps2mwPlyStartFname(char* fname);
void ps2mwPlyStop();
MWE_PLY_STAT ps2mwPlyGetStat();
void ps2mwPlyGetTime(int* ncount, int* tscale);
void ps2mwPlyPause(int sw);
void ps2mwPlySetOutVol(int vol);
int ps2mwPlyGetOutVol();
void ps2mwErrorStop();
void Setps2FuncTbl(MWPLY* mwply);