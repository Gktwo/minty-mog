#pragma once


// Namespace: UnityEngine
enum class CursorLockMode__Enum : int32_t {
    None = 0x00000000,
    Locked = 0x00000001,
    Confined = 0x00000002,
};

enum class PrimitiveType__Enum : int32_t {
    Sphere = 0x00000000,
    Capsule = 0x00000001,
    Cylinder = 0x00000002,
    Cube = 0x00000003,
    Plane = 0x00000004,
    Quad = 0x00000005,
};
//// Namespace: Sdw.Dungeon.Map.Domain
enum class PlayerStateId__Enum : int32_t {
    Idle = 0x00000000, //闲置
    Move = 0x00000001,
};

//Namespace: CaravanWa.Shared.MasterTable
enum class BossType__Enum : int32_t {
    None = 0x00000000,
    Boss = 0x00000001,
    GuildBoss = 0x00000002, //帮会老大
};

enum class EnemyType__Enum : int32_t {
    Normal = 0x00000000,
    Boss = 0x00000001,
    ImmortalBoss = 0x00000002, //精英怪
};

enum class Role__Enum : int32_t {
    None = 0x00000000,
    Tank = 0x00000001,
    Attacker = 0x00000002,
    Healer = 0x00000003,
};

// Namespace: Sdw.Enhancement 增效
enum class AbilityType__Enum : int32_t {
    DamageLimit = 0x00000000,
    OverHeal = 0x00000001,

};

// Namespace: Sdw.SkillViewer
enum class ActorType__Enum : int32_t {
    None = 0x00000000,
    Playable = 0x00000001,
    EnemyOnly = 0x00000002,
};

enum class CutsceneType__Enum : int32_t {
    None = 0x00000000,
    Skill = 0x00000001,
    SpSkillEnd = 0x00000002,
    Exit= 0x00000003,
    Appearance= 0x00000004, 
    Winning= 0x00000005, 
    SummonAppear= 0x00000006,
};
//CaravanWa.Shared.MasterTable
enum class SkillTargetTeam__Enum : int32_t {
    None ,
    Enemy ,
    Ally ,

};

enum class SkillTargetGroup__Enum : int32_t {
    None,
    Enemy,
    Ally,
    AllyExceptSelf,
    All,

};
enum class QuestPassiveSkillUserTeam__Enum : int32_t {   //任务被动技能用户团队
    None = 0x00000000,
    Enemy = 0x00000001,
    Ally = 0x00000002,

};
enum class SkillTargetRangeType__Enum : int32_t {
   
    Single = 0x00000001,
    All = 0x00000002,
    Range = 0x00000003,
    RangeIgnoreCenterRadius = 0x00000004,
    FrontRange = 0x00000005,
    FrontRangeIgnoreCenterRadius = 0x00000006,
    BehindRange = 0x00000007,
    BehindRangeIgnoreCenterRadius = 0x00000008,
    Random = 0x00000009

};

enum class SkillType__Enum : int32_t {

    PhysicalDamage = 100,
    MagicDamage,
    MaxHealthRateDamage,
    CurrentHealthRateDamage,
    TrueDamage,
    ParameterPhysicalAttack,
    SelfBuffCountDamage = 110,
    SelfDebuffCountDamage,
    SelfAbnormalConditionCountDamage,
    EnemyBuffCountDamage = 115,
    EnemyDebuffCountDamage,
    EnemyAbnormalConditionCountDamage,
    Buff = 200,
    Debuff,
    UpdateNormalCharaBitFlag = 250,
    Heal = 300,
    RecoverSpecialPoint,
    ReduceSpecialPoint,
    AbnormalCondition = 400,
    Summon = 500,
    RemoveBuffTime = 600,
    RemoveBuffCount,
    RemoveDeBuffTime = 610,
    RemoveDeBuffCount,
    RemoveAbnormalTime = 620,
    RemoveAbnormalCount,
    Invincible = 700,
    InterruptBehavior = 800,

};

enum class ElementType__Enum : int32_t {

    None,
    Fire,
    Water,
    Wind,
    Earth,
    Light,
    Dark,
    All,

};
