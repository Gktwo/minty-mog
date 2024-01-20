#include "il2cpp-types.h"
#include "il2cpp-enum.h"


using namespace app;


//globalupdate
//UnityEngine.EventSystems.EventSystem$$Update
DO_APP_FUNC(0x01851940, void, Global_Update, (app::UnityEngine_EventSystems_EventSystem_o* __this, app::MethodInfo* method));

//BattleLogic.BattleMatch
DO_APP_FUNC(0x03195700, void, BattleLogic_BattleMatch__Update, (app::BattleLogic_BattleMatch_o* __this));
DO_APP_FUNC(0x03194cf0, float, BattleLogic_BattleMatch__get_TimeScale, (app::BattleLogic_BattleMatch_o* __this));
//DO_APP_FUNC(0x03198010, void, BattleLogic_BattleMatch__SetTimeScale, (app::BattleLogic_BattleMatch_o* __this, float a));
DO_APP_FUNC(0x03194c50, bool, BattleLogic_BattleMatch__get_IsPause, (app::BattleLogic_BattleMatch_o* __this));
DO_APP_FUNC(0x03197ef0, void, BattleLogic_BattleMatch__Pause,(app::BattleLogic_BattleMatch_o* __this));
DO_APP_FUNC(0x03197fb0, void, BattleLogic_BattleMatch__Resume,(app::BattleLogic_BattleMatch_o* __this));



DO_APP_FUNC(0x00adb940, app::Network_MatchId_o, BattleLogic_BattleMatch__get_MatchId, (app::BattleLogic_BattleMatch_o* __this));
DO_APP_FUNC(0x03196e50, void*, BattleLogic_BattleMatch__WipeEnemies, (app::BattleLogic_BattleMatch_o* __this));




//demage hack


//skillshack
//DO_APP_FUNC(0x02ff39c0, bool, BattleLogic_Skills_SkillAffectable__IsNotBlocked, (app::Network_Utility_SkillUsingStatus_o* a));
//DO_APP_FUNC(0x00b3f270, void, CaravanWa_Shared_MasterTable_SkillPowerMaster__set_Power, (app::Network_Utility_SkillUsingStatus_o* a));
DO_APP_FUNC(0x00d07bf0, app::String*, CaravanWa_Shared_MasterTable_SkillPowerMaster__GetPowerDisplayString, (app::CaravanWa_Shared_MasterTable_SkillPowerMaster_o* __this));
//DO_APP_FUNC(0x028078c0, bool, BattleObjectModel__CanUseSpecialSkill, (app::BattleObjectModel_o* __this));
DO_APP_FUNC(0x03194f80, bool, BattleLogic_BattleMatch__get_CanUseSpecialSkillAnytime, (app::BattleLogic_BattleMatch_o* __this));




//BattleLogic
DO_APP_FUNC(0x03192400, void, BattleLogic_BattleLogic__Update, (app::BattleLogic_BattleLogic_o* __this));
DO_APP_FUNC(0x03191ca0, void, BattleLogic_BattleLogic__set_DebugUnlockRankSkills, (bool a));
DO_APP_FUNC(0x019dba20, void, BattleLogic_BattleLogic__set_IgnoreDamage, (app::BattleLogic_BattleLogic_o* __this, bool a));




//godmode
DO_APP_FUNC(0x030580a0, void, BattleLogic_Skills_SkillPerformer__RecordMiss, (app::BattleLogic_Skills_SkillPerformer_o* __this, app::Network_SkillActionType_o a, app::BattleLogic_Models_BattleObject_o* b, app::BattleLogic_Models_BattleObject_o* c, bool d));
DO_APP_FUNC(0x03057270, void, BattleLogic_Skills_SkillPerformer__RecordDamage, (app::BattleLogic_Skills_SkillPerformer_o* __this, float a, app::Network_SkillActionType_o b, bool c, app::BattleLogic_Skills_SkillPerformer_CalculatedParameters_o d, app::BattleLogic_Models_BattleObject_o* e, app::BattleLogic_Models_BattleObject_o* f, app::Network_Utility_SkillUsingStatus_o* g, bool h, float i));


//BattleObject analyzer

DO_APP_FUNC(0x0319aa90, bool, BattleLogic_Models_BattleObject__get_IsBoss,(app::BattleLogic_Models_BattleObject_o* __this));
DO_APP_FUNC(0x0319a9c0, app::BattleTeams__Enum, BattleLogic_Models_BattleObject__get_Team,(app::BattleLogic_Models_BattleObject_o* __this));
//Alpha,//Bravo
DO_APP_FUNC(0x0319bd00, void*, BattleLogic_Models_BattleObject__Die, (app::BattleLogic_Models_BattleObject_o* __this, bool a));










//UnityEngine.UI.Text$$
//DO_APP_FUNC(0x022dba90, void, Text_set_text, (app::Text* __this, app::String* value));
////UnityEngine.UI.Text$$set_text
//DO_APP_FUNC(0x022dbdf0, void, Text_set_alignment, (app::Text* __this, app::TextAnchor__Enum value));
//DO_APP_FUNC(0x022dbf50, void, Text_set_horizontalOverflow, (app::Text* __this, app::HorizontalWrapMode__Enum value));
//DO_APP_FUNC(0x022dbfd0, void, Text_set_verticalOverflow, (app::Text* __this, app::VerticalWrapMode__Enum value));
//DO_APP_FUNC(0x022dbc70, void, Text_set_resizeTextForBestFit, (app::Text* __this, bool value));
//DO_APP_FUNC(0x022dbed0, void, Text_set_fontSize, (app::Text* __this, int32_t value));
////UnityEngine.UI.Slider
//DO_APP_FUNC(0x02066700, void, Slider_1_set_minValue, (app::Slider_1* __this, float value));
//DO_APP_FUNC(0x02066780, void, Slider_1_set_maxValue, (app::Slider_1* __this, float value));
//DO_APP_FUNC(0x020668b0, void, Slider_1_set_value, (app::Slider_1* __this, float value));

//DO_APP_FUNC(0x07E0AC70, float, MoleMole_SafeFloat_get_Value, (app::SafeFloat safeFloat));
//DO_APP_FUNC(0x07E0AC50, app::SafeFloat, MoleMole_SafeFloat_set_Value, (float value));

//System.Runtime.InteropServices.Marshal$$PtrToStringAnsi
DO_APP_FUNC(0x01dec080, app::String*, Marshal_PtrToStringAnsi, (void* ptr));


//UnityEngine.UI.ScrollRect$$GetBounds
//DO_APP_FUNC(0x0205eab0, app::Bounds, GetBounds, (app::GameObject* target));

// Game Object, Transform, Object, Component Utility

//public sealed class GameObject :
//UnityEngine.GameObject$$CreatePrimitive
DO_APP_FUNC(0x03beafb0,app::GameObject*, GameObject_CreatePrimitive, (app::PrimitiveType__Enum type));
//UnityEngine.GameObject$$get_active
DO_APP_FUNC(0x03bebc30,bool, GameObject_get_active, (app::GameObject* __this));
//UnityEngine.GameObject$$SetActive
DO_APP_FUNC(0x03bebce0,void, GameObject_SetActive, (app::GameObject* __this, bool value));
//UnityEngine.GameObject$$Find
DO_APP_FUNC(0x03bec5b0,app::GameObject*, GameObject_Find, (app::String* name));

//DO_APP_FUNC(0x03B9C710,app::Component*, GameObject_GetComponentByName, (app::GameObject* __this, app::String* className));
////internal Component GetComponentByName(string type) { }
//DO_APP_FUNC(0x03B9D0B0 ,app::Component*, GameObject_AddComponentInternal, (app::GameObject* __this, app::String* className));
////internal Component AddComponentInternal(string className) { }
//DO_APP_FUNC(0x03B9D170,app::Transform*, GameObject_get_transform, (app::GameObject* __this));
////public Transform get_transform() { }
//DO_APP_FUNC(0x047ab0f0, app::Transform*, Transform_GetChild, (app::Transform* __this, int32_t index));
////UnityEngine.Transform$$GetChild
//DO_APP_FUNC(0x047ab150,int32_t, Transform_GetChildCount, (app::Transform* __this));
////UnityEngine.Transform$$FindChild
//DO_APP_FUNC(0x047aad40,app::Transform*, Transform_FindChild, (app::Transform* __this, app::String* name));
//
//DO_APP_FUNC(0x047a7d60,void, Transform_set_localPosition, (app::Transform* __this, app::Vector3 value));
//DO_APP_FUNC(0x047a89b0,void, Transform_set_localRotation, (app::Transform* __this, app::Quaternion value));
//DO_APP_FUNC(0x047a8ac0, app::Vector3, Transform_get_localScale, (app::Transform* __this));
//DO_APP_FUNC(0x047a8b30,void, Transform_set_localScale, (app::Transform* __this, app::Vector3 value));
//DO_APP_FUNC(0x047a8270,app::Vector3, Transform_get_right, (app::Transform* __this));
//DO_APP_FUNC(0x047a8470,app::Vector3, Transform_get_up, (app::Transform* __this));
//DO_APP_FUNC(0x047a8670,app::Vector3, Transform_get_forward, (app::Transform* __this));
//DO_APP_FUNC(0x047a7c20,app::Vector3, Transform_get_position, (app::Transform* __this));
//DO_APP_FUNC(0x047a7c90,void, Transform_set_position, (app::Transform* __this, app::Vector3 value));
//DO_APP_FUNC(0x047a8870,app::Quaternion, Transform_get_rotation, (app::Transform* __this));
//DO_APP_FUNC(0x047a88e0,void, Transform_set_rotation, (app::Transform* __this, app::Quaternion value));
//DO_APP_FUNC(0x047a8b90,app::Transform*, Transform_get_parent, (app::Transform* __this));
//DO_APP_FUNC(0x047a8be0,void, Transform_set_parent, (app::Transform* __this, app::Transform* value));
//DO_APP_FUNC(0x047a9120,void, Transform_Translate, (app::Transform* __this, app::Vector3 translation));
////UnityEngine.Object$$get_name
//DO_APP_FUNC(0x01dbae70,app::String*, Object_get_name, (app::Object* __this));
////UnityEngine.Object$$DestroyImmediate
//DO_APP_FUNC(0x01dbbd10, void, Object_DestroyImmediate_1, (app::Object* obj));
////UnityEngine.Component$$get_gameObject
//DO_APP_FUNC(0x0204f4d0,app::GameObject*, Component_get_gameObject, (app::Component* __this));


// UnityEngine
//DO_APP_FUNC(0x03ACC530, void, RenderSettings_set_fog, (bool value));
//public static void set_fog(bool value) { }

//public class Time
DO_APP_FUNC(0x011e3990, float, Time_get_deltaTime, ());
//public static float get_deltaTime() { }
DO_APP_FUNC(0x023c40b0, float, Time_get_timeScale, ());
//public static float get_timeScale() { }
DO_APP_FUNC(0x0478cfc0, void*, Time_set_timeScale, (float time));


DO_APP_FUNC(0x03bcfcf0, bool*, Application_get_isFocused, ());
//public static bool get_isFocused() { }
DO_APP_FUNC(0x03bd01f0, void*, Application_set_targetFrameRate, (int32_t value));
//	public static void set_targetFrameRate(int value) { }
DO_APP_FUNC(0x03adc140, void*, QualitySettings_set_vSyncCount, (int32_t value));//帧率限制倍数（垂直同步）
//	public static void set_vSyncCount(int value) { }

//DO_APP_FUNC(0x047B21B0, float, Vector3_Distance, (app::Vector3 pos1, app::Vector3 pos2));
////public static float Distance(Vector3 a, Vector3 b) { }
//DO_APP_FUNC(0x047B0F50, app::Vector3, Vector3_Lerp, (app::Vector3 start, app::Vector3 end, float time));
////	public static Vector3 Lerp(Vector3 a, Vector3 b, float t) { }

//public class Cursor
DO_APP_FUNC(0x03be7dd0, void, Cursor_set_visible, (bool value));
//public static void set_visible(bool value) { }
DO_APP_FUNC(0x03be7e20, void, Cursor_get_lockState, ());
//public static CursorLockMode get_lockState() { }
DO_APP_FUNC(0x03be7e70, void, Cursor_set_lockState, (app::CursorLockMode__Enum value));
//public static void set_lockState(CursorLockMode value) { }

//public sealed class Screen
DO_APP_FUNC(0x03aed440, int32_t, Screen_get_width, (app::MethodInfo* method));
//	 public static int get_width() { }
DO_APP_FUNC(0x03aed490, int32_t, Screen_get_height, (app::MethodInfo* method));
//public static int get_height() { }
DO_APP_FUNC(0x03aed7f0, void, Screen_SetResolution, (int width, int height, bool fullscreen));








// Protection bypass
//DO_APP_FUNC(0x0529E520, 0x052818B0, app::Byte__Array*, MoleMole_SecurityModule_RecordUserData, (int32_t nType, app::MethodInfo* method));


