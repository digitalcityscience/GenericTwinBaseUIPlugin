// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ConfigurationPropertyWidgetBase.generated.h"

class UGenericTwinConfigurationWidget;

/**
 * 
 */
UCLASS()
class GENERICTWINBASEUI_API UConfigurationPropertyWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintNativeEvent, Category=Default)
	bool SetProperty(ULayerConfigurationPropertyBase *Property);

	UFUNCTION(BlueprintNativeEvent, Category=Default)
	int32 Revert();

	UFUNCTION(BlueprintNativeEvent, Category=Default)
	int32 ReportValue();

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, Category=Default)
	UGenericTwinConfigurationWidget *ConfigurationWidget = 0;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, Category=Default)
	int32 ItemId = 0;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, Category=Default)
	FString	DisplayName;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, Category=Default)
	bool	IsRealtime;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category=Default)
	bool	HasChanged;


protected:

};
