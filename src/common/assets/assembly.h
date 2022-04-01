//
// Created by eli on 2/2/2022.
//

#ifndef BRANEENGINE_ASSEMBLY_H
#define BRANEENGINE_ASSEMBLY_H

#include "asset.h"
#include "ecs/core/component.h"
#include <json/json.h>

class EntityManager;

struct WorldEntity
{
	std::vector<VirtualComponent> components;
	std::vector<const ComponentAsset*> componentDefs();
	void serialize(OSerializedData& message);
	void deserialize(ISerializedData& message, AssetManager& am);
};

class Assembly : public Asset
{
public:
	Assembly();
	std::vector<AssetID> scripts; // Any systems in dependencies will be automatically loaded
	std::vector<AssetID> meshes; // We need to store these in a list, so we can tell witch asset entities are referring to
	std::vector<AssetID> textures;
	std::vector<WorldEntity> entities;
	void serialize(OSerializedData& message) override;
	void deserialize(ISerializedData& message, AssetManager& am) override;
	Json::Value toJson(AssetManager& am) const;
	static Assembly* fromJson(Json::Value& json, AssetManager& am);


	void  inject(EntityManager& em, EntityID rootID);
};


#endif //BRANEENGINE_ASSEMBLY_H