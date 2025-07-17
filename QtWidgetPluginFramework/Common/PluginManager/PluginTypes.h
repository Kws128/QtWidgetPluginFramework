/**
 * @file    PluginTypes.h
 * @brief   Defines function pointer types for plugin factory and release functions.
 *
 * @author  https://github.com/Kws128
 * @date    2025-07-17
 * @version 1.0
 *
 * @copyright MIT License
 */

#pragma once
#include "IPlugin.h"
#include "PluginContext.h"

 /**
  *  @typedef CreatePlugin
  *  @brief   Function pointer type for plugin creation.
  */
using fnCreate  = IPlugin* (*)(PluginContext*);

/**
 *  @typedef DestroyPlugin
 *  @brief   Function pointer type for plugin destroy.
 */
using fnDestroy = void (*)(IPlugin*);