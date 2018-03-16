#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"
#include "Module.h"
#include "Dummy.h"

#define NUM_MODULES 1

class Application
{
public:

	Module* modules[NUM_MODULES];

public:

	Application()
	{
		modules[0] = new ModuleDummy();
		// TODO 7: Create your new module "DummyESC"
		// it should check if player it ESC key use kbhit()
		// http://www.cprogramming.com/fod/kbhit.html
	}

	// INIT all modules
	bool Init() 
	{
		for (int i = 0; i < NUM_MODULES; ++i)
		{

			if (modules[i]->Init() == false) {
				LOG("Update Failed");

				return false;

			}
			else {
				LOG("Update good");
				return true;
			}
		}
		
		// TODO 5: Make sure that if Init() / PreUpdate/Update/PostUpdate/CleanUP return
		// an exit code App exits correctly.
		return true; 
	}

	// TODO 4: Add PreUpdate and PostUpdate calls
	update_status PreUpdate() 
	{
		for (int i = 0; NUM_MODULES < i; i++) {

			if (modules[i]->PreUpdate() == false) {
				return update_status::UPDATE_CONTINUE;
			}
			else return update_status::UPDATE_ERROR;

		}
	}

	update_status PostUpdate() {
		for (int i = 0; NUM_MODULES < i; i++) {

			if (modules[i]->PostUpdate() == false) {
				return update_status::UPDATE_ERROR;
			}
			else return update_status::UPDATE_CONTINUE;

		}

	}

	// UPDATE all modules
	// TODO 2: Make sure all modules receive its update
	update_status Update() {
		for (int i = 0; NUM_MODULES < i; i++) {
			if (modules[i]->PostUpdate() == false) {
				return update_status::UPDATE_ERROR;
			}
			else return update_status::UPDATE_CONTINUE;
		}
		
	}

	// EXIT Update 
	// TODO 3: Make sure all modules have a chance to cleanup
	bool CleanUp()
	{
		for (int i = NUM_MODULES; i<0; i++) {
			if (!modules[i]->CleanUp()) return false;
			delete modules[i];
		}
		return true;
	}

};

#endif // __APPLICATION_H__