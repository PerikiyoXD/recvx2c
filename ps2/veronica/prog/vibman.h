#pragma once

#ifndef _VIBMAN_H_
#define _VIBMAN_H_

#include "types.h"

void InitVibrationUnit();
void ExitVibrationUnit();
void SetUseVibrationUnit(Sint32 Flag);
Sint32 GetUseVibrationUnit();
Sint32 CheckVibrationUnit(Uint32 PortId);
Sint32 StartVibration(Uint32 PortId, PDS_VIBPARAM* vpp);
Sint32 StopVibration(Uint32 PortId);

#endif // _VIBMAN_H_