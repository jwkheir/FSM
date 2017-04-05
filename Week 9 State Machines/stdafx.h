// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

class Bulb;

typedef  void (Bulb::*CBP)();
typedef  bool (Bulb::*GP)();


enum TStates { On, Off, Broken };
// TODO: reference additional headers your program requires here
