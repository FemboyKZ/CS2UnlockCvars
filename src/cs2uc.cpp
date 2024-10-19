/**
 * =============================================================================
 * CS2UC
 * Copyright (C) 2023-2024 Source2ZE
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cs2uc.h"

#include "common.h"
#include "icvar.h"

#include "tier0/memdbgon.h"

void Message(const char *msg, ...)
{
	va_list args;
	va_start(args, msg);

	char buf[1024] = {};
	V_vsnprintf(buf, sizeof(buf) - 1, msg, args);

	ConColorMsg(Color(255, 0, 255, 255), "[UnlockCvars] %s", buf);

	va_end(args);
}

void Panic(const char *msg, ...)
{
	va_list args;
	va_start(args, msg);

	char buf[1024] = {};
	V_vsnprintf(buf, sizeof(buf) - 1, msg, args);

	Warning("[UnlockCvars] %s", buf);

	va_end(args);
}

CS2UC g_CS2UC;

PLUGIN_EXPOSE(CS2UC, g_CS2UC);
bool CS2UC::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();
	
	GET_V_IFACE_CURRENT(GetEngineFactory, g_pCVar, ICvar, CVAR_INTERFACE_VERSION);

	g_SMAPI->AddListener(this, this);

	UnlockConVars();
	UnlockConCommands();

	return true;
}

bool CS2UC::Unload(char *error, size_t maxlen)
{
	return true;
}

bool CS2UC::Pause(char *error, size_t maxlen)
{
	return true;
}

bool CS2UC::Unpause(char *error, size_t maxlen)
{
	return true;
}

const char *CS2UC::GetLicense()
{
	return "GPL v3 License";
}

const char *CS2UC::GetVersion()
{
	return "v0.0.3";
}

const char *CS2UC::GetDate()
{
	return __DATE__;
}

const char *CS2UC::GetLogTag()
{
	return "CS2UnlockCvars";
}

const char *CS2UC::GetAuthor()
{
	return "CS2Fixes, (mod by dots)";
}

const char *CS2UC::GetDescription()
{
	return "Stripped CS2Fixes for Cvar Unlocker";
}

const char *CS2UC::GetName()
{
	return "CS2UnlockCvars";
}

const char *CS2UC::GetURL()
{
	return "https://github.com/FemboyKZ/CS2UnlockCvars";
}
