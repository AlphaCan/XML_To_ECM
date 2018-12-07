#pragma once

#ifndef PACKED
#define PACKED_BEGIN __pragma(pack(push, 1))
#define PACKED
#define PACKED_END __pragma(pack(pop))
#endif
PACKED_BEGIN
typedef struct vendor
{
	const char* FileVersion;
	const char* Id;
	const char* Name;
	const char* ImageData;

}Vendor_t;
PACKED_END
typedef struct group
{
	const char* Type;
	const char* Name;
	const char* ImageData;

}group_t;