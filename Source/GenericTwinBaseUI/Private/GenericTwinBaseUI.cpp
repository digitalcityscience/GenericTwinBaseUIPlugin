// Copyright Epic Games, Inc. All Rights Reserved.

#include "GenericTwinBaseUI.h"
#include "Actionbar/GenericTwinActionbarLayer.h"
#include "Toolbar/GenericTwinToolbarLayer.h"
#include "Layers/LayerRepository.h"

#define LOCTEXT_NAMESPACE "FGenericTwinBaseUIModule"

void FGenericTwinBaseUIModule::StartupModule()
{
	LayerRepository::GetInstance().RegisterLayer(UGenericTwinActionbarLayer::GetLayerMetaData(), &UGenericTwinActionbarLayer::Create);
	LayerRepository::GetInstance().RegisterLayer(UGenericTwinToolbarLayer::GetLayerMetaData(), &UGenericTwinToolbarLayer::Create);
}

void FGenericTwinBaseUIModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGenericTwinBaseUIModule, GenericTwinBaseUI)