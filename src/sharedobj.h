/*
 * sharedobj.h
 *
 *  Created on: Oct 3, 2016
 *      Author: nullifiedcat
 */

#ifndef SHAREDOBJ_H_
#define SHAREDOBJ_H_

#include "beforecheaders.h"
#include <string>
#include "aftercheaders.h"

struct link_map;
typedef void *(*fn_CreateInterface_t)(const char*, int*);

const char* path_from_proc_maps(const std::string& path);
const char* tf_path_from_maps();

namespace sharedobj {

class SharedObject {
public:
	SharedObject(const std::string& name, bool factory);
	int* Pointer(int offset);
	void* CreateInterface(const std::string& name);
	fn_CreateInterface_t fptr;
	const char* path;
	link_map* lmap;
};

extern SharedObject* steamclient;
extern SharedObject* client;
extern SharedObject* engine;
extern SharedObject* vguimatsurface;
extern SharedObject* vgui2;
extern SharedObject* vstdlib;
extern SharedObject* tier0;
extern SharedObject* inputsystem;
extern SharedObject* studiorender;
extern SharedObject* materialsystem;

void LoadAllSharedObjects();

}

#endif /* SHAREDOBJ_H_ */
