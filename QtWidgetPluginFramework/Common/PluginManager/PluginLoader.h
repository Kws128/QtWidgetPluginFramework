/**
 * @file    PluginLoader.h
 * @brief   Declares the PluginLoader class for loading dynamic libraries and retrieving symbols.
 *
 * @author  https://github.com/Kws128
 * @date    2025-07-17
 * @version 1.0
 *
 * @copyright MIT License
 */

#pragma once

#include <Windows.h>
#include <string>

/**
*  @class PluginLoader
*  @brief RAII wrapper for loading and unloading dynamic libraries (DLLs) and resolving symbols.
*/
class PluginLoader
{
public:
	PluginLoader();
	explicit PluginLoader(const std::string& path);
	virtual ~PluginLoader();

	PluginLoader(const PluginLoader& other) = delete;
	PluginLoader& operator=(const PluginLoader& other) = delete;

	PluginLoader(PluginLoader&& other) noexcept;
	PluginLoader& operator=(PluginLoader&& other) noexcept;

	/// @brief  Loads the library from the specified path.
	/// @param  path Path to the dynamic library.
	/// @return true if loaded successfully; false otherwise.
	bool  Load(const std::string& path);


	/// @brief  Checks if a library is currently loaded.
	/// @return true if a library is loaded; false otherwise.
	bool  IsLoad() { return m_hModule != nullptr; }

	/// @brief Unloads the currently loaded library, if any.
	void  UnLoad();

	/// @brief  Retrieves a symbol (function or variable) from the loaded library.
	/// @param  name Name of the symbol to retrieve.
	/// @return Pointer to the symbol, or nullptr if not found.
	void* GetSymbol(const std::string& name);
	
protected:
	HMODULE m_hModule;
};

