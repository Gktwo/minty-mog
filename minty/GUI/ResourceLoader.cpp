
#include "ResourceLoader.h"


std::string ResourceLoader::Load(const char* name, const char* type)
{
	LOG_INFO("Starting Load with name: %s, type: %s", name, type);

	LPBYTE pData = nullptr;
	DWORD size = 0;
	if (!LoadEx(name, type, pData, size))
	{
		LOG_ERROR("Failed to load resource %s", name);
		return {};
	}

	LOG_INFO("Loaded resource successfully with name: %s, type: %s", name, type);
	return std::string(reinterpret_cast<char*>(pData), size);
}

std::string ResourceLoader::Load(int resID, const char* type)
{
	return ResourceLoader::Load(MAKEINTRESOURCE(resID), type);
}

bool ResourceLoader::LoadEx(const char* name, const char* type, LPBYTE& pDest, DWORD& size)
{
  LOG_INFO("Starting LoadEx with name: %s, type: %s", name, type);

  HRSRC hResource = FindResource(s_Handle, name, type);
  if (hResource) {
    LOG_INFO("Resource found: %s", name);
    HGLOBAL hGlob = LoadResource(s_Handle, hResource);
    if (hGlob) {
      LOG_INFO("Resource loaded: %s", name);
      size = SizeofResource(s_Handle, hResource);
      pDest = static_cast<LPBYTE>(LockResource(hGlob));
      if (size > 0 && pDest) {
        LOG_INFO("Resource locked and ready to use: %s", name);
        return true;
      }
    }
  }
  LOG_ERROR("Failed to load or lock resource: %s", name);
  return false;
}


bool ResourceLoader::LoadEx(int resId, const char* type, LPBYTE& pDest, DWORD& size)
{
	return ResourceLoader::LoadEx(MAKEINTRESOURCE(resId), type, pDest, size);
}

void ResourceLoader::SetModuleHandle(HMODULE handle)
{
  s_Handle = handle;
  LOG_INFO("Module handle set");
}

