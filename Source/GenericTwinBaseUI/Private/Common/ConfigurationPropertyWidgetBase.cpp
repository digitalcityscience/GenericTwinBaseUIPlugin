// Fill out your copyright notice in the Description page of Project Settings.


#include "Common/ConfigurationPropertyWidgetBase.h"

bool UConfigurationPropertyWidgetBase::SetProperty_Implementation(ULayerConfigurationPropertyBase *Property)
{
    return false;
}

int32 UConfigurationPropertyWidgetBase::Revert_Implementation()
{
    return 0;
}

int32 UConfigurationPropertyWidgetBase::ReportValue_Implementation()
{
    return 0;
}

