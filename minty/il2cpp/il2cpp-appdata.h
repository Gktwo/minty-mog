﻿#pragma once

#include <cstdint>

#include "../includes.h"
#include "../api/imgui/ImGuiNotify/imgui_notify.h"

#define DO_API(a, r, n, p) extern r(*n) p
	#include "il2cpp-api-functions.h"
#undef DO_API

//#include "il2cpp-types.h"
#define DO_APP_FUNC(a, r, n, p) extern r(*n) p
#define DO_TYPEDEF(a, n) extern n ## __Class** n ## __TypeInfo
#define DO_APP_FUNC_METHODINFO(a, n) extern struct MethodInfo ** n
namespace app {
	#include "il2cpp-functions.h"
}
#undef DO_APP_FUNC
#undef DO_TYPEDEF
#undef DO_APP_FUNC_METHODINFO

#define DO_UP_FUNC(a, r, n, p) extern r(*n) p
namespace app {
	#include "il2cpp-unityplayer-functions.h"
}
#undef DO_UP_FUNC

#define DO_TYPEDEF(a, n) extern n ## __Class** n ## __TypeInfo
namespace app {
	#include "il2cpp-types-ptr.h"
}
#undef DO_TYPEDEF
