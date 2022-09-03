//
// Created by eli on 8/24/2022.
//

#ifndef BRANEENGINE_ASSETCACHE_H
#define BRANEENGINE_ASSETCACHE_H

#include "json/value.h"
#include <string>
#include <filesystem>

class Asset;
class AssetID;
class BraneProject;
class AssetCache
{
	BraneProject* _project = nullptr;
	std::filesystem::path getPath(const AssetID& id);
public:
	void setProject(BraneProject* project);
	void cacheAsset(const Asset* asset);
	bool hasAsset(const AssetID& asset);
	Asset* getAsset(const AssetID& asset);
	void deleteCachedAsset(const AssetID& asset);

};

#endif //BRANEENGINE_ASSETCACHE_H