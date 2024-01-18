#include "Translations.h"
#include <optional>
#include <charconv>

std::string result;
static bool ifParse;
int LangTR = 2;

std::string LoadResourceString(int resourceId, LPCSTR resourceType) {
  HMODULE handle = GetModuleHandle("minty-MOG.dll");
  HRSRC resource = FindResource(handle, MAKEINTRESOURCE(resourceId), resourceType);
  if (!resource) {
    LOG_ERROR("Resource not found.");
    return "";
  }

  HGLOBAL loadedResource = LoadResource(handle, resource);
  if (!loadedResource) {
    LOG_ERROR("Failed to load resource.");
    return "";
  }

  DWORD size = SizeofResource(handle, resource);
  LPCSTR data = static_cast<LPCSTR>(LockResource(loadedResource));

  if (size == 0 || !data) {
    LOG_ERROR("Resource data is invalid.");
    return "";
  }

  return std::string(data, size);
}

std::optional<std::string> safeGet(nlohmann::json& json, const std::string& key, const std::string& lang) {
  if (json.contains(lang) && json[lang].is_object() && json[lang].contains(key)) {
    return json[lang][key].get<std::string>();
  }
  return key; // 如果没有找到，返回原本
}
std::u8string u8result;
const char* _(const char* code) {
  static nlohmann::json trJson; // 将 trJson 设置为 static 以避免重复解析

  if (result.empty()) {
    result = LoadResourceString(R_LANGUAGES, RT_RCDATA);
    LOG_DEBUG("loading languages...");
    if (result.empty()) {
      return code; // 如果资源加载失败，返回原始代码
    }
    try {
      trJson = nlohmann::json::parse(result);
    }
    catch (nlohmann::json::parse_error& e) {
      LOG_ERROR("JSON parsing error: %s", e.what());
      return code; // 如果解析出错，返回原始代码
    }
    LOG_DEBUG("parse languages...");
  }
  //return code;
  std::string retStr = code; // 设置默认返回字符串
  std::optional<std::string> ret;

  switch (LangTR) {
  case 0:
    ret = safeGet(trJson, code, "EN");
    break;
  case 1:
    ret = safeGet(trJson, code, "RU");
    break;
  case 2:
    ret = safeGet(trJson, code, "CN");
    break;
  case 3:
    ret = safeGet(trJson, code, "ID");
    break;
  default:
    ret = safeGet(trJson, code, "EN");
    break;
  }

  if (ret.has_value()) {
    retStr = ret.value();
  }

  u8result = std::u8string(retStr.begin(), retStr.end());
  return reinterpret_cast<const char*>(u8result.c_str());

}
